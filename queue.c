#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *pNext;
};
typedef struct node node;

struct queue
{
    node *pHead;
    node *pTail;
};
typedef struct queue queue;

node *khoitaonode(int x)
{
    node *p = (node*)malloc(sizeof(p));
    p->data = x;
    p->pNext = NULL;
    return p;
}

void khoitaoqueue(queue *q)
{
    q->pHead = NULL;
    q->pTail = NULL;
}

bool Isempty(queue *q)
{
    if (q->pHead == NULL)
        return true;
    else
        return false;
}

void Enqueue(queue *q, int x)
{
    node *p = khoitaonode(x);
    if(Isempty(q)){
        q->pHead = q->pTail = p;
        return;
    }    
    else{
        p->pNext = q->pHead;
        q->pHead = p;
        return;
    }

}
void Dequeue(queue *q)
{
    if(Isempty(q))
        printf("Queue is empty\n");
    else{
        node *temp;
        for (node *p = q->pHead; p!=NULL; p = p->pNext)
        {
            if (p == q->pTail)
            {
                printf("%d\n", p->data);
                q->pTail = temp;
                temp->pNext = NULL;
                free(p);
                return;
            }
            temp = p;
        }
    }
}

void Front(queue *q)
{
    if(Isempty(q))
        printf("Queue is empty\n");
    else{
        printf("%d\n", q->pTail->data);
    }
}

void nhapqueue(queue *q, int n)
{
    for(int i = 1; i <= n; i++)
    {
        int x;
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &x);
        Enqueue(q, x);
    }
}

void xuatqueue(queue *q)
{
    for (node *p = q->pHead; p!=NULL; p = p->pNext)
    {
        printf("%d\t", p->data);
    }
}

int main()
{
    queue q;
    khoitaoqueue(&q);
    nhapqueue(&q, 6);
    Enqueue(&q, 4);
    Front(&q);
    Dequeue(&q);
    xuatqueue(&q);
}