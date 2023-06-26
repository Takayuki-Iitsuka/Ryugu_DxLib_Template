// mouse.h
#pragma once

#include "DxLib.h"
#include "geometory.h"

//�}�N����`
#define MouseKindMax       	8 //�}�E�X�{�^���̎��
#define MouseCodeErrIndex   999 //�}�E�X�R�[�h��ύX�����v�f���̃G���[�l

//�O���̃v���g�^�C�v�錾
extern void MouseNowInToOld(void); //Now???�n�̒l��Old�n�֓����
extern int MouseCodeToIndex(int MOUSE_INPUT_); //�}�E�X�̃{�^���I�[�g��z��̗v�f���ɕϊ�����

extern void MouseInit(void);			//�}�E�X�����̏�����
extern void MouseUpdate(void);			//�}�E�X�����̍X�V
extern BOOL MouseDown(int MOUSE_INPUT_);			//����̃{�^�������������H
extern BOOL MouseClick(int MOUSE_INPUT_);			//����̃{�^�����N���b�N�������H
extern int  MousePressFrame(int MOUSE_INPUT_);	//����̃{�^�����������t���[����

extern POINT GetPointMouse(void); //�}�E�X�̌��݂̈ʒu���擾����
extern POINT GetOldPointMouse(void); //�}�E�X�̈ȑO�̈ʒu���擾����
extern POINT GetDiffPointMouse(void); //�}�E�X�̈ȑO�ƌ��݂̈ʒu�̍����擾����
extern int GetWheelMouse(void); //�}�E�X�̌��݂̃z�C�[���ʂ��擾����

//��`
extern BOOL CollRectToMouse(RECT rect);//��`�ƃ}�E�X�̍��W���������Ă��邩�H
extern BOOL CollRectToMouseDown(RECT rect, int MOUSE_INPUT_);//��`���Ń}�E�X�̃{�^�������������H
extern BOOL CollRectToMouseClick(RECT rect, int MOUSE_INPUT_);//��`���Ń}�E�X�̃{�^�����N���b�N�������H

//�~
extern BOOL CollCircleToMouse(CIRCLE circle);//�~���Ń}�E�X�̍��W���������Ă��邩�H
extern BOOL CollCircleToMouseDown(CIRCLE circle, int MOUSE_INPUT_); //�~���Ń}�E�X�̃{�^�������������H
extern BOOL CollCircleToMouseClick(CIRCLE circle, int MOUSE_INPUT_); //�~���Ń}�E�X�̃{�^�����N���b�N�������H


// End
