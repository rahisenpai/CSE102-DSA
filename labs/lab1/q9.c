//Given as input an integer number of seconds, print as output the equivalent time in hours, minutes and seconds. Recommended output format is something like
//7322 seconds is equivalent to 2 hours 2 minutes 2 seconds.

#include <stdio.h>

int main(){
    int t;
    printf("enter time(s): ");
    scanf("%d",&t);
    int m1 = t/60, s=t%60;
    int h=m1/60, m=m1%60;
    printf("%d hour(s), %d min(s), %d sec(s)\n", h, m, s);

    return 0;
}