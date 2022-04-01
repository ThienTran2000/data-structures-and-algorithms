#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *pNext;
};
typedef struct node node;

struct stack
{
    node *pStop;
};
typedef struct stack stack;

node *khoitaonode(int x)
{
    node *p = (node*)malloc(sizeof(p));
    p->data = x;
    p->pNext = NULL;
    return p;
}

void khoitaostack(stack *s)
{
    s->pStop = NULL;
}

bool Isempty(stack *s)
{
    if (s->pStop == NULL)
        return true;
    else
        return false;
}

void push(stack *s, int x)
{
    node *p = khoitaonode(x);
    if(Isempty(s)){
        s->pStop = p;
        return;
    }    
    else{
        p->pNext = s->pStop;
        s->pStop = p;
        return;
    }

}
void pop(stack *s)
{
    if(Isempty(s))
        printf("Stack is empty\n");
    else{
        printf("%d\n",s->pStop->data);
        node *temp = s->pStop;
        s->pStop = s->pStop->pNext;
        free(temp);
    }
}

void top(stack *s)
{
    if(Isempty(s))
        printf("Stack is empty\n");
    else{
        printf("%d\n", s->pStop->data);
    }
}

void nhapstack(stack *s, int n)
{
    for(int i = 1; i <= n; i++)
    {
        int x;
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &x);
        push(s,x);
    }
}

void xuatstack(stack *s)
{
    for (node *p = s->pStop; p!=NULL; p = p->pNext)
    {
        printf("%d\t", p->data);
    }
}

int main()
{
    stack s;
    khoitaostack(&s);
    nhapstack(&s, 6);
    top(&s);
    pop(&s);
    push(&s, 20);
    xuatstack(&s);
}