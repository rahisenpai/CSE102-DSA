//Write a program to read two integers with the following significance.
//The first integer value represents a time of day on a 24 hour clock, so that 1245 represents quarter to one mid-day, for example.
//The second integer represents a time duration in a similar way, so that 345 represents three hours and 45 minutes.
//This duration is to be added to the first time, and the result printed out in the same notation, in this case 1630 which is the time 3 hours and 45 minutes after 12.45.
//Typical output might be Start time is 1415. Duration is 50. End time is 1505.
//There are a few extra marks for spotting.
//Start time is 2300. Duration is 200. End time is 100.

#include <stdio.h>

int main(){
    int i1,i2,outtime;
    printf("enter first time: ");
    scanf("%d",&i1);
    printf("enter second time: ");
    scanf("%d",&i2);
    int h1=i1/100,m1=i1%100,h2=i2/100,m2=i2%100;
    int m=m1+m2,h=h1+h2;
    if (m>=60){
        h += m/60;
        m%=60;
    }
    if (h>=24){
        h%=24;
    }
    outtime=h*100+m;
    printf("Start time is %d. Duration is %d. End time is %d.\n",i1,i2,outtime);

    return 0;
}