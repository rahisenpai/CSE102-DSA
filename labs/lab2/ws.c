#include <stdio.h>

int power (int a, int b);

int main(){
    int base,i=0,check=0,len=0,result=0,temp=0;
    char num[100],num1[20];
    scanf("%d %[^\n]s",&base,&num);

    while (num[i]!='\0') {
        if (num[i]=='0' || num[i]=='1' || num[i]=='2' || num[i]=='3' || num[i]=='4' || num[i]=='5' || num[i]=='6' || num[i]=='7' || num[i]=='8' || num[i]=='9'){
            check=1;
        }
        if (check==1){
            num1[len]=num[i];
            len++;
            if (num[i+1]!='0' && num[i+1]!='1' && num[i+1]!='2' && num[i+1]!='3' && num[i+1]!='4' && num[i+1]!='5' && num[i+1]!='6' && num[i+1]!='7' && num[i+1]!='8' && num[i+1]!='9'){
                num1[len]='\0';
                len--;
                break;
            }
        }
        i++;
    }

    for (int i=0;i<=len;i++){
        temp=power(base,(len-i));
        result+=((int)num1[i]-'0')*temp;
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