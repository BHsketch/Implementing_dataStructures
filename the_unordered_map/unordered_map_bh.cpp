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
    public:
    pair<kT, T> nodepair;
    listnode<kT, T>* next;
};

template<typename kT, typename T>
class unordered_map_bh{

    public:
    listnode<kT, T>* H[100] = {nullptr};
    //kT tempkey;
    int index;

    void processkey(int key) //hash function if the key is an integer
    {
        srand(key);
        index = 1+(rand()%100);
    }

    //probability of collisions is 1/100 with the current hash functions, which is very bad. 

    void processkey(std::string key)//hash function if the key is a string
    {
        std::cout<<"process key: ";
    
        int sum=0;
        for(int i=0; key[i]!='\0'; i++)
        {
            int ascii = (int)key[i];
            sum=sum+ascii;
        }
        srand(sum);
        index=1+(rand()%100);

        std::cout<<index<<std::endl;
    }

    void processkey(float key) //hash function if the key is a float
    {
        int integralpart = trunc(key);
        float decimalpart = key - trunc(key);
        for(int i=0; (decimalpart - trunc(decimalpart))>0 ; i++)
        {
            decimalpart = 10*decimalpart;
        }
        srand((int)integralpart + (int)decimalpart);
        index=1+(rand()%100);
    }

     //overloading the [] operator to return an lvalue corresponding to the variable that stores our value
    T& operator[](const kT &tempkey)
    {
        processkey(tempkey);
        listnode<kT, T>* current;
        listnode<kT, T>* parentnode = nullptr;
        listnode<kT, T>* tempnode;
        int foundkey;

        current = H[index];

        foundkey = 0;
        for(int i=0; current!=nullptr; i++)
        {
            if((current->nodepair).key == tempkey)
            {
                foundkey = 1;
                break;
            }
            parentnode = current;
            current = current->next;
        }
        //current is either pointing to the found node or to null(because the node doesn't exist)

        //if node doesn't exist, create one and set current to point to it
        if(!foundkey)
        {
            std::cout<<"key not found"<<std::endl;

            if(parentnode == nullptr)
            {
                //tempnode = (listnode<kT, T>* )malloc(sizeof(listnode<kT,T>));
                tempnode = new listnode<kT, T>;
                tempnode->next = nullptr;
                (tempnode->nodepair).key = tempkey;
                 
                H[index] = tempnode;
            }else{
                //tempnode = (listnode<kT, T>* )malloc(sizeof(listnode<kT,T>));
                tempnode = new listnode<kT, T>;
                tempnode->next = nullptr;
                (tempnode->nodepair).key = tempkey;
                //inserting the node at the end
                parentnode->next = tempnode;
            }
            current = tempnode;
        }
        //current is now pointing to the required node

        return (current->nodepair).value;
        
    }
};



int main()
{
    unordered_map_bh<std::string, int> agemap;
    agemap["sheldon"]=25;
    std::cout<<agemap["sheldon"]<<std::endl<<std::endl;
    agemap["dolensh"]=15;
    std::cout<<agemap["dolensh"]<<std::endl<<std::endl;
    agemap["rona"]=15;
    std::cout<<agemap["rona"]<<std::endl<<std::endl;
    agemap["sheldon"]=35;
    std::cout<<agemap["sheldon"]<<std::endl<<std::endl;

    int age = agemap["sheldon"];
    std::cout<<"age: "<<age;
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
