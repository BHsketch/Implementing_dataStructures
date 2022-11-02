#include<iostream>

typedef struct treenode{
    struct treenode* lptr;
    int val;
    struct treenode* rptr;
} node;

node* createtree()
{
    node* tempnode = (node*)malloc(sizeof(node));
    node* root = tempnode;
    node* current;
    int set;
    char instr;
    char buffer[1];
    tempnode -> lptr = nullptr;
    tempnode -> rptr = nullptr;
    std::cout<<"enter value for the root node: ";
    std::cin>>tempnode->val;

    for(int i=0; instr!='n'; i++)
    {
        std::cout<<"do you want to insert a value in the tree? (Y/n): ";
        std::cin>>instr;
        gets(buffer);
        if(instr == 'Y')
        {
            set = 0;
            tempnode = (node*)malloc(sizeof(node));
            tempnode->lptr = nullptr;
            tempnode->rptr = nullptr;
            
            std::cout<<"enter the value to be inserted: ";
            std::cin>>tempnode->val;
            gets(buffer);

            current = root;

            for(int j=0; set==0; j++)
            {
                //std::cout<<"setloop"<<std::endl;
                if(tempnode->val < current->val)
                {
                    if(current->lptr == nullptr)
                    {
                        current->lptr = tempnode;
                        set = 1;
                    }else
                    {
                        current = current ->lptr;
                    }
                }else if(tempnode->val > current->val)
                {
                    if(current->rptr == nullptr)
                    {
                        current->rptr = tempnode;
                        set = 1;
                    }else
                    {
                        current = current->rptr;
                    }
                }
            }

        }
    }

    return root;
}

void traversetree(node* root)
{
    node* current = root;

    if(current != nullptr)
    {
        traversetree(current->lptr);
        std::cout<<current->val<<" ";
        traversetree(current->rptr);
    }

    return;
}

void deletefromtree(node* &root)
{
    int valuetobedeleted;
    node* current;
    char buffer[1];

    std::cout<<"enter value of the node to be deleted: ";
    std::cin>>valuetobedeleted;
    gets(buffer);

    
}

int main()
{
    char instr;
    char buffer[1];

    for(int i=0; instr != 'e'; i++)
    {
        std::cout<<"enter instruction (c for create; d for delete; t for traverse; e to exit): ";
        std::cin>>instr;
        gets(buffer);
        node* root;

        if(instr == 'c')
        {
            root = createtree();
        }else if(instr == 't')
        {
            traversetree(root);
        }else if(instr == 'd')
        {
            //deletefromtree(root);
        }
    }

}