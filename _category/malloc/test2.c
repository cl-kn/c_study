//***************************************************
/** 課題6-1 動的メモリ確保*/
//***************************************************

#include <stdio.h>
#include <stdlib.h>
#define DATA_SIZE 5

double result[DATA_SIZE];
void *returnData(double *);

int main(void)
{
    // double data[DATA_SIZE] = {1, 2, 3, 4, 5};
    // double data[DATA_SIZE] = {1.5, 2.2, 3.3, 4.4, 5.5};
    double data[DATA_SIZE];
    int i;

    for (i = 0; i < DATA_SIZE; i++)
    {
        printf(">> ");
        scanf("%lf", &data[i]);
    }

    returnData(data);

    for (i = 0; i < DATA_SIZE; i++)
    {
        printf("result[%d] = %5.2f\n", i, result[i]);
    }

    return 0;
}

void *returnData(double *data)
{
    double *ip = (double *)malloc(DATA_SIZE * sizeof(double));
    int i;

    for (i = 0; i < DATA_SIZE; i++)
    {
        result[i] = data[i] * data[i];
    }
    return result;
}