//
// game.cpp
//
// �����E�O�E�E�A�[�J�C�u�X
// https://www.youtube.com/@user-wn3lb2po1y
// 
// �͂��߂Ă�DXײ����
// https://youtube.com/playlist?list=PL4B4qq0SOLcVX1FSTZl2ugrfF8AYFdTRW
//

#include "game.h"
#include "key.h"
#include "mouse.h"
#include "geometory.h"

//�O���[�o���ϐ�

//�Q�[���V�[��
enum AppScene NowAppScene; // ���݂̃A�v���V�[��
enum AppScene ChangeAppScene; // �؂�ւ��A�v���V�[��

//�A�v����ʊ֌W
RECT AppWindow; //�A�v����ʂ���`
HWND AppHandle; //�A�v���̃E�B���h�E�n���h��

//�V�[���̖��O
char AppSceneName[AppSceneCount][AppSceneNameMax]
{
	"�^�C�g�����",
	"�v���C���",
	"���U���g���"
};

//�V�[���؂�ւ���̃t���[�������Ǘ�
int AppSceneFrameCount[AppSceneCount];

//�e�V�[���̐؂�ւ��{�^��
CIRCLE StartCircle; //�X�^�[�g�~
CIRCLE PlayCircle; //�v���C�~
CIRCLE ResultCircle; //���U���g�~

//�֐�

//�A�v����ʂ̃n���h�����擾
HWND GetAppHandle(void)
{
	return AppHandle;
}

//�Q�[����ʂ̋�`���擾
RECT GetAppWindow(void)
{
	return AppWindow;
}

//�\�t�g��ʂ̏㉺���E�̒������W���擾
POINT GetAppWindowCenter(void)
{
	POINT pt;
	pt.x = W_Width / 2;
	pt.y = W_Height / 2;

	return pt;
}

//�\�t�g��ʂ̏�����
void AppInit(void)
{
	//�\�t�g��ʂ̃n���h���i�Ǘ��ԍ��j���擾
	AppHandle = GetMainWindowHandle();

	//�\�t�g��ʂ̋�`���擾
	AppWindow = GetRect(0, 0, W_Width, W_Height);

	//�ŏ��̃V�[���́A�^�C�g������
	NowAppScene = TitleScene;
	//���̃V�[�����^�C�g������
	ChangeAppScene = TitleScene;

	//�e�V�[���̉~��������
	StartCircle = GetCircle(GetAppWindowCenter(), 300.0f); //���a300�̉~����ʒ����ɒu��
	PlayCircle = GetCircle(GetAppWindowCenter(), 300.0f); //���a300�̉~����ʒ����ɒu��
	ResultCircle = GetCircle(GetAppWindowCenter(), 300.0f); //���a300�̉~����ʒ����ɒu��

	return;
}

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
			"%s%s", AppSceneName[ChangeAppScene], "��������......");

		//�K�؂ȃV�[���̏��������ł��Ă��邩�e�X�g
		//ScreenFlip(); //�����Ŋ����ė���ʂ�`��
		//WaitTimer(500); //���̌�A�K���ɑ҂�
		//
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
	//if (MouseDown(MOUSE_INPUT_LEFT) == TRUE //�}�E�X�̍��{�^���������ꂽ�Ƃ�
	//if (CollWindowToMousePoint() == TRUE //��ʓ��Ƀ}�E�X�̍��W������Ƃ�
	//if (CollRectToMouseClick(GetRect(0, 0, W_Width, W_Height), MOUSE_INPUT_LEFT) == TRUE //��ʓ��Ƀ}�E�X�̍��W������Ƃ�

	//�~�̂ǂ������}�E�X���{�^���ŃN���b�N�����Ƃ�
	//���A�؂�ւ��\�ȃt���[�����𒴂�����
	if (CollCircleToMouseDown(StartCircle, MOUSE_INPUT_LEFT) == TRUE
		&& AppSceneFrameCount[NowAppScene] >= AppSceneChangeFrame)
	{
		//�V�[���؂�ւ�
		ChangeAppScene = PlayScene;
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
		DrawBox(20, 20, W_Width / 1.3, W_Height / 1.3, GetColor(176, 114, 223), TRUE);

		//�V�[�����\��
		DrawFormatString(
			W_Width - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", AppSceneName[NowAppScene], "�`�撆......");
	}

	//�~�̒��Ƀ}�E�X���W����������~�̐F��ς���
	if (CollCircleToMouse(StartCircle) == TRUE)
	{
		//�~�̕`��
		DrawEn(StartCircle, Color_tomato, TRUE);
	}
	else {
		//�~�̕`��
		DrawEn(StartCircle, Color_white, TRUE);
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
	//�}�E�X�@�\�e�X�g End
	

	//�Ƃ肠�����̃V�[������`��
	//�ꎞ�I�Ƀt�H���g�̃T�C�Y��ύX
	//�������d���̂ŏ����I�ɂ̓t�H���g�n���h���𐶐�����
	SetFontSize(100);
	DrawFormatString(GetAppWindowCenter().x - 170,
					 GetAppWindowCenter().y,
					 Color_black, "%s", "START!!!!!");
	SetFontSize(16); //���Ƃ̂��炢�ɖ߂�

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
			"%s%s", AppSceneName[ChangeAppScene], "��������......");

		//�K�؂ȃV�[���̏��������ł��Ă��邩�e�X�g
		//ScreenFlip(); //�����Ŋ����ė���ʂ�`��
		//WaitTimer(500); //���̌�A�K���ɑ҂�
		//
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
	//if (MouseDown(MOUSE_INPUT_LEFT) == TRUE //�}�E�X�̍��{�^���������ꂽ�Ƃ�

	//�~�̂ǂ������}�E�X���{�^���ŉ������Ƃ�
	//���A�؂�ւ��\�ȃt���[�����𒴂����Ƃ�
	if (CollCircleToMouseDown(PlayCircle, MOUSE_INPUT_LEFT) == TRUE
		&& AppSceneFrameCount[NowAppScene] >= AppSceneChangeFrame)
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
		DrawBox(100, 100, W_Width / 1.8, W_Height / 1.8, GetColor(176, 114, 23), TRUE);

		//�V�[�����\��
		DrawFormatString(
			W_Width - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", AppSceneName[NowAppScene], "�`�撆......");
	}

	//�~�̒��Ƀ}�E�X���W����������~�̐F��ς���
	if (CollCircleToMouse(PlayCircle) == TRUE)
	{
		//�~�̕`��
		DrawEn(PlayCircle, Color_lawngreen, TRUE);
	}
	else {
		//�~�̕`��
		DrawEn(PlayCircle, Color_white, TRUE);
	}

	//�Ƃ肠�����̃V�[������`��
	//�ꎞ�I�Ƀt�H���g�̃T�C�Y��ύX
	//�������d���̂ŏ����I�ɂ̓t�H���g�n���h���𐶐�����
	SetFontSize(100);
	DrawFormatString(GetAppWindowCenter().x - 170,
					 GetAppWindowCenter().y,
					 Color_black, "%s", "PLAY!!!!!");
	SetFontSize(16); //���Ƃ̂��炢�ɖ߂�

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
			"%s%s", AppSceneName[ChangeAppScene], "��������......");

		//�K�؂ȃV�[���̏��������ł��Ă��邩�e�X�g
		//ScreenFlip(); //�����Ŋ����ė���ʂ�`��
		//WaitTimer(500); //���̌�A�K���ɑ҂�
		//
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
	//if (MouseDown(MOUSE_INPUT_LEFT) == TRUE //�}�E�X�̍��{�^���������ꂽ�Ƃ�
	//if (KeyDown(KEY_INPUT_SPACE) == TRUE //�X�y�[�X�������ꂽ��

	//�~�̂ǂ������}�E�X���{�^���ŉ������Ƃ�
	//���A�؂�ւ��\�ȃt���[�����𒴂����Ƃ�
	if (CollCircleToMouseDown(ResultCircle, MOUSE_INPUT_LEFT) == TRUE
		&& AppSceneFrameCount[NowAppScene] >= AppSceneChangeFrame)
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
		//DrawBox(150, 160, W_Width / 1.5, W_Height / 1.5, GetColor(216, 14, 223), TRUE);

		//�V�[�����\��
		DrawFormatString(
			W_Width - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", AppSceneName[NowAppScene], "�`�撆......");
	}

	//�~�̒��Ƀ}�E�X���W����������~�̐F��ς���
	if (CollCircleToMouse(ResultCircle) == TRUE)
	{
		//�~�̕`��
		DrawEn(PlayCircle, Color_yellow, TRUE);
	}
	else {
		//�~�̕`��
		DrawEn(PlayCircle, Color_white, TRUE);
	}

	//�Ƃ肠�����̃V�[������`��
	//�ꎞ�I�Ƀt�H���g�̃T�C�Y��ύX
	//�������d���̂ŏ����I�ɂ̓t�H���g�n���h���𐶐�����
	SetFontSize(100);
	DrawFormatString(GetAppWindowCenter().x - 170,
					 GetAppWindowCenter().y,
					 Color_black, "%s", "RESULT!!!!!");
	SetFontSize(16); //���Ƃ̂��炢�ɖ߂�

	return;
}

// End
