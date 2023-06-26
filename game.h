// game.h
#pragma once

#include "DxLib.h"

// �}�N����`
#define W_Title "DxLib�@�V�[���؂�ւ� Test..." //�@�^�C�g��
#define W_Vsync TRUE // V-Sync���g���Ȃ�TRUE
#define W_Icon 555 //�@�A�C�R��
#define W_Width 1280 //�@��ʂ̕�
#define W_Height 720 // ��ʂ̍���
#define W_ColorBit 32 // ��ʂ̐F

#define MY_PI 3.141592653589793238462643

#define AppDebug TRUE //�f�o�b�N���[�h

#define AppSceneCount 3 //�A�v���V�[���̐�
#define AppSceneNameMax 20 //�A�v���V�[�����̕�����MAX

#define AppSceneChangeFrame 60 //�A�v���V�[���̐؂�ւ����\�ɂ���t���[����

//�F�n�̖��O�i���F�厫�T���Q�l�� https://www.colordir.org/ �j
#define Color_black				GetColor(0,0,0)
#define Color_white				GetColor(255,255,255)
#define Color_skyblue			GetColor(135,205,235)
#define Color_tomato			GetColor(255,99,71)
#define Color_lightyellow		GetColor(255,255,224)
#define Color_lawngreen			GetColor(124,252,0)
#define Color_pink				GetColor(255,192,203)
#define Color_yellow			GetColor(255,255,0)

//�񋓌^

//�A�v���V�[��
enum AppScene {
	TitleScene, //�^�C�g���V�[��
	PlayScene, //�v���C�V�[��
	ResultScene //���U���g�V�[��
};

//�O���̃O���[�o���ϐ�
extern enum AppScene NowAppScene; // ���݂̃A�v���V�[��
extern enum AppScene ChangeAppScene; // �؂�ւ��A�v���V�[��

//�O���̃v���g�^�C�v�錾

extern void AppInit(void); //�A�v����ʏ�����
extern HWND GetAppHandle(void); //�A�v����ʂ��n���h�����擾
extern RECT GetAppWindow(void); //�A�v����ʂ̋�`���擾

extern POINT GetAppWindowCenter(void); //�A�v����ʂ̏㉺���E�̒������W���擾

extern void TitleInit(void); //�^�C�g��������
extern void TitleCtrl(void); //�^�C�g���Ǘ�
extern void TitleProc(void); //�^�C�g������
extern void TitleDraw(void); //�^�C�g���`��

extern void PlayInit(void); //�v���C������
extern void PlayCtrl(void); //�v���C�Ǘ�
extern void PlayProc(void); //�v���C����
extern void PlayDraw(void); //�v���C�`��

extern void ResultInit(void); //���U���g������
extern void ResultCtrl(void); //���U���g�Ǘ�
extern void ResultProc(void); //���U���g����
extern void ResultDraw(void); //���U���g�`��

// End
