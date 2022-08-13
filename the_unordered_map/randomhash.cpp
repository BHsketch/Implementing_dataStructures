#include<iostream>
#include<cstdlib>
#include<cmath>

void hashfloat(float key)
{
    int hashoutput;
    int integralpart = trunc(key);
    float decimalpart = key - trunc(key);
    for(int i=0; (decimalpart - trunc(decimalpart))>0 ; i++)
    {
        decimalpart = 10*decimalpart;
    }
    srand((int)integralpart + (int)decimalpart);
    hashoutput=1+(rand()%100);
    std::cout<<"hash("<<key<<") = "<<hashoutput<<std::endl;

}

int main()
{
    int b=5;
    srand(b);
    int a= 1+(rand()%100);
    std::cout<<a<<std::endl;

    srand(b);
    a= 1+(rand()%100);
    std::cout<<a<<std::endl;

    std::cout<<"trunc(20.411) is "<<trunc(20.411)<<std::endl;

    hashfloat(20.453);

    hashfloat(20.444);

    hashfloat(20.100);

    hashfloat(19.233);

    hashfloat(20.453);


}