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

//�F�n
#define Color_black		GetColor(0,0,0)

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
