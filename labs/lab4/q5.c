//Write a program that takes three variable (a, b, b) in as separate parameters and rotates the values stored so that value a goes to be, b, to c and c to a.

#include <stdio.h>

int main(){
    int a,b,c;
    int *p1=&a, *p2=&b, *p3=&c;
    printf("enter values for a,b,c (space separated): ");
    scanf("%d %d %d",&a,&b,&c);
    int temp;
    temp=*p3;
    *p3=*p2;
    *p2=*p1;
    *p1=temp;
    printf("new values are %d %d %d",a,b,c);
    return 0;
}