#include <stdio.h>
#include <time.h>

#ifndef Boolean /* Boolean が定義されていなかったら */
#define Boolean int
#endif

#ifndef TRUE /* TRUE が定義されていなかったら */
#define TRUE 1 /* TRUEを1に置き換え */
#endif

#ifndef FALSE /* FALSE が定義されていなかったら */
#define FALSE 0 /* FALSEを0に置き換え */
#endif

//関数プロトタイプ
Boolean checkPrime(int num);
void printPrime(long primeNumber);

int main()
{

    long prime = 100000;
    printPrime(prime);
    return 0;
}

Boolean checkPrime(int num)
{

    if (num == 0 || num == 1)
    {
        return FALSE;
    }

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return FALSE;
        }
    }
    return TRUE;
}

void printPrime(long primeNumber)
{

    int count = 0;
    long cpu_time;
    double sec;

    for (int i = 0; i < primeNumber; i++)
    {

        if (checkPrime(i) == FALSE)
        {
            // code
        }
        else
        {
            count++;
        }
    }

    cpu_time = clock();
    sec = (double)cpu_time / CLOCKS_PER_SEC;

    printf("%ld prime = %d \n", primeNumber, count);
    printf("%fsec\n", sec);
}