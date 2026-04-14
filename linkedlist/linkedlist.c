#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

/*Private function to add a new_node right after curr_node*/
static void
_linkedlist_add_next(linkedlist_node_t* curr_node,
    linkedlist_node_t* new_node) {

    if (!curr_node->right) {
        curr_node->right = new_node;
        new_node->left = curr_node;
        return;
    }

    linkedlist_node_t* temp = curr_node->right;
    curr_node->right = new_node;
    new_node->left = curr_node;
    new_node->right = temp;
    temp->left = new_node;
}

/*Fn to insert a new GLnode into a glthread at the first position
 * in a glthread i.e. new node becomes a head
 * */
void
linkedlist_add(linkedlist_t* lst, linkedlist_node_t* llnode) {

    llnode->left = NULL;
    llnode->right = NULL;
    if (!lst->head) {
        lst->head = llnode;
        return;
    }
    linkedlist_node_t* head = lst->head;
    _linkedlist_add_next(llnode, head);
    lst->head = llnode;
}

static void
_remove_llthread(linkedlist_node_t* llnode) {

    if (!llnode->left) {
        if (llnode->right) {
            llnode->right->left = NULL;
            llnode->right = 0;
            return;
        }
        return;
    }
    if (!llnode->right) {
        llnode->left->right = NULL;
        llnode->left = NULL;
        return;
    }

    llnode->left->right = llnode->right;
    llnode->right->left = llnode->left;
    llnode->left = 0;
    llnode->right = 0;
}

/*API to remove a glnode from glthread*/
void
linkedlist_remove(linkedlist_t* lst, linkedlist_node_t* llnode) {

    linkedlist_node_t* head = lst->head;
    /*If the node being removed is the head node itself, then update the
     * head*/
    if (head == llnode) {
        lst->head = head->right;
    }
    _remove_llthread(llnode);
}

void
init_linkedlist(linkedlist_t* linkedlist, unsigned int offset) {

    linkedlist->head = NULL;
    linkedlist->offset = offset;
}