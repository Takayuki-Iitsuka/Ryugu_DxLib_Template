// game.cpp
#include "game.h"
#include "key.h"

//グローバル変数

//ゲームシーン
enum AppScene NowAppScene; // 現在のアプリシーン
enum AppScene ChangeAppScene; // 切り替わるアプリシーン

//シーンの名前
char AppSceneName[AppSceneCount][AppSceneNameMax]
{
	"タイトル画面",
	"プレイ画面",
	"リザルト画面"
};

//シーン切り替え後のフレーム数を管理
int AppSceneFrameCount[AppSceneCount];

//関数
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
			"%s%s", AppSceneName[ChangeAppScene], "初期化");

		//適切なシーンの初期化ができているかテスト
		ScreenFlip(); //ここで敢えて裏画面を描画
		WaitTimer(2000); //その後、適当に待つ
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
	if (KeyDown(KEY_INPUT_SPACE) == TRUE //スペースが押された時
		&& AppSceneFrameCount[NowAppScene] >= AppSceneChangeFrame) //かつ、切り替え可能なフレーム数を超えたら
	{
		//シーン切り替え
		ChangeAppScene = PlayScene; //ここで初めてシーンが切り替わる
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
		DrawBox(50, 50, W_Width / 2, W_Height / 2, GetColor(176, 214, 223), TRUE);

		//シーン名表示
		DrawFormatString(
			W_Width - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", AppSceneName[NowAppScene], "描画中");
	}
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
			"%s%s", AppSceneName[ChangeAppScene], "初期化");

		//適切なシーンの初期化ができているかテスト
		ScreenFlip(); //ここで敢えて裏画面を描画
		WaitTimer(2000); //その後、適当に待つ
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
	if (KeyDown(KEY_INPUT_SPACE) == TRUE //スペースが押された時
		&& AppSceneFrameCount[NowAppScene] >= AppSceneChangeFrame) //かつ、切り替え可能なフレーム数を超えたら
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
		DrawBox(0, 0, W_Width, W_Height, GetColor(176, 114, 23), TRUE);

		//シーン名表示
		DrawFormatString(
			W_Width - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", AppSceneName[NowAppScene], "描画中");
	}
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
			"%s%s", AppSceneName[ChangeAppScene], "初期化");

		//適切なシーンの初期化ができているかテスト
		ScreenFlip(); //ここで敢えて裏画面を描画
		WaitTimer(2000); //その後、適当に待つ
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
	if (KeyDown(KEY_INPUT_SPACE) == TRUE //スペースが押された時
		&& AppSceneFrameCount[NowAppScene] >= AppSceneChangeFrame) //かつ、切り替え可能なフレーム数を超えたら
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
		DrawBox(100, 50, W_Width, W_Height, GetColor(216, 14, 223), TRUE);

		//シーン名表示
		DrawFormatString(
			W_Width - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", AppSceneName[NowAppScene], "描画中");
	}
	return;
}

// End
