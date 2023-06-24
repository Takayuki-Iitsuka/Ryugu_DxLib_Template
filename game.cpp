// game.cpp
#include "game.h"
#include "key.h"
#include "mouse.h"
#include "geometory.h"

//�O���[�o���ϐ�

//�Q�[���V�[��
enum AppScene NowAppScene; // ���݂̃A�v���V�[��
enum AppScene ChangeAppScene; // �؂�ւ��A�v���V�[��

//�V�[���̖��O
char AppSceneName[AppSceneCount][AppSceneNameMax]
{
	"�^�C�g�����",
	"�v���C���",
	"���U���g���"
};

//�V�[���؂�ւ���̃t���[�������Ǘ�
int AppSceneFrameCount[AppSceneCount];

//�֐�
// �^�C�g�� ///////////////////////////////////////////
//�^�C�g��������
void TitleInit(void)
{
	if (AppDebug == TRUE)
	{
		//�V�[�����\��
		DrawFormatString(
			W_Width - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", AppSceneName[ChangeAppScene], "������");

		//�K�؂ȃV�[���̏��������ł��Ă��邩�e�X�g
		ScreenFlip(); //�����Ŋ����ė���ʂ�`��
		WaitTimer(1000); //���̌�A�K���ɑ҂�
	}
	//�V�[����؂�ւ����t���[������������
	AppSceneFrameCount[ChangeAppScene] = 0;

	return;
}
//�^�C�g���Ǘ�
void TitleCtrl(void)
{
	TitleProc(); //���������Ă���
	TitleDraw(); //�`�悷��
	return;
}
//�^�C�g������
void TitleProc(void)
{
	//�V�[���؂�ւ���̃t���[�������J�E���g�A�b�v
	AppSceneFrameCount[NowAppScene]++;

	//�V�[���؂�ւ�
	
	//if (KeyDown(KEY_INPUT_SPACE) == TRUE //�X�y�[�X�������ꂽ��
	if (MouseDown(MOUSE_INPUT_LEFT) == TRUE //�}�E�X�̍��{�^���������ꂽ�Ƃ�
	//if (CollWindowToMousePoint() == TRUE //��ʓ��Ƀ}�E�X�̍��W������Ƃ�
	//if (CollRectToMouseClick(GetRect(0, 0, W_Width, W_Height), MOUSE_INPUT_LEFT) == TRUE //��ʓ��Ƀ}�E�X�̍��W������Ƃ�

	//if (CollWindowToMouseClick(MOUSE_INPUT_LEFT) == TRUE //��ʓ��Ƀ}�E�X�̍��W�����荶�N���b�N�����Ƃ�
		&& AppSceneFrameCount[NowAppScene] >= AppSceneChangeFrame) //���A�؂�ւ��\�ȃt���[�����𒴂�����
	{
		//�V�[���؂�ւ�
		ChangeAppScene = PlayScene; //�����ŏ��߂ăV�[�����؂�ւ��
		//�����ɐ؂�ւ���
		return;
	}
	return;
}
//�^�C�g���`��
void TitleDraw(void) {
	if (AppDebug == TRUE)
	{
		//�K���ɕ`��
		DrawBox(50, 50, W_Width / 2, W_Height / 2, GetColor(176, 214, 223), TRUE);

		//�V�[�����\��
		DrawFormatString(
			W_Width - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", AppSceneName[NowAppScene], "�`�撆");
	}

	//�}�E�X�@�\�e�X�g
	DrawCircle(GetOldPointMouse().x, GetOldPointMouse().y,  //�ȑO�̃}�E�X�̈ʒu
			   20,											//�~�̑傫��
			   GetColor(0, 255, 0),							//�~�̐F�@�@�@�@�@
			   TRUE);										//�~��h��Ԃ��@�@�@�@�@

	DrawCircle(GetPointMouse().x, GetPointMouse().y,		//���݂̃}�E�X�̈ʒu
			   abs(GetWheelMouse()) * 100 + 10,	//�}�E�X�̃z�C�[���ʁi�{�Ɓ[������̂Ő�Βl�j���g�p���Čv�Z
			   GetColor(255, 0, 0),							//�~�̐F
			   TRUE);										//�~��h��Ԃ�

	return;
}

// �v���C //////////////////////////////////////////////
//�v���C������
void PlayInit(void)
{
	if (AppDebug == TRUE)
	{
		//�V�[�����\��
		DrawFormatString(
			W_Width - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", AppSceneName[ChangeAppScene], "������");

		//�K�؂ȃV�[���̏��������ł��Ă��邩�e�X�g
		ScreenFlip(); //�����Ŋ����ė���ʂ�`��
		WaitTimer(1000); //���̌�A�K���ɑ҂�
	}
	//�V�[����؂�ւ����t���[������������
	AppSceneFrameCount[ChangeAppScene] = 0;

	return;
}
//�v���C�Ǘ�
void PlayCtrl(void)
{
	PlayProc(); //���������Ă���
	PlayDraw(); //�`�悷��
	return;
}
//�v���C����
void PlayProc(void)
{
	//�V�[���؂�ւ���̃t���[�������J�E���g�A�b�v
	AppSceneFrameCount[NowAppScene]++;

	//�V�[���؂�ւ�
	//if (KeyDown(KEY_INPUT_SPACE) == TRUE //�X�y�[�X�������ꂽ��
	if (MouseDown(MOUSE_INPUT_LEFT) == TRUE //�}�E�X�̍��{�^���������ꂽ�Ƃ�
		&& AppSceneFrameCount[NowAppScene] >= AppSceneChangeFrame) //���A�؂�ւ��\�ȃt���[�����𒴂�����
	{
		//�V�[���؂�ւ�
		ChangeAppScene = ResultScene;
		//�����ɐ؂�ւ���
		return;
	}
	return;
}
//�v���C�`��
void PlayDraw(void)
{
	if (AppDebug == TRUE)
	{
		//�K���ɕ`��
		DrawBox(0, 0, W_Width, W_Height, GetColor(176, 114, 23), TRUE);

		//�V�[�����\��
		DrawFormatString(
			W_Width - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", AppSceneName[NowAppScene], "�`�撆");
	}
	return;
}

// ���U���g //////////////////////////////////////////////
//���U���g������
void ResultInit(void)
{
	if (AppDebug == TRUE)
	{
		//�V�[�����\��
		DrawFormatString(
			W_Width - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", AppSceneName[ChangeAppScene], "������");

		//�K�؂ȃV�[���̏��������ł��Ă��邩�e�X�g
		ScreenFlip(); //�����Ŋ����ė���ʂ�`��
		WaitTimer(1000); //���̌�A�K���ɑ҂�
	}

	//�V�[����؂�ւ����t���[������������
	AppSceneFrameCount[ChangeAppScene] = 0;

	return;
}
//���U���g�Ǘ�
void ResultCtrl(void)
{
	ResultProc(); //���������Ă���
	ResultDraw(); //�`�悷��
	return;
}
//���U���g����
void ResultProc(void)
{
	//�V�[���؂�ւ���̃t���[�������J�E���g�A�b�v
	AppSceneFrameCount[NowAppScene]++;

	//�V�[���؂�ւ�
	if (MouseDown(MOUSE_INPUT_LEFT) == TRUE //�}�E�X�̍��{�^���������ꂽ�Ƃ�
		//if (KeyDown(KEY_INPUT_SPACE) == TRUE //�X�y�[�X�������ꂽ��
		&& AppSceneFrameCount[NowAppScene] >= AppSceneChangeFrame) //���A�؂�ւ��\�ȃt���[�����𒴂�����
	{
		//�V�[���؂�ւ�
		ChangeAppScene = TitleScene;
		//�����ɐ؂�ւ���
		return;
	}
	return;
}
//���U���g�`��
void ResultDraw(void)
{
	if (AppDebug == TRUE)
	{
		//�K���ɕ`��
		DrawBox(100, 50, W_Width, W_Height, GetColor(216, 14, 223), TRUE);

		//�V�[�����\��
		DrawFormatString(
			W_Width - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", AppSceneName[NowAppScene], "�`�撆");
	}
	return;
}

// End
