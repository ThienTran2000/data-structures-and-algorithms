#include <stdlib.h>
#include <stdio.h>
#define HASH_SIZE 11

typedef struct node {
    int data;
    struct node *pNext;
} node;

node *hashindex[HASH_SIZE];

int hashfunction(int x)
{
    return x%HASH_SIZE;
}

void insert(int x)
{
    int index = hashfunction(x);
    node *temp = (node *)malloc(sizeof temp);
    temp->data = x;
    temp->pNext = NULL;
    if(hashindex[index]==NULL)
    {
        hashindex[index]=temp;
    }
    else{
        temp->pNext = hashindex[index];
        hashindex[index]=temp;
    }
}

void find(int x)
{
    int index = hashfunction(x);
    for(node *p = hashindex[index]; p!=NULL; p = p->pNext)
    {
        if(p->data == x)
        {
            printf("Yes\n");
            return;
        }
    }
    printf("No\n");
}

int main()
{
    for(int i = 0; i<20; i++)
    {
        insert(i);
    }
    find(5);
    find(50);
}
