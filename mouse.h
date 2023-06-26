// mouse.h
#pragma once

#include "DxLib.h"
#include "geometory.h"

//マクロ定義
#define MouseKindMax       	8 //マウスボタンの種類
#define MouseCodeErrIndex   999 //マウスコードを変更した要素数のエラー値

//外部のプロトタイプ宣言
extern void MouseNowInToOld(void); //Now???系の値をOld系へ入れる
extern int MouseCodeToIndex(int MOUSE_INPUT_); //マウスのボタンオートを配列の要素数に変換する

extern void MouseInit(void);			//マウス処理の初期化
extern void MouseUpdate(void);			//マウス処理の更新
extern BOOL MouseDown(int MOUSE_INPUT_);			//特定のボタンを押したか？
extern BOOL MouseClick(int MOUSE_INPUT_);			//特定のボタンをクリックしたか？
extern int  MousePressFrame(int MOUSE_INPUT_);	//特定のボタンを押したフレーム数

extern POINT GetPointMouse(void); //マウスの現在の位置を取得する
extern POINT GetOldPointMouse(void); //マウスの以前の位置を取得する
extern POINT GetDiffPointMouse(void); //マウスの以前と現在の位置の差を取得する
extern int GetWheelMouse(void); //マウスの現在のホイール量を取得する

//矩形
extern BOOL CollRectToMouse(RECT rect);//矩形とマウスの座標が当たっているか？
extern BOOL CollRectToMouseDown(RECT rect, int MOUSE_INPUT_);//矩形内でマウスのボタンを押したか？
extern BOOL CollRectToMouseClick(RECT rect, int MOUSE_INPUT_);//矩形内でマウスのボタンをクリックしたか？

//円
extern BOOL CollCircleToMouse(CIRCLE circle);//円内でマウスの座標が当たっているか？
extern BOOL CollCircleToMouseDown(CIRCLE circle, int MOUSE_INPUT_); //円内でマウスのボタンを押したか？
extern BOOL CollCircleToMouseClick(CIRCLE circle, int MOUSE_INPUT_); //円内でマウスのボタンをクリックしたか？


// End
