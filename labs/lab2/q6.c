//Write a program to read in numbers until the number -999 is encountered. The sum of all number read until this point should be printed out.

#include <stdio.h>

int main(){
    int x,sum=0;
    do{
        printf("enter: ");
        scanf("%d",&x);
        sum+=x;
    }
    while (x!=-999);

    printf("\nsum: %d\n",sum+999);   
    
    return 0;
}