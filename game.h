// game.h
#pragma once

#include "DxLib.h"

// マクロ定義
#define W_Title "DxLib　シーン切り替え Test..." //　タイトル
#define W_Vsync TRUE // V-Syncを使うならTRUE
#define W_Icon 555 //　アイコン
#define W_Width 1280 //　画面の幅
#define W_Height 720 // 画面の高さ
#define W_ColorBit 32 // 画面の色

#define MY_PI 3.141592653589793238462643

#define AppDebug TRUE //デバックモード

#define AppSceneCount 3 //アプリシーンの数
#define AppSceneNameMax 20 //アプリシーン名の文字数MAX

#define AppSceneChangeFrame 60 //アプリシーンの切り替えを可能にするフレーム数

//色系
#define Color_black		GetColor(0,0,0)

//列挙型

//アプリシーン
enum AppScene {
	TitleScene, //タイトルシーン
	PlayScene, //プレイシーン
	ResultScene //リザルトシーン
};

//外部のグローバル変数
extern enum AppScene NowAppScene; // 現在のアプリシーン
extern enum AppScene ChangeAppScene; // 切り替わるアプリシーン

//外部のプロトタイプ宣言
extern void TitleInit(void); //タイトル初期化
extern void TitleCtrl(void); //タイトル管理
extern void TitleProc(void); //タイトル処理
extern void TitleDraw(void); //タイトル描画

extern void PlayInit(void); //プレイ初期化
extern void PlayCtrl(void); //プレイ管理
extern void PlayProc(void); //プレイ処理
extern void PlayDraw(void); //プレイ描画

extern void ResultInit(void); //リザルト初期化
extern void ResultCtrl(void); //リザルト管理
extern void ResultProc(void); //リザルト処理
extern void ResultDraw(void); //リザルト描画

// End
