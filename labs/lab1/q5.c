//Write a program to print several lines (such as your name and address). You may use either several printf instructions, each with a newline character in it, or one printf with several newlines in the string.

#include <stdio.h>

int main(){
    char str[100] = "this program can print multiple lines\nname\nage\ncontact\ncollege";
    printf("%s\n",str);

    return 0;
}