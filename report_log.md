Gearlad (Seth):
Day 1: I would imagine, even though I'm a computer science student, just like most other students in the class I've had to start from square one on a lot of things in this homework, like creating networked P2P communicating nodes. That's it's best and most difficult aspect, but it will force rendering an effective learning environment. I shall continue.

I am having difficulty in creating the networked aspect of this homework as I've had little experience with sockets/server requests. This may be the most difficult aspect of this Blockchain.


HW2 區塊鏈導論 m10702286江祿檠
這次作業我認為是非常大的挑戰，但我認為完成它會讓我在區塊鏈的了解與程式能力有極具的提升，除了在隊員上遇到幾次分合以外，以下是我在這次作業遇到的幾個困難。
1.	Peer to peer socket programing:
我認為這個部分是最難做的，一開始我們的方向是朝發現其他裝置在將其放入list中，但評估了一下後，這麼做會非常麻煩，所以改成一開始就設定好的list ，每台裝置分別讀完後，便試著去與其他台connect。然後接下來遇到第二個問題，裝置間該如何決定誰當server，於是我們試了兩種方式，一種是利用機率，假設有n台裝置，每台都有1/n的機率可以成為server向其他人廣播，但這個方式會導致效率不好需要非常久才能完成廣播；另一個方式便是用Ring的拓墣方式，利用傳遞一個token，拿到token的人可以當server並且對每一台裝置(依序list)做一次p2p，並在最後一次p2p時遞交給下一個節點當server，已達成每次在當server時（timeout之內）如果有節點自己有挖到礦，或是剛連上線需要向大家請求資料時，便可以向大家廣播，雖然有些缺點，如沒辦法在挖到礦時馬上廣播給所有節點，但節點夠少並都在同一台工作站內網時，連接、傳輸速度理論上不需非常久，所以server廣播一台timeout時間可以設短一點，使影響減少。
2.	C++ ＆ Python : 
對於要使用哪種語言來寫，我們掙扎很久，因為我對於C++是較為熟悉的，所以一開始，我們用C++完成了 SHA256,及區塊鏈結構的部分，但是到socket programing 及json 讀寫時，便產生使否要混用的想法，我們有試著利用呼叫其他語言函式及一些函式庫，如jsoncpp來簡化大部分的字串處理。
比特幣與無限chain差別
1.	沒有merkle_root，merkle_root一直為零
2.	Target is fixed
3.	不需要discovery 其他節點 (no DNS seed)
4.	廣播方式為直接傳給所有節點
            bitcoin	               ∞-Chain
Merkle root	紀錄交易位址	            x
Target	    浮動(維持出塊時間10min)	  固定
發現節點     DNS seed	               固定list，不發現新節點
廣播	       間接廣播(傳附近的，
            附近再接著傳下去)	        直接廣播(直接傳給所有附近的)
規模	      數萬node         
           (reachable/unrechable)   數個node
