#include <stdio.h>

typedef struct person
{
    int age;
    char *name;
    // メソッド 関数のポインタを使って実現する
    void (*grow)(struct person *, int);
} person;

void grow(person *self, int year)
{
    self->age += year;
}

int main()
{
    person takao = {21, "takao", grow};
    takao.grow(&takao, 3);
    printf("%s:%d\n", takao.name, takao.age);
}