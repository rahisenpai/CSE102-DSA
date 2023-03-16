//Read an integer value. Assume it is the number of a month of the year; print out the name of that month.

#include <stdio.h>

int main(){
    int a;
    printf("enter: ");
    scanf("%d",&a);
    if (a==1)
        printf("january");
    if (a==2)
        printf("february");
    if (a==3)
        printf("march");
    if (a==4)
        printf("april");
    if (a==5)
        printf("may");
    if (a==6)
        printf("june");
    if (a==7)
        printf("july");
    if (a==8)
        printf("august");
    if (a==9)
        printf("september");
    if (a==10)
        printf("october");
    if (a==11)
        printf("november");
    if (a==12)
        printf("december");  

    return 0;
}