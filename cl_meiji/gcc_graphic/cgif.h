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
  著作権者もコントリビューターも、事由のいかんを問わず、 損害発生の原因いかんを問わず、
  かつ責任の根拠が契約であるか厳格責任であるか（過失その他の）不法行為であるかを問わず、
  仮にそのような損害が発生する可能性を知らされていたとしても、
  本ソフトウェアの使用によって発生した（代替品または代用サービスの調達、使用の喪失、
  データの喪失、利益の喪失、業務の中断も含め、またそれに限定されない）直接損害、間接損害、
  偶発的な損害、特別損害、懲罰的損害、または結果損害について、
  一切責任を負わないものとします。
*/

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

/*
** GIF Header
*/
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


int cgif_frame; /* アニメーションの総ページ数 */
/* cgif_image[frame][ ImageBlockp[frame].size ]をmallocで作成 */
cgifByte1** cgif_image;

/* 初期化：引数はgif画像の大きさ こま数 繰り返し回数*/
void cgif_init(cgifByte2 width,cgifByte2 height, int frame,int iteration);

/* gif画像に点を打つ
   返り値 : 点を打ったなら1, 範囲外なら0 */
int cgif_putpixel(cgifByte2 x, cgifByte2 y,
                  cgifByte1 color_index, int frame);

/* cgif_output:標準出力にgifファイルとして出力 */
void cgif_output(char *filename);

/* frame番目のイメージをmat(2次元)にコピー(メモリー確保のチェック無し) */
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
                          int UserInputFlag,/*ユーザーの入力を必要とするか*/
                          int DisposalMethod,/*画像を表示し終えた後の処理*/
                          cgifByte2 time, int frame);

/* RGB表示をグローバルカラーテーブルのインデックスに変える
   0x1000000 ~ (0x1000000 + cgif_frame-1)が透明色 */
cgifByte2 cgif_color_to_index(cgifByte4 color);

/* ウインドウの(x1,y1):左上の座標, (x2,y2):右上の座標
   何回でも変更可 */
void cgif_create_window(double x1, double y1, double x2, double y2);

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
