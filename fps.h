// fps.h
//FPS�����̃w�b�_�t�@�C��
#pragma once

#include <DxLib.h>

//�}�N����`
#define W_FPS			60 //FPS�̐ݒ�
#define MicroSecond		1000000.0f //1�}�N���b
#define MillSecond		1000.0f //1�~���b
#define WaitTimeMill	3000 //�ő�ő҂Ă�~���b

//�\���̂̒�`�����O�̒�`
typedef struct _FPS {
	LONGLONG FirstTakeTime = 0; //�P�t���[���ڂ̌v������
	LONGLONG NowTakeTime = 0; //���݂̌v������
	LONGLONG OldTakeTime = 0; //�ȑO�̌v������

	float DeltaTime = 0.000001f; //�f���^�^�C���i�o�ߎ��ԁj
	int FrameCount = 1; //���݂̃t���[�����i�P�t���[���ځ`MAX�t���[���ڂ܂Łj
	float Average = 0.0f; //����FPS�l
}FPS;

//�O���O���[�o���ϐ�
extern FPS fps;

//�O���v���g�^�C�v�錾
extern void FPSInit(void); //FPS������
extern void FPSCheck(void); //FPS�v��
extern void FPSDraw(void); //FPS�`��
extern void FPSWait(void); //FPS�ҋ@

// End
