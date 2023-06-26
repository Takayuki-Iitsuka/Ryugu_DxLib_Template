//
// WinMain.cpp
//
// �����E�O�E�E�A�[�J�C�u�X
// https://www.youtube.com/@user-wn3lb2po1y
// 
// �͂��߂Ă�DXײ����
// https://youtube.com/playlist?list=PL4B4qq0SOLcVX1FSTZl2ugrfF8AYFdTRW
//

#include <DxLib.h>
#include "fps.h"
#include "game.h"
#include "key.h"
#include "mouse.h"

#include <math.h>
#include <boost\format.hpp>

// Windows Main �֐�
int WINAPI WinMain(_In_	HINSTANCE hInstance, _In_opt_ HINSTANCE	hPrevInstance,
				   _In_	LPSTR lpCmdLine, // LPSTR or PSTR
				   _In_	int	nCmdShow)
{
// Log.txt�̏o��
#ifndef _DEBUG // ifndef or ifdef
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

	//�\�t�g��ʂ�������
	AppInit();

	//FPS�̏�����
	FPSInit();

	//�L�[�{�[�h�ƃ}�E�X�̏�����
	KeyInit();
	MouseInit();

	//�^�C�g���V�[����������
	TitleInit();

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
			MouseUpdate(); //�}�E�X�̍X�V
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
