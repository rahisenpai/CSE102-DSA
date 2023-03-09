//Input and output your name, address and age to an appropriate structure.

#include <stdio.h>

int main(){
    int age;
    char name[20],address[100];
    printf("enter name: ");
    gets(name);
    printf("enter address: ");
    gets(address);
    printf("enter age: ");
    scanf("%d",&age);

    printf("\nname is ");
    puts(name);
    printf("age is %d\naddress is ",age);
    puts(address);

    return 0;
}