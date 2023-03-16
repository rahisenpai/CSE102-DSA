//Read a file of English text, and print it out one word per line, all punctuation and non-alpha characters being omitted.
//For end-of-data, the program loop should read until "getchar" delivers a value <= 0. When typing input, end the data by typing the end-of-file character, usually control-D. When reading from a file, "getchar" will deliver a negative value when it encounters the end of the file.

#include <stdio.h>

int main(){
    FILE *f;
    char ch;
    f = fopen("test.txt", "r");
    while(ch!=EOF){
        ch=fgetc(f);
        if (ch==' ' || ch=='\n'){
            printf("\n");
        }
        else if ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
            printf("%c",ch);
        }
    }

    fclose(f);
    return 0;
}