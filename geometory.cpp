// geometory.cpp
//�􉽊w�i�}�`�j�����̃\�[�X�t�@�C��

#include "geometory.h"

//�֐� //////////////
//�_�֌W
//X�n�_��Y�n�_����POINT�^���ꎞ�I�Ɏ擾
POINT GetPoint(int x, int y)
{
	POINT pt{};

	pt.x = x;
	pt.y = y;

	return pt;
}

//�_�Ɠ_���������Ă��邩�H
BOOL CollPointToPoint(POINT a, POINT b)
{
	if (a.x == b.x && a.y == b.y)
	{
		//�������Ă���
		return TRUE;
	}
	//�������Ă��Ȃ�
	return FALSE;
}

//��`�i���������l�p�j�֌W
//����E������RECT�^���ꎞ�I�Ɏ擾
RECT GetRect(int left, int top, int right, int bottom)
{
	RECT rect{};

	rect.left = left;
	rect.top = top;
	rect.right = right;
	rect.bottom = bottom;

	return rect;
}

//��`�Ƌ�`���������Ă��邩�H
BOOL CollRectToRect(RECT a, RECT b)
{
	if (a.left <= b.right
		&& a.top <= b.bottom
		&& a.right >= b.left
		&& a.bottom >= b.top)
	{
		//�������Ă���
		return TRUE;
	}
	//�������Ă��Ȃ�
	return FALSE;
}

//��`�Ɠ_���������Ă��邩�H
BOOL CollRectToPoint(RECT rect, POINT pt)
{
	if (rect.left <= pt.x
		&& rect.top <= pt.y
		&& rect.right >= pt.x
		&& rect.bottom >= pt.y)
	{
		//�������Ă���
		return TRUE;
	}
	//�������Ă��Ȃ�
	return FALSE;
}

//RECT�^�ŋ�`��`��
void DrawRect(RECT rect, unsigned int color, BOOL fill)
{
	//��`��`��
	DrawBox(
		rect.left,
		rect.top,
		rect.right,
		rect.bottom,
		color,
		fill
	);

	return;
}

// End
