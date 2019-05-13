const net = require("net");
const fs = require("fs");

const vorpal = require("vorpal")();
const chalk = require("chalk");
const _ = require("lodash");

let config = fs.readFileSync("config.json", "utf8").toString();
config = JSON.parse(config);

const user_port = config.user_port;

function sendAPI(json, callback, validator) {
    const socket = net.Socket();
    socket.connect(user_port, function() {
        socket.write(json);
    });

    let response = "";
    socket.on('data', function(data) {
        response += data;
        try {
            const j = JSON.parse(response);
            console.log(JSON.stringify(j, null, 4));
            if (!validator(j)) {
                console.log(chalk.red("回傳值不符合規範"));
            }
            socket.destroy();
            callback();
        } catch (err) {
            console.log(`已蒐集 ${response}`);
        }
    })
    socket.on('close', function(data) {
        socket.destroy();
    })
}

function getbalance_validator(res) {
    return _.has(res, "balance")
        && _.has(res, "error")
        && _.isInteger(res.balance)
        && _.isInteger(res.error);
}

function sendtoaddress_validator(res) {
    return _.has(res, "error")
        && _.isInteger(res.error);
}

function is_address(a) {
    let re = /[0-9A-Fa-f]+/g;
    return _.isString(a) && a.length == 128 && re.test(a);
}

vorpal.command("getbalance <address>")
    .action(function (args, callback) {
        if (!is_address(args.address)) {
            console.log(chalk.red(`不合法的地址： ${args.address}`));
            callback();
            return;
        }
        let json = JSON.stringify({
            method: "getbalance",
            data: {
                address: args.address
            }
        });
        sendAPI(json, callback, getbalance_validator);
    });

function is_amount(a) {
    return parseInt(a) != NaN;
}

vorpal.command("sendtoaddress <address> <amount>")
    .action(function (args, callback) {
        if (!is_address(args.address)) {
            console.log(chalk.red(`不合法的地址： ${args.address}`));
            callback();
            return;
        }
        if (!is_amount(args.amount)) {
            console.log(chalk.red(`不合法的金額： ${args.amount}`));
            callback();
            return;
        }
        let json = JSON.stringify({
            method: "sendtoaddress",
            data: {
                address: args.address,
                amount: parseInt(args.amount)
            }
        });
        sendAPI(json, callback, sendtoaddress_validator);
    });

vorpal
    .delimiter("inf-cli >")
    .show();