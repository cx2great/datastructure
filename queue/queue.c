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

queue_t *queue_prev( queue_t *p)
{
    return p->prev;
}

queue_t *queue_last( queue_t *p)
{
    return p->prev;
}

queue_t *queue_middle( queue_t *queue)
{
    queue_t *middle = queue_next(queue);
    if( middle == queue_last(queue) ) return middle;

    queue_t *next = queue_next(queue);
    for(;;)
    {
        middle = queue_next(middle);
        next = queue_next(next);
        if( next == queue_last(queue) ) return middle;

        next = queue_next(next);
        if( next == queue_last(queue) ) return middle;
    }
}

/*test
struct node{
    int num ;
    queue_t q;
};
typedef struct node node ;

void test()
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
}

int main(void)
{
    test();
    return 0;
}


