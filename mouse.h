// mouse.h
#pragma once

#include "DxLib.h"

//マクロ定義
#define MouseKindMax	8 //マウスボタンの種類
#define MouseCodeErrIndex	999 //マウスコードを変更した要素数のエラー値

//構造体
typedef struct _MousePoint {
	int x; //マウスのX位置
	int y; //マウスのY位置
} MousePoint;

//外部のプロトタイプ宣言
extern void MouseNowIntoOld(void); //Now???系の値をOld系へ入れる
extern int MouseCodeToIndex(int MOUSE_INPUT_); //マウスのボタンオートを配列の要素数に変換する

extern void MouseInit(void);			//マウス処理の初期化
extern void MouseUpdate(void);			//マウス処理の更新
extern BOOL MouseDown(int MOUSE_INPUT_);			//特定のボタンを押したか？
extern BOOL MouseClick(int MOUSE_INPUT_);			//特定のボタンをクリックしたか？
extern int  MousePressFrame(int MOUSE_INPUT_);	//特定のボタンを押したフレーム数

extern MousePoint GetPointMouse(void); //マウスの現在の位置を取得する
extern MousePoint GetOldPointMouse(void); //マウスの以前の位置を取得する
extern MousePoint GetDiffPointMouse(void); //マウスの以前と現在の位置の差を取得する

extern int GetWheelMouse(void); //マウスの現在のホイール量を取得する

// End
