//Write a program to read two characters, and print their value when interpreted as a 2-digit hexadecimal number. Accept upper case letters for values from 10 to 15.

#include <stdio.h>

int convert(char x){
    if (x=='A')
        return 10;
    else if (x=='B')
        return 11;
    else if (x=='C')
        return 12;
    else if (x=='D')
        return 13;
    else if (x=='E')
        return 14;
    else if (x=='F')
        return 15;
    else if (x=='0')
        return 0;
    else if (x=='1')
        return 1;
    else if (x=='2')
        return 2;
    else if (x=='3')
        return 3;
    else if (x=='4')
        return 4;
    else if (x=='5')
        return 5;
    else if (x=='6')
        return 6;
    else if (x=='7')
        return 7;
    else if (x=='8')
        return 8;
    else if (x=='9')
        return 9;
}

int main(){
    char a,b;
    printf("Enter: ");
    scanf("%c%c",&a,&b);
    //printf("%c %c\n",a,b);
    int m=convert(a);
    int n=convert(b);
    //printf("%d %d\n",m,n);
    printf("%d\n",m*16+n);
    return 0;
}