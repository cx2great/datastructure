#include<stdint.h>

typedef struct queue_s queue_t
struct queue_s {
    queue_t *next ;
    queue_t *prev ;
};

