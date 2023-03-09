//Write a program to read a "float" representing a number of degrees Celsius, and print as a "float" the equivalent temperature in degrees Fahrenheit. Print your results in a form such as 100.0 degrees Celsius converts to 212.0 degrees Fahrenheit.

#include <stdio.h>

int main(){
    float c,f;
    printf("enter temp(C): ");
    scanf("%f",&c);
    f = c*(9/5) + 32;
    printf("temp(F): %f\n",f);
    
    return 0;
}