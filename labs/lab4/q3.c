//Write a C program to read through an array of any type using pointers. Write a C program to scan through this array to find a particular value.

#include <stdio.h>

int main(){
    int n,check=0,arr[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int *p = arr;
    printf("enter value: ");
    scanf("%d",&n);
    for (int i=0;i<16;i++){
        if (n==*(p+i)){
            printf("value is in array at index %d\n",i);
            check=1;
        }
    }
    if (check==0)
        printf("value is not in array");
    return 0;
}