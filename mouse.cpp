// mouse.cpp
#include "mouse.h"
#include "game.h"

//グローバル変数
MousePoint NowPoint; //現在のマウスの位置
MousePoint OldPoint; //以前のマウスの位置

int NowMousePressFrame[MouseKindMax]; //現在のマウスのボタンを押しているフレーム数を管理
int OldMousePressFrame[MouseKindMax]; //以前のマウスのボタンを押しているフレーム数を管理

int NowWheelValue; //現在のマウスのホイール回転量
int OldWheelValue; //以前のマウスのホイール回転量

//マウスのボタンコードとフレーム数を管理している配列の要素数を紐付ける
int MouseCodeIndex[MouseKindMax]
{
	MOUSE_INPUT_LEFT,	//配列の要素数[０]にはマウスのボタン情報の[0x0001]の情報をいれる
	MOUSE_INPUT_RIGHT,	//配列の要素数[１]にはマウスのボタン情報の[0x0002]の情報をいれる
	MOUSE_INPUT_MIDDLE,	//配列の要素数[２]にはマウスのボタン情報の[0x0004]の情報をいれる
	MOUSE_INPUT_4,		//配列の要素数[３]にはマウスのボタン情報の[0x0008]の情報をいれる
	MOUSE_INPUT_5,		//配列の要素数[４]にはマウスのボタン情報の[0x0010]の情報をいれる
	MOUSE_INPUT_6,		//配列の要素数[５]にはマウスのボタン情報の[0x0020]の情報をいれる
	MOUSE_INPUT_7,		//配列の要素数[６]にはマウスのボタン情報の[0x0040]の情報をいれる
	MOUSE_INPUT_8,		//配列の要素数[７]にはマウスのボタン情報の[0x0080]の情報をいれる
};

//Now???系の値をOld系へ入れる
void MouseNowIntoOld(void)
{
	OldPoint = NowPoint; //マウスの位置

	//フレーム数
	for (int i = 0; i < MouseKindMax; i++)
	{
		OldMousePressFrame[i] = NowMousePressFrame[i];
	}
	//ホイール量
	OldWheelValue = NowWheelValue;

	return;
}

//マウスのボタンオートを配列の要素数に変換する
//引数：DXライブラリのマウスコード（MOUSE_INPUT_で始まるマクロ定義）
int MouseCodeToIndex(int MOUSE_INPUT_)
{
	for (int i = 0; i < MouseKindMax; i++)
	{
		//マウスコードが紐付けされているなら
		if (MouseCodeIndex[i] == MOUSE_INPUT_)
		{
			return i; //その要素数を返す
		}
	}
	//マウスコードが無いならエラー！
	return MouseCodeErrIndex;
}

//マウス処理の初期化
void MouseInit(void)
{
	//マウスの位置
	NowPoint.x = 0;
	NowPoint.y = 0;

	//フレーム数
	for (int i = 0; i < MouseKindMax; i++)
	{
		NowMousePressFrame[i] = 0;
	}
	//ホイール量
	NowWheelValue = 0;
	//Old系も初期化
	MouseNowIntoOld();

	return;
}

//マウス処理の更新
void MouseUpdate(void)
{
	//マウスのボタン情報を全て取得
	int Input;

	//現在の情報を以前の情報として保存
	MouseNowIntoOld();

	//現在のマウスのクライアント座標の位置を取得
	GetMousePoint(&NowPoint.x, &NowPoint.y);

	//もし、マウスの座標がゲーム画面外にあるなら、ゲーム画面内に収める
	if (NowPoint.x < 0) { NowPoint.x = 0; } //左
	else if (NowPoint.x > W_Width) { NowPoint.x = W_Width; } //右
	if (NowPoint.y < 0) { NowPoint.y = 0; } //上
	else if (NowPoint.y > W_Height) { NowPoint.x = W_Height; } //下

	//マウスのボタン情報を一気に取得
	Input = GetMouseInput();

	//各ボタンを押しているかチェック
	for (int i = 0; i < MouseKindMax; i++)
	{
		//【if文の条件説明】
		//取得した値をマウスコードでマスク処理した結果が、そのマウスコードならば
		//　例）　取得した値が[0x0007]　→　最後のバイトが[00000111]の場合
		//　マウスコードが[0x0001]（左） →　最後のバイトが[00000001]で、
		//論理積でマウス処理（上下とも１なら１、それ以外は０）＆--------
		//　　　　結果　0x0001　→　最後のバイトが　00000001　となる
		//複数の値が入っていても、マスク処理をすれば、特定の値のみ抽出できる。
		//※某サイトでは、 Input & 1 << i  としている。（左シフトで１のビットをずらす）

		if ((Input & MouseCodeIndex[i]) == MouseCodeIndex[i])
		{
			//現在押しているボタンのフレーム数がカウントアップ
			NowMousePressFrame[i]++;
		}
		else if ((Input & MouseCodeIndex[i]) != MouseCodeIndex[i])
		{
			//現在押しているボタンのフレーム数をゼロクリア
			NowMousePressFrame[i] = 0;
		}
	}

	//ホイールの回転量を取得
	NowWheelValue = GetMouseWheelRotVol();

	return;
}

//特定のボタンを押したか？
//引数：DXライブラリのマウスコード（MOUSE_INPUT_で始まるマクロ定義）
BOOL MouseDown(int MOUSE_INPUT_)
{
	//マウスコードを配列の要素数に変換
	int index = MouseCodeToIndex(MOUSE_INPUT_);

	//実在するマウスコードなら
	if (index != MouseCodeErrIndex)
	{
		//現在押しているなら
		if (NowMousePressFrame[index] > 0)
		{
			return TRUE; //押している
		}
	}

	return FALSE;
}

//特定のボタンをクリックしたか？
//引数：DXライブラリのマウスコード（MOUSE_INPUT_で始まるマクロ定義）
//説明：「ボタンを押す　→　ボタンを上げる」がセットで行われたときが、クリック
BOOL MouseClick(int MOUSE_INPUT_)
{
	//マウスコードを配列の要素数に変換
	int index = MouseCodeToIndex(MOUSE_INPUT_);

	//実在するマウスコードなら
	if (index != MouseCodeErrIndex)
	{
		//現在押しているなら
		if (NowMousePressFrame[index] == 0		//現在は押していないが
			&& OldMousePressFrame[index] > 0)   //以前は押していた
		{
			return TRUE; //押している
		}
	}

	return FALSE;
}

//特定のボタンを押したフレーム数
//引数：DXライブラリのマウスコード（MOUSE_INPUT_で始まるマクロ定義）
//注意：戻り値はミリ秒などではなく、フレーム数
int  MousePressFrame(int MOUSE_INPUT_)
{
	//マウスコードを配列の要素数に変換
	int index = MouseCodeToIndex(MOUSE_INPUT_);

	//実在するマウスコードなら
	if (index != MouseCodeErrIndex)
	{
		return NowMousePressFrame[MOUSE_INPUT_];
	}

	return 0;
}


//マウスの現在の位置を取得する
MousePoint GetPointMouse(void)
{
	return NowPoint;
}

//マウスの以前の位置を取得する
MousePoint GetOldPointMouse(void)
{
	return OldPoint;
}

//マウスの以前と現在の位置の差を取得する
MousePoint GetDiffPointMouse(void)
{
	MousePoint diff;
	diff.x = OldPoint.x - NowPoint.x;
	diff.y = OldPoint.y - NowPoint.y;
	
	return diff;
}

//マウスの現在のホイール量を取得する
int GetWheelMouse(void)
{
	return NowWheelValue;
}

// End
