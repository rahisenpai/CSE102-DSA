//Read in three values representing respectively a capital sum (integer number of pence), a rate of interest in percent (float), and a number of years (integer).
//Compute the values of the capital sum with compound interest added over the given period of years. Each year's interest is calculated as interest = capital * interest_rate / 100; and is added to the capital sum by capital += interest;
//Print out money values as pounds (pence / 100.0) accurate to two decimal places.
//Print out a floating value for the value with compound interest for each year up to the end of the period.

#include <stdio.h>

int main(){
    int time;
    float sum,rate,interest;
    printf("enter capital sum: ");
    scanf("%f",&sum);
    printf("enter rate of interest: ");
    scanf("%f",&rate);
    printf("enter time: ");
    scanf("%d",&time);
    
    printf("\nOriginal sum %.2f at  %f percent for %d years\n",sum,rate,time);
    for (int i=1;i<=time;i++){
        interest=sum*rate/100;
        sum+=interest;
        printf("\n%d %.2f %.2f",i,interest,sum);
    }

    return 0;
}