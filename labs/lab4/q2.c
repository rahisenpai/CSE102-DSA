//Write a simple database program that will store a persons details such as age, date of birth, address etc.

#include <stdio.h>

struct details{
    char name[25];
    char age[3];
    char dob[10];
    char address[100];
};

int main(){
    struct details person;
    printf("enter name: ");
    gets(person.name);
    printf("enter age: ");
    gets(person.age);
    printf("enter dob(dd/mm/yyyy): ");
    gets(person.dob);
    printf("enter address: ");
    gets(person.address);
    return 0;
}