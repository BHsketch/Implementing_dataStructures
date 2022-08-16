//I need hashmap[key]=value store the  key and  value in tempkey and tempvalue respectively, 
//and then make a pair object with those two as the arguments
//but what will the operator "=" operate on? Since the LHS of it will also be a function (overloaded operator[]).
//seeing if I can return a pointer to tempval in function hashmap[key] and assign value to that dereferenced pointer 
//using operator overloading for "="

#include<iostream>
#include<string>

template<typename kT, typename T>
class unordered_map_bh
{
    private:
    kT tempkey;
    T tempval;

    public:

    set_tempkey(kT valueToBeSetTo)
    {
        tempkey=valueToBeSetTo;
    }

    set_tempval(T valueToBeSetTo)
    {
        tempval=valueToBeSetTo;
    }

    unordered_map_bh<kT, T> * operator[] (kT inputkey)
    {
        (this->tempkey)=inputkey;
        std::cout<<"tempkey is "<<tempkey<<std::endl;
        return this;
    }

    void operator= (T inputvalue)
    {
        //unordered_map_bh<kT, T> *tempptr =  this;
        //(*this).set_tempval(inputvalue);
        (this->tempval)=inputvalue;
        std::cout<<"tempval is "<<tempval<<std::endl;
    }
    
};

int main()
{
    unordered_map_bh<std::string, int> agemap;
    //agemap["Sheldon"]=25;
}