// font.h

#pragma once

#include "DxLib.h"

//�t�H���g�̃p�X�Ɩ��O

//�O���t�H���g
//#define FontPathJiyu ".\\FONT\\Jiyucho.otf"
//#define FontNameJiyu "���䂤���傤�t�H���g"

#define FontPathMukashi ".\\Font\\gomarice_mukasi_mukasi.ttf"
#define FontNameMukashi "�́X�ӂ����"

#define FontPathGenjyuuL_N ".\\Font\\GenJyuuGothicL-Normal.ttf"
#define FontNameGenjyuuL_N "���_�S�V�b�NL Normal"

#define FontPathGenjyuu_N ".\\Font\\GenJyuuGothic-Normal.ttf"
#define FontNameGenjyuu_N "���_�S�V�b�N �m����������"
//#define FontNameGenjyuu_N "���_�S�V�b�N Normal"


//�����t�H���g
#define FontNameMSMincho "�l�r ����"
#define FontNameGenJyuu_M "���_�S�V�b�N Medium"
#define FontNameGenjyuuX_N "���_�S�V�b�NX Normal"

//�f�t�H���g�̃t�H���g
//#define FontDefName FontNameMSMincho //�t�H���g��
#define FontDefName FontNameGenjyuuX_N //�t�H���g��
#define FontDefSize 20 //�����T�C�Y
#define FontDefThinck 1 //�����̑傫��
//#define FontDefType DX_FONTTYPE_ANTIALIASING_8X8 //�A���`�G�C���A�X
#define FontDefType DX_FONTTYPE_ANTIALIASING_16X16 //�A���`�G�C���A�X
//#define FontDefType DX_FONTTYPE_ANTIALIASING_EDGE_16X16 //�A���`�G�C���A�X

//������̒���
#define FontNameStrMax 256
#define FontErrStrMax 512

//�G���[
#define FontInstallErrCap "���C���X�g�[���ł��܂���"
#define FontInstallErrTitle "�t�H���g�C���X�g�[���G���["

#define FontCreateErrCap "���쐬�ł��܂���"
#define FontCreateErrTitle "�t�H���g�쐬�G���["

//��������MAX������
#define FontAlignStrMax 512

//�񋓌^
enum Font_Align {
	Align_Left, //������
	Align_Center, //��������
	Align_Right, //�E����
	Align_AllCenter //�㉺�����E����������
};

//�\����
typedef struct _AddFont {
	char FontPath[FontNameStrMax];
	char FontName[FontNameStrMax];
	BOOL CanInstall = FALSE; //�C���X�g�[���ł������H

}AddFont; //�ꎞ�I�ɃC���X�g�[������t�H���g���

typedef struct _Font {
	int Handle; //�t�H���g�n���h���i�t�H���g�f�[�^�̊Ǘ��ԍ��j

	char Name[FontNameStrMax]; //�t�H���g��
	int Size; //�t�H���g�̃T�C�Y
	int Thinck; //�t�H���g�̑���
	int Type; //�A���`�G�C���A�X

}Font; //�t�H���g�f�[�^�쐬�p

//�O���O���[�o���ϐ�
//extern AddFont addMukashi; //�́X�ӂ���Ƃ�ǉ�
//extern AddFont addGenjyuu_N; //���_�S�V�b�N Normal��ǉ�
//extern AddFont addGenjyuuL_N; //���_�S�V�b�NL Normal��ǉ�
//extern AddFont addGenjyuuX_N; //���_�S�V�b�NX Normal��ǉ�
//extern AddFont addJiyu; //���䂤���傤�t�H���g��ǉ�

extern Font fontDefault; //�f�t�H���g�̃t�H���g
//extern Font fontDefault100pt; //�f�t�H���g100pt�̃t�H���g

//extern Font fontMukashi100pt; //�́X�ӂ���� 100pt
//extern Font fontGenjyuu_N; //���_�S�V�b�N  Normal
//extern Font fontGenjyuu_N100pt; //���_�S�V�b�N  Normal 100pt
//extern Font fontGenjyuuL_N; //���_�S�V�b�NL  Normal
//extern Font fontGenjyuuL_N100pt; //���_�S�V�b�NL Normal 100pt
//extern Font fontGenjyuuX_N; //���_�S�V�b�NX  Normal

//����
extern Font fontGenjyuu_N; //���_�S�V�b�N Medium 100pt
//extern Font fontJiyu100pt; //���䂤���傤�t�H���g100pt

//�O���v���g�^�C�v�錾
extern BOOL Font_Init(void); //�C���X�g�[��������
extern AddFont FontInstall(const char* path, const char* name); //--�C���X�g�[��
extern void FontInstallErrMessage(const char* path); //--�C���X�g�[���G���[���b�Z�[�W
extern Font FontCreate(const char* name, int size, int thinck, int type); //----�t�H���g�n���h������
extern void FontCreateErrMessage(Font font); //----�t�H���g�n���h�������G���[���b�Z�[�W
extern void FontDelete(Font font); //----�t�H���g�n���h���폜
extern void FontUnInstall(AddFont add); //--�A���C���X�g�[��
extern void Font_End(void); //�폜���A���C���X�g�[��

//�t�H���g�𑵂��ĕ`��
extern void DrawFormatStringToHandleAlign(
	int x, int y,
	Font_Align align, unsigned int Color, int FontHandle,
	const char* FormatString, ...);

// End
