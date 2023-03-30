//Write program using enumerated types which when given today's date will print out tomorrow's date in the for 31st January, for example.

#include <stdio.h>

enum months {jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec};

int main(){
    int d;
    char mon[4],data[12][4]={"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
    enum months m;
    printf("enter(date month): ");
    scanf("%d %[^\n]c",&d,&mon);
    char a=mon[0], b=mon[1], c=mon[2];

    if (a=='j' && b=='a'){
        m=jan;}
    else if (a=='f'){
        m=feb;}
    else if (a=='m' && b=='a' && c=='r'){
        m=mar;}
    else if (a=='a' && b=='p'){
        m=apr;}
    else if (a=='m' && b=='a' && c=='y'){
        m=may;}
    else if (a=='j' && b=='u' && c=='n'){
        m=jun;}
    else if (a=='j' && b=='u' && c=='l'){
        m=jul;}
    else if (a=='a' && b=='u'){
        m=aug;}
    else if (a=='s'){
        m=sep;}
    else if (a=='o'){
        m=oct;}
    else if (a=='n'){
        m=nov;}
    else if (a=='d'){
        m=dec;}
    else{
        printf("invalid input");
        return 0;
    }

    if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
        if (d>=31){
            if (m==12){
                d=1;
                m=1;
            }
            else {
            d=1;
            m=m+1;
            }
        }
        else{
            d=d+1;
        }
    }
    else if (m==4 || m==6 || m==9 || m==11){
        if (d>=30){
            d=1;
            m=m+1;
        }
        else{
            d=d+1;
        }
    }
    else{
        if (d>=28){
            d=1;
            m=m+1;
        }
        else{
            d=d+1;
        }        
    }

    printf("%d %s",d,data[m-1]);
    return 0;
}