#define _CRT_SECURE_NO_WARNINGS

#include "setConsoleInfo.hpp"

int main() {
	// デフォルトでは，画面が2行3列に分割される
	// 左上から順にid=0,1,2...と振られる

	// - id割り当て -
	//  #0# #1# #2#
	//  #3# #4# #5#
	// -------------

	// setConsoleSixpack()の引数でidを指定する
	setConsoleSixpack(0); //左上

	// その他も同様に
	//setConsoleSixpack(2); //右上
	//setConsoleSixpack(2); //中央上
	//setConsoleSixpack(3); //左下
	//setConsoleSixpack(4); //中央下
	//setConsoleSixpack(5); //右下

	// !Note! setConsoleSixpackの第2,3引数で分割粒度を変更できる
}
