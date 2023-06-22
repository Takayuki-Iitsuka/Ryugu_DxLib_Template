// fps.cpp
#include "fps.h"

//�O���[�o���ϐ�
FPS fps;

//������
void FPSInit(void)
{
	//Windows���N�����Ă��猻�݂܂ł̎��Ԃ𓾂�i�}�C�N���b�j
	fps.FirstTakeTime = GetNowHiPerformanceCount();
	//���̒l��������
	fps.NowTakeTime = fps.FirstTakeTime;
	fps.OldTakeTime = fps.FirstTakeTime;
	fps.DeltaTime = 0.000001f;
	fps.FrameCount = 1;
	fps.Average = 0.0f;

	return;
}

//�v��
void FPSCheck(void)
{
	//���݂̎������擾
	fps.NowTakeTime = GetNowHiPerformanceCount();
	//�f���^�^�C�����v�Z
	fps.DeltaTime = (fps.NowTakeTime - fps.OldTakeTime) / MicroSecond;
	//���݂̎�����ۑ�
	fps.OldTakeTime = fps.NowTakeTime;
	//���݂�MAX�t���[���ڂȂ�
	if (fps.FrameCount == W_FPS) {
		//�P�t���[���ځ`MAX�t���[���ڂ܂ł̍��v���Ԃ��v�Z
		float TotalFrameTime = fps.NowTakeTime - fps.FirstTakeTime;
		//���v���Ԃ𗝑z��FPS�l�Ŋ����ĕ��ϒl���v�Z
		float CalcAveasge = TotalFrameTime / W_FPS;
		//�P�b������̃t���[�����ɕϊ�
		fps.Average = MicroSecond / CalcAveasge;
		//�P�t���[���ڂ̎������擾
		fps.FirstTakeTime = GetNowHiPerformanceCount();
		//�t���[�������P�ɖ߂�
		fps.FrameCount = 1;
	}
	else {
		fps.FrameCount++; //�t���[�������J�E���g�A�b�v
	}

	return;
}

//�`��
void FPSDraw(void)
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "FPS:%3.1f", fps.Average);

	return;
}

//�ҋ@
void FPSWait(void)
{
	//���������Ƃ��ɑҋ@����~���b
	//int wait = 0;
	float wait = 0;
	//�҂����Ԃ��v��
	wait =
		MicroSecond / W_FPS * fps.FrameCount		//���z�̎���
		- (fps.NowTakeTime - fps.FirstTakeTime);	//���ۂ̎���

	//�}�C�N���b���~���b�ɕϊ�
	wait /= MillSecond;

	//�҂����Ԃ�����Ȃ��
	if (wait > 0 && wait <= WaitTimeMill)
	{
		//�u���b�Z�[�W�v���������Ȃ���҂�
		WaitTimer(wait);
	}

	return;
}

// End
