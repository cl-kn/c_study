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
  ���쌠�҂��R���g���r���[�^�[���A���R�̂�������킸�A���Q�����̌�����������킸�A
  ���ӔC�̍������_��ł��邩���i�ӔC�ł��邩�i�ߎ����̑��́j�s�@�s�ׂł��邩���킸�A
  ���ɂ��̂悤�ȑ��Q����������\����m�炳��Ă����Ƃ��Ă��A
  �{�\�t�g�E�F�A�̎g�p�ɂ���Ĕ��������i��֕i�܂��͑�p�T�[�r�X�̒��B�A�g�p�̑r���A
  �f�[�^�̑r���A���v�̑r���A�Ɩ��̒��f���܂߁A�܂�����Ɍ��肳��Ȃ��j���ڑ��Q�A�Ԑڑ��Q�A
  �����I�ȑ��Q�A���ʑ��Q�A�����I���Q�A�܂��͌��ʑ��Q�ɂ��āA
  ��ؐӔC�𕉂�Ȃ����̂Ƃ��܂��B
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < (-(a)) ? (-(a)) : (a))
#define dswap(a,b) {double tmp; tmp = a; a = b; b = tmp;}
#define DICT_MAX 220 /* lzw�����o�^�ő吔 */

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

static double PI = 3.14159265358979323846;

/*
** GIF Header
*/
/* �_����ʂ̕��ƍ��� */
static cgifByte2 LogicalScreenWidth; /* 2byte */
static cgifByte2 LogicalScreenHeight; /* 2byte */
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
static cgifImageBlock *ImageBlockp;

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
static cgifGraphicBlock *GraphicBlockp;

struct point {
  double x;
  double y;
};

static struct rect {
  struct point pt1;
  struct point pt2;
} cgif_window;

int cgif_frame; /* �A�j���[�V�����̑��y�[�W�� */
/* cgif_image[frame][ ImageBlockp[frame].size ]��malloc�ō쐬 */
cgifByte1** cgif_image;


/* �������F������gif�摜�̑傫�� ���ܐ� �J��Ԃ���*/
void cgif_init(cgifByte2 width,cgifByte2 height, int frame,int iteration);

/* gif�摜�ɓ_��ł�
   �Ԃ�l : �_��ł����Ȃ�1, �͈͊O�Ȃ�0 */
int cgif_putpixel(cgifByte2 x, cgifByte2 y,
                  cgifByte1 color_index, int frame);

/* Image Block��Block Size��Image Data���o�� */
static void lzw_output(int frame, char *filename, FILE *fp);

/* foutarray:array[0]����array[n-1]�܂ł��t�@�C���ɏo�� */
static void foutarray(char *name, cgifByte1 *array, int n, FILE *fp);

/* cgif_output:�W���o�͂�gif�t�@�C���Ƃ��ďo�� */
void cgif_output(char *filename);

/* frame�Ԗڂ̃C���[�W��mat(2����)�ɃR�s�[(�������[�m�ۂ̃`�F�b�N����)
   cgif_image��1�����̔z��ɂȂ��Ă��邪�A
   �����2�����̍s��ɂ��ăR�s�[ */
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
                          int UserInputFlag,/*���[�U�[���͂�K�v�Ƃ��邩*/
                          int DisposalMethod,/* �摜��\��������̏��� */
                          cgifByte2 time, int frame);

/* RGB�\�����O���[�o���J���[�e�[�u���̃C���f�b�N�X�ɕς���
   0x1000000 ~ (0x1000000 + cgif_frame-1)�������F */
cgifByte2 cgif_color_to_index(cgifByte4 color);

/* �l�̌ܓ� */
static long rounding(double n);

/* �E�C���h�E��(x1,y1):����̍��W, (x2,y2):�E��̍��W
   ����ł��ύX�� */
void cgif_create_window(double x1, double y1, double x2, double y2);

/* cgif_window��̍��W��gif��̍��W�ɕϊ� */
static cgifByte2 change_x( double x, int frame);
static cgifByte2 change_y( double y, int frame);

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

/* �G���[���� */
static void error(char *message);


void cgif_init(cgifByte2 width,cgifByte2 height, int frame, int iteration)
{
  cgifByte2 i; cgifByte4 j; 
  
  /* �����̃G���[�`�F�b�N */
  if (frame < 1)
    error("In cgif_init : frame(�y�[�W��)��1�ȏ�");
  LogicalScreenWidth = (width > 0) ? width : 0x32;
  LogicalScreenHeight = (height > 0) ? height : 0x32;
  
  cgifBackgroundColorIndex = cgifWHITE; /* �� */
  
  cgif_frame = frame;
  
  cgifNumberOfIterations = iteration;
  
  ImageBlockp = malloc( sizeof(cgifImageBlock)*cgif_frame );
  GraphicBlockp = malloc( sizeof(cgifGraphicBlock)*cgif_frame );
  
  cgif_image = (cgifByte1 **)malloc( sizeof(cgifByte1 *) * cgif_frame );
  
  for ( i = 0; i < cgif_frame; i++){
    cgif_image[i] = NULL;
    cgif_setImageBlock( 0, 0, LogicalScreenWidth, LogicalScreenHeight, i);
    cgif_setGraphicBlock(1,0,0, 30, i);
  }
  
  for ( i = 0; i < cgif_frame; i++)
    for( j = 0; j < ImageBlockp[i].width * ImageBlockp[i].height; j++)
      cgif_image[i][j] = cgifTRANSPARENT;
  
  /* cgif_window�̏����� */
  cgif_create_window(0,0,LogicalScreenWidth,LogicalScreenHeight);
}

int cgif_putpixel(cgifByte2 x,cgifByte2 y,cgifByte1 color_index,int frame)
{
  /* �����̃G���[�`�F�b�N */
  if (frame < 0 || cgif_frame <= frame)
    error("In cgif_putpixel : frame(�y�[�W�ԍ�)���͈͊O");
  /* �_��ł͈͊O�Ȃ牽�������Ɋ֐����I�� */
  if (x < 0 || ImageBlockp[frame].width < x)
    return 0;
  if (y < 0 || ImageBlockp[frame].height < y)
    return 0;
  
  cgif_image[frame][(cgifByte4)x+y*ImageBlockp[frame].width]=color_index;
  return 1;
}

void foutarray(char *name, cgifByte1 *array, int n, FILE *fp)
{
  int i;
  
  for (i=0; i < n; i++)
    fputc( array[i], fp);
  return;
}

void cgif_output(char *filename){
  FILE *fp;
  int i;
  cgifByte2 l1,l2,l3;
  cgifByte1 model[100]; /* �O���[�o���J���[�e�[�u���ȂǂɎg�p */
  
  if ((fp = fopen( filename, "wb")) == NULL )
    error("In cgif_output : cannot add file");
  
  /*
  ** �w�b�_
  */
  /* ���`���̍쐬 �A�X�L�[�R�[�h��GIF89a */
  model[0]=0x47; model[1]=0x49; model[2]=0x46; model[3]=0x38;
  model[4]=0x39; model[5]=0x61;
  foutarray(filename, model, 6, fp);  
  
  /*
  ** �_����ʋL�q�q
  */
  /* 2byte : �_����ʂ̕��ƍ��� */
  fputc( LogicalScreenWidth & 0x00ff ,fp);
  fputc( LogicalScreenWidth >> 8 ,fp);
  
  fputc( LogicalScreenHeight & 0x00ff ,fp);
  fputc( LogicalScreenHeight >> 8 ,fp);
  /* �F�\���p�����[�^ */
  fputc( 0xf7, fp);
  /* �w�i�F�̃J���[�C���f�b�N�X */
  fputc( cgifBackgroundColorIndex, fp);
  /* �s�N�Z���̃A�X�y�N�g�� 0:���Ȃ� */
  fputc( 0x00, fp);
  
  /*
  ** �O���[�o���J���[�e�[�u��
  */
  /* ��{16�F */
  model[0]=0x00; model[1]=0x00; model[2]=0x00; model[3]=0x80;
  model[4]=0x00; model[5]=0x00; model[6]=0x00; model[7]=0x80;
  model[8]=0x00; model[9]=0x80; model[10]=0x80; model[11]=0x00;
  model[12]=0x00; model[13]=0x00; model[14]=0x80; model[15]=0x80;
  model[16]=0x00; model[17]=0x80; model[18]=0x00; model[19]=0x80;
  model[20]=0x80; model[21]=0x80; model[22]=0x80; model[23]=0x80;
  model[24]=0xC0; model[25]=0xC0; model[26]=0xC0; model[27]=0xFF;
  model[28]=0x00; model[29]=0x00; model[30]=0x00; model[31]=0xFF;
  model[32]=0x00; model[33]=0xFF; model[34]=0xFF; model[35]=0x00;
  model[36]=0x00; model[37]=0x00; model[38]=0xFF; model[39]=0xFF;
  model[40]=0x00; model[41]=0xFF; model[42]=0x00; model[43]=0xFF;
  model[44]=0xFF; model[45]=0xFF; model[46]=0xFF; model[47]=0xFF;
  
  foutarray(filename, model, 48, fp);
  
  /* ���g�p�� */
  for (i = 0; i < 24*3; i++)
    fputc( 0x00, fp);
  
  /* 216�F */
  for (l1 = 0; l1 <= 0xff; l1+=0x33)
    for (l2 = 0; l2 <= 0xff; l2+=0x33)
      for (l3 = 0; l3 <= 0xff; l3+=0x33){
        fputc( l1, fp); fputc( l2, fp); fputc( l3, fp);
      }
  
  /*
  ** �A�v���P�[�V�����g���u���b�N
  ** cgifNumberOfIterations��1�̏ꍇ�͔�΂�
  */
  if (cgifNumberOfIterations != 1){
    fputc( 0x21, fp); fputc( 0xff, fp); /* �Œ� */
    fputc( 0xb, fp); /* �u���b�N�̃o�C�g��. �Œ� */
    
    model[0]='N'; model[1]='E'; model[2]='T'; model[3]='S';
    model[4]='C'; model[5]='A'; model[6]='P'; model[7]='E';
    model[8]='2'; model[9]='.'; model[10]='0';
    foutarray(filename, model, 11, fp);
    
    fputc( 0x3, fp); /* �T�u�u���b�N(����3�o�C�g)�̃o�C�g��. �Œ� */
    fputc( 0x1, fp); /* �Œ� */
    /* 2byte : �J��Ԃ��� */
    fputc( cgifNumberOfIterations & 0x00ff ,fp);
    fputc( cgifNumberOfIterations >> 8 , fp);
    
    fputc( 0x00, fp); /* �u���b�N�I�����ʎq. �Œ�l0 */
  }
  
  /*
  ** cgif_frame�̐�����
  ** Graphic Control Extention
  ** Image Block(�C���[�W�f�B�X�N���v�^ + �C���[�W�f�[�^)
  ** �̏��ɑ�����
  */
  for ( i = 0; i < cgif_frame; i++){
    
    /* 
    ** �O���t�B�b�N�g���u���b�NGraphic Control Extention 
    */
    fputc(0x21,fp); /* �g���u���b�N�ł��邱�Ƃ������Œ�l */
    /*���̃u���b�N��Graphic Control Extention�ł��邱�Ƃ������Œ�l*/
    fputc(0xf9,fp);
    fputc(0x04,fp );/* �u���b�N�T�C�Y.�Œ�l */
    /* �\�������p�����[�^(Packed Fields) */
    fputc( GraphicBlockp[i].PackedFields , fp);
    /* 2byte : �ҋ@����(Delay Time)(1/100�b */
    fputc( GraphicBlockp[i].time & 0x00ff , fp);
    fputc( GraphicBlockp[i].time >> 8 , fp);
    
    /* �����F�̃J���[�C���f�b�N�X(Transparent Color Index) */
    fputc( GraphicBlockp[i].TransparentIndex , fp);
    fputc(0x00,fp); /* �u���b�N�I�����ʎq(Block Terminator) */
    
    /*
    ** �C���[�W�f�[�^�u���b�NImage Block
    */
    /* �C���[�W�L�q�q */
    fputc(0x2c,fp );
    /* 2byte : GIF�摜�S�̂ɑ΂��鍶�[���ΈʒuImage Left Position */
    fputc( ImageBlockp[i].left & 0x00ff , fp);
    fputc( ImageBlockp[i].left >> 8 , fp);
    /* 2byte : GIF�摜�S�̂ɑ΂����[���ΈʒuImage top Position */
    fputc( ImageBlockp[i].top & 0x00ff , fp);
    fputc( ImageBlockp[i].top >> 8 ,fp);
    /* 2byte : ���̃C���[�W�u���b�N�̉���Image Width */
    fputc( ImageBlockp[i].width & 0x00ff ,fp);
    fputc( ImageBlockp[i].width >> 8 , fp);
    /* 2byte : ���̃C���[�W�u���b�N�̏c��Image Width */
    fputc( ImageBlockp[i].height & 0x00ff , fp);
    fputc( ImageBlockp[i].height >> 8 , fp);
    /* �F�\���p�����[�^��0 */
    fputc( 0x00 , fp);
    /* Local Color Table�͎g�p���Ȃ��̂� ����Lzw Minimum Code Size
       256�F�ł�8 */
    fputc( 0x08 , fp);
    
    /* Block Size(�C���[�W�f�[�^�̃o�C�g��)�ƃC���[�W�f�[�^ */
    lzw_output( i, filename, fp);
    
    fputc(0x00,fp); /* �u���b�N�̕��т̏I����\��.�Œ�. */
    
  }
  fputc(0x3b,fp);/* Trailer:GIF�f�[�^�X�g���[���̏I����\��.�Œ� */

  fclose(fp);
  return;
}

void lzw_output( int frame, char *filename, FILE *fp)
{
  /* �����쐬���̒�` */
  cgifByte2 prefix[DICT_MAX];
  cgifByte2 suffix[DICT_MAX];
  /* cgif_image[frame][]���ǂ��܂œǂ񂾂�. ���ɓǂޏꏊ���w�� */
  cgifByte4 image_p = 0;
  /* ���Ɏ������쐬����ꏊ���w�� */
  cgifByte2 dict_p = 0;
  /* �����ɓ����f�[�^ */
  cgifByte2 dict_index;
  /* cgif_image[frame][image_p]~[image_p+length]�܂ł����̎����ɓ��� */
  cgifByte4 length;
  
  /* �C���[�W�f�[�^���̒�` */
  cgifByte4 buf = 0;
  cgifByte4 bufp = 0;
  
  /* �ėp�̒�` */
  cgifByte2 i, end;
  
  /* cgif_image[frame][]�S����ǂނ܂ł܂킷 */
  while (image_p < ImageBlockp[frame].size){
    
    /*
    ** �C���[�W�f�[�^��1�����̏ꍇ�̕ʏ���
    */
    if (image_p == ImageBlockp[frame].size - 1){
      
      /*
      ** �C���[�W�f�[�^�̃o�C�g�����v�Z���ďo��
      */
      /* +3�̓N���A�R�[�h�ƃT�t�B�b�N�X�ƏI���R�[�h�� */
      fputc( (cgifByte1)ceil((double)(bufp + 9.0*(0.0 + 3.0))/8.0) , fp);
      
      /*
      ** �C���[�W�f�[�^���쐬���ďo��
      */
      /* �ŏ��ɃN���A�R�[�h��buf�̐擪�ɑ}�� */
      buf = (0x100 << bufp) | buf;
      bufp += 9;
      /* �f���o��->�}��->�f���o���Ƃ���ׂ̃��[�v */
      for ( i = 0 ; i < 2; i++){
        /* buf��1byte�ȏ㗭�܂�����image_data�ɓf���o�� */
        while (bufp >= 8){
          fputc( (cgifByte1)(0xff & buf) , fp);
          buf = buf >> 8;
          bufp -= 8;
        }
        if (i == 0){
          /* �C���[�W�f�[�^��buf�̐擪�ɑ}�� */
          buf = (cgif_image[frame][image_p] << bufp) | buf;
          bufp += 9;
        }
      }
      break;
      
    }
    /* ��O�����I��� */
    
    /*
    ** ����(prefix)�쐬��
    */
    dict_p = 0; /* �����̏����� */
    /* -1�̈Ӗ���suffix��. cgif_image[frame][]�S����ǂނ܂ł܂킷 */
    for ( ;image_p < ImageBlockp[frame].size - 1 && dict_p < DICT_MAX;
          image_p += length){
      dict_index = cgif_image[frame][image_p];
      length = 1;
      
      for ( i = 0; i < dict_p; i++)
        if (image_p + length < ImageBlockp[frame].size - 1)
          if (prefix[i]==dict_index)
            if(suffix[i]==cgif_image[frame][image_p+length]){
              dict_index = i + 0x102;
              length++;
            }
      prefix[dict_p] = dict_index;
      suffix[dict_p] = cgif_image[frame][image_p + length];
      if (dict_p > DICT_MAX)
        error("In lzw_output : dict_p���傫������l���w����");
      dict_p++;
    }
    image_p++; /* �T�t�B�b�N�X�̕����C���N�������g */

    /*    
    for (i=0; i < dict_p; i++)
      printf("prefix[0x%x+0x102=0x%x]=0x%x suffix=0x%x\n"
             ,i,i+0x102,prefix[i],suffix[i]);
    */
    
    /*
    ** �C���[�W�f�[�^�̃o�C�g�����v�Z���ďo��
    */
    /* gif_image�̍Ōゾ���́A�I���R�[�h������̂�
       buf�ɓr���܂œ��������̂�f���o�����Ƃ���ꍇ�������K�v */
    if (image_p < ImageBlockp[frame].size)
      /* +2�̓N���A�R�[�h�ƃT�t�B�b�N�X�� */
      fputc( (cgifByte1)floor((double)(bufp + 9.0*(dict_p + 2))/8.0), fp);
    else
      /* +3�̓N���A�R�[�h�ƃT�t�B�b�N�X�ƏI���R�[�h�� */
      fputc( (cgifByte1)ceil((double)(bufp + 9.0*(dict_p + 3))/8.0) , fp);
    
    /*
    ** �C���[�W�f�[�^���쐬���ďo��
    */
    /* �܂��ŏ��ɃN���A�R�[�h��buf�̐擪�ɑ}�� */
    buf = (0x100 << bufp) | buf;
    bufp += 9;
    
    for ( i = 0, end = 0; i < dict_p || end != 2; i++){
      
      /* buf��1byte�ȏ㗭�܂�����image_data�ɓf���o�� */
      while (bufp >= 8){
        fputc( (cgifByte1)(0xff & buf) , fp);
        buf = buf >> 8;
        bufp -= 8;
      }
      
      if (i < dict_p){ /* �ʏ킱��������s*/
        /* prefix[i]��buf�̐擪�ɑ}�� */
        buf = (prefix[i] << bufp) | buf;
        bufp += 9;
        
        /* �ȉ��͏I������ */
      }else if (end == 0){ /* �オ�I�������Ō��suffix�������� */
        /* suffix[dict_p-1]��buf�̐擪�ɑ}�� */
        buf = (suffix[dict_p-1] << bufp) | buf;
        bufp += 9;
        end = 1;
      }else /* for���𔲂��� */
        end = 2;
      
    }
    
  }
  
  /* �I���R�[�h������ */
  buf = (0x101 << bufp) | buf;
  bufp += 9;
  /* buf��1byte�ȏ㗭�܂�����image_data�ɓf���o�� */
  while (bufp >= 8){
    fputc( (cgifByte1)(0xff & buf) , fp);
    buf = buf >> 8;
    bufp -= 8;
  }
  
  /* buf�Ɏc�����]���f���o�� */
  if (bufp > 0){
    fputc( buf, fp);
    bufp = 0; buf = 0;
  }
  
}

void cgif_copy_mat(cgifByte1** mat, int frame)
{
  cgifByte2 i,j;

  for ( i = 0; i < ImageBlockp[frame].height; i++)
    for ( j = 0; j < ImageBlockp[frame].width; j++)
      mat[i][j] = cgif_image[frame][i * ImageBlockp[frame].height + j];
}

void cgif_copy_array(cgifByte1* array, int frame)
{
  cgifByte4 i;

  for ( i = 0; i < ImageBlockp[frame].size; i++)
    array[i] = cgif_image[frame][i];
}

void cgif_setImageBlock(cgifByte2 left, cgifByte2 top,
                        cgifByte2 width, cgifByte2 height,
                        int frame)
{
  /* �����̃G���[�`�F�b�N */
  if (frame < 0 || cgif_frame <= frame)
    error("In cgif_setImageBlock : frame(�y�[�W�ԍ�)���͈͊O");
  
  ImageBlockp[frame].left = left;
  ImageBlockp[frame].top = top;
  ImageBlockp[frame].width = width;
  ImageBlockp[frame].height = height;
  
  ImageBlockp[frame].size =
    (cgifByte4)ImageBlockp[frame].width * ImageBlockp[frame].height;
  free((void *)cgif_image[frame]); /* NULL���g���Ă���͂��Ȃ̂ŉ�� */
  cgif_image[frame] =
    (cgifByte1 *)malloc(sizeof(cgifByte1 *) * ImageBlockp[frame].size);
}

void cgif_setGraphicBlock( int TransparentFlag,
                           int UserInputFlag,
                           int DisposalMethod,
                           cgifByte2 time, int frame)
{
  /* �����̃G���[�`�F�b�N */
  if (frame < 0 || cgif_frame <= frame)
    error("In cgif_setGraphicBlock : frame(�y�[�W�ԍ�)���͈͊O");
  if (TransparentFlag != 0)
    TransparentFlag = 1;
  if (UserInputFlag != 0)
    UserInputFlag = 1;
  if (DisposalMethod > 7 || DisposalMethod < 0)
    DisposalMethod = 0;
  
  /* PackedFields�Ɋe�t���O���Z�b�g */
  DisposalMethod <<= 2;
  UserInputFlag <<= 1;
  GraphicBlockp[frame].PackedFields =
    DisposalMethod | UserInputFlag | TransparentFlag;
  
  GraphicBlockp[frame].TransparentIndex = cgifTRANSPARENT;
  GraphicBlockp[frame].time = time;
}

cgifByte2 cgif_color_to_index(cgifByte4 color)
{
  cgifByte4 c[3];/* c[2]:�� c[1]:�� c[0]:�� */
  int i;
  /* �܂���{16�F�ⓧ�ߐF�łȂ����`�F�b�N */
  switch (color){
  case cgifBlack: return 0x0;
  case cgifGray: return 0x7;
  case cgifSilver: return 0x8;
  case cgifWhite: return 0xf;
  case cgifRed: return 0x9;
  case cgifYellow: return 0xb;
  case cgifLime: return 0xa;
  case cgifAqua: return 0xe;
  case cgifBlue: return 0xc;
  case cgifFuchsia: return 0xd;
  case cgifMaroon: return 0x1;
  case cgifOlive: return 0x3;
  case cgifGreen: return 0x2;
  case cgifTeal: return 0x6;
  case cgifNavy: return 0x4;
  case cgifPurple: return 0x5;
  }
  if (0x1000000 <= color) /* ���ߐF�̏ꍇ */
    return GraphicBlockp[color - 0x1000000].TransparentIndex;
  
  /* RGB�̐������Ɏ��o�� */
  c[0] = 0x0000ff & color;
  c[1] = (color >> 8) & 0x00ff;
  c[2] = color >> 16;
  
  for ( i = 0; i < 3; i++)
    /* WEB�Z�[�t�J���[��RGB�̊e�F��6�i�K�ɕ�����.
       0%, 20% 40% 60% 80% 100%��6�i�K */
    c[i] = rounding((double)c[i]*5.0/0xff);
  
  return 6*6*c[2]+6*c[1]+c[0] + 16 + 24;
}

long rounding(double n)
{
  if (n - floor(n) < 0.5) return floor(n);
  else return ceil(n);
}

void cgif_create_window(double x1, double y1, double x2, double y2)
{
  /* �����̃G���[�`�F�b�N */
  if (x1 == x2 || y1 == y2)
    error("In cgif_create_window : �E�C���h�E�����܂���.");
  cgif_window.pt1.x = x1;
  cgif_window.pt1.y = y1;
  cgif_window.pt2.x = x2;
  cgif_window.pt2.y = y2;
}

cgifByte2 change_x( double x, int frame)
{
  /* �G���[�`�F�b�N���Ȃ� */
  x = (x - cgif_window.pt1.x) / (cgif_window.pt2.x - cgif_window.pt1.x);
  x *= ImageBlockp[frame].width - 1;
  return rounding(x);
}

cgifByte2 change_y( double y, int frame)
{
  /* �G���[�`�F�b�N���Ȃ� */
  y = (y - cgif_window.pt1.y) / (cgif_window.pt2.y - cgif_window.pt1.y);
  y *= ImageBlockp[frame].height - 1;
  return rounding(y);
}

int cgif_pset(double x, double y, cgifByte4 color, int frame)
{
  /* �����̃G���[�`�F�b�N */
  if (frame < 0 || cgif_frame <= frame)
    error("In cgif_pset : frame(�y�[�W�ԍ�)���͈͊O");
  /* �_��ł͈͊O�Ȃ牽�������Ɋ֐����I�� */
  if ( x < min(cgif_window.pt1.x, cgif_window.pt2.x) )
    return 0;
  if ( max(cgif_window.pt1.x, cgif_window.pt2.x) <= x)
    return 0;
  if ( y < min(cgif_window.pt1.y, cgif_window.pt2.y) )
    return 0;
  if ( max(cgif_window.pt1.y, cgif_window.pt2.y) <= y)
    return 0;
  
  return cgif_putpixel( change_x(x,frame), change_y(y,frame),
                        cgif_color_to_index(color), frame );
}

int cgif__line( double x_0, double y_0, double x_1, double y_1,
                cgifByte4 color, int frame)
{
  int e; /* ( (y�̎����l-����������y) - 0.5 ) * 2*dx */
  cgifByte2 x,y; /* �_��ł��ۂ̒l */
  cgifByte2 x0,y0,x1,y1; /* �ϊ���̎n�_�I�_ */
  cgifByte2 dx,dy;
  int sx,sy,i;
  
  /* �����̃G���[�`�F�b�N */
  if (frame < 0 || cgif_frame <= frame)
    error("In cgif__line : frame(�y�[�W�ԍ�)���͈͊O");
  
  x0 = change_x( x_0, frame); x1 = change_x( x_1, frame);
  y0 = change_y( y_0, frame); y1 = change_y( y_1, frame);
  
  sx = ( x0 < x1 ) ? 1 : -1; /* x���C���N�������g���Ă������� */
  dx = ( x0 < x1 ) ? x1 - x0 : x0 - x1;/* x1����x0�܂ł̕����Ȃ��̋��� */
  sy = ( y0 < y1 ) ? 1 : -1; /* y���C���N�������g��������� */
  dy = ( y0 < y1 ) ? y1 - y0 : y0 - y1;/* y1����y0�܂ł̕����Ȃ��̋��� */
  
  x = x0; y = y0;
  
  /* �X���̐�Βl��1�ȉ��̏ꍇ */
  if ( dy <= dx ) {
    e = -dx; /* e = (0 - 0.5) * 2*dx */
    for (i = 0; i <= dx; i++){
      /* (x0,y0)����(x1,y1)�֌������ē_��ł��Ă��� */
      cgif_putpixel( x, y, cgif_color_to_index(color), frame);
      x += sx;
      e += 2*dy; /* e += dy/dx * 2*dx */
      /* �덷�����܂�����f���o�� */
      if ( e >= 0 ){ /* e >= (0.5 - 0.5) * 2*dx */
        y += sy;
        e -= 2*dx; /* e -= 1 * 2*dx */
      }
    }
    
  /* �X���̐�Βl��1���傫���ꍇ */
  }else{
    e = -dy; /* e = (0 - 0.5) * 2*dy */
    for (i = 0; i <= dy; i++){
      /* (x0,y0)����(x1,y1)�֌������ē_��ł��Ă��� */
      cgif_putpixel( x, y, cgif_color_to_index(color), frame);
      y += sy;
      e += 2*dx; /* e += dx/dy * 2*dy */
      /* �덷�����܂�����f���o�� */
      if ( e >= 0 ){ /* e >= (0.5 - 0.5) * 2*dy */
        x += sx;
        e -= 2*dy; /* e -= 1 * 2*dy */
      }
    }
  }
  return 1;
}

unsigned char cgif_looker(double x, double y)
{
  unsigned char c = 0;
  
  if ( x < min(cgif_window.pt1.x, cgif_window.pt2.x) )
    c |= 1;
  if ( max(cgif_window.pt1.x, cgif_window.pt2.x) < x)
    c |= 2;
  if ( y < min(cgif_window.pt1.y, cgif_window.pt2.y) )
    c |= 4;
  if ( max(cgif_window.pt1.y, cgif_window.pt2.y) < y)
    c |= 8;
  
  return c;
}

int cgif_line( double x1, double y1, double x2, double y2,
                cgifByte4 color, int frame)
{
  struct point min_pt, max_pt;
  unsigned char c1, c2; /* (x1,y1), (x2,y2)���ǂ��ɂ��邩 */
  
  /* �����̃G���[�`�F�b�N */
  if (frame < 0 || cgif_frame <= frame)
    error("In cgif_line : frame(�y�[�W�ԍ�)���͈͊O");
  
  c1 = cgif_looker(x1, y1);
  c2 = cgif_looker(x2, y2);
  
  min_pt.x = min(cgif_window.pt1.x, cgif_window.pt2.x);
  min_pt.y = min(cgif_window.pt1.y, cgif_window.pt2.y);
  max_pt.x = max(cgif_window.pt1.x, cgif_window.pt2.x);
  max_pt.y = max(cgif_window.pt1.y, cgif_window.pt2.y);
  
  while(1){
    if (c1 == 0 && c2 == 0) /* �n�_�I�_���ɕ`��̈���ɂ���ꍇ */
      return cgif__line( x1, y1, x2, y2, color, frame);
    if (c1 & c2) /* ���̏ꍇ�A��������ʂƏd�Ȃ�Ȃ� */
      return 0;
    if (c2 == 0){ /* �I�_����ʂ̓����Ȃ�n�_�ƌ������āA��ʂ���O�� */
      dswap(x1,x2); dswap(y1,y2); dswap(c1,c2);
    }
    /* �ȉ��A��ʂ���O��Ă���I�_���C�����Ă��� */
    /* �͂ݏo���Ă��������͉�ʂ�4�ӂ��������钼���ŏ������؂��
       �����Ƃ�4��ŃN���b�s���O���������� */
    if (c2 & 1){
      y2 = y2 + (y1 - y2) * (min_pt.x - x2)/(x1 - x2);
      x2 = min_pt.x;
    }else if (c2 & 2){
      y2 = y2 + (y1 - y2) * (max_pt.x - x2)/(x1 - x2);
      x2 = max_pt.x;
    }else if (c2 & 4){
      x2 = x2 + (x1 - x2) * (min_pt.y - y2)/(y1 - y2);
      y2 = min_pt.y;
    }else{
      x2 = x2 + (x1 - x2) * (max_pt.y - y2)/(y1 - y2);
      y2 = max_pt.y;
    }
    c2 = cgif_looker(x2,y2);
  }
}

int cgif_circle(double x_0, double y_0, double radius_w, double radius_h,
                double radian_s, double radian_e,
                cgifByte4 color, int frame)
{
  /* �܂����_���S�ŁA(a,0)���甽���v����4���~��`�����Ƃ��l����B
     �^�ォ���ォ�^���̂�����ɐi�ނ������ꂼ��ړ��������ʂ̌덷
     e := (x/a)^2 + (y/b)^2 - 1 ���ŏ��ƂȂ�悤�Ɍ��߂�B
     �^��(vertical)�Ɉړ� ev := (x/a)^2 + ((y+1)/b)^2 - 1
     ����(diagonal)�Ɉړ� ed := ((x-1)/a)^2 + ((y+1)/b)^2 - 1
     �^��(left)�Ɉړ�     el := ((x-1)/a)^2 + (y/b)^2 - 1
     err1 := 2*e - 2*(1/a^2)*x + 4*(1/b^2)*y + 1/a^2 + 2*(1/b^2)
     err2 := 2*e - 4*(1/a^2)*x + 2*(1/b^2)*y + 2*(1/a^2) + 1/b^2
     err3 := 2*e - 2*(1/a^2)*x + 2*(1/b^2)*y + 1/a^2 + 1/b^2
     e1 := ev^2 - ed^2 = (1/a^2)(2*x - 1) * err1
     e2 := ev^2 - el^2 = ((1/a^2)(2*x - 1) + (1/b^2)(2*y + 1)) * err3
     e3 := ed^2 - el^2 = (1/b^2)(2*y + 1) * err2
     �Ƃ����ƁA
     �Ee1 < 0 and e2 < 0 �Ȃ�^��Ɉړ�
     �Ee3 < 0 and e1 >= 0 �Ȃ獶��Ɉړ�
     �Ee2 >= 0 and e3 >= 0 �Ȃ�^���Ɉړ�
     x >= 1, y >= 0 �ł��邱�Ƃɒ��ӂ���ƁA
     e1,e2,e3�̑����err1,err3,err2�̐����Ŕ���ł���B�܂��A
     e3 = e1 - (1/b^2)(2*y + 1) < e1, e2 = e3 - (1/a^2)(2*x - 1) < e3
     ���Ae2 < e3 < e1 ���K�����藧���Ƃ���A�ŏI�I�Ȕ����
     �Eer1 := (a^2*b^2)*e1 < 0 �Ȃ�^��Ɉړ�
     �E(a^2*b^2)*e1 >= 0, er2 := (a^2*b^2)*e2 < 0 �Ȃ獶��Ɉړ�
     �E(a^2*b^2)*e2 >= 0 �Ȃ�^���Ɉړ�
     ++y����ƁAer1(x,y) - er1(x,y-1) = 4*a^2*y + 2*a^2
     er2(x,y) - er2(x,y-1) = 4*a^2*y
     --x����ƁAer1(x,y) - er1(x+1,y) = -4*b^2*x
     er2(x,y) - er2(x+1,y) = -4*b^2*x + 2*b^2
     ��er1,er2���ω����邱�Ƃɒ��ӂ��āA
     er1(a,0) = -2*b^2*a + b^2 + 2*a^2
     er2(a,0) = -4*b^2*a + 2*b^2 + a^2
     ���珇��er1, er2�����߂�B */
  
  cgifByte4 x, y, x0, y0, a, b;
  int er1, er2;
  cgifByte4 xmin, ymin, xmax, ymax;
  int s1draw[4],e1draw[4];/*0:���S�ɓ���Ȃ�, 1:���S�ɓ���, 2:�ꕔ����*/
  int s2draw[4],e2draw[4];
  cgifByte4 sx, sy, ex, ey; /* �~�ʂ̊J�n���W�A�I�����W */
  double th_max, th_min, temp;
  int i;

  /*
  ** cgif_window�ɂ��㉺���]���p�xradian_s,radian_e��ω������Ď��s
  */
  if (cgif_window.pt2.y < cgif_window.pt1.y){
    radian_s *= -1.0;
    radian_e *= -1.0;
  }
  if (cgif_window.pt2.x < cgif_window.pt1.x){
    radian_s *= -1.0; radian_s += PI;
    radian_e *= -1.0; radian_e += PI;
  }
  
  /*
  ** radian_s, radian_e��W���`
  ** (0 <= radian_s < 2*PI, 0 <= radian_e - radian_s <= 2*PI)�ɒ���
  */
  /* radian_s <= radian_e �ɂ��� */
  if (radian_e < radian_s) dswap(radian_e, radian_s);

  /* 2*PI <= radian_e - radian_s �̎�(���S�ȉ~)�̕ʏ��� */
  if (2.0*PI <= radian_e - radian_s)
     { radian_s = 0.0; radian_e = 2.0*PI;}
  
  /* 0 <= radian_s �ɂ��� */
  if (radian_s < 0)
    for(; radian_s < 0; radian_s += 2.0*PI, radian_e += 2.0*PI);
  
  /* radian_s < 2*PI �ɂ��� */
  if (2.0*PI <= radian_s){
    temp = floor(radian_s/(2.0*PI));
    radian_s -= temp*(2.0*PI); radian_e -= temp*(2.0*PI);
  }
  
  /*
  ** �e�X��4���~�̕`��͈͂̃^�C�v�𒲂ׁA
  ** s1draw[],e1draw[],s2draw[],e2draw[]�Ƀ^�C�v���i�[
  */
  for( i = 0; i < 4; i++){
    /* �e�X��4���~�̒��ł̍ŏ��p�x�A�ő�p�x�����߂� */ 
    th_min = (PI/2.0) * (double)i;
    th_max = (PI/2.0) * (double)(i+1);
    
    /*
      �܂��ȉ��̏����𖞂����͈͕͂K���`��Bs1draw[],e1draw[]�Ɋi�[
    */
    /* �`��J�n�͈�s1draw[4]�̍쐬 */
    if (radian_s <= th_min)
      s1draw[i] = 1; /* ���S�ɓ��� */
    else if (radian_s <= th_max) /* th_min < radian_s <= th_max �̏ꍇ */
      s1draw[i] = 2; /* �ꕔ���� */
    else /* th_max < radian_s �̏ꍇ */
      s1draw[i] = 0; /* ���S�ɓ���Ȃ� */

    /* �`��I���͈�e1draw[4]�̍쐬 */
    if (th_max <= radian_e)
      e1draw[i] = 1; /* ���S�ɓ��� */
    else if (th_min <= radian_e) /* th_min <= radian_e < th_max �̏ꍇ */
      e1draw[i] = 2; /* �ꕔ���� */
    else /* radian_e < th_min �̏ꍇ */
      e1draw[i] = 0; /* ���S�ɓ���Ȃ� */
    
    /*
      ������radian_e��(2*PI,4*PI)�̎��A�ȉ��̏����𖞂����͈͂��`��B
      s2draw[],e2draw[]�Ɋi�[
    */
    /* �`��J�n�͈�e2draw[4]�̍쐬(s2draw[4]�͎���) */
    if (th_min < radian_e - 2.0*PI){ /* <= ����ύX */
      s2draw[i] = 1;
      if (th_max < radian_e - 2.0*PI)
        e2draw[i] = 1;
      else if (th_min <= radian_e - 2.0*PI)
        e2draw[i] = 2;
      else
        e2draw[i] = 0;
    }else{
      s2draw[i] = 0; e2draw[i] = 0;
    }
  }
  
  /*
  ** ������(cgif_putpixel�Œ��ڕ`���������W�ɕϊ�)
  */
  /* �C���[�W�ɏ������ޒ��S���W�����߂� */
  x0 = change_x(x_0, frame); y0 = change_y(y_0, frame);
  
  /*
    cgif_create_window�ɂ��L�k���l������
    �ŏI�I�ɃC���[�W�ɏ�������x�������̔��aa, y�������̔��ab�����߂�
  */
  temp = (double)ImageBlockp[frame].width
    /(cgif_window.pt2.x - cgif_window.pt1.x);
  a = ABS(temp * radius_w);
  temp = (double)ImageBlockp[frame].height
    /(cgif_window.pt2.y - cgif_window.pt1.y);
  b = ABS(temp * radius_h);
  
  /* �~�ʊJ�n�_(sx,sy)�A�~�ʏI���_(ex,ey)�����߂� */
  sx = rounding((double)a * cos(radian_s)) + x0;
  sy = rounding((double)b * sin(radian_s)) + y0;
  ex = rounding((double)a * cos(radian_e)) + x0;
  ey = rounding((double)b * sin(radian_e)) + y0;
  
  /* �J�n�_(x=a,y=0)�̊e�X�̒l�����߂� */
  x = a;
  y = 0;
  er1 = -2*b*b*a + b*b + 2*a*a; /* (x=a,y=0)����er1 */
  er2 = -4*b*b*a + 2*b*b + a*a; /* (x=a,y=0)����er2 */
  xmin = x0 - x; ymin = y0 - y; xmax = x0 + x; ymax = y0 + y;
  
  /*
  ** 4���~�ɕ����ĕ`��
  */
  while ( x >= 0 ) { /* x = 0�̎��A�_�����`���ĉ���break�Ŕ����� */
    /* s1draw[],e1draw[]�Ŏw�肵���͈͂̕`�� */
    if (s1draw[0] == 1 || (s1draw[0] == 2 && xmax <= sx && sy <= ymax))
      if (e1draw[0] == 1 || (e1draw[0] == 2  && ex <= xmax && ymax <= ey))
        cgif_putpixel( xmax, ymax, cgif_color_to_index(color), frame);
    
    if (s1draw[1] == 1 || (s1draw[1] == 2 && xmin <= sx && ymax <= sy))
      if (e1draw[1] == 1 || (e1draw[1] == 2 && ex <= xmin && ey <= ymax))
        cgif_putpixel( xmin, ymax, cgif_color_to_index(color), frame);
    
    if (s1draw[2] == 1 || (s1draw[2] == 2 && sx <= xmin && ymin <= sy))
      if (e1draw[2] == 1 || (e1draw[2] == 2 && xmin <= ex && ey <= ymin))
        cgif_putpixel( xmin, ymin, cgif_color_to_index(color), frame);
    
    if (s1draw[3] == 1 || (s1draw[3] == 2 && sx <= xmax && sy <= ymin))
      if (e1draw[3] == 1 || (e1draw[3] == 2 && xmax <= ex && ymin <= ey))
        cgif_putpixel( xmax, ymin, cgif_color_to_index(color), frame);
    
    /* s2draw[],e2draw[]�Ŏw�肵���͈͂̕`�� */
    if (e2draw[0] == 1 || (e2draw[0] == 2 && ex <= xmax && ymax <= ey))
      cgif_putpixel( xmax, ymax, cgif_color_to_index(color), frame);

    if (e2draw[1] == 1 || (e2draw[1] == 2 && ex <= xmin && ey <= ymax))
      cgif_putpixel( xmin, ymax, cgif_color_to_index(color), frame);

    if (e2draw[2] == 1 || (e2draw[2] == 2 && xmin <= ex && ey <= ymin))
      cgif_putpixel( xmin, ymin, cgif_color_to_index(color), frame);

    if (e2draw[3] == 1 || (e2draw[3] == 2 && xmax <= ex && ymin <= ey))
      cgif_putpixel( xmax, ymin, cgif_color_to_index(color), frame);
    
    if (x == 0) break; /* x = 0��`���Ă��甲���� */
    if ( er1 < 0 ) { /* �^��Ɉړ� */
      y++;
      er1 += 4*a*a*y + 2*a*a;
      er2 += 4*a*a*y;
      ymin = y0 - y; ymax = y0 + y;
    } else if ( er2 >= 0 ) { /* �^���Ɉړ� */
      x--;
      er1 -= 4*b*b*x;
      er2 -= 4*b*b*x - 2*b*b;
      xmin = x0 - x; xmax = x0 + x;
    } else { /* ����Ɉړ� */
      x--;
      y++;
      er1 += 4*a*a*y + 2*a*a - 4*b*b*x;
      er2 += 4*a*a*y - 4*b*b*x - 2*b*b;
      xmin = x0 - x; ymin = y0 - y; xmax = x0 + x; ymax = y0 + y;
    }
  }
  return 0; /* ���̂Ƃ����� 0 */
}

long cgif_point( double x, double y, int frame)
{
  cgifByte4 temp;
  /* �����̃G���[�`�F�b�N */
  if (frame < 0 || cgif_frame <= frame)
    error("In cgif_point : frame(�y�[�W�ԍ�)���͈͊O");
  if ( x < min(cgif_window.pt1.x, cgif_window.pt2.x) )
    return -1;
  if ( max(cgif_window.pt1.x, cgif_window.pt2.x) <= x)
    return -1;
  if ( y < min(cgif_window.pt1.y, cgif_window.pt2.y) )
    return -1;
  if ( max(cgif_window.pt1.y, cgif_window.pt2.y) <= y)
    return -1;
  
  temp = change_x(x,frame) + change_y(y,frame)*ImageBlockp[frame].width;
  return cgif_image[frame][temp];
}

void error(char *message)
{
  fprintf(stderr,"Error in cgif.c\n  %s\n",message);
  exit(1);
}
