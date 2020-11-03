/*
  Copyright (c) 2005-2006, Akihiro Yamaguchi
  All rights reserved.
  
  ソースコード形式かバイナリ形式か、変更するかしないかを問わず、
  以下の条件を満たす場合に限り、再頒布および使用が許可されます。
  
  1. ソースコードを再頒布する場合、上記の著作権表示、本条件一覧、
  および下記免責条項を含めること。 
  2. バイナリ形式で再頒布する場合、頒布物に付属のドキュメント等の資料に、
  上記の著作権表示、本条件一覧、および下記免責条項を含めること。 
  
  本ソフトウェアは、著作権者およびコントリビューターによって「現状のまま」提供されており、
  明示黙示を問わず、商業的な使用可能性、および特定の目的に対する適合性に関する暗黙の保証も
  含め、またそれに限定されない、いかなる保証もありません。
  著作権者もコントリビューターも、事由のいかんを問わず、損害発生の原因いかんを問わず、
  かつ責任の根拠が契約であるか厳格責任であるか（過失その他の）不法行為であるかを問わず、
  仮にそのような損害が発生する可能性を知らされていたとしても、
  本ソフトウェアの使用によって発生した（代替品または代用サービスの調達、使用の喪失、
  データの喪失、利益の喪失、業務の中断も含め、またそれに限定されない）直接損害、間接損害、
  偶発的な損害、特別損害、懲罰的損害、または結果損害について、
  一切責任を負わないものとします。
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < (-(a)) ? (-(a)) : (a))
#define dswap(a,b) {double tmp; tmp = a; a = b; b = tmp;}
#define DICT_MAX 220 /* lzw辞書登録最大数 */

/* 基本16色パレット */
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

/* インデックス版 */
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
#define cgifTRANSPARENT 0x10 /* 透過処理する色のインデックス */

typedef unsigned char cgifByte1;
typedef unsigned int cgifByte2;
typedef unsigned long cgifByte4;

static double PI = 3.14159265358979323846;

/*
** GIF Header
*/
/* 論理画面の幅と高さ */
static cgifByte2 LogicalScreenWidth; /* 2byte */
static cgifByte2 LogicalScreenHeight; /* 2byte */
/* 背景色のグローバルカラーテーブルにおけるインデックス */
cgifByte1 cgifBackgroundColorIndex;

/*
** Block:Application Extention
*/
cgifByte2 cgifNumberOfIterations; /* 繰り返し回数(0:無限) */

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
       |   |  | TransParentColorFlag(1bit):透過処理するかどうか
       |   |  UserInputFlag(1bit):ユーザー入力を必要をするかどうか
       |   DisposalMethod(3bit):画像表示後の処理
       |   0:指定なし 1:画像を残す 2:背景色を回復 3:以前のものを回復
       予約済み(3bit)固定(000) */
  cgifByte1 PackedFields; /* 表示処理パラメータ */
  cgifByte2 time; /* DelayTime:後に続くイメージを表示するまでの待ち時間 */
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

int cgif_frame; /* アニメーションの総ページ数 */
/* cgif_image[frame][ ImageBlockp[frame].size ]をmallocで作成 */
cgifByte1** cgif_image;


/* 初期化：引数はgif画像の大きさ こま数 繰り返し回数*/
void cgif_init(cgifByte2 width,cgifByte2 height, int frame,int iteration);

/* gif画像に点を打つ
   返り値 : 点を打ったなら1, 範囲外なら0 */
int cgif_putpixel(cgifByte2 x, cgifByte2 y,
                  cgifByte1 color_index, int frame);

/* Image BlockのBlock SizeとImage Dataを出力 */
static void lzw_output(int frame, char *filename, FILE *fp);

/* foutarray:array[0]からarray[n-1]までをファイルに出力 */
static void foutarray(char *name, cgifByte1 *array, int n, FILE *fp);

/* cgif_output:標準出力にgifファイルとして出力 */
void cgif_output(char *filename);

/* frame番目のイメージをmat(2次元)にコピー(メモリー確保のチェック無し)
   cgif_imageは1次元の配列になっているが、
   それを2次元の行列にしてコピー */
void cgif_copy_mat(cgifByte1** mat, int frame);

/*frame番目のイメージをarray(1次元)にコピー(メモリー確保のチェック無し)*/
void cgif_copy_array(cgifByte1* array, int frame);

/* frame目(0から数える)のcgifImageBlockをセットする. */
void cgif_setImageBlock( cgifByte2 left, cgifByte2 top,
                         cgifByte2 width, cgifByte2 height,
                         int frame);

/* frame目(0から数える)のcgifGraphicBlockに
   PackedFieldsの各フラグをセット
   timeは画面表示後、次の処理を続行するまでの待機時間 (1/100秒)
   透明色のカラーインデックスはTRANSPARENTに固定 */
void cgif_setGraphicBlock(int TransparentFlag,/* 透過処理するかどうか */
                          int UserInputFlag,/*ユーザー入力を必要とするか*/
                          int DisposalMethod,/* 画像を表示した後の処理 */
                          cgifByte2 time, int frame);

/* RGB表示をグローバルカラーテーブルのインデックスに変える
   0x1000000 ~ (0x1000000 + cgif_frame-1)が透明色 */
cgifByte2 cgif_color_to_index(cgifByte4 color);

/* 四捨五入 */
static long rounding(double n);

/* ウインドウの(x1,y1):左上の座標, (x2,y2):右上の座標
   何回でも変更可 */
void cgif_create_window(double x1, double y1, double x2, double y2);

/* cgif_window上の座標をgif上の座標に変換 */
static cgifByte2 change_x( double x, int frame);
static cgifByte2 change_y( double y, int frame);

/* cgif_windowに点を打つ */
int cgif_pset(double x, double y, cgifByte4 color, int frame);

/* クリッピング処理後の線引き. Bresenhamの(線分発生)アルゴリズム */
int cgif__line( double x0, double y0, double x1, double y1,
                cgifByte4 color, int frame);

/* ２進４桁で(x,y)がcgif_windowに対してどの位置にあるかを表す
   第1桁目 : 画面の左端を外れているかどうか
   第2桁目 : 画面の右端を外れているかどうか
   第3桁目 : 画面の上端を外れているかどうか
   第4桁目 : 画面の下端を外れているかどうか */
unsigned char cgif_looker(double x, double y);

/* 線を引く. 中身はクリッピングしてcgif__lineを呼ぶ */
int cgif_line( double x1, double y1, double x2, double y2,
               cgifByte4 color, int frame);

/* 中心(x_0,y_0)、x軸方向の半径radius_w、y軸方向の半径radius_h
   の楕円を角度radian_sからradian_eまで色colorで描く */
int cgif_circle(double x_0, double y_0, double radius_w, double radius_h,
                double radian_s, double radian_e,
                cgifByte4 color, int frame);

/* 色のインデックスの取り出し ( -1 : 領域外 )*/
long cgif_point( double x, double y, int frame);

/* エラー処理 */
static void error(char *message);


void cgif_init(cgifByte2 width,cgifByte2 height, int frame, int iteration)
{
  cgifByte2 i; cgifByte4 j; 
  
  /* 引数のエラーチェック */
  if (frame < 1)
    error("In cgif_init : frame(ページ数)は1以上");
  LogicalScreenWidth = (width > 0) ? width : 0x32;
  LogicalScreenHeight = (height > 0) ? height : 0x32;
  
  cgifBackgroundColorIndex = cgifWHITE; /* 白 */
  
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
  
  /* cgif_windowの初期化 */
  cgif_create_window(0,0,LogicalScreenWidth,LogicalScreenHeight);
}

int cgif_putpixel(cgifByte2 x,cgifByte2 y,cgifByte1 color_index,int frame)
{
  /* 引数のエラーチェック */
  if (frame < 0 || cgif_frame <= frame)
    error("In cgif_putpixel : frame(ページ番号)が範囲外");
  /* 点を打つ範囲外なら何もせずに関数を終了 */
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
  cgifByte1 model[100]; /* グローバルカラーテーブルなどに使用 */
  
  if ((fp = fopen( filename, "wb")) == NULL )
    error("In cgif_output : cannot add file");
  
  /*
  ** ヘッダ
  */
  /* 雛形部の作成 アスキーコードでGIF89a */
  model[0]=0x47; model[1]=0x49; model[2]=0x46; model[3]=0x38;
  model[4]=0x39; model[5]=0x61;
  foutarray(filename, model, 6, fp);  
  
  /*
  ** 論理画面記述子
  */
  /* 2byte : 論理画面の幅と高さ */
  fputc( LogicalScreenWidth & 0x00ff ,fp);
  fputc( LogicalScreenWidth >> 8 ,fp);
  
  fputc( LogicalScreenHeight & 0x00ff ,fp);
  fputc( LogicalScreenHeight >> 8 ,fp);
  /* 色構造パラメータ */
  fputc( 0xf7, fp);
  /* 背景色のカラーインデックス */
  fputc( cgifBackgroundColorIndex, fp);
  /* ピクセルのアスペクト比 0:情報なし */
  fputc( 0x00, fp);
  
  /*
  ** グローバルカラーテーブル
  */
  /* 基本16色 */
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
  
  /* 未使用部 */
  for (i = 0; i < 24*3; i++)
    fputc( 0x00, fp);
  
  /* 216色 */
  for (l1 = 0; l1 <= 0xff; l1+=0x33)
    for (l2 = 0; l2 <= 0xff; l2+=0x33)
      for (l3 = 0; l3 <= 0xff; l3+=0x33){
        fputc( l1, fp); fputc( l2, fp); fputc( l3, fp);
      }
  
  /*
  ** アプリケーション拡張ブロック
  ** cgifNumberOfIterationsが1の場合は飛ばす
  */
  if (cgifNumberOfIterations != 1){
    fputc( 0x21, fp); fputc( 0xff, fp); /* 固定 */
    fputc( 0xb, fp); /* ブロックのバイト数. 固定 */
    
    model[0]='N'; model[1]='E'; model[2]='T'; model[3]='S';
    model[4]='C'; model[5]='A'; model[6]='P'; model[7]='E';
    model[8]='2'; model[9]='.'; model[10]='0';
    foutarray(filename, model, 11, fp);
    
    fputc( 0x3, fp); /* サブブロック(下の3バイト)のバイト数. 固定 */
    fputc( 0x1, fp); /* 固定 */
    /* 2byte : 繰り返し回数 */
    fputc( cgifNumberOfIterations & 0x00ff ,fp);
    fputc( cgifNumberOfIterations >> 8 , fp);
    
    fputc( 0x00, fp); /* ブロック終了識別子. 固定値0 */
  }
  
  /*
  ** cgif_frameの数だけ
  ** Graphic Control Extention
  ** Image Block(イメージディスクリプタ + イメージデータ)
  ** の順に続ける
  */
  for ( i = 0; i < cgif_frame; i++){
    
    /* 
    ** グラフィック拡張ブロックGraphic Control Extention 
    */
    fputc(0x21,fp); /* 拡張ブロックであることを示す固定値 */
    /*このブロックがGraphic Control Extentionであることを示す固定値*/
    fputc(0xf9,fp);
    fputc(0x04,fp );/* ブロックサイズ.固定値 */
    /* 表示処理パラメータ(Packed Fields) */
    fputc( GraphicBlockp[i].PackedFields , fp);
    /* 2byte : 待機時間(Delay Time)(1/100秒 */
    fputc( GraphicBlockp[i].time & 0x00ff , fp);
    fputc( GraphicBlockp[i].time >> 8 , fp);
    
    /* 透明色のカラーインデックス(Transparent Color Index) */
    fputc( GraphicBlockp[i].TransparentIndex , fp);
    fputc(0x00,fp); /* ブロック終了識別子(Block Terminator) */
    
    /*
    ** イメージデータブロックImage Block
    */
    /* イメージ記述子 */
    fputc(0x2c,fp );
    /* 2byte : GIF画像全体に対する左端相対位置Image Left Position */
    fputc( ImageBlockp[i].left & 0x00ff , fp);
    fputc( ImageBlockp[i].left >> 8 , fp);
    /* 2byte : GIF画像全体に対する上端相対位置Image top Position */
    fputc( ImageBlockp[i].top & 0x00ff , fp);
    fputc( ImageBlockp[i].top >> 8 ,fp);
    /* 2byte : このイメージブロックの横幅Image Width */
    fputc( ImageBlockp[i].width & 0x00ff ,fp);
    fputc( ImageBlockp[i].width >> 8 , fp);
    /* 2byte : このイメージブロックの縦幅Image Width */
    fputc( ImageBlockp[i].height & 0x00ff , fp);
    fputc( ImageBlockp[i].height >> 8 , fp);
    /* 色構造パラメータは0 */
    fputc( 0x00 , fp);
    /* Local Color Tableは使用しないので 次はLzw Minimum Code Size
       256色では8 */
    fputc( 0x08 , fp);
    
    /* Block Size(イメージデータのバイト数)とイメージデータ */
    lzw_output( i, filename, fp);
    
    fputc(0x00,fp); /* ブロックの並びの終わりを表す.固定. */
    
  }
  fputc(0x3b,fp);/* Trailer:GIFデータストリームの終わりを表す.固定 */

  fclose(fp);
  return;
}

void lzw_output( int frame, char *filename, FILE *fp)
{
  /* 辞書作成部の定義 */
  cgifByte2 prefix[DICT_MAX];
  cgifByte2 suffix[DICT_MAX];
  /* cgif_image[frame][]をどこまで読んだか. 次に読む場所を指す */
  cgifByte4 image_p = 0;
  /* 次に辞書を作成する場所を指す */
  cgifByte2 dict_p = 0;
  /* 辞書に入れるデータ */
  cgifByte2 dict_index;
  /* cgif_image[frame][image_p]~[image_p+length]までが次の辞書に入る */
  cgifByte4 length;
  
  /* イメージデータ部の定義 */
  cgifByte4 buf = 0;
  cgifByte4 bufp = 0;
  
  /* 汎用の定義 */
  cgifByte2 i, end;
  
  /* cgif_image[frame][]全部を読むまでまわす */
  while (image_p < ImageBlockp[frame].size){
    
    /*
    ** イメージデータが1個だけの場合の別処理
    */
    if (image_p == ImageBlockp[frame].size - 1){
      
      /*
      ** イメージデータのバイト数を計算して出力
      */
      /* +3はクリアコードとサフィックスと終了コード分 */
      fputc( (cgifByte1)ceil((double)(bufp + 9.0*(0.0 + 3.0))/8.0) , fp);
      
      /*
      ** イメージデータを作成して出力
      */
      /* 最初にクリアコードをbufの先頭に挿入 */
      buf = (0x100 << bufp) | buf;
      bufp += 9;
      /* 吐き出し->挿入->吐き出しとする為のループ */
      for ( i = 0 ; i < 2; i++){
        /* bufに1byte以上溜まったらimage_dataに吐き出す */
        while (bufp >= 8){
          fputc( (cgifByte1)(0xff & buf) , fp);
          buf = buf >> 8;
          bufp -= 8;
        }
        if (i == 0){
          /* イメージデータをbufの先頭に挿入 */
          buf = (cgif_image[frame][image_p] << bufp) | buf;
          bufp += 9;
        }
      }
      break;
      
    }
    /* 例外処理終わり */
    
    /*
    ** 辞書(prefix)作成部
    */
    dict_p = 0; /* 辞書の初期化 */
    /* -1の意味はsuffix分. cgif_image[frame][]全部を読むまでまわす */
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
        error("In lzw_output : dict_pが大きすぎる値を指した");
      dict_p++;
    }
    image_p++; /* サフィックスの分をインクリメント */

    /*    
    for (i=0; i < dict_p; i++)
      printf("prefix[0x%x+0x102=0x%x]=0x%x suffix=0x%x\n"
             ,i,i+0x102,prefix[i],suffix[i]);
    */
    
    /*
    ** イメージデータのバイト数を計算して出力
    */
    /* gif_imageの最後だけは、終了コードが入るのと
       bufに途中まで入ったものを吐き出すことから場合分けが必要 */
    if (image_p < ImageBlockp[frame].size)
      /* +2はクリアコードとサフィックス分 */
      fputc( (cgifByte1)floor((double)(bufp + 9.0*(dict_p + 2))/8.0), fp);
    else
      /* +3はクリアコードとサフィックスと終了コード分 */
      fputc( (cgifByte1)ceil((double)(bufp + 9.0*(dict_p + 3))/8.0) , fp);
    
    /*
    ** イメージデータを作成して出力
    */
    /* まず最初にクリアコードをbufの先頭に挿入 */
    buf = (0x100 << bufp) | buf;
    bufp += 9;
    
    for ( i = 0, end = 0; i < dict_p || end != 2; i++){
      
      /* bufに1byte以上溜まったらimage_dataに吐き出す */
      while (bufp >= 8){
        fputc( (cgifByte1)(0xff & buf) , fp);
        buf = buf >> 8;
        bufp -= 8;
      }
      
      if (i < dict_p){ /* 通常こちらを実行*/
        /* prefix[i]をbufの先頭に挿入 */
        buf = (prefix[i] << bufp) | buf;
        bufp += 9;
        
        /* 以下は終了処理 */
      }else if (end == 0){ /* 上が終わったら最後のsuffixを代入して */
        /* suffix[dict_p-1]をbufの先頭に挿入 */
        buf = (suffix[dict_p-1] << bufp) | buf;
        bufp += 9;
        end = 1;
      }else /* for文を抜ける */
        end = 2;
      
    }
    
  }
  
  /* 終了コードを入れる */
  buf = (0x101 << bufp) | buf;
  bufp += 9;
  /* bufに1byte以上溜まったらimage_dataに吐き出す */
  while (bufp >= 8){
    fputc( (cgifByte1)(0xff & buf) , fp);
    buf = buf >> 8;
    bufp -= 8;
  }
  
  /* bufに残った余りを吐き出す */
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
  /* 引数のエラーチェック */
  if (frame < 0 || cgif_frame <= frame)
    error("In cgif_setImageBlock : frame(ページ番号)が範囲外");
  
  ImageBlockp[frame].left = left;
  ImageBlockp[frame].top = top;
  ImageBlockp[frame].width = width;
  ImageBlockp[frame].height = height;
  
  ImageBlockp[frame].size =
    (cgifByte4)ImageBlockp[frame].width * ImageBlockp[frame].height;
  free((void *)cgif_image[frame]); /* NULLか使っているはずなので解放 */
  cgif_image[frame] =
    (cgifByte1 *)malloc(sizeof(cgifByte1 *) * ImageBlockp[frame].size);
}

void cgif_setGraphicBlock( int TransparentFlag,
                           int UserInputFlag,
                           int DisposalMethod,
                           cgifByte2 time, int frame)
{
  /* 引数のエラーチェック */
  if (frame < 0 || cgif_frame <= frame)
    error("In cgif_setGraphicBlock : frame(ページ番号)が範囲外");
  if (TransparentFlag != 0)
    TransparentFlag = 1;
  if (UserInputFlag != 0)
    UserInputFlag = 1;
  if (DisposalMethod > 7 || DisposalMethod < 0)
    DisposalMethod = 0;
  
  /* PackedFieldsに各フラグをセット */
  DisposalMethod <<= 2;
  UserInputFlag <<= 1;
  GraphicBlockp[frame].PackedFields =
    DisposalMethod | UserInputFlag | TransparentFlag;
  
  GraphicBlockp[frame].TransparentIndex = cgifTRANSPARENT;
  GraphicBlockp[frame].time = time;
}

cgifByte2 cgif_color_to_index(cgifByte4 color)
{
  cgifByte4 c[3];/* c[2]:赤 c[1]:緑 c[0]:青 */
  int i;
  /* まず基本16色や透過色でないかチェック */
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
  if (0x1000000 <= color) /* 透過色の場合 */
    return GraphicBlockp[color - 0x1000000].TransparentIndex;
  
  /* RGBの成分毎に取り出す */
  c[0] = 0x0000ff & color;
  c[1] = (color >> 8) & 0x00ff;
  c[2] = color >> 16;
  
  for ( i = 0; i < 3; i++)
    /* WEBセーフカラーはRGBの各色を6段階に分ける.
       0%, 20% 40% 60% 80% 100%の6段階 */
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
  /* 引数のエラーチェック */
  if (x1 == x2 || y1 == y2)
    error("In cgif_create_window : ウインドウを作れません.");
  cgif_window.pt1.x = x1;
  cgif_window.pt1.y = y1;
  cgif_window.pt2.x = x2;
  cgif_window.pt2.y = y2;
}

cgifByte2 change_x( double x, int frame)
{
  /* エラーチェックしない */
  x = (x - cgif_window.pt1.x) / (cgif_window.pt2.x - cgif_window.pt1.x);
  x *= ImageBlockp[frame].width - 1;
  return rounding(x);
}

cgifByte2 change_y( double y, int frame)
{
  /* エラーチェックしない */
  y = (y - cgif_window.pt1.y) / (cgif_window.pt2.y - cgif_window.pt1.y);
  y *= ImageBlockp[frame].height - 1;
  return rounding(y);
}

int cgif_pset(double x, double y, cgifByte4 color, int frame)
{
  /* 引数のエラーチェック */
  if (frame < 0 || cgif_frame <= frame)
    error("In cgif_pset : frame(ページ番号)が範囲外");
  /* 点を打つ範囲外なら何もせずに関数を終了 */
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
  int e; /* ( (yの実数値-整数化したy) - 0.5 ) * 2*dx */
  cgifByte2 x,y; /* 点を打つ実際の値 */
  cgifByte2 x0,y0,x1,y1; /* 変換後の始点終点 */
  cgifByte2 dx,dy;
  int sx,sy,i;
  
  /* 引数のエラーチェック */
  if (frame < 0 || cgif_frame <= frame)
    error("In cgif__line : frame(ページ番号)が範囲外");
  
  x0 = change_x( x_0, frame); x1 = change_x( x_1, frame);
  y0 = change_y( y_0, frame); y1 = change_y( y_1, frame);
  
  sx = ( x0 < x1 ) ? 1 : -1; /* xをインクリメントしていく方向 */
  dx = ( x0 < x1 ) ? x1 - x0 : x0 - x1;/* x1からx0までの符号なしの距離 */
  sy = ( y0 < y1 ) ? 1 : -1; /* yをインクリメントさせる方向 */
  dy = ( y0 < y1 ) ? y1 - y0 : y0 - y1;/* y1からy0までの符号なしの距離 */
  
  x = x0; y = y0;
  
  /* 傾きの絶対値が1以下の場合 */
  if ( dy <= dx ) {
    e = -dx; /* e = (0 - 0.5) * 2*dx */
    for (i = 0; i <= dx; i++){
      /* (x0,y0)から(x1,y1)へ向かって点を打っていく */
      cgif_putpixel( x, y, cgif_color_to_index(color), frame);
      x += sx;
      e += 2*dy; /* e += dy/dx * 2*dx */
      /* 誤差が溜まったら吐き出す */
      if ( e >= 0 ){ /* e >= (0.5 - 0.5) * 2*dx */
        y += sy;
        e -= 2*dx; /* e -= 1 * 2*dx */
      }
    }
    
  /* 傾きの絶対値が1より大きい場合 */
  }else{
    e = -dy; /* e = (0 - 0.5) * 2*dy */
    for (i = 0; i <= dy; i++){
      /* (x0,y0)から(x1,y1)へ向かって点を打っていく */
      cgif_putpixel( x, y, cgif_color_to_index(color), frame);
      y += sy;
      e += 2*dx; /* e += dx/dy * 2*dy */
      /* 誤差が溜まったら吐き出す */
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
  unsigned char c1, c2; /* (x1,y1), (x2,y2)がどこにあるか */
  
  /* 引数のエラーチェック */
  if (frame < 0 || cgif_frame <= frame)
    error("In cgif_line : frame(ページ番号)が範囲外");
  
  c1 = cgif_looker(x1, y1);
  c2 = cgif_looker(x2, y2);
  
  min_pt.x = min(cgif_window.pt1.x, cgif_window.pt2.x);
  min_pt.y = min(cgif_window.pt1.y, cgif_window.pt2.y);
  max_pt.x = max(cgif_window.pt1.x, cgif_window.pt2.x);
  max_pt.y = max(cgif_window.pt1.y, cgif_window.pt2.y);
  
  while(1){
    if (c1 == 0 && c2 == 0) /* 始点終点共に描画領域内にある場合 */
      return cgif__line( x1, y1, x2, y2, color, frame);
    if (c1 & c2) /* この場合、線分が画面と重ならない */
      return 0;
    if (c2 == 0){ /* 終点が画面の内側なら始点と交換して、画面から外す */
      dswap(x1,x2); dswap(y1,y2); dswap(c1,c2);
    }
    /* 以下、画面から外れている終点を修正していく */
    /* はみ出していた線分は画面の4辺を延長する直線で少しずつ切られ
       多くとも4回でクリッピングが完了する */
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
  /* まず原点中心で、(a,0)から反時計回りに4分円を描くことを考える。
     真上か左上か真左のいずれに進むかをそれぞれ移動した結果の誤差
     e := (x/a)^2 + (y/b)^2 - 1 が最小となるように決める。
     真上(vertical)に移動 ev := (x/a)^2 + ((y+1)/b)^2 - 1
     左上(diagonal)に移動 ed := ((x-1)/a)^2 + ((y+1)/b)^2 - 1
     真左(left)に移動     el := ((x-1)/a)^2 + (y/b)^2 - 1
     err1 := 2*e - 2*(1/a^2)*x + 4*(1/b^2)*y + 1/a^2 + 2*(1/b^2)
     err2 := 2*e - 4*(1/a^2)*x + 2*(1/b^2)*y + 2*(1/a^2) + 1/b^2
     err3 := 2*e - 2*(1/a^2)*x + 2*(1/b^2)*y + 1/a^2 + 1/b^2
     e1 := ev^2 - ed^2 = (1/a^2)(2*x - 1) * err1
     e2 := ev^2 - el^2 = ((1/a^2)(2*x - 1) + (1/b^2)(2*y + 1)) * err3
     e3 := ed^2 - el^2 = (1/b^2)(2*y + 1) * err2
     とおくと、
     ・e1 < 0 and e2 < 0 なら真上に移動
     ・e3 < 0 and e1 >= 0 なら左上に移動
     ・e2 >= 0 and e3 >= 0 なら真左に移動
     x >= 1, y >= 0 であることに注意すると、
     e1,e2,e3の代わりにerr1,err3,err2の正負で判定できる。また、
     e3 = e1 - (1/b^2)(2*y + 1) < e1, e2 = e3 - (1/a^2)(2*x - 1) < e3
     より、e2 < e3 < e1 が必ず成り立つことから、最終的な判定は
     ・er1 := (a^2*b^2)*e1 < 0 なら真上に移動
     ・(a^2*b^2)*e1 >= 0, er2 := (a^2*b^2)*e2 < 0 なら左上に移動
     ・(a^2*b^2)*e2 >= 0 なら真左に移動
     ++yすると、er1(x,y) - er1(x,y-1) = 4*a^2*y + 2*a^2
     er2(x,y) - er2(x,y-1) = 4*a^2*y
     --xすると、er1(x,y) - er1(x+1,y) = -4*b^2*x
     er2(x,y) - er2(x+1,y) = -4*b^2*x + 2*b^2
     とer1,er2が変化することに注意して、
     er1(a,0) = -2*b^2*a + b^2 + 2*a^2
     er2(a,0) = -4*b^2*a + 2*b^2 + a^2
     から順次er1, er2を求める。 */
  
  cgifByte4 x, y, x0, y0, a, b;
  int er1, er2;
  cgifByte4 xmin, ymin, xmax, ymax;
  int s1draw[4],e1draw[4];/*0:完全に入らない, 1:完全に入る, 2:一部入る*/
  int s2draw[4],e2draw[4];
  cgifByte4 sx, sy, ex, ey; /* 円弧の開始座標、終了座標 */
  double th_max, th_min, temp;
  int i;

  /*
  ** cgif_windowによる上下反転を角度radian_s,radian_eを変化させて実行
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
  ** radian_s, radian_eを標準形
  ** (0 <= radian_s < 2*PI, 0 <= radian_e - radian_s <= 2*PI)に直す
  */
  /* radian_s <= radian_e にする */
  if (radian_e < radian_s) dswap(radian_e, radian_s);

  /* 2*PI <= radian_e - radian_s の時(完全な円)の別処理 */
  if (2.0*PI <= radian_e - radian_s)
     { radian_s = 0.0; radian_e = 2.0*PI;}
  
  /* 0 <= radian_s にする */
  if (radian_s < 0)
    for(; radian_s < 0; radian_s += 2.0*PI, radian_e += 2.0*PI);
  
  /* radian_s < 2*PI にする */
  if (2.0*PI <= radian_s){
    temp = floor(radian_s/(2.0*PI));
    radian_s -= temp*(2.0*PI); radian_e -= temp*(2.0*PI);
  }
  
  /*
  ** 各々の4分円の描画範囲のタイプを調べ、
  ** s1draw[],e1draw[],s2draw[],e2draw[]にタイプを格納
  */
  for( i = 0; i < 4; i++){
    /* 各々の4分円の中での最小角度、最大角度を求める */ 
    th_min = (PI/2.0) * (double)i;
    th_max = (PI/2.0) * (double)(i+1);
    
    /*
      まず以下の条件を満たす範囲は必ず描画。s1draw[],e1draw[]に格納
    */
    /* 描画開始範囲s1draw[4]の作成 */
    if (radian_s <= th_min)
      s1draw[i] = 1; /* 完全に入る */
    else if (radian_s <= th_max) /* th_min < radian_s <= th_max の場合 */
      s1draw[i] = 2; /* 一部入る */
    else /* th_max < radian_s の場合 */
      s1draw[i] = 0; /* 完全に入らない */

    /* 描画終了範囲e1draw[4]の作成 */
    if (th_max <= radian_e)
      e1draw[i] = 1; /* 完全に入る */
    else if (th_min <= radian_e) /* th_min <= radian_e < th_max の場合 */
      e1draw[i] = 2; /* 一部入る */
    else /* radian_e < th_min の場合 */
      e1draw[i] = 0; /* 完全に入らない */
    
    /*
      加えてradian_eが(2*PI,4*PI)の時、以下の条件を満たす範囲も描画。
      s2draw[],e2draw[]に格納
    */
    /* 描画開始範囲e2draw[4]の作成(s2draw[4]は自明) */
    if (th_min < radian_e - 2.0*PI){ /* <= から変更 */
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
  ** 初期化(cgif_putpixelで直接描く整数座標に変換)
  */
  /* イメージに書き込む中心座標を求める */
  x0 = change_x(x_0, frame); y0 = change_y(y_0, frame);
  
  /*
    cgif_create_windowによる伸縮を考慮した
    最終的にイメージに書き込むx軸方向の半径a, y軸方向の半径bを求める
  */
  temp = (double)ImageBlockp[frame].width
    /(cgif_window.pt2.x - cgif_window.pt1.x);
  a = ABS(temp * radius_w);
  temp = (double)ImageBlockp[frame].height
    /(cgif_window.pt2.y - cgif_window.pt1.y);
  b = ABS(temp * radius_h);
  
  /* 円弧開始点(sx,sy)、円弧終了点(ex,ey)を求める */
  sx = rounding((double)a * cos(radian_s)) + x0;
  sy = rounding((double)b * sin(radian_s)) + y0;
  ex = rounding((double)a * cos(radian_e)) + x0;
  ey = rounding((double)b * sin(radian_e)) + y0;
  
  /* 開始点(x=a,y=0)の各々の値を求める */
  x = a;
  y = 0;
  er1 = -2*b*b*a + b*b + 2*a*a; /* (x=a,y=0)時のer1 */
  er2 = -4*b*b*a + 2*b*b + a*a; /* (x=a,y=0)時のer2 */
  xmin = x0 - x; ymin = y0 - y; xmax = x0 + x; ymax = y0 + y;
  
  /*
  ** 4分円に分けて描画
  */
  while ( x >= 0 ) { /* x = 0の時、点だけ描いて下のbreakで抜ける */
    /* s1draw[],e1draw[]で指定した範囲の描画 */
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
    
    /* s2draw[],e2draw[]で指定した範囲の描画 */
    if (e2draw[0] == 1 || (e2draw[0] == 2 && ex <= xmax && ymax <= ey))
      cgif_putpixel( xmax, ymax, cgif_color_to_index(color), frame);

    if (e2draw[1] == 1 || (e2draw[1] == 2 && ex <= xmin && ey <= ymax))
      cgif_putpixel( xmin, ymax, cgif_color_to_index(color), frame);

    if (e2draw[2] == 1 || (e2draw[2] == 2 && xmin <= ex && ey <= ymin))
      cgif_putpixel( xmin, ymin, cgif_color_to_index(color), frame);

    if (e2draw[3] == 1 || (e2draw[3] == 2 && xmax <= ex && ymin <= ey))
      cgif_putpixel( xmax, ymin, cgif_color_to_index(color), frame);
    
    if (x == 0) break; /* x = 0を描いてから抜ける */
    if ( er1 < 0 ) { /* 真上に移動 */
      y++;
      er1 += 4*a*a*y + 2*a*a;
      er2 += 4*a*a*y;
      ymin = y0 - y; ymax = y0 + y;
    } else if ( er2 >= 0 ) { /* 真左に移動 */
      x--;
      er1 -= 4*b*b*x;
      er2 -= 4*b*b*x - 2*b*b;
      xmin = x0 - x; xmax = x0 + x;
    } else { /* 左上に移動 */
      x--;
      y++;
      er1 += 4*a*a*y + 2*a*a - 4*b*b*x;
      er2 += 4*a*a*y - 4*b*b*x - 2*b*b;
      xmin = x0 - x; ymin = y0 - y; xmax = x0 + x; ymax = y0 + y;
    }
  }
  return 0; /* 今のところ常に 0 */
}

long cgif_point( double x, double y, int frame)
{
  cgifByte4 temp;
  /* 引数のエラーチェック */
  if (frame < 0 || cgif_frame <= frame)
    error("In cgif_point : frame(ページ番号)が範囲外");
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
