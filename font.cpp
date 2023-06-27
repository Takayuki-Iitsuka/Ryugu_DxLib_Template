//font.cpp

#include "font.h"

//�O���[�o���ϐ�
AddFont addMukashi; //�́X�ӂ���Ƃ�ǉ�
AddFont addGenjyuu_N; //���_�S�V�b�NL Normal��ǉ�
AddFont addGenjyuu_N100pt; //���_�S�V�b�NL Normal��ǉ�
AddFont addGenjyuuL_N; //���_�S�V�b�NL Normal��ǉ�
AddFont addGenjyuuX_N; //���_�S�V�b�NL Normal��ǉ�
//AddFont addJiyu; //���䂤���傤�t�H���g��ǉ�

Font fontDefault; //�f�t�H���g�̃t�H���g
Font fontMukashi100pt; //�́X�ӂ���� 100pt
Font fontGenjyuu_N; //���_�S�V�b�NL Normal 100pt
Font fontGenjyuu_N100pt; //���_�S�V�b�N Medium 100pt
Font fontGenjyuuL_N; //���_�S�V�b�NL Normal
Font fontGenjyuuX_N; //���_�S�V�b�NL Normal 100pt
//Font fontJiyu100pt; //���䂤���傤�t�H���g100pt


//�O���v���g�^�C�v�錾

//�C���X�g�[��������
BOOL Font_Init(void)
{
	//�O���̃t�H���g���ꎞ�I�ɃC���X�g�[��
/*
	addJiyu = FontInstall(FontPathJiyu, FontNameJiyu); if (addJiyu.CanInstall == FALSE)
	{
		return FALSE;
	}
*/

//addMukashi = FontInstall(FontPathGenjyuu_N, FontNameGenjyuu_N); if (addGenjyuu_N.CanInstall == FALSE)
//{
//	return FALSE;
//}

	//���_�S�V�b�N Normal��ǉ�
	/*
	addGenjyuu_N = FontInstall(FontPathGenjyuu_N, FontNameGenjyuu_N);
	if (addGenjyuu_N.CanInstall == FALSE)
	{
		return FALSE;
	}
*/

	//�t�H���g�f�[�^�𐶐����ăn���h���ŊǗ�

	fontDefault = FontCreate(FontDefName, FontDefSize, FontDefThinck, FontDefType);
	if (fontDefault.Handle == -1) { return FALSE; }

	//fontDefault100pt = FontCreate(FontDefName, 100, 1, FontDefType);
	//if (fontDefault100pt.Handle == -1) { return FALSE; }

	/*
	fontGenjyuu_N100pt = FontCreate(addGenjyuu_N.FontName, 100, 1, FontDefType);
	if (fontGenjyuuL_N.Handle == -1) { return FALSE; }
	*/

	/*
		fontJiyu100pt = FontCreate(addJiyu.FontName, 100, 1, FontDefType);
		if (fontJiyu100pt.Handle == -1) { return FALSE; }
	*/


	//	fontGenjyuuL_N100pt = FontCreate(addGenjyuuL_N.FontName, 100, 1, FontDefType);
	//	if (fontGenjyuuL_N100pt.Handle == -1) { return FALSE; }

	return TRUE;
}

//�C���X�g�[��
AddFont FontInstall(const char* path, const char* name)
{
	AddFont add;

	//�t�H���g����ݒ�
	strcpy_s(add.FontPath, sizeof(add.FontPath), path); //�t�H���g�̃p�X���R�s�[
	strcpy_s(add.FontName, sizeof(add.FontName), path); //�t�H���g�̖��O���R�s�[

	//��WinAPI�֐�
	//���̃\�t�g���̂ݎg����悤�A�ꎞ�I�ɃC���X�g�[��
	if (AddFontResourceEx(add.FontPath, FR_PRIVATE, NULL) == 0)
	{
		//�t�H���g�C���X�g�[�����s
		FontInstallErrMessage(add.FontPath); //�G���[���b�Z�[�W�\��
		add.CanInstall = FALSE;
	}
	else {
		//�t�H���g�C���X�g�[������
		add.CanInstall = TRUE;
	}

	return add;
}

//�C���X�g�[���G���[���b�Z�[�W
void FontInstallErrMessage(const char* path)
{
	//�G���[�p������
	char ErrStr[FontErrStrMax];

	//�G���[�p������̓��e����ɂ���
	for (int i = 0; i < FontErrStrMax; i++) { ErrStr[i] = '\0'; } //�k�������i���O�j�Ŗ��߂�

	//�G���[���e��A�����Đ���
	sprintf_s(ErrStr, sizeof(ErrStr), "%s%s", path, FontInstallErrCap);

	//��WinAPI�֐�
	//�p�X���Ԉ���Ă���ȂǂŃC���X�g�[���ł��Ȃ��ꍇ�̓G���[
	MessageBox(
		GetMainWindowHandle(), //�E�B���h�E�n���h��
		ErrStr, //�G���[���e
		FontInstallErrTitle, //�G���[�^�C�g��
		MB_OK); //�n�j�{�^���̂�

	return;
}

//�t�H���g�n���h������
Font FontCreate(const char* name, int size, int thinck, int type)
{
	Font font;

	strcpy_s(font.Name, sizeof(font.Name), name); //�t�H���g�̖��O�̃R�s�[
	font.Size = size;
	font.Thinck = thinck;
	font.Type = type;

	//�t�H���g�̖��O���Ԉ���Ă���ȂǂŃt�H���g�����Ȃ��Ƃ��̓G���[
	if (CheckFontName(font.Name) == FALSE)
	{
		FontCreateErrMessage(font); //�G���[���b�Z�[�W�\��
		font.Handle = -1; //�G���[�̃n���h���ԍ������Ă���
	}
	else {
		//�t�H���g�f�[�^����
		font.Handle = CreateFontToHandle(font.Name, font.Size, font.Thinck, font.Type);
	}

	return font;
}

//�t�H���g�n���h�������G���[���b�Z�[�W
void FontCreateErrMessage(Font font)
{
	//�G���[�p������
	char ErrStr[FontErrStrMax];

	//�G���[�p������̓��e����ɂ���
	for (int i = 0; i < FontErrStrMax; i++) { ErrStr[i] = '\0'; } //�k�������i���O�j�Ŗ��߂�

	//�G���[���e��A�����Đ���
	sprintf_s(ErrStr, sizeof(ErrStr), "%s%s", font.Name, FontCreateErrCap);

	//��WinAPI�֐�
	//�p�X���Ԉ���Ă���ȂǂŃC���X�g�[���ł��Ȃ��ꍇ�̓G���[
	MessageBox(
		GetMainWindowHandle(), //�E�B���h�E�n���h��
		ErrStr, //�G���[���e
		FontInstallErrTitle, //�G���[�^�C�g��
		MB_OK); //�n�j�{�^���̂�

	return;
}

//�t�H���g�n���h���폜
void FontDelete(Font font)
{
	//�t�H���g�n���h���𐶐������Ȃ�
	if (font.Handle != -1)
	{
		//�t�H���g�f�[�^���폜
		DeleteFontToHandle(font.Handle);
	}

	return;
}

//�A���C���X�g�[��
void FontUnInstall(AddFont add)
{
	//�t�H���g���C���X�g�[�������Ȃ�
	if (add.CanInstall != FALSE)
	{
		//��WinAPI�֐�
		//�A���C���X�g�[��
		RemoveFontResourceEx(add.FontPath, FR_PRIVATE, NULL);
	}

	return;
}

//�폜���A���C���X�g�[��
void Font_End(void)
{
	//�t�H���g�f�[�^�̍폜
	FontDelete(fontDefault);
	//FontDelete(fontDefault100pt);
	//FontDelete(fontJiyu100pt);
	//FontDelete(fontMukashi100pt);
	//FontDelete(fontGenjyuu_N);
	//FontDelete(fontGenjyuuL_N);
	//FontDelete(fontGenjyuuL_N100pt);
	//FontDelete(fontGenjyuu_M100pt);

	//�t�H���g�A���C���X�g�[��
	//FontUnInstall(addJiyu);
	//FontUnInstall(addMukashi);
	//FontUnInstall(addGenjyuu_N);
	//FontUnInstall(addGenjyuuL_N);
	//FontUnInstall(addGenjyuuX_N);
	//FontUnInstall(addGenjyuu_N);

	return;
}

//�t�H���g�𑵂��ĕ`��
//�����ӁF�������� FontAlignMax �𒴂���Ƃ���ȏ�͏o�͂��Ȃ�
void DrawFormatStringToHandleAlign(
	int x, int y, Font_Align align, unsigned int Color,
	int FontHandle, const char* FormatString, ...)
{
	int align_x = x; //�������Ƃ���X�ʒu
	int align_y = y; //�������Ƃ���Y�ʒu
	int StrWidth = 0; //������̕�
	int StrHeight = 0; //������̍���

	char DrawStr[FontAlignStrMax];

	//�ψ���(...)�����炤����������
	va_list args;

	//�ψ�����FormatSyring�̌�납��n�܂�
	va_start(args, FormatString);

	//������������w��q�ŉψ������琶��
	vsnprintf(DrawStr, sizeof(DrawStr), FormatString, args);

	//������̕����v�Z
	StrWidth = GetDrawStringWidthToHandle(DrawStr, strlen(DrawStr), FontHandle);

	//��������������擾
	StrHeight = GetFontSizeToHandle(FontHandle);

	//�������ƂɈʒu���v�Z����
	switch (align)
	{
		case Align_Left:
			//�������͂��̂܂܂̈ʒu�Ȃ̂ŁA�������Ȃ�
			break;
		case Align_Center:
			//���������͒����l���v�Z

			//X�ʒu�̂݁A�����Ɋ񂹂�
			align_x = x - StrWidth / 2;
			break;
		case Align_Right:
			//�E����

			//X�ʒu�̂݁A�E�Ɋ񂹂�
			align_x = x - StrWidth;

			break;
		case Align_AllCenter:
			//�㉺�����E����������

			//X�ʒu���A�����Ɋ񂹂�
			align_x = x - StrWidth / 2;
			//Y�ʒu���A�����Ɋ񂹂�
			align_y = y - StrHeight / 2;

			break;
		default:
			break;
	}

	//�����̗�̕`��
	DrawFormatStringToHandle(align_x, align_y, Color, FontHandle, "%s", DrawStr);

	//�ψ��������炤�̂��I��
	va_end(args);

	return;
}


// End
