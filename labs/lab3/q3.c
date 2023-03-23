//Write a program to read English text to end-of-data (type control-D to indicate end of data at a terminal, see below for detecting it), and print a count of word lengths, i.e. the total number of words of length 1 which occurred, the number of length 2, and so on.
//Define a word to be a sequence of alphabetic characters. You should allow for word lengths up to 25 letters.

#include <stdio.h>

int main(){
    char ch;
    int c=0,arr[25];
    for (int i=0;i<25;i++){
        arr[i]=0;
    }
    printf("enter text: ");
    while( scanf( "%c", &ch ) == 1 ){
        if (ch==' ' || ch=='\t' || ch=='\n'){
            arr[c-1]++;
            c=-1;
        }
        c++;
    }
    for (int i=0;i<25;i++){
        printf("length %d : %d occurences\n",i+1,arr[i]);
    }
    return 0;
}