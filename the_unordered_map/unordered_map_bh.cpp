#include<iostream>
#include<string>
#include<cstdlib>

template<typename kT, typename T>
class pair
{
    const kT key;
    T value;

    public:
    pair(const int key)
    {
        int hashoutput;
        srand(key);
        hashoutput = 1+(rand()%100);
    }

    pair(const std::string key) const
    {
        int hashoutput;
        int sum=0;
        for(int i=0; key[i]!='\0'; i++)
        {
            int ascii = (int)key[i];
            sum=sum+ascii;
        }
        srand(sum);
        hashoutput=1+(rand()%100);
    }

    pair(const float key)
    {

    }

    pair(const double key)
    {

    }
};

template<typename kT, typename T>
class unordered_map_bh
{
    
};

int main()
{
    unordered_map_bh<std::string, int> agemap;
    //map1["Sheldon"]=18;   
}