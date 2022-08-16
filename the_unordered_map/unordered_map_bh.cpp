#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>

template<typename kT, typename T>
class pair
{
    const kT key;
    T value;
    int hashoutput;

    public:
    pair(const int key) //hash function if the key is an integer
    {
        srand(key);
        hashoutput = 1+(rand()%100);
    }

    //probability of collisions is 1/100 with the current hash functions, which is very bad. 

    pair(const std::string key) const //hash function if the key is a string
    {
        int sum=0;
        for(int i=0; key[i]!='\0'; i++)
        {
            int ascii = (int)key[i];
            sum=sum+ascii;
        }
        srand(sum);
        hashoutput=1+(rand()%100);
    }

    pair(const float key) //hash function if the key is a float
    {
        int integralpart = trunc(key);
        float decimalpart = key - trunc(key);
        for(int i=0; (decimalpart - trunc(decimalpart))>0 ; i++)
        {
            decimalpart = 10*decimalpart;
        }
        srand((int)integralpart + (int)decimalpart);
        hashoutput=1+(rand()%100);
    }

    pair(const double key)
    {

    }

    void pairallocate(hashoutput)
    {

    }
};

template<typename kT, typename T>
class ListNode{

    private:
    pair<kT, T> val;
    pair<kT, T> *next;

};

template<typename kT, typename T>
class unordered_map_bh
{
    kT tempkey;
    T tempval;

    void operator[] (kT inputkey)
    {
        (this->tempkey)=inputkey;
    }

    void operator= (T value)
    
};

int main()
{
    unordered_map_bh<std::string, int> agemap;   
}