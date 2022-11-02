#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Implementing a hashmap using chaining

int hash(char* str)
{
    int i;
    int sum;
    int hashoutput;
    for(i=0; str[i]!='\0'; i++)
    {
        sum = sum + (int)str[i];
    }
    hashoutput = sum%100;
    return hashoutput;
}

// typedef struct pair
// {
//     char key[20];
//     int value;
// } pair;
struct node
{
    char key[20];
    int value;
    struct node* next;
    int hashoutput;
};

typedef struct node node;

typedef struct unordered_map
{
    node* H[100];
    node* C[100];
} map;

map* createhashmap()
{
    map* map1 = (map*)malloc(sizeof(map));
    int i;
    char instruction='Y';
    node* tempnode;
    char buffer[1];

    for(i=0; i<100; i++)
    {
        (map1->H)[i]=(node* )malloc(sizeof(node));
        (map1->H)[i]->hashoutput = 0;
        (map1->H)[i]->next = NULL;
        (map1->C)[i]=(map1->H)[i];
    }

    for(i=0; instruction!='n'; i++)
    {
        printf("Do you want to create a new key-value pair? (Y/n)\n");
        scanf("%c", &instruction);
        gets(buffer);
        if(instruction == 'n')
        {
            break;
        }else if(instruction == 'Y')
        {
            tempnode = (node *)malloc(sizeof(node));
            printf("enter the key: ");
            gets((tempnode->key));
            printf("enter the value: ");
            scanf("%d", &(tempnode->value));
            gets(buffer);
            tempnode->next=NULL;
            (tempnode->hashoutput)=hash(&((tempnode->key)[0]));

            (map1->C)[tempnode->hashoutput]->next = tempnode;
            (map1->C)[tempnode->hashoutput] = tempnode;
            (((map1->H)[tempnode->hashoutput])->hashoutput)++;
        }
    }
    return map1;
}

void find(map* map1)
{
    int j;
    int i;
    int count;
    char instruction='Y';
    char key[20];
    int hashoutput;
    int found = 0;
    node* current;
    char buffer[1];
    
    for(j=0; instruction != 'n'; j++)
    {
        found=0;
        printf("Do you want to search a key? (Y/n)\n");
        scanf("%c", &instruction);
        gets(buffer);
        int compare;
        if(instruction == 'n')
        {
            break;
        }else if(instruction == 'Y')
        {
            printf("enter key: ");
            gets(key);
            hashoutput = hash(&(key[0]));
            i=0;
            count = ((map1->H)[hashoutput])->hashoutput;
            current = ((map1->H)[hashoutput]);
            for(i=0; i<count; i++)
            {
                current = current->next;
                compare=strcmp(&((current->key)[0]), &(key[0]));
                if( compare == 0)
                {
                    found = 1;
                    printf("corresponding value is: %d\n", current->value);
                    break;
                }
            }
            if(found == 0)
            {
                printf("key-value pair does not exist\n");
            }
        }
    }
}

int main()
{
    map* agemap = createhashmap();
    find(agemap);
    free((void*)agemap);
}