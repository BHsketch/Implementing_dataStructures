#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>

template<typename kT, typename T>
class pair
{
    public:
    const kT key;
    T value;
    int hashoutput;

    int gethashoutput()
    {
        return hashoutput;
    }

    T& getvalref()
    {
        T& valrefpair = value;
        return valrefpair;
    }

    kT& getkeyref()
    {
        kT& keyrefpair = key;
        return keyrefpair;
    }

    void setkey(kT pairkey)
    {
        (this->key)=pairkey;
    }

    void setval(T pairval)
    {
        (this->val)=pairval;
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

    public:
    pair<kT, T> nodepair;
    ListNode<kT, T> *next;

    // Pair<kT, T>* getnodepair()
    // {
    //     Pair<kT, T>& nodepairreturn = nodepair;
    //     return nodepairreturn;
    // }

    int gethashoutput()
    {
        int output = nodepair.gethashoutput();
        return output;
    }

    T& getvalref()
    {
        T& valrefnode = nodepair.getvalref();
        return valrefnode;
    }

    kT& getkeyref()
    {
        kT& keyrefnode = nodepair.getkeyref();
        return keyrefnode;
    }

    void setnext(ListNode * nextnode)
    {
        next=nextnode;
    }

    void setpairkey(kT nodekey)
    {
        nodepair.setkey(nodekey);
    }

    ListNode<kT, T>()
    {
        nodepair.setkey(NULL);
        setnext(nullptr);
    }

    // ListNode(kT nodekey) : next(nullptr) 
    // {
    //     nodepair.setkey(nodekey);
    // }
};

template<typename kT, typename T>
class unordered_map_bh
{
    private:
    ListNode<kT, T>* H[100] = {nullptr}; // to store the Heads of all corresponding linked lists
    ListNode<kT, T>* C[100] = {nullptr};// to store the addrest of the last listnode in the corresponding linked list i.e. the Current node

    public:

    void getkeyval()
    {
        for(int i=0; i<100; i++)
        {
            if(H[i]!=nullptr)
            {
                std::cout<<"key: "<<(H[i]->getkeyref())<<std::endl;
                std::cout<<"value: "<<(H[i]->getvalref())<<std::endl;
            }
        }
    }

    T& operator[] (const kT& inputkey) //overloading the [] operator to store the argument in the tempkey variable
    {
        ListNode<kT, T>* tempnode = new ListNode<kT, T>; //creates a new listnode
        tempnode->setpairkey(inputkey);//sets the key variable in the pair inside that listnode = input
        
        int hashoutput=tempnode->gethashoutput();

        if((H[hashoutput])==nullptr)
        {
            H[hashoutput]=tempnode;
            C[hashoutput]=tempnode;
        }else if(H[hashoutput]!=nullptr)
        {
            C[hashoutput]->next = tempnode;
            C[hashoutput]=tempnode;
        }//appends tempnode to the linked list that starts from H[hashoutput]. tempnode is now connected

        T& valref = (tempnode->getvalref()); //sets a reference valref to the value variable inside the pair in tempnode

        return valref;
    }//since this returns a reference to the actual val variable, the expression agemap["sheldon"] allows us to both assign, and access the value, which is what we want
    };

int main()
{
    unordered_map_bh<std::string, int> agemap;
    agemap["sheldon"]=25;
    agemap.getkeyval();
}