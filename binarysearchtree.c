#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *pLeft;
    struct node *pRight;
} node;


node *khoitaonode(int x)
{
        node *temp = (node *)malloc(sizeof(temp));
        temp->data = x;
        temp->pLeft = NULL;
        temp->pRight = NULL;
        return temp;
}

node *themphantu(node *t, int x)
{
    if (t==NULL)
    {
        t = khoitaonode(x);
        return t;
    }
    else {
        if(t->data > x)
            t->pLeft = themphantu(t->pLeft, x);
        else if(t->data<x)
            t->pRight = themphantu(t->pRight, x);
    }
    return t;
}

void duyetLNR(node *t)
{
    if(t!=NULL)
    {
        duyetLNR(t->pLeft);
        printf("%d\t", t->data);
        duyetLNR(t->pRight);
    }
}
bool find(node *t, int x)
{
    if(t!=NULL)
    {
        if (t->data == x)
        {
            return true;
        }
        find(t->pLeft, x);
        find(t->pRight, x);
    }
    return false;
}

node *xoanodebatky(node *t, int x)
{
    if(t==NULL)
    {
        return 0;
    }
    else if(t->data > x)
    {
        t->pLeft = xoanodebatky(t->pLeft, x);
    }
    else if (t->data<x)
    {
        t->pRight = xoanodebatky(t->pRight, x);
    }
    else{
        node *temp = t;
        if (t->pLeft == NULL)
            t = t->pRight;
        else if (t->pRight == NULL)
            t = t->pLeft;
        else{
            node *p = t ->pRight;
            while (p->pLeft!=NULL)
            {
                p = p->pLeft;
            }
            t = p;
            p = p->pRight;
        }
        free(temp);
    }
    return t;
}


int main()
{
    node *t = NULL;
    t = themphantu(t,5);
    t = themphantu(t,7);
    t = themphantu(t,-2);
    t = themphantu(t,0);
    t = themphantu(t,-5);
    t = themphantu(t,1);
    t = themphantu(t,6);
    t = themphantu(t,-3);
    if(find(t, 5))
        printf("Yes\n");
    else
        printf("No\n");
    duyetLNR(t);
    t = xoanodebatky(t, 0);
    printf("\n");
    t = themphantu(t,0);
    duyetLNR(t);
    printf("\n");
}