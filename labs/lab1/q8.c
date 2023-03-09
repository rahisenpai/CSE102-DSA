//Given as input a floating (real) number of centimeters, print out the equivalent number of feet (integer) and inches (floating, 1 decimal), with the inches given to an accuracy of one decimal place.
//Assume 2.54 centimeters per inch, and 12 inches per foot.
//If the input value is 333.3, the output format should be:
//333.3 centimeters is 10 feet 11.2 inches.

#include <stdio.h>

int main(){
    float cm,in;
    printf("enter: ");
    scanf("%f",&cm);
    in=cm/2.54;
    int ft=in/12;
    in -= ft*12;
    printf("%f centimeters is %d feet %.1f inch(es)\n",cm,ft,in);

    return 0;
}