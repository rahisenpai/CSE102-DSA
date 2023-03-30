//Write a program to find the number of times that a given word(i.e. a short string) occurs in a sentence (i.e. a long string!).
//Read data from standard input. The first line is a single word, which is followed by general text on the second line. Read both up to a newline character, and insert a terminating null before processing.

#include <stdio.h>
#include <string.h>

int main(){
    char word[10],text[100];
    char *p1 = word, *p2 = text; 
    int n=0,l,l1,check=1;
    printf("enter word: ");
    fgets(word,10,stdin);
    printf("enter text: ");
    fgets(text,100,stdin);
    l=strlen(word)-1;
    word[l]='\0';
    text[strlen(text)-1]='\0';
    while(*p2 != '\0'){
        if (*p2 == *p1){
            for (int i=1;i<l;i++){
                if (*(p2+i) != *(p1+i)){
                    check=0;
                }
            }
            if (check == 1){
                n++;
            } else {
                check=1;
            }
        }
        p2++;
    }
    printf("\nThe word is \"%s\".\nThe sentence is \"%s\".\nThe word occurs %d times.",word,text,n);
    return 0;
}