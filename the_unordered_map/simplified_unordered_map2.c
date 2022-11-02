#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Implementing a hashmap using linear probing

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

struct row
{
    int valid;
    char key[20];
    int value;
};

typedef struct row row;

row* create()
{
    row* map = calloc(100, sizeof(row));
    int i=0;
    char instruction;
    char tempkey[20];
    int tempval;
    int hashoutput;
    int j;
    int placed=0;
    int found;
    int compare;
    char buffer[1];

    for(i=0; i<100; i++)
    {
        map[i].valid = 0; // note: map[i].valid and not map[i]->valid because map[i] will give me a row and not row*
    }

    for(i=0; instruction!='e'; i++)
    {
        printf("choose an option: \n \t to create a key value pair enter 'Y' \n \t to delete a key value pair enter 'x' \n \t to find a value enter 'f' \n \t to exit enter 'e' \n \t");
        scanf("%c", &instruction);
        gets(buffer);
        if(instruction == 'Y')
        {
            printf("enter key: ");
            gets(tempkey);
            printf("enter value: ");
            scanf("%d", &tempval);
            gets(buffer);
            hashoutput = hash(&(tempkey[0]));
            j=hashoutput;
            do{
                if(map[j].valid == 0)
                {
                    strcpy(&(map[j].key)[0], &(tempkey[0]));
                    map[j].value = tempval;
                    map[j].valid=1;
                    placed=1;
                    printf("%s placed at position %d\n", tempkey, j);
                    break;

                }else if(map[j].valid==1)
                {
                    if(j<100)
                    {
                        j++;
                    }else if(j==100)
                    {
                        j=0;
                    }
                }
            } while(j!=hashoutput);

            if(placed == 0)
            {
                printf("no empty space found\n");
            }

        }else if((instruction == 'f') || (instruction == 'x'))
        {
            printf("enter key: ");
            gets(tempkey);
            hashoutput = hash(&(tempkey[0]));
            j=hashoutput;
            found=0;
            do{

                if(map[j].valid == 1)
                {
                    printf("comparing\n");
                    printf("'%s' and ", map[j].key);
                    printf("%s\n", tempkey);
                    compare = strcmp(&(map[j].key)[0], &(tempkey[0]));
                    printf("compare = %d\n", compare);
                    if(compare == 0)
                    {
                        if(instruction == 'x')
                        {
                            map[j].valid = 0;
                            found=1;
                        }else if(instruction == 'f')
                        {
                            printf("corresponding value is: %d\n", map[j].value);
                            found=1; 
                        }
                        break;
                    }
                }
                if((map[j].valid == 0)||(compare!=0))
                {
                    if(j<100)
                    {
                        j++;
                    }else if(j==100)
                    {
                        j=0;
                    }
                }

            } while(j!=hashoutput);

            if(found==0)
            {
                printf("key value pair not found\n");
            }

        }
    }

    return map;
}

int main()
{
    row* map1 = create();
}