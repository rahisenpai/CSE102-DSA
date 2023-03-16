//Write a program which will read an integer value for a base, then read a positive integer written to that base and print its value.
//Read the second integer a character at a time; skip over any leading non-valid (i.e. not a digit between zero and ``base-1'') characters, then read valid characters until an invalid one is encountered.
//The base will be less than or equal to 10.

#include <stdio.h>

int power (int a, int b);
int check (int x, char arr[10]);

int main(){
    int base,i=0,check1,check2,len=0,result=0,temp=0;
    char num[100],num1[20],arr[10];
    scanf("%d %[^\n]s",&base,&num);

    for(int j=0; j<=9; j++){
        if (j<base){
            arr[j]=(char)j+'0';
        }
        else {
            arr[j]='\0';
            break;
        }
    }

    while (num[i]!='\0') {
        check1=check(num[i],arr);
        check2=check(num[i+1],arr);
        if (check1==1){
            num1[len]=num[i];
            len++;
            if (check2==0){
                num1[len]='\0';
                len--;
                break;
            }
        }
        i++;
    }

    for (int j=0;j<=len;j++){
        temp=power(base,(len-j));
        result+=((int)num1[j]-'0')*temp;
    }
    printf("%d\n",result);
    
    return 0;
}

int power (int a, int b) {
    int res=1;
    for (int i=1;i<=b;i++) {
        res *= a;
    }
    return res;
}

int check (int x, char arr[10]) {
    for (int i=0;i<=9;i++) {
        if (arr[i]==x){
            return 1;
        }
    }
    return 0;
}