#include<iostream>
#include<cstdlib>


int main()
{
    int b=5;
    srand(b);
    int a= 1+(rand()%100);
    std::cout<<a<<std::endl;

    srand(b);
    a= 1+(rand()%100);
    std::cout<<a<<std::endl;
}