// key.h
// キーボードの処理
#pragma once

#include "DxLib.h"

//マクロ定義
#define KeyKindMax 256 //キーの種類

//外部のプロトタイプ宣言
extern void KeyInit(void); //キーボード処理の初期化
extern void KeyUpdate(void); //キーボード処理の更新
extern BOOL KeyDown(int KEY_INPUT_); //特定のキーを押したか？
extern BOOL KeyClick(int KEY_INPUT_); //特定のキーをクリックしたか？
extern int KeyPressFrame(int KEY_INPUT_); //特定のキーを押したフレーム数

// End
