// font.h

#pragma once

#include "DxLib.h"

//フォントのパスと名前

//外部フォント
//#define FontPathJiyu ".\\FONT\\Jiyucho.otf"
//#define FontNameJiyu "じゆうちょうフォント"

#define FontPathMukashi ".\\Font\\gomarice_mukasi_mukasi.ttf"
#define FontNameMukashi "昔々ふぉんと"

#define FontPathGenjyuuL_N ".\\Font\\GenJyuuGothicL-Normal.ttf"
#define FontNameGenjyuuL_N "源柔ゴシックL Normal"

#define FontPathGenjyuu_N ".\\Font\\GenJyuuGothic-Normal.ttf"
#define FontNameGenjyuu_N "源柔ゴシック Ｎｏｒｍａｌ"
//#define FontNameGenjyuu_N "源柔ゴシック Normal"


//内部フォント
#define FontNameMSMincho "ＭＳ 明朝"
#define FontNameGenJyuu_M "源柔ゴシック Medium"
#define FontNameGenjyuuX_N "源柔ゴシックX Normal"

//デフォルトのフォント
//#define FontDefName FontNameMSMincho //フォント名
#define FontDefName FontNameGenjyuuX_N //フォント名
#define FontDefSize 20 //文字サイズ
#define FontDefThinck 1 //文字の大きさ
//#define FontDefType DX_FONTTYPE_ANTIALIASING_8X8 //アンチエイリアス
#define FontDefType DX_FONTTYPE_ANTIALIASING_16X16 //アンチエイリアス
//#define FontDefType DX_FONTTYPE_ANTIALIASING_EDGE_16X16 //アンチエイリアス

//文字列の長さ
#define FontNameStrMax 256
#define FontErrStrMax 512

//エラー
#define FontInstallErrCap "がインストールできません"
#define FontInstallErrTitle "フォントインストールエラー"

#define FontCreateErrCap "が作成できません"
#define FontCreateErrTitle "フォント作成エラー"

//文字揃えMAX文字数
#define FontAlignStrMax 512

//列挙型
enum Font_Align {
	Align_Left, //左揃え
	Align_Center, //中央揃え
	Align_Right, //右揃え
	Align_AllCenter //上下も左右も中央揃え
};

//構造体
typedef struct _AddFont {
	char FontPath[FontNameStrMax];
	char FontName[FontNameStrMax];
	BOOL CanInstall = FALSE; //インストールできたか？

}AddFont; //一時的にインストールするフォント情報

typedef struct _Font {
	int Handle; //フォントハンドル（フォントデータの管理番号）

	char Name[FontNameStrMax]; //フォント名
	int Size; //フォントのサイズ
	int Thinck; //フォントの太さ
	int Type; //アンチエイリアス

}Font; //フォントデータ作成用

//外部グローバル変数
//extern AddFont addMukashi; //昔々ふぉんとを追加
//extern AddFont addGenjyuu_N; //源柔ゴシック Normalを追加
//extern AddFont addGenjyuuL_N; //源柔ゴシックL Normalを追加
//extern AddFont addGenjyuuX_N; //源柔ゴシックX Normalを追加
//extern AddFont addJiyu; //じゆうちょうフォントを追加

extern Font fontDefault; //デフォルトのフォント
//extern Font fontDefault100pt; //デフォルト100ptのフォント

//extern Font fontMukashi100pt; //昔々ふぉんと 100pt
//extern Font fontGenjyuu_N; //源柔ゴシック  Normal
//extern Font fontGenjyuu_N100pt; //源柔ゴシック  Normal 100pt
//extern Font fontGenjyuuL_N; //源柔ゴシックL  Normal
//extern Font fontGenjyuuL_N100pt; //源柔ゴシックL Normal 100pt
//extern Font fontGenjyuuX_N; //源柔ゴシックX  Normal

//内部
extern Font fontGenjyuu_N; //源柔ゴシック Medium 100pt
//extern Font fontJiyu100pt; //じゆうちょうフォント100pt

//外部プロトタイプ宣言
extern BOOL Font_Init(void); //インストール＆生成
extern AddFont FontInstall(const char* path, const char* name); //--インストール
extern void FontInstallErrMessage(const char* path); //--インストールエラーメッセージ
extern Font FontCreate(const char* name, int size, int thinck, int type); //----フォントハンドル生成
extern void FontCreateErrMessage(Font font); //----フォントハンドル生成エラーメッセージ
extern void FontDelete(Font font); //----フォントハンドル削除
extern void FontUnInstall(AddFont add); //--アンインストール
extern void Font_End(void); //削除＆アンインストール

//フォントを揃えて描画
extern void DrawFormatStringToHandleAlign(
	int x, int y,
	Font_Align align, unsigned int Color, int FontHandle,
	const char* FormatString, ...);

// End
