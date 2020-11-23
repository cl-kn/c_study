#include <stdio.h>

typedef struct person
{
    char *name;
    int age;
} person;

void grow_up(person *p)
{
    // (*p).age++;
    p->age++;
}

void rename_person(person *p, char *new_name)
{
    p->name = new_name;
}

void print_person(person p)
{
    printf("name:%s,age:%d\n", p.name, p.age);
}

int main()
{
    person takao = {"takao", 21};
    person *takao_p = &takao;
    grow_up(takao_p);
    rename_person(takao_p, "tako");
    print_person(takao);
}