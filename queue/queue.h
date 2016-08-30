#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

#define offsetof(type, member) (size_t)&(((type *)0)->member)
#define queue_data(q,type,link) (type *)((u_char *)q - offsetof(type,link))

typedef struct queue_s queue_t ;
struct queue_s {
    queue_t *next ;
    queue_t *prev ;
};

int32_t queue_init( queue_t *h );
// if empty return 0 else non zero
int32_t queue_empty(queue_t *h );

//insert element to head
void queue_insert_head( queue_t *h , queue_t *x );
//insert element to tail
void queue_insert_tail( queue_t *h , queue_t *x );

//return the head element
queue_t* queue_head( queue_t *h );
//return the last element
queue_t* queue_last( queue_t *h );
//
queue_t* queue_sentinel( queue_t *h );

//remove element
int32_t queue_remove( queue_t *x );

int32_t queue_split( queue_t *h , queue_t *q , queue_t **n );

int32_t queue_add( queue_t *h , queue_t *n );


//options for elements

//insert q after x
void queue_insert_after( queue_t *q , queue_t *x );
//return q->next
queue_t *queue_next( queue_t *q ) ;
//return q->prev
queue_t *queue_prev( queue_t *q ) ;
//return q's data struct queue_data( q ,type , link);


