#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>

template<typename kT, typename T>
class pair{

};

template<typename kT, typename T>
class listnode{

};

template<typename kT, typename T>
class unordered_map_bh{

    

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
2. create a listnode with a pair object called tempnode
3. read the argument passed to the operator [] via function overloading, and assign it to the "key" variable in our pair object
4. set the next pointer of tempnode to null
5. put the key through a hash function to determine the index -> store that index in a node object variable called 'index'
6. search the linked list at that index for the mentioned key
7. If found, return that variable (either to be used somewhere or to be overwritten if the user entered the expression in step 1)
8. Else, if end of the linked list is reached without finding the key, (end pointed to by 'current')
    create a new listnode called tempnnode
    set the key variable equal to the input key
    set the next pointer to null
    set the last node of the linked list (current) to point to tempnode
    set the pointer of C at the corresponding index to point to tempnode
    retun the value variable (it is an lvalue) so it cane be assigned its value throught the = operator in the expression that the user entered
*/

// In order to create an iterator, what if the end of a linked list points to the head node of the linked list at the next index?
