#include <stdlib.h>
#include <stdio.h>

struct list {
    int head;
    struct list *tail;
};

int * f(){
    int tmp;

    return &tmp;
}

struct list *construct_list(int head, struct list *tail){
    struct list *nuovo = (struct list*)malloc(sizeof(struct list));
    nuovo -> head = head;
    nuovo -> tail = tail;

    return nuovo;
}


void recursive(struct list *this) {
    
    if(this != NULL)
        recursive(this->tail);
    else
        //Siamo qua
    
}

int *x;

int main(void) {
    struct list *a = construct_list(1, construct_list(2, NULL));

    x = f();

    recursive(a);


}
