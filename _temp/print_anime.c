//***************************************************
/** アニメもどき */
//***************************************************

#include <stdio.h>
#include <windows.h>
#include <conio.h>

int main(void)
{
    int i;

    char * animeText[] ={

        "    |||||\n",
        "   ||-_-||\n",
        "   ||   ||\n",
        "     |||\n",
        "  ==m===w==////\n",
        "    |||||  ////\n",
        "   |||||||\n",
        "   |||||||\n",
        "  |||||||||\n",
        " ～～～～～～～\n",
        " ～～～～～～～\n"
    };

    for (i = 0; ; i++){
        printf("%s\r",animeText[i%11]);
        Sleep(100);

        if (_kbhit()) {
            break;
        }
    }
    return 0;
}
