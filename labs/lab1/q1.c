//Input two numbers and work out their sum, average and sum of the squares of the numbers.

#include<stdio.h>

int main(){
    int a,b;
    printf("enter first number: ");
    scanf("%d",&a);
    printf("enter second number: ");
    scanf("%d",&b);
    
    printf("sum is %d\n",a+b);
    printf("average is %f\n",(a+b)/2.0);
    printf("sum of squares is %d\n",a*a+b*b);

    return 0;
}