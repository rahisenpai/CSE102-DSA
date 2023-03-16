//Read a positive integer value, and compute the following sequence: If the number is even, halve it; if it's odd, multiply by 3 and add 1. Repeat this process until the value is 1, printing out each value. Finally print out how many of these operations you performed.
//If the input value is less than 1, print a message containing the word Error and perform an exit( 0 );

#include <stdio.h>

int main(){
    int n,count=0;
    printf("enter: ");
    scanf("%d",&n);
    if (n<1){
        printf("Error\n");
        return 0;
    }
    printf("\nInitial value is %d\n",n);
    while (n!=1){
        if (n%2==0)
            n/=2;
        else
            n = n*3+1;
        count++;
        if (n!=1)
            printf("Next value is %d\n",n);
    }
    printf("Final value 1, number of steps %d",count);

    return 0;
}