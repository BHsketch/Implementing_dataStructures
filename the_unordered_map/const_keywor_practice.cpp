#include<iostream>

int main()
{
    int age = 20;
    int age2 = 45;
    int * const ageptr = &age;
    *ageptr = 18;
    //ageptr = &age2;
}