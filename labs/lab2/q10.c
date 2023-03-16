//Write a program to count the vowels and letters in free text given as standard input. Read text a character at a time until you encounter end-of-data.
//Then print out the number of occurrences of each of the vowels a, e, i, o and u in the text, the total number of letters, and each of the vowels as an integer percentage of the letter total.

#include <stdio.h>

// ctrl-z to give eof as input
int main(){
    int ca,ce,ci,co,cu,crest;
    ca=ce=ci=co=cu=crest=0;
    char ch;
    while( ( ch = getchar() ) >= 0) {
        if (ch =='a' || ch == 'A')
            ca++;
        else if (ch =='e' || ch == 'E')
            ce++;
        else if (ch =='i' || ch == 'I')
            ci++;
        else if (ch =='o' || ch == 'O')
            co++;
        else if (ch =='u' || ch == 'O')
            cu++;
        else if ((ch >='a' && ch <='z') || (ch >='A' && ch <='Z'))
            crest++;
    }
    
    int total=ca+ce+ci+co+cu+crest;
    printf("Total number of letters are %d\n",total);
    printf("\nNumber of characters:\na  %d ; e  %d ; i  %d ; o  %d ; u  %d ; rest  %d\n",ca,ce,ci,co,cu,crest);
    printf("Percentages of total:\na  %d%% ; e  %d%% ; i  %d%% ; o  %d%% ; u  %d%% ; rest  %d%%",ca*100/total,ce*100/total,ci*100/total,co*100/total,cu*100/total,crest*100/total);

    return 0;
}