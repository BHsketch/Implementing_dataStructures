#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>

template<typename kT, typename T>
class pair{
    public:

    kT key;
    T value;

};

template<typename kT, typename T>
class listnode{
    pair nodepair;
    listnode* next;

    listnode(kT key)
    {
        nodepair.processkey(key);
    }
};

template<typename kT, typename T>
class unordered_map_bh{

    listnode* H[100];
    listnode* C[100];
    kT tempkey;
    int index;

    void processkey(const int key) //hash function if the key is an integer
    {
        (this->key)=key;
        srand(key);
        hashoutput = 1+(rand()%100);
    }

    //probability of collisions is 1/100 with the current hash functions, which is very bad. 

    void processkey(std::string key)//hash function if the key is a string
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

    void processkey(const float key) //hash function if the key is a float
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

    T& operator[] (const &kT key)
    {
        tempkey = key;
        index = processkey(tempkey);
        
    }
};



int main()
{
    // unordered_map_bh<std::string, int> agemap;
    // agemap["sheldon"]=25;
    // agemap.getkeyval();
}

/*
algorithm:
1. the user enters: agemap["Jupiter"] = 19
2. read the argument passed to agemap via operator overloading the [] operator, and set a key variable to the input
3. put the key through a hash function to determine the index -> store that index in a variable called 'index'
4. search the linked list at that index for the mentioned key
5. If found, return that variable (either to be used somewhere or to be overwritten if the user entered the expression in step 1)
6. Else, if end of the linked list is reached without finding the key, (end pointed to by 'current')
    create a new listnode called tempnnode
    set the key variable equal to the input key
    set the next pointer to null
    set the last node of the linked list (current) to point to tempnode
    set the pointer of C at the corresponding index to point to tempnode
    retun a reference to its value variable (it is an lvalue) so it cane be assigned its value throught the = operator in the expression that the user entered
*/

// In order to create an iterator, what if the end of a linked list points to the head node of the linked list at the next index?
