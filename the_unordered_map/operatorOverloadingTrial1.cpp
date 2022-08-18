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
        (this->tempkey)=inputkey;
        T& valref = this->tempval;
        return valref; // returning the object we are working with; it will be the lvalue in agemap["sheldon"] = 25
    }
    
};

int main()
{
    unordered_map_bh<std::string, int> agemap;
    agemap["Sheldon"]=25;
    agemap.gettempkey();
    agemap.gettempval();
}