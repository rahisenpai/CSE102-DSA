//Write a program to read in 10 numbers and compute the average, maximum and minimum values.

#include <stdio.h>

int main(){
    int x,y=1,max,min,sum=0;
    while (y<=10){
        printf("enter: ");
        scanf("%d",&x);
        sum+=x;
        if (y==1){
            max=x;
            min=x;
        }
        else{
            if (x>max)
                max=x;
            else if (x<min)
                min=x;
        }
        y++;
    }
    printf("average is %f\n",sum/10.0);
    printf("max is %d\n",max);
    printf("min is %d\n",min);
    return 0;
}