#include <stdlib.h>
#include <stdio.h>

struct list {
    int head;
    struct list *tail;
};

void recursive(struct list *curr){

    if(curr != NULL)
        recursive(curr -> tail);
    //siamo qua
}
    
struct list *construct_list(int head, struct list *tail){

    struct list *nuovo = (struct list*)malloc(sizeof(struct list));
    nuovo -> head = head;
    nuovo -> tail = tail;

    return nuovo;
}

int main(void){

    struct list *a = construct_list(1, NULL);
    a = construct_list(1, construct_list(2, NULL);

    recursive(a);
    
}