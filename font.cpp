//font.cpp

#include "font.h"

//グローバル変数
AddFont addMukashi; //昔々ふぉんとを追加
AddFont addGenjyuu_N; //源柔ゴシックL Normalを追加
AddFont addGenjyuu_N100pt; //源柔ゴシックL Normalを追加
AddFont addGenjyuuL_N; //源柔ゴシックL Normalを追加
AddFont addGenjyuuX_N; //源柔ゴシックL Normalを追加
//AddFont addJiyu; //じゆうちょうフォントを追加

Font fontDefault; //デフォルトのフォント
Font fontMukashi100pt; //昔々ふぉんと 100pt
Font fontGenjyuu_N; //源柔ゴシックL Normal 100pt
Font fontGenjyuu_N100pt; //源柔ゴシック Medium 100pt
Font fontGenjyuuL_N; //源柔ゴシックL Normal
Font fontGenjyuuX_N; //源柔ゴシックL Normal 100pt
//Font fontJiyu100pt; //じゆうちょうフォント100pt


//外部プロトタイプ宣言

//インストール＆生成
BOOL Font_Init(void)
{
	//外部のフォントを一時的にインストール
/*
	addJiyu = FontInstall(FontPathJiyu, FontNameJiyu); if (addJiyu.CanInstall == FALSE)
	{
		return FALSE;
	}
*/

//addMukashi = FontInstall(FontPathGenjyuu_N, FontNameGenjyuu_N); if (addGenjyuu_N.CanInstall == FALSE)
//{
//	return FALSE;
//}

	//源柔ゴシック Normalを追加
	/*
	addGenjyuu_N = FontInstall(FontPathGenjyuu_N, FontNameGenjyuu_N);
	if (addGenjyuu_N.CanInstall == FALSE)
	{
		return FALSE;
	}
*/

	//フォントデータを生成してハンドルで管理

	fontDefault = FontCreate(FontDefName, FontDefSize, FontDefThinck, FontDefType);
	if (fontDefault.Handle == -1) { return FALSE; }

	//fontDefault100pt = FontCreate(FontDefName, 100, 1, FontDefType);
	//if (fontDefault100pt.Handle == -1) { return FALSE; }

	/*
	fontGenjyuu_N100pt = FontCreate(addGenjyuu_N.FontName, 100, 1, FontDefType);
	if (fontGenjyuuL_N.Handle == -1) { return FALSE; }
	*/

	/*
		fontJiyu100pt = FontCreate(addJiyu.FontName, 100, 1, FontDefType);
		if (fontJiyu100pt.Handle == -1) { return FALSE; }
	*/


	//	fontGenjyuuL_N100pt = FontCreate(addGenjyuuL_N.FontName, 100, 1, FontDefType);
	//	if (fontGenjyuuL_N100pt.Handle == -1) { return FALSE; }

	return TRUE;
}

//インストール
AddFont FontInstall(const char* path, const char* name)
{
	AddFont add;

	//フォント情報を設定
	strcpy_s(add.FontPath, sizeof(add.FontPath), path); //フォントのパスをコピー
	strcpy_s(add.FontName, sizeof(add.FontName), path); //フォントの名前をコピー

	//※WinAPI関数
	//このソフト内のみ使えるよう、一時的にインストール
	if (AddFontResourceEx(add.FontPath, FR_PRIVATE, NULL) == 0)
	{
		//フォントインストール失敗
		FontInstallErrMessage(add.FontPath); //エラーメッセージ表示
		add.CanInstall = FALSE;
	}
	else {
		//フォントインストール成功
		add.CanInstall = TRUE;
	}

	return add;
}

//インストールエラーメッセージ
void FontInstallErrMessage(const char* path)
{
	//エラー用文字列
	char ErrStr[FontErrStrMax];

	//エラー用文字列の内容を空にする
	for (int i = 0; i < FontErrStrMax; i++) { ErrStr[i] = '\0'; } //ヌル文字（￥０）で埋める

	//エラー内容を連結して生成
	sprintf_s(ErrStr, sizeof(ErrStr), "%s%s", path, FontInstallErrCap);

	//※WinAPI関数
	//パスが間違っているなどでインストールできない場合はエラー
	MessageBox(
		GetMainWindowHandle(), //ウィンドウハンドル
		ErrStr, //エラー内容
		FontInstallErrTitle, //エラータイトル
		MB_OK); //ＯＫボタンのみ

	return;
}

//フォントハンドル生成
Font FontCreate(const char* name, int size, int thinck, int type)
{
	Font font;

	strcpy_s(font.Name, sizeof(font.Name), name); //フォントの名前のコピー
	font.Size = size;
	font.Thinck = thinck;
	font.Type = type;

	//フォントの名前が間違っているなどでフォントを作れないときはエラー
	if (CheckFontName(font.Name) == FALSE)
	{
		FontCreateErrMessage(font); //エラーメッセージ表示
		font.Handle = -1; //エラーのハンドル番号を入れておく
	}
	else {
		//フォントデータ生成
		font.Handle = CreateFontToHandle(font.Name, font.Size, font.Thinck, font.Type);
	}

	return font;
}

//フォントハンドル生成エラーメッセージ
void FontCreateErrMessage(Font font)
{
	//エラー用文字列
	char ErrStr[FontErrStrMax];

	//エラー用文字列の内容を空にする
	for (int i = 0; i < FontErrStrMax; i++) { ErrStr[i] = '\0'; } //ヌル文字（￥０）で埋める

	//エラー内容を連結して生成
	sprintf_s(ErrStr, sizeof(ErrStr), "%s%s", font.Name, FontCreateErrCap);

	//※WinAPI関数
	//パスが間違っているなどでインストールできない場合はエラー
	MessageBox(
		GetMainWindowHandle(), //ウィンドウハンドル
		ErrStr, //エラー内容
		FontInstallErrTitle, //エラータイトル
		MB_OK); //ＯＫボタンのみ

	return;
}

//フォントハンドル削除
void FontDelete(Font font)
{
	//フォントハンドルを生成したなら
	if (font.Handle != -1)
	{
		//フォントデータを削除
		DeleteFontToHandle(font.Handle);
	}

	return;
}

//アンインストール
void FontUnInstall(AddFont add)
{
	//フォントをインストールしたなら
	if (add.CanInstall != FALSE)
	{
		//※WinAPI関数
		//アンインストール
		RemoveFontResourceEx(add.FontPath, FR_PRIVATE, NULL);
	}

	return;
}

//削除＆アンインストール
void Font_End(void)
{
	//フォントデータの削除
	FontDelete(fontDefault);
	//FontDelete(fontDefault100pt);
	//FontDelete(fontJiyu100pt);
	//FontDelete(fontMukashi100pt);
	//FontDelete(fontGenjyuu_N);
	//FontDelete(fontGenjyuuL_N);
	//FontDelete(fontGenjyuuL_N100pt);
	//FontDelete(fontGenjyuu_M100pt);

	//フォントアンインストール
	//FontUnInstall(addJiyu);
	//FontUnInstall(addMukashi);
	//FontUnInstall(addGenjyuu_N);
	//FontUnInstall(addGenjyuuL_N);
	//FontUnInstall(addGenjyuuX_N);
	//FontUnInstall(addGenjyuu_N);

	return;
}

//フォントを揃えて描画
//※注意：文字数が FontAlignMax を超えるとそれ以上は出力しない
void DrawFormatStringToHandleAlign(
	int x, int y, Font_Align align, unsigned int Color,
	int FontHandle, const char* FormatString, ...)
{
	int align_x = x; //揃えたときのX位置
	int align_y = y; //揃えたときのY位置
	int StrWidth = 0; //文字列の幅
	int StrHeight = 0; //文字列の高さ

	char DrawStr[FontAlignStrMax];

	//可変引数(...)をもらう準備をする
	va_list args;

	//可変引数はFormatSyringの後ろから始まる
	va_start(args, FormatString);

	//文字列を書式指定子で可変引数から生成
	vsnprintf(DrawStr, sizeof(DrawStr), FormatString, args);

	//文字列の幅を計算
	StrWidth = GetDrawStringWidthToHandle(DrawStr, strlen(DrawStr), FontHandle);

	//文字列も高さを取得
	StrHeight = GetFontSizeToHandle(FontHandle);

	//揃えごとに位置を計算する
	switch (align)
	{
		case Align_Left:
			//左揃えはそのままの位置なので、何もしない
			break;
		case Align_Center:
			//中央揃えは中央値を計算

			//X位置のみ、中央に寄せる
			align_x = x - StrWidth / 2;
			break;
		case Align_Right:
			//右揃え

			//X位置のみ、右に寄せる
			align_x = x - StrWidth;

			break;
		case Align_AllCenter:
			//上下も左右も中央揃え

			//X位置を、中央に寄せる
			align_x = x - StrWidth / 2;
			//Y位置を、中央に寄せる
			align_y = y - StrHeight / 2;

			break;
		default:
			break;
	}

	//文字の列の描画
	DrawFormatStringToHandle(align_x, align_y, Color, FontHandle, "%s", DrawStr);

	//可変引数をもらうのを終る
	va_end(args);

	return;
}


// End
