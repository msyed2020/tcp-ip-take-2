#ifndef __LLTHREADS__
#define __LLTHREADS__

typedef struct linkedlist_node_ {

    struct linkedlist_node_* left;
    struct linkedlist_node_* right;
} linkedlist_node_t;

typedef struct linkedlist_ {
    linkedlist_node_t* head;
    unsigned int offset;
} linkedlist_t;

void
linkedlist_add(linkedlist_t* lst, linkedlist_node_t* llnode);

void
linkedlist_remove(linkedlist_t* lst, linkedlist_node_t* llnode);

/*Iterative macro to Iterate Over LinkedList*/
#define ITERATE_LINKEDLIST_BEGIN(lstptr, struct_type, ptr)      \
{                                                               \
    linkedlist_node_t *_llnode = NULL, *_next = NULL;             \
    for(_llnode = lstptr->head; _llnode; _llnode = _next){      \
        _next = _llnode->right;                                 \
        ptr = (struct_type *)((char *)_llnode - lstptr->offset);

#define ITERATE_LINKEDLIST_ENDS }}

#define linkedlist_node_init(llnode)  \
    llnode->left = NULL;            \
    llnode->right = NULL;

void
init_linkedlist(linkedlist_t* linkedlist, unsigned int offset);
#define offsetof(struct_name, field_name)   \
    ((unsigned int)&((struct_name *)0)->field_name)

#endif /* __LLTHREADS__ */