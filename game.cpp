//
// game.cpp
//
// リュウグウ・アーカイブス
// https://www.youtube.com/@user-wn3lb2po1y
// 
// はじめてのDXﾗｲﾌﾞﾗﾘ
// https://youtube.com/playlist?list=PL4B4qq0SOLcVX1FSTZl2ugrfF8AYFdTRW
//

#include "game.h"
#include "key.h"
#include "mouse.h"
#include "geometory.h"

//グローバル変数

//ゲームシーン
enum AppScene NowAppScene; // 現在のアプリシーン
enum AppScene ChangeAppScene; // 切り替わるアプリシーン

//アプリ画面関係
RECT AppWindow; //アプリ画面も矩形
HWND AppHandle; //アプリのウィンドウハンドル

//シーンの名前
char AppSceneName[AppSceneCount][AppSceneNameMax]
{
	"タイトル画面",
	"プレイ画面",
	"リザルト画面"
};

//シーン切り替え後のフレーム数を管理
int AppSceneFrameCount[AppSceneCount];

//各シーンの切り替えボタン
CIRCLE StartCircle; //スタート円
CIRCLE PlayCircle; //プレイ円
CIRCLE ResultCircle; //リザルト円

//関数

//アプリ画面のハンドルを取得
HWND GetAppHandle(void)
{
	return AppHandle;
}

//ゲーム画面の矩形を取得
RECT GetAppWindow(void)
{
	return AppWindow;
}

//ソフト画面の上下左右の中央座標を取得
POINT GetAppWindowCenter(void)
{
	POINT pt;
	pt.x = W_Width / 2;
	pt.y = W_Height / 2;

	return pt;
}

//ソフト画面の初期化
void AppInit(void)
{
	//ソフト画面のハンドル（管理番号）を取得
	AppHandle = GetMainWindowHandle();

	//ソフト画面の矩形を取得
	AppWindow = GetRect(0, 0, W_Width, W_Height);

	//最初のシーンは、タイトルから
	NowAppScene = TitleScene;
	//次のシーンもタイトルから
	ChangeAppScene = TitleScene;

	//各シーンの円を初期化
	StartCircle = GetCircle(GetAppWindowCenter(), 300.0f); //半径300の円を画面中央に置く
	PlayCircle = GetCircle(GetAppWindowCenter(), 300.0f); //半径300の円を画面中央に置く
	ResultCircle = GetCircle(GetAppWindowCenter(), 300.0f); //半径300の円を画面中央に置く

	return;
}

// タイトル ///////////////////////////////////////////
//タイトル初期化
void TitleInit(void)
{
	if (AppDebug == TRUE)
	{
		//シーン名表示
		DrawFormatString(
			W_Width - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", AppSceneName[ChangeAppScene], "初期化中......");

		//適切なシーンの初期化ができているかテスト
		//ScreenFlip(); //ここで敢えて裏画面を描画
		//WaitTimer(500); //その後、適当に待つ
		//
	}
	//シーンを切り替えたフレーム数を初期化
	AppSceneFrameCount[ChangeAppScene] = 0;

	return;
}

//タイトル管理
void TitleCtrl(void)
{
	TitleProc(); //処理をしてから
	TitleDraw(); //描画する

	return;
}

//タイトル処理
void TitleProc(void)
{
	//シーン切り替え後のフレーム数をカウントアップ
	AppSceneFrameCount[NowAppScene]++;

	//シーン切り替え

	//if (KeyDown(KEY_INPUT_SPACE) == TRUE //スペースが押された時
	//if (MouseDown(MOUSE_INPUT_LEFT) == TRUE //マウスの左ボタンが押されたとき
	//if (CollWindowToMousePoint() == TRUE //画面内にマウスの座標があるとき
	//if (CollRectToMouseClick(GetRect(0, 0, W_Width, W_Height), MOUSE_INPUT_LEFT) == TRUE //画面内にマウスの座標があるとき

	//円のどこかをマウス左ボタンでクリックしたとき
	//かつ、切り替え可能なフレーム数を超えたら
	if (CollCircleToMouseDown(StartCircle, MOUSE_INPUT_LEFT) == TRUE
		&& AppSceneFrameCount[NowAppScene] >= AppSceneChangeFrame)
	{
		//シーン切り替え
		ChangeAppScene = PlayScene;
		//すぐに切り替える
		return;
	}
	return;
}

//タイトル描画
void TitleDraw(void) {
	if (AppDebug == TRUE)
	{
		//適当に描画
		DrawBox(20, 20, W_Width / 1.3, W_Height / 1.3, GetColor(176, 114, 223), TRUE);

		//シーン名表示
		DrawFormatString(
			W_Width - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", AppSceneName[NowAppScene], "描画中......");
	}

	//円の中にマウス座標が入ったら円の色を変える
	if (CollCircleToMouse(StartCircle) == TRUE)
	{
		//円の描画
		DrawEn(StartCircle, Color_tomato, TRUE);
	}
	else {
		//円の描画
		DrawEn(StartCircle, Color_white, TRUE);
	}

	
	//マウス機能テスト
	DrawCircle(GetOldPointMouse().x, GetOldPointMouse().y,  //以前のマウスの位置
			   20,											//円の大きさ
			   GetColor(0, 255, 0),							//円の色　　　　　
			   TRUE);										//円を塗りつぶす　　　　　

	DrawCircle(GetPointMouse().x, GetPointMouse().y,		//現在のマウスの位置
			   abs(GetWheelMouse()) * 100 + 10,	//マウスのホイール量（＋とーがあるので絶対値）を使用して計算
			   GetColor(255, 0, 0),							//円の色
			   TRUE);										//円を塗りつぶす
	//マウス機能テスト End
	

	//とりあえずのシーン名を描画
	//一時的にフォントのサイズを変更
	//処理が重いので将来的にはフォントハンドルを生成する
	SetFontSize(100);
	DrawFormatString(GetAppWindowCenter().x - 170,
					 GetAppWindowCenter().y,
					 Color_black, "%s", "START!!!!!");
	SetFontSize(16); //もとのぐらいに戻す

	return;
}

// プレイ //////////////////////////////////////////////
//プレイ初期化
void PlayInit(void)
{
	if (AppDebug == TRUE)
	{
		//シーン名表示
		DrawFormatString(
			W_Width - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", AppSceneName[ChangeAppScene], "初期化中......");

		//適切なシーンの初期化ができているかテスト
		//ScreenFlip(); //ここで敢えて裏画面を描画
		//WaitTimer(500); //その後、適当に待つ
		//
	}
	//シーンを切り替えたフレーム数を初期化
	AppSceneFrameCount[ChangeAppScene] = 0;

	return;
}

//プレイ管理
void PlayCtrl(void)
{
	PlayProc(); //処理をしてから
	PlayDraw(); //描画する

	return;
}

//プレイ処理
void PlayProc(void)
{
	//シーン切り替え後のフレーム数をカウントアップ
	AppSceneFrameCount[NowAppScene]++;

	//シーン切り替え

	//if (KeyDown(KEY_INPUT_SPACE) == TRUE //スペースが押された時
	//if (MouseDown(MOUSE_INPUT_LEFT) == TRUE //マウスの左ボタンが押されたとき

	//円のどこかをマウス左ボタンで押したとき
	//かつ、切り替え可能なフレーム数を超えたとき
	if (CollCircleToMouseDown(PlayCircle, MOUSE_INPUT_LEFT) == TRUE
		&& AppSceneFrameCount[NowAppScene] >= AppSceneChangeFrame)
	{
		//シーン切り替え
		ChangeAppScene = ResultScene;
		//すぐに切り替える
		return;
	}
	return;
}

//プレイ描画
void PlayDraw(void)
{
	if (AppDebug == TRUE)
	{
		//適当に描画
		DrawBox(100, 100, W_Width / 1.8, W_Height / 1.8, GetColor(176, 114, 23), TRUE);

		//シーン名表示
		DrawFormatString(
			W_Width - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", AppSceneName[NowAppScene], "描画中......");
	}

	//円の中にマウス座標が入ったら円の色を変える
	if (CollCircleToMouse(PlayCircle) == TRUE)
	{
		//円の描画
		DrawEn(PlayCircle, Color_lawngreen, TRUE);
	}
	else {
		//円の描画
		DrawEn(PlayCircle, Color_white, TRUE);
	}

	//とりあえずのシーン名を描画
	//一時的にフォントのサイズを変更
	//処理が重いので将来的にはフォントハンドルを生成する
	SetFontSize(100);
	DrawFormatString(GetAppWindowCenter().x - 170,
					 GetAppWindowCenter().y,
					 Color_black, "%s", "PLAY!!!!!");
	SetFontSize(16); //もとのぐらいに戻す

	return;
}

// リザルト //////////////////////////////////////////////
//リザルト初期化
void ResultInit(void)
{
	if (AppDebug == TRUE)
	{
		//シーン名表示
		DrawFormatString(
			W_Width - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", AppSceneName[ChangeAppScene], "初期化中......");

		//適切なシーンの初期化ができているかテスト
		//ScreenFlip(); //ここで敢えて裏画面を描画
		//WaitTimer(500); //その後、適当に待つ
		//
	}

	//シーンを切り替えたフレーム数を初期化
	AppSceneFrameCount[ChangeAppScene] = 0;

	return;
}

//リザルト管理
void ResultCtrl(void)
{
	ResultProc(); //処理をしてから
	ResultDraw(); //描画する

	return;
}

//リザルト処理
void ResultProc(void)
{
	//シーン切り替え後のフレーム数をカウントアップ
	AppSceneFrameCount[NowAppScene]++;

	//シーン切り替え
	//if (MouseDown(MOUSE_INPUT_LEFT) == TRUE //マウスの左ボタンが押されたとき
	//if (KeyDown(KEY_INPUT_SPACE) == TRUE //スペースが押された時

	//円のどこかをマウス左ボタンで押したとき
	//かつ、切り替え可能なフレーム数を超えたとき
	if (CollCircleToMouseDown(ResultCircle, MOUSE_INPUT_LEFT) == TRUE
		&& AppSceneFrameCount[NowAppScene] >= AppSceneChangeFrame)
	{
		//シーン切り替え
		ChangeAppScene = TitleScene;
		//すぐに切り替える
		return;
	}
	return;
}

//リザルト描画
void ResultDraw(void)
{
	if (AppDebug == TRUE)
	{
		//適当に描画
		//DrawBox(150, 160, W_Width / 1.5, W_Height / 1.5, GetColor(216, 14, 223), TRUE);

		//シーン名表示
		DrawFormatString(
			W_Width - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", AppSceneName[NowAppScene], "描画中......");
	}

	//円の中にマウス座標が入ったら円の色を変える
	if (CollCircleToMouse(ResultCircle) == TRUE)
	{
		//円の描画
		DrawEn(PlayCircle, Color_yellow, TRUE);
	}
	else {
		//円の描画
		DrawEn(PlayCircle, Color_white, TRUE);
	}

	//とりあえずのシーン名を描画
	//一時的にフォントのサイズを変更
	//処理が重いので将来的にはフォントハンドルを生成する
	SetFontSize(100);
	DrawFormatString(GetAppWindowCenter().x - 170,
					 GetAppWindowCenter().y,
					 Color_black, "%s", "RESULT!!!!!");
	SetFontSize(16); //もとのぐらいに戻す

	return;
}

// End
