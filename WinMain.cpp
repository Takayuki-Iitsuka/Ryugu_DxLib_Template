// WinMain.cpp
//
#include <DxLib.h>
#include "fps.h"
#include "game.h"
#include "key.h"
#include <cmath>
#include <boost\format.hpp>

// Windows Main �֐�
int WINAPI WinMain(_In_	HINSTANCE hInstance, _In_opt_ HINSTANCE	hPrevInstance,
				   _In_	LPSTR lpCmdLine, // LPSTR or PSTR
				   _In_	int	nCmdShow)
{
	// Log.txt�̏o��
#ifndef _DEBUG // ifndef or
	SetOutApplicationSystemLogValidFlag(FALSE); // log.txt
#endif

	//��{�ݒ�
	ChangeWindowMode(TRUE); //�E�B���h�E���[�h�̐ݒ�
	SetGraphMode(W_Width, W_Height, W_ColorBit); //�𑜓x�̐ݒ�
	SetWindowSizeChangeEnableFlag(TRUE);
	//SetWindowSize(W_Width, W_Height); //�E�B���h�E�̑傫���ݒ�
	SetMainWindowText(W_Title); //�E�B���h�E�̃^�C�g���ݒ�
	SetBackgroundColor(5, 50, 100); //�E�B���h�E�̔w�i�F
	SetWaitVSyncFlag(W_Vsync); //���������̐ݒ�
	SetAlwaysRunFlag(TRUE); //��A�N�e�B�u�ł����s����
	SetWindowIconID(W_Icon); // �A�C�R��

	//DxLib�̏�����
	if (DxLib_Init() == -1)
	{
		return -1; //DxLib���������s�Ȃ�\�t�g�I��
		//return EXIT_FAILURE; // 1 or -1
	}

	//����ʂɕ`�悷��i�_�u���o�b�t�@�����O�j
	SetDrawScreen(DX_SCREEN_BACK);

	//FPS�̏�����
	FPSInit();

	//�L�[�{�[�h�̏�����
	KeyInit();

	//�^�C�g���V�[����������
	TitleInit();

	//�ŏ��̃V�[���̓^�C�g������
	NowAppScene = TitleScene;

	//���̃V�[�����^�C�g����
	ChangeAppScene = TitleScene;

	//�������[�v�i�Q�[�����[�v�j
	while (TRUE)
	{
		//���b�Z�[�W����������i�}�E�X�����L�[���͂Ȃǂ��󂯑�����j
		if (ProcessMessage() != 0)
		{
			break; //�������[�v����o��i�Q�[���I���j
		}
		//��ʂ���������i�P���[�v������������j
		if (ClearDrawScreen() != 0)
		{
			break; //�������[�v����o��i�Q�[���I���j
		}

		// main loop
		//�����ɑS�Ă̏������삪����
		{
			FPSCheck(); //FPS�v��
			KeyUpdate(); //�L�[�{�[�h�X�V
			////////////////////////////

			//���̃V�[����������
			if (NowAppScene != ChangeAppScene)
			{
				//�e�V�[���̏��������Ăяo��
				switch (ChangeAppScene)
				{
					case TitleScene:
						TitleInit(); //������
						break;
					case PlayScene:
						PlayInit(); //������
						break;
					case ResultScene:
						ResultInit(); //������
						break;
					default:
						break;
				}
				//�V�[���؂�ւ���̃V�[�������݂̃V�[���ɂ���
				NowAppScene = ChangeAppScene;
			}
			else {
				//�V�[���؂�ւ�
				switch (NowAppScene)
				{
					case TitleScene:
						TitleCtrl(); //�Ǘ�
						break;
					case PlayScene:
						PlayCtrl(); //�Ǘ�
						break;
					case ResultScene:
						ResultCtrl(); //�Ǘ�
						break;
					default:
						break;
				}
			}

			////////////////////////////
			FPSDraw(); //FPS�`��
			FPSWait(); //FPS�ҋ@
		}
		//main loop End
		//�����܂ŁA�S�Ă̏������삪����

		//����ʂ���ʂɕ`��
		ScreenFlip();

	} // main loop

	DxLib_End(); //DxLib�I��
	return EXIT_SUCCESS; // �\�t�g�I�� return 0;
}

// End
