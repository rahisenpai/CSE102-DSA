//Write a program to read a number of units of length (a float) and print out the area of a circle of that radius. Assume that the value of pi is 3.14159 (an appropriate declaration will be given you by ceilidh - select setup).
//Your output should take the form: The area of a circle of radius ... units is .... units.
//If you want to be clever, and have looked ahead in the notes, print the message Error: Negative values not permitted. if the input value is negative.

#include <stdio.h>

int main(){
    float pi=3.14159, r;
    printf("enter radius: ");
    scanf("%f",&r);
    if (r < 0){
        printf("Error: Negative values not permitted");
    } else{
        float a=pi*r*r;
        printf("the area of a circle of radius %f units is %f units",r,a);
    }

    return 0;
}