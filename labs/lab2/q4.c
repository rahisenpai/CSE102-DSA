//Write a program which reads two integer values. If the first is less than the second, print the message up. If the second is less than the first, print the message down If the numbers are equal, print the message equal If there is an error reading the data, print a message containing the word Error and perform exit( 0 );

#include <stdio.h>

int main(){
    int a,b,check1,check2;
    printf("Enter first number: ");
    check1=scanf("%d",&a);
    if (check1==0){
        printf("Error");
        return 0;
    }
    printf("Enter second number: ");
    check2=scanf("%d",&b);
    if (check2==0){
        printf("Error");
        return 0;
    }

    if (a<b)
        printf("up");
    else if (a>b)
        printf("down");
    else
        printf("equal");

    return 0;
}