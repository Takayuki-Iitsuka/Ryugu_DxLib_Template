// mouse.cpp
#include "mouse.h"
#include "game.h"

//�O���[�o���ϐ�
MousePoint NowPoint; //���݂̃}�E�X�̈ʒu
MousePoint OldPoint; //�ȑO�̃}�E�X�̈ʒu

int NowMousePressFrame[MouseKindMax]; //���݂̃}�E�X�̃{�^���������Ă���t���[�������Ǘ�
int OldMousePressFrame[MouseKindMax]; //�ȑO�̃}�E�X�̃{�^���������Ă���t���[�������Ǘ�

int NowWheelValue; //���݂̃}�E�X�̃z�C�[����]��
int OldWheelValue; //�ȑO�̃}�E�X�̃z�C�[����]��

//�}�E�X�̃{�^���R�[�h�ƃt���[�������Ǘ����Ă���z��̗v�f����R�t����
int MouseCodeIndex[MouseKindMax]
{
	MOUSE_INPUT_LEFT,	//�z��̗v�f��[�O]�ɂ̓}�E�X�̃{�^������[0x0001]�̏��������
	MOUSE_INPUT_RIGHT,	//�z��̗v�f��[�P]�ɂ̓}�E�X�̃{�^������[0x0002]�̏��������
	MOUSE_INPUT_MIDDLE,	//�z��̗v�f��[�Q]�ɂ̓}�E�X�̃{�^������[0x0004]�̏��������
	MOUSE_INPUT_4,		//�z��̗v�f��[�R]�ɂ̓}�E�X�̃{�^������[0x0008]�̏��������
	MOUSE_INPUT_5,		//�z��̗v�f��[�S]�ɂ̓}�E�X�̃{�^������[0x0010]�̏��������
	MOUSE_INPUT_6,		//�z��̗v�f��[�T]�ɂ̓}�E�X�̃{�^������[0x0020]�̏��������
	MOUSE_INPUT_7,		//�z��̗v�f��[�U]�ɂ̓}�E�X�̃{�^������[0x0040]�̏��������
	MOUSE_INPUT_8,		//�z��̗v�f��[�V]�ɂ̓}�E�X�̃{�^������[0x0080]�̏��������
};

//Now???�n�̒l��Old�n�֓����
void MouseNowIntoOld(void)
{
	OldPoint = NowPoint; //�}�E�X�̈ʒu

	//�t���[����
	for (int i = 0; i < MouseKindMax; i++)
	{
		OldMousePressFrame[i] = NowMousePressFrame[i];
	}
	//�z�C�[����
	OldWheelValue = NowWheelValue;

	return;
}

//�}�E�X�̃{�^���I�[�g��z��̗v�f���ɕϊ�����
//�����FDX���C�u�����̃}�E�X�R�[�h�iMOUSE_INPUT_�Ŏn�܂�}�N����`�j
int MouseCodeToIndex(int MOUSE_INPUT_)
{
	for (int i = 0; i < MouseKindMax; i++)
	{
		//�}�E�X�R�[�h���R�t������Ă���Ȃ�
		if (MouseCodeIndex[i] == MOUSE_INPUT_)
		{
			return i; //���̗v�f����Ԃ�
		}
	}
	//�}�E�X�R�[�h�������Ȃ�G���[�I
	return MouseCodeErrIndex;
}

//�}�E�X�����̏�����
void MouseInit(void)
{
	//�}�E�X�̈ʒu
	NowPoint.x = 0;
	NowPoint.y = 0;

	//�t���[����
	for (int i = 0; i < MouseKindMax; i++)
	{
		NowMousePressFrame[i] = 0;
	}
	//�z�C�[����
	NowWheelValue = 0;
	//Old�n��������
	MouseNowIntoOld();

	return;
}

//�}�E�X�����̍X�V
void MouseUpdate(void)
{
	//�}�E�X�̃{�^������S�Ď擾
	int Input;

	//���݂̏����ȑO�̏��Ƃ��ĕۑ�
	MouseNowIntoOld();

	//���݂̃}�E�X�̃N���C�A���g���W�̈ʒu���擾
	GetMousePoint(&NowPoint.x, &NowPoint.y);

	//�����A�}�E�X�̍��W���Q�[����ʊO�ɂ���Ȃ�A�Q�[����ʓ��Ɏ��߂�
	if (NowPoint.x < 0) { NowPoint.x = 0; } //��
	else if (NowPoint.x > W_Width) { NowPoint.x = W_Width; } //�E
	if (NowPoint.y < 0) { NowPoint.y = 0; } //��
	else if (NowPoint.y > W_Height) { NowPoint.x = W_Height; } //��

	//�}�E�X�̃{�^��������C�Ɏ擾
	Input = GetMouseInput();

	//�e�{�^���������Ă��邩�`�F�b�N
	for (int i = 0; i < MouseKindMax; i++)
	{
		//�yif���̏��������z
		//�擾�����l���}�E�X�R�[�h�Ń}�X�N�����������ʂ��A���̃}�E�X�R�[�h�Ȃ��
		//�@��j�@�擾�����l��[0x0007]�@���@�Ō�̃o�C�g��[00000111]�̏ꍇ
		//�@�}�E�X�R�[�h��[0x0001]�i���j ���@�Ō�̃o�C�g��[00000001]�ŁA
		//�_���ςŃ}�E�X�����i�㉺�Ƃ��P�Ȃ�P�A����ȊO�͂O�j��--------
		//�@�@�@�@���ʁ@0x0001�@���@�Ō�̃o�C�g���@00000001�@�ƂȂ�
		//�����̒l�������Ă��Ă��A�}�X�N����������΁A����̒l�̂ݒ��o�ł���B
		//���^�T�C�g�ł́A Input & 1 << i  �Ƃ��Ă���B�i���V�t�g�łP�̃r�b�g�����炷�j

		if ((Input & MouseCodeIndex[i]) == MouseCodeIndex[i])
		{
			//���݉����Ă���{�^���̃t���[�������J�E���g�A�b�v
			NowMousePressFrame[i]++;
		}
		else if ((Input & MouseCodeIndex[i]) != MouseCodeIndex[i])
		{
			//���݉����Ă���{�^���̃t���[�������[���N���A
			NowMousePressFrame[i] = 0;
		}
	}

	//�z�C�[���̉�]�ʂ��擾
	NowWheelValue = GetMouseWheelRotVol();

	return;
}

//����̃{�^�������������H
//�����FDX���C�u�����̃}�E�X�R�[�h�iMOUSE_INPUT_�Ŏn�܂�}�N����`�j
BOOL MouseDown(int MOUSE_INPUT_)
{
	//�}�E�X�R�[�h��z��̗v�f���ɕϊ�
	int index = MouseCodeToIndex(MOUSE_INPUT_);

	//���݂���}�E�X�R�[�h�Ȃ�
	if (index != MouseCodeErrIndex)
	{
		//���݉����Ă���Ȃ�
		if (NowMousePressFrame[index] > 0)
		{
			return TRUE; //�����Ă���
		}
	}

	return FALSE;
}

//����̃{�^�����N���b�N�������H
//�����FDX���C�u�����̃}�E�X�R�[�h�iMOUSE_INPUT_�Ŏn�܂�}�N����`�j
//�����F�u�{�^���������@���@�{�^�����グ��v���Z�b�g�ōs��ꂽ�Ƃ����A�N���b�N
BOOL MouseClick(int MOUSE_INPUT_)
{
	//�}�E�X�R�[�h��z��̗v�f���ɕϊ�
	int index = MouseCodeToIndex(MOUSE_INPUT_);

	//���݂���}�E�X�R�[�h�Ȃ�
	if (index != MouseCodeErrIndex)
	{
		//���݉����Ă���Ȃ�
		if (NowMousePressFrame[index] == 0		//���݂͉����Ă��Ȃ���
			&& OldMousePressFrame[index] > 0)   //�ȑO�͉����Ă���
		{
			return TRUE; //�����Ă���
		}
	}

	return FALSE;
}

//����̃{�^�����������t���[����
//�����FDX���C�u�����̃}�E�X�R�[�h�iMOUSE_INPUT_�Ŏn�܂�}�N����`�j
//���ӁF�߂�l�̓~���b�Ȃǂł͂Ȃ��A�t���[����
int  MousePressFrame(int MOUSE_INPUT_)
{
	//�}�E�X�R�[�h��z��̗v�f���ɕϊ�
	int index = MouseCodeToIndex(MOUSE_INPUT_);

	//���݂���}�E�X�R�[�h�Ȃ�
	if (index != MouseCodeErrIndex)
	{
		return NowMousePressFrame[MOUSE_INPUT_];
	}

	return 0;
}


//�}�E�X�̌��݂̈ʒu���擾����
MousePoint GetPointMouse(void)
{
	return NowPoint;
}

//�}�E�X�̈ȑO�̈ʒu���擾����
MousePoint GetOldPointMouse(void)
{
	return OldPoint;
}

//�}�E�X�̈ȑO�ƌ��݂̈ʒu�̍����擾����
MousePoint GetDiffPointMouse(void)
{
	MousePoint diff;
	diff.x = OldPoint.x - NowPoint.x;
	diff.y = OldPoint.y - NowPoint.y;
	
	return diff;
}

//�}�E�X�̌��݂̃z�C�[���ʂ��擾����
int GetWheelMouse(void)
{
	return NowWheelValue;
}

// End
