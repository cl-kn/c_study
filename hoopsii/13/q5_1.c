#include <stdio.h>

//***************************************************
/**
 * ��13�� �|�C���^
 * ���K���F
 * (1) �z��(int, double, char)���e�X5�p�ӂ��A���ꂼ��̔z��̃A�h���X�̕ω��̗l�q���o��
 */
//***************************************************

int main(void)
{
    int int_array[5], *p_int, i;
    double double_array[5], *p_double;
    char char_array[5], *p_char;

    p_int = int_array;
    p_double = double_array;
    p_char = char_array;

    for (i = 0; i < 5; i++)
    {
        printf("p_int[%d]_address = %d\n", i, p_int + i);
    }
    for (i = 0; i < 5; i++)
    {
        printf("p_double[%d]_address = %d\n", i, p_double + i);
    }
    for (i = 0; i < 5; i++)
    {
        printf("p_char[%d]_address = %d\n", i, p_char + i);
    }

    return 0;
}