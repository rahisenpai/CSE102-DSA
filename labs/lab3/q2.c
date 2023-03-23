//Read ordinary text a character at a time from the program's standard input, and print it with each line reversed from left to right. Read until you encounter end-of-data.

#include <stdio.h>

int main(){
    int k=1,i=0;
    char ch, arr[100][25];
    printf("enter text: ");
    while( scanf( "%c", &ch ) == 1){
        if (ch==' ' || ch=='\t' || ch=='\n'){
            arr[i][0]=ch;
            arr[i][k]='\0';
            k=1;
            i++;
        }
        else{
        arr[i][k]=ch;
        k++;
        }
        if (ch=='\n'){
            break;
        }
    }
    //printf("%s\n",arr[1]);
    printf("the output is:");
    for (int j=i-1; j>=0; j--){
        printf("%s",arr[j]);
    }
    return 0;
}