// mouse.h
#pragma once

#include "DxLib.h"

//�}�N����`
#define MouseKindMax	8 //�}�E�X�{�^���̎��
#define MouseCodeErrIndex	999 //�}�E�X�R�[�h��ύX�����v�f���̃G���[�l

//�\����
typedef struct _MousePoint {
	int x; //�}�E�X��X�ʒu
	int y; //�}�E�X��Y�ʒu
} MousePoint;

//�O���̃v���g�^�C�v�錾
extern void MouseNowIntoOld(void); //Now???�n�̒l��Old�n�֓����
extern int MouseCodeToIndex(int MOUSE_INPUT_); //�}�E�X�̃{�^���I�[�g��z��̗v�f���ɕϊ�����

extern void MouseInit(void);			//�}�E�X�����̏�����
extern void MouseUpdate(void);			//�}�E�X�����̍X�V
extern BOOL MouseDown(int MOUSE_INPUT_);			//����̃{�^�������������H
extern BOOL MouseClick(int MOUSE_INPUT_);			//����̃{�^�����N���b�N�������H
extern int  MousePressFrame(int MOUSE_INPUT_);	//����̃{�^�����������t���[����

extern MousePoint GetPointMouse(void); //�}�E�X�̌��݂̈ʒu���擾����
extern MousePoint GetOldPointMouse(void); //�}�E�X�̈ȑO�̈ʒu���擾����
extern MousePoint GetDiffPointMouse(void); //�}�E�X�̈ȑO�ƌ��݂̈ʒu�̍����擾����

extern int GetWheelMouse(void); //�}�E�X�̌��݂̃z�C�[���ʂ��擾����

// End
