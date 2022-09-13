# setConsoleInfo
コンソール画面の表示位置を指定するライブラリ

# 使い方
setConsoleInfo.hppをインクルードしてください．  
sample.cppを参考に，メインプログラムから，設定関数を呼び出してください．

デフォルトでは、画面が2行3列に分割されます．  
左上から順にid=0,1,2...と振られます．  

	// - id割り当て -
	//  #0# #1# #2#
	//  #3# #4# #5#
	// -------------

setConsoleSixpack()の引数でコンソール画面を配置したいidを指定します．  
setConsoleSixpack()の第2,3引数で分割粒度を変更できます．  

# 実行結果
sample.cppを実行した結果を示します．  
setConsoleSixpack(0)により，コンソール画面が6等分された内の左上に表示されました．  

<img src="https://github.com/TMU-Wada-Lab/setConsoleInfo/blob/main/sampleResult.png" width=700>

# その他
Windowsでのみ利用可能
