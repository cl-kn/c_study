//***************************************************
/**  */
//***************************************************

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char cmd[32];
    char tmp[8];

    strcpy(cmd, "ls");

    if ((argc > 1) && (argv[1] != NULL))
    {
        strcpy(tmp, argv[1]);
    }

    system(cmd);

    return 0;
}