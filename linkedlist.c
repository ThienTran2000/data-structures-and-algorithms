#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *pNext;
};
typedef struct node node;

struct list{
    node *pHead;
    node *pTail;
};
typedef struct list list;

void khoitaolist(list *l)
{
    l->pHead = NULL;
    l->pTail = NULL;
}

node *khoitaonode(int data)
{
    node *p = (node*)malloc(sizeof(p));
    p->data = data;
    p->pNext = NULL;
    return p;
}

void themvaodau(list *l, int x)
{
    node *p = khoitaonode(x);
    if (l->pHead == NULL)
        l->pHead = l->pTail = p;
    else
    {
        p->pNext = l->pHead;
        l->pHead = p;
    }
}

void themvaocuoi(list *l, int x)
{
    node *p = khoitaonode(x);
    if (l->pHead == NULL)
        l->pHead = l->pTail = p;
    else
    {
        l->pTail->pNext = p;
        l->pTail = p;
    }
}

void themvaosau(list *l, int x, int data)
{
    node *k = khoitaonode(data);
    for (node *p = l->pHead; p!=NULL; p = p->pNext)
    {
        if(p->data == x)
        {
            node *temp = p->pNext;
            p->pNext = k;
            k->pNext = temp;
            return;
        }
    }
}

void xoadau(list *l)
{
    if(l->pHead == NULL)
        return;
    else
    {
        node *temp = l->pHead;
        l->pHead = l->pHead->pNext;
        free(temp);
    }
}

void xoacuoi(list *l)
{
    if(l->pHead == NULL)
        return;
    else
    {
        node *temp;
        for (node *p = l->pHead; p!=NULL; p = p->pNext)
        {
            if (p == l->pTail)
            {
                l->pTail = temp;
                temp->pNext = NULL;
                free(p);
                return;
            }
            temp = p;
        }
    }
}

void xoanodesau(list *l, int x)
{
    for (node *p = l->pHead; p!=NULL; p = p->pNext)
    {
        if(p->data == x)
        {
            if(p->pNext == l->pTail)
                xoacuoi(l);
            else if (p == l->pTail)
                ;
            else
            {
                node *temp = p->pNext;
                p->pNext = p->pNext->pNext;
                free(temp);
            }
            return;
        }
    }
}

void xoanodebatky(list *l, int x)
{
    if(l->pHead->data == x)
        xoadau(l);
    else if(l->pTail->data == x)
        xoacuoi(l);
    else
    {
        node *temp;
        for (node *p = l->pHead; p!=l->pTail; p = p->pNext)
        {
            if (p->data == x)
            {
                temp->pNext = p->pNext;
                free(p);
                return;
            }
            temp = p;
        }
    }
}

void hoanvi(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sapxep(list *l)
{
    for (node *p = l->pHead; p!=l->pTail; p = p->pNext)
        for (node *k = p->pNext; k!=NULL; k = k->pNext)
        {
            if(p->data>k->data)
            {
                hoanvi(&p->data, &k->data);
            }
        }
}

void giaiphong(list *l)
{
    node *k;
    while(l->pHead!=NULL)
    {
        k = l->pHead;
        l->pHead = l->pHead->pNext;
        free(k);
        printf("x");
    }
}

void nhaplist(list *l, int n)
{
    for(int i = 1; i<= n; i++)
    {
        int x;
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &x);
        themvaocuoi(l, x);
    }
}

void xuatlist(list *l)
{
    for (node *p = l->pHead; p!=NULL; p = p->pNext)
    {
        printf("%d\t", p->data);
    }
}

int main()
{
    list l;
    khoitaolist(&l);
    nhaplist(&l, 5);
    xuatlist(&l);
    giaiphong(&l);
}