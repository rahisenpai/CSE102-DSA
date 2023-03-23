//It's rates of pay again!
//Loop performing the following operation in your program:
//Read two integers, representing a rate of pay (pence per hour) and a number of hours. Print out the total pay, with hours up to 40 being paid at basic rate, from 40 to 60 at rate-and-a-half, above 60 at double-rate. Print the pay as pounds to two decimal places.
//Terminate the loop when a zero rate is encountered. At the end of the loop, print out the total pay.
//The code for computing the pay from the rate and hours is to be written as a function.

#include <stdio.h>

float fun(int r, int h){
    if(h>=40){
        if (h>=60){
            return ((40*r + 20*1.5*r + (h-60)*2*r)/100.0);
        }
        else {
            return ((40*r + (h-40)*1.5*r)/100.0);
        }
    }
    else {
        return ((h*r)/100.0);
    }
}

int main(){
    int rate=-1,hours;
    float sum=0,pay;
    while (rate!=0){
        printf("enter rate and hours: ");
        scanf("%d %d",&rate,&hours);
        if (rate!=0){
            pay = fun(rate,hours);
            printf("Pay at %d pence/hr for %d hours is %.2f pounds\n\n",rate,hours,pay);
            sum+=pay;
        }
    }
    printf("\nTotal pay is %.2f pounds\n",sum);
    return 0;
}