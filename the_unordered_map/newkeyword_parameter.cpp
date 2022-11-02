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

    setkey(kT pairkey)
    {
        (this->key)=pairkey;
    }

    pair(const int key) //hash function if the key is an integer
    {
        (this->key)=key;
        srand(key);
        hashoutput = 1+(rand()%100);
    }

    //probability of collisions is 1/100 with the current hash functions, which is very bad. 

    pair(std::string key)//hash function if the key is a string
    {
        (this->key)=key;
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
        (this->key)=key;
        int integralpart = trunc(key);
        float decimalpart = key - trunc(key);
        for(int i=0; (decimalpart - trunc(decimalpart))>0 ; i++)
        {
            decimalpart = 10*decimalpart;
        }
        srand((int)integralpart + (int)decimalpart);
        hashoutput=1+(rand()%100);
    }
};

template<typename kT, typename T>
class ListNode{

    private:
    pair<kT, T> nodepair;
    pair<kT, T> *next;

    public:
    ListNode(kT nodekey) : next(nullptr) 
    {
        nodepair.setkey(nodekey);
    }
};

template<typename kT, typename T>
class unordered_map_bh
{
    private:
    kT tempkey;
    T tempval;
    ListNode<kT, T>* buckets[100];


    public:
    void gettempkey()
    {
        std::cout<<"tempkey is "<<tempkey<<std::endl;
    }

    void gettempval()
    {
        std::cout<<"tempval is "<<tempval<<std::endl;
    }

    void set_tempkey(kT valueToBeSetTo) //function to set tempkey from outside the class
    {
        tempkey=valueToBeSetTo;
    }

    void set_tempval(T valueToBeSetTo) //function to set tempvalue from outside the class
    {
        tempval=valueToBeSetTo;
    }

    T& operator[] (const kT& inputkey) //overloading the [] operator to store the argument in the tempkey variable
    {
        ListNode<kT, T>* tempnode = new ListNode<kT, T>;
    }
    
};

int main()
{
    unordered_map_bh<std::string, int> agemap; 
    agemap["sheldon"]=25;
    
}