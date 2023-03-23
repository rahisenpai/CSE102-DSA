//Write a function ``replace'' which takes a pointer to a string as a parameter, which replaces all spaces in that string by minus signs, and delivers the number of spaces it replaced.

#include <stdio.h>
#include <string.h>

int replace(char *s){
    int n=0,l=strlen(s);
    for (int i=0; i<l; i++){
        if (s[i]==' '){
            s[i]='-';
            n++;
        }
    }
    return n;
}

int main(){
    int n;
    char x[100];
    char *ptr = x;
    printf("enter string: ");
    fgets(x,100,stdin);
    n = replace(ptr);
    printf("\nmodified string: %s",x);
    printf("number of spaces: %d", n);
    return 0;
}