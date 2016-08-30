#include "queue.h"

int32_t queue_init( queue_t *h)
{
    h->next = h->prev = h ;
    return 0 ;
}

queue_t *queue_sentinel( queue_t *h )
{
    return h;
}

void queue_insert_head( queue_t* h, queue_t *x)
{
    x->prev = h;
    x->next = h->next;
    h->next->prev = x ;
    h->next = x;
}

void queue_insert_tail( queue_t *h , queue_t *x)
{
    x->prev = h->prev ;
    x->next = h ;
    h->prev->next = x ;
    h->prev = x;
}

void queue_insert_after( queue_t *q, queue_t *x)
{
    x->next = q->next ;
    x->prev = q ;
    q->next->prev = x ;
    q->next = x ;
}

queue_t *queue_next( queue_t *p)
{
    return p->next;
}

struct node{
    int num ;
    queue_t q;
};
typedef struct node node ;

int main(void)
{
    node n[5];
    n[0].num=0;
    n[1].num=1;
    n[2].num=2;
    n[3].num=3;
    n[4].num=4;

    queue_t h ;
    queue_init(&h);

    queue_insert_tail(&h,&n[0].q) ;
    queue_insert_head(&h,&n[1].q) ;
    queue_insert_tail(&h,&n[2].q) ;
    queue_insert_after(&h,&n[3].q) ;
    queue_insert_tail(&h,&n[4].q) ;

    queue_t *t ;
    for( t = queue_next(&h);  t != queue_sentinel(&h) ; t = queue_next(t) )
    {
        node *tmp = queue_data( t , node , q );
        printf("%d\n",tmp->num) ;
    }
    return 0 ;
}


