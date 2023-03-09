//Write a program that works out the largest and smallest values from a set of 10 inputted numbers.

#include<stdio.h>

int main(){
    int arr[10];
    for (int i = 0; i < 10; i++){ 
        printf("enter: ");
        scanf("%d",&arr[i]);
    }

    int max=arr[0],min=arr[0];
    for (int i = 1; i < 10; i++){
        if (arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }
    printf("min:%d, max:%d\n",min,max);

    return 0;
}