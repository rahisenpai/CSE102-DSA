//Write a program to read a positive integer at least equal to 3, and print out all possible permutations of three positive integers less or equal to than this value.

#include <stdio.h>
// 123, 132, 213, 231, 312, 321
int main(){
    int arr[3];
    printf("enter number(n>=3): ");
    scanf("%d",&arr[0]);
    arr[1]=arr[0]-1;
    arr[2]=arr[0]-2;
    for(int i=0; i<=2; i++){
        for(int j=0; j<=2; j++){
            for(int k=0; k<=2; k++){
                if (i!=j && j!=k && k!=i){
                    printf("%d %d %d\n",arr[i],arr[j],arr[k]);
                }
            }
        }
    }

    return 0;
}