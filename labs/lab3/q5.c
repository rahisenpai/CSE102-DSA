//Write a program which will read in the source of a C program from its standard input, and print out the following statistics for the program (all as integers).
// Total lines                     126
// Total blank lines               3
// Total characters                3897
// Total spaces                    1844
// Total leading spaces            1180
// Total comments                  7
// Total chars in comments         234
// Total number of identifiers     132
// Total length of identifiers     606
// Total indenting errors          2

#include <stdio.h>

int main(){
    int lines=0,blines=0,characters=0,spaces=0,lspaces=0;
    int comments=0,comchar=0,identifier=0,idenchar=0;
    int checkline=0;
    float checkcom=0;
    char ch;
    while(ch=getchar(), ch>=0 ){
        if (ch=='\n'){
            if (checkline==0){
                blines++;
            }
            else{
                lines++;
                checkline=0;
            }
        }
        if ((ch=='\t' || ch==' ') && checkline==0){
            if (ch==' '){
                lspaces++;
            } else {
                lspaces+=4;
            }
        }
        if (ch!=' ' && ch!='\t' && ch!='\n'){
            checkline=1;
            characters++;
        }
        if ((ch=='\t' || ch==' ') && checkline==1){
            if (ch==' '){
                spaces++;
            } else {
                spaces+=4;
            }
        }
        if (checkcom==0.1 && ch!='*'){
            checkcom=0;
        }
        if (ch=='/'){
            checkcom=0.1;
        }
        if ((ch=='*') && checkcom==0.1){
            comments++; checkcom=1;
        }
        if ((ch!=' ' && ch!='\t' && ch!='\n') && checkcom!=0){
            if (ch=='/' && checkcom==0.5){
                comchar--;
                checkcom=0;
            }
            if (ch!='/' && checkcom==0.5){
                comchar++;
                checkcom=1;
            }
            if (ch=='*'){
                checkcom=0.5;
            }
            if (checkcom == 1){
                comchar++;
            }
        }
    }
    printf("total lines %d\ntotal blank lines %d\n", lines,blines);
    printf("total characters %d\ntotal spaces %d\ntotal leading spaces %d\n", characters,spaces,lspaces);
    //printf("total comments %d\ntotal chars in comments %d\n", comments,comchar);
    return 0;
}