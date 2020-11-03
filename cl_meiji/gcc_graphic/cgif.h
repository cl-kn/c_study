/*
  Copyright (c) 2005-2006, Akihiro Yamaguchi
  All rights reserved.
  
  �\�[�X�R�[�h�`�����o�C�i���`�����A�ύX���邩���Ȃ������킸�A
  �ȉ��̏����𖞂����ꍇ�Ɍ���A�ĔЕz����юg�p��������܂��B
  
  1. �\�[�X�R�[�h���ĔЕz����ꍇ�A��L�̒��쌠�\���A�{�����ꗗ�A
  ����щ��L�Ɛӏ������܂߂邱�ƁB 
  2. �o�C�i���`���ōĔЕz����ꍇ�A�Еz���ɕt���̃h�L�������g���̎����ɁA
  ��L�̒��쌠�\���A�{�����ꗗ�A����щ��L�Ɛӏ������܂߂邱�ƁB 
  
  �{�\�t�g�E�F�A�́A���쌠�҂���уR���g���r���[�^�[�ɂ���āu����̂܂܁v�񋟂���Ă���A
  �����َ����킸�A���ƓI�Ȏg�p�\���A����ѓ���̖ړI�ɑ΂���K�����Ɋւ���Öق̕ۏ؂�
  �܂߁A�܂�����Ɍ��肳��Ȃ��A�����Ȃ�ۏ؂�����܂���B
  ���쌠�҂��R���g���r���[�^�[���A���R�̂�������킸�A ���Q�����̌�����������킸�A
  ���ӔC�̍������_��ł��邩���i�ӔC�ł��邩�i�ߎ����̑��́j�s�@�s�ׂł��邩���킸�A
  ���ɂ��̂悤�ȑ��Q����������\����m�炳��Ă����Ƃ��Ă��A
  �{�\�t�g�E�F�A�̎g�p�ɂ���Ĕ��������i��֕i�܂��͑�p�T�[�r�X�̒��B�A�g�p�̑r���A
  �f�[�^�̑r���A���v�̑r���A�Ɩ��̒��f���܂߁A�܂�����Ɍ��肳��Ȃ��j���ڑ��Q�A�Ԑڑ��Q�A
  �����I�ȑ��Q�A���ʑ��Q�A�����I���Q�A�܂��͌��ʑ��Q�ɂ��āA
  ��ؐӔC�𕉂�Ȃ����̂Ƃ��܂��B
*/

/* ��{16�F�p���b�g */
#define cgifBlack 0x000000
#define cgifGray 0x808080
#define cgifSilver 0xC0C0C0
#define cgifWhite 0xFFFFFF
#define cgifRed 0xFF0000
#define cgifYellow 0xFFFF00
#define cgifLime 0x00FF00
#define cgifAqua 0x00FFFF
#define cgifBlue 0x0000FF
#define cgifFuchsia 0xFF00FF
#define cgifMaroon 0x800000
#define cgifOlive 0x808000
#define cgifGreen 0x008000
#define cgifTeal 0x008080
#define cgifNavy 0x000080
#define cgifPurple 0x800080

/* �C���f�b�N�X�� */
#define cgifBLACK 0x0
#define cgifGRAY 0x7
#define cgifSILVER 0x8
#define cgifWHITE 0xf
#define cgifRED 0x9
#define cgifYELLOW 0xb
#define cgifLIME 0xa
#define cgifAQUA 0xe
#define cgifBLUE 0xc
#define cgifFUCHSIA 0xd
#define cgifMAROON 0x1
#define cgifOLIVE 0x3
#define cgifGREEN 0x2
#define cgifTEAL 0x6
#define cgifNAVY 0x4
#define cgifPURPLE 0x5
#define cgifTRANSPARENT 0x10 /* ���ߏ�������F�̃C���f�b�N�X */

typedef unsigned char cgifByte1;
typedef unsigned int cgifByte2;
typedef unsigned long cgifByte4;

/*
** GIF Header
*/
/* �w�i�F�̃O���[�o���J���[�e�[�u���ɂ�����C���f�b�N�X */
cgifByte1 cgifBackgroundColorIndex;

/*
** Block:Application Extention
*/
cgifByte2 cgifNumberOfIterations; /* �J��Ԃ���(0:����) */

/*
** Block:Image Block
*/
typedef struct {
  cgifByte2 left; /* ImageLeftPosition */
  cgifByte2 top; /* ImageTopPosition */
  cgifByte2 width; /* ImageWidth */
  cgifByte2 height; /* ImageHeight */
  cgifByte4 size; /* width * height */
} cgifImageBlock;

/*
** Block:Graphic Control Extension
*/
typedef struct {
  /* |000|   | | |
       |   |  | |
       |   |  | TransParentColorFlag(1bit):���ߏ������邩�ǂ���
       |   |  UserInputFlag(1bit):���[�U�[���͂�K�v�����邩�ǂ���
       |   DisposalMethod(3bit):�摜�\����̏���
       |   0:�w��Ȃ� 1:�摜���c�� 2:�w�i�F���� 3:�ȑO�̂��̂���
       �\��ς�(3bit)�Œ�(000) */
  cgifByte1 PackedFields; /* �\�������p�����[�^ */
  cgifByte2 time; /* DelayTime:��ɑ����C���[�W��\������܂ł̑҂����� */
  cgifByte1 TransparentIndex; /* TransparentColorIndex */
} cgifGraphicBlock;


int cgif_frame; /* �A�j���[�V�����̑��y�[�W�� */
/* cgif_image[frame][ ImageBlockp[frame].size ]��malloc�ō쐬 */
cgifByte1** cgif_image;

/* �������F������gif�摜�̑傫�� ���ܐ� �J��Ԃ���*/
void cgif_init(cgifByte2 width,cgifByte2 height, int frame,int iteration);

/* gif�摜�ɓ_��ł�
   �Ԃ�l : �_��ł����Ȃ�1, �͈͊O�Ȃ�0 */
int cgif_putpixel(cgifByte2 x, cgifByte2 y,
                  cgifByte1 color_index, int frame);

/* cgif_output:�W���o�͂�gif�t�@�C���Ƃ��ďo�� */
void cgif_output(char *filename);

/* frame�Ԗڂ̃C���[�W��mat(2����)�ɃR�s�[(�������[�m�ۂ̃`�F�b�N����) */
void cgif_copy_mat(cgifByte1** mat, int frame);

/*frame�Ԗڂ̃C���[�W��array(1����)�ɃR�s�[(�������[�m�ۂ̃`�F�b�N����)*/
void cgif_copy_array(cgifByte1* array, int frame);

/* frame��(0���琔����)��cgifImageBlock���Z�b�g����. */
void cgif_setImageBlock( cgifByte2 left, cgifByte2 top,
                         cgifByte2 width, cgifByte2 height,
                         int frame);

/* frame��(0���琔����)��cgifGraphicBlock��
   PackedFields�̊e�t���O���Z�b�g
   time�͉�ʕ\����A���̏����𑱍s����܂ł̑ҋ@���� (1/100�b)
   �����F�̃J���[�C���f�b�N�X��TRANSPARENT�ɌŒ� */
void cgif_setGraphicBlock(int TransparentFlag,/* ���ߏ������邩�ǂ��� */
                          int UserInputFlag,/*���[�U�[�̓��͂�K�v�Ƃ��邩*/
                          int DisposalMethod,/*�摜��\�����I������̏���*/
                          cgifByte2 time, int frame);

/* RGB�\�����O���[�o���J���[�e�[�u���̃C���f�b�N�X�ɕς���
   0x1000000 ~ (0x1000000 + cgif_frame-1)�������F */
cgifByte2 cgif_color_to_index(cgifByte4 color);

/* �E�C���h�E��(x1,y1):����̍��W, (x2,y2):�E��̍��W
   ����ł��ύX�� */
void cgif_create_window(double x1, double y1, double x2, double y2);

/* cgif_window�ɓ_��ł� */
int cgif_pset(double x, double y, cgifByte4 color, int frame);

/* �N���b�s���O������̐�����. Bresenham��(��������)�A���S���Y�� */
int cgif__line( double x0, double y0, double x1, double y1,
                cgifByte4 color, int frame);

/* �Q�i�S����(x,y)��cgif_window�ɑ΂��Ăǂ̈ʒu�ɂ��邩��\��
   ��1���� : ��ʂ̍��[���O��Ă��邩�ǂ���
   ��2���� : ��ʂ̉E�[���O��Ă��邩�ǂ���
   ��3���� : ��ʂ̏�[���O��Ă��邩�ǂ���
   ��4���� : ��ʂ̉��[���O��Ă��邩�ǂ��� */
unsigned char cgif_looker(double x, double y);

/* ��������. ���g�̓N���b�s���O����cgif__line���Ă� */
int cgif_line( double x1, double y1, double x2, double y2,
               cgifByte4 color, int frame);

/* ���S(x_0,y_0)�Ax�������̔��aradius_w�Ay�������̔��aradius_h
   �̑ȉ~���p�xradian_s����radian_e�܂ŐFcolor�ŕ`�� */
int cgif_circle(double x_0, double y_0, double radius_w, double radius_h,
                double radian_s, double radian_e,
                cgifByte4 color, int frame);

/* �F�̃C���f�b�N�X�̎��o�� ( -1 : �̈�O )*/
long cgif_point( double x, double y, int frame);
