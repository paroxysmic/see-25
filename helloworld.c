#include<stdio.h>
#include<string.h>
int main()
{
    char name[50];
    printf("type your name here\n");
    scanf("%s", &name);
    printf("%s%s%s", "hi ", name, "!");
    return 0;
}

