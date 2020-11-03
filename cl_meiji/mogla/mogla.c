#include <stdio.h>
#include "mogla.f" /* ���̍s��Y��Ȃ����� */

void graphic(void)
{
	double x1, x2, x3, y1, y2, y3;

	gl_clearbuffer();

	x1 = -200.0;
	y1 = 0.0;
	x2 = 0.0;
	y2 = 200.0;

	x3 = (x1 + x2) / 2.0;
	y3 = (y1 + y2) / 2.0;

	line(x1, y1, x2, y2, 10);
	line(0.0, 0.0, x3, y3, 12);
	line(0, 0, 320, 0, 5);

	box(-100, -100, 100, 100, 2);

	circle(0, 0, 100, 3);

	gl_flush();
}

void main()
{
	gl_int(640, 480); /*  640*480�s�N�Z���̃E�C���h�E���J��  */

	gl_displayfunc(graphic); /* �`��֐��̌Ăяo�� */

	gl_loop(); /* �ĕ`�揈��  */
}
