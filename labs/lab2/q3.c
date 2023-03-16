//Given as input three integers representing a date as day, month, year, print out the number day, month and year for the following day's date.
//Typical input: 28 2 1992 Typical output: Date following 28:02:1992 is 29:02:1992

#include <stdio.h>

int main(){
    int d,m,y,d1=0,m1=0,y1=0;
    printf("enter (space-separated): ");
    scanf("%d %d %d",&d,&m,&y);

    if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
        y1=y;
        if (d==31){
            if (m==12){
                d1=1;
                m1=1;
                y1++;
            }
            else {
            d1=1;
            m1=m+1;
            }
        }
        else{
            d1=d+1;
            m1=m;
        }
    }

    else if (m==4 || m==6 || m==9 || m==11){
        y1=y;
        if (d==30){
            d1=1;
            m1=m+1;
        }
        else{
            d1=d+1;
            m1=m;
        }
    }

    else if (m==2){
        y1=y;
        if (d==29){
            d1=1;
            m1=3;
        }
        else if (d==28){
            if (y%4==0){
                if ((y%100==0) && (y%400!=0)){
                    d1=1;
                    m1=3;
                }
                else {
                    d1=29;
                    m1=2;
                }
            }
            else{
                d1=1;
                m1=3;
            }
        }
        else {
            d1=d+1;
            m1=m;
        }
    }

    printf("Date following %02d:%02d:%d is %02d:%02d:%d",d,m,y,d1,m1,y1);

    return 0;
}