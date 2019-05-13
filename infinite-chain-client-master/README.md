SOURCE: https://github.com/MROS/infinite-chain-client

# HW3 輔助客戶端

## 功能

協助發送 getbalance, sendtoaddress 等兩個用戶 API。

## 準備

客戶端使用 Node.js 編寫，請先行安裝，安裝流程可見[Node.js 官網](https://nodejs.org/en/download/)。

## 執行

``` sh
git clone https://github.com/MROS/infinite-chain-client # 先下載源碼
cd infinite-chain-client        # 進入目錄
cp <path/to/config.json> .      # 複製你的 config.json 至此（客戶端需要知道節點的 port）
npm install                     # 安裝依賴
npm start                       # 執行客戶端
```

`npm start` 之後，會看到
```
inf-cli >
```
這樣的提示字元。

詳細功能請輸入 help 查看。
