// WinMain.cpp
//
#include <DxLib.h>
#include "fps.h"
#include "game.h"
#include "key.h"
#include <cmath>
#include <boost\format.hpp>

// Windows Main 関数
int WINAPI WinMain(_In_	HINSTANCE hInstance, _In_opt_ HINSTANCE	hPrevInstance,
				   _In_	LPSTR lpCmdLine, // LPSTR or PSTR
				   _In_	int	nCmdShow)
{
	// Log.txtの出力
#ifndef _DEBUG // ifndef or
	SetOutApplicationSystemLogValidFlag(FALSE); // log.txt
#endif

	//基本設定
	ChangeWindowMode(TRUE); //ウィンドウモードの設定
	SetGraphMode(W_Width, W_Height, W_ColorBit); //解像度の設定
	SetWindowSizeChangeEnableFlag(TRUE);
	//SetWindowSize(W_Width, W_Height); //ウィンドウの大きさ設定
	SetMainWindowText(W_Title); //ウィンドウのタイトル設定
	SetBackgroundColor(5, 50, 100); //ウィンドウの背景色
	SetWaitVSyncFlag(W_Vsync); //垂直同期の設定
	SetAlwaysRunFlag(TRUE); //非アクティブでも実行する
	SetWindowIconID(W_Icon); // アイコン

	//DxLibの初期化
	if (DxLib_Init() == -1)
	{
		return -1; //DxLib初期化失敗ならソフト終了
		//return EXIT_FAILURE; // 1 or -1
	}

	//裏画面に描画する（ダブルバッファリング）
	SetDrawScreen(DX_SCREEN_BACK);

	//FPSの初期化
	FPSInit();

	//キーボードの初期化
	KeyInit();

	//タイトルシーンを初期化
	TitleInit();

	//最初のシーンはタイトルから
	NowAppScene = TitleScene;

	//次のシーンもタイトルか
	ChangeAppScene = TitleScene;

	//無限ループ（ゲームループ）
	while (TRUE)
	{
		//メッセージ処理をする（マウス操作やキー入力などを受け続ける）
		if (ProcessMessage() != 0)
		{
			break; //無限ループから出る（ゲーム終了）
		}
		//画面を消去する（１ループずつ書き換える）
		if (ClearDrawScreen() != 0)
		{
			break; //無限ループから出る（ゲーム終了）
		}

		// main loop
		//ここに全ての処理動作が入る
		{
			FPSCheck(); //FPS計測
			KeyUpdate(); //キーボード更新
			////////////////////////////

			//次のシーンを初期化
			if (NowAppScene != ChangeAppScene)
			{
				//各シーンの初期化を呼び出す
				switch (ChangeAppScene)
				{
					case TitleScene:
						TitleInit(); //初期化
						break;
					case PlayScene:
						PlayInit(); //初期化
						break;
					case ResultScene:
						ResultInit(); //初期化
						break;
					default:
						break;
				}
				//シーン切り替え後のシーンを現在のシーンにする
				NowAppScene = ChangeAppScene;
			}
			else {
				//シーン切り替え
				switch (NowAppScene)
				{
					case TitleScene:
						TitleCtrl(); //管理
						break;
					case PlayScene:
						PlayCtrl(); //管理
						break;
					case ResultScene:
						ResultCtrl(); //管理
						break;
					default:
						break;
				}
			}

			////////////////////////////
			FPSDraw(); //FPS描画
			FPSWait(); //FPS待機
		}
		//main loop End
		//ここまで、全ての処理動作が入る

		//裏画面を画面に描画
		ScreenFlip();

	} // main loop

	DxLib_End(); //DxLib終了
	return EXIT_SUCCESS; // ソフト終了 return 0;
}

// End
