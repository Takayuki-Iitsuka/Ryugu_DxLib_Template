// geometory.h
//�􉽊w�i�}�`�j�����̃w�b�_�t�@�C��
#pragma once

#include "DxLib.h"
#include <math.h>

//�\����
typedef struct _CIRCLE
{
	POINT pt; //�~�̒��S
	float radius = 0.0f; //�~�̔��a
}CIRCLE; //�~

//�O���̃v���g�^�C�v�錾

//�_�֌W
extern POINT GetPoint(int x, int y); //X�n�_��Y�n�_����POINT�^���ꎞ�I�Ɏ擾
extern BOOL CollPointToPoint(POINT a, POINT b); //�_�Ɠ_���������Ă��邩�H

//��`�i���������l�p�j�֌W
extern RECT GetRect(int left, int top, int right, int bottom); //����E������RECT�^���ꎞ�I�Ɏ擾
extern BOOL CollRectToRect(RECT a, RECT b); //��`�Ƌ�`���������Ă��邩�H
extern BOOL CollRectToPoint(RECT rect, POINT pt); //��`�Ɠ_���������Ă��邩�H
extern void DrawRect(RECT rect, unsigned int color, BOOL fill); //RECT�^�ŋ�`��`��

//�~�֌W
extern CIRCLE GetCircle(POINT pt, float rad); //CIRCLE�^���ꎞ�I�Ɏ擾
extern BOOL CollCircleToCircle(CIRCLE C1, CIRCLE C2); //�~�Ɖ~���������Ă��邩�H
extern BOOL CollCircleToPoint(CIRCLE circle, POINT pt); //�~�Ɠ_���������Ă��邩�H
extern void DrawEn(CIRCLE circle, unsigned int color, BOOL fill); //CIRCLE�^�ŕ`��


// End
