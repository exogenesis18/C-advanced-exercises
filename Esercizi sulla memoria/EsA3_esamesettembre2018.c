#include <stdlib.h>
#include <stdio.h>

struct list{
    int value;
    struct list *next;
};

struct list *genera_lista_din(int value){
    struct list *t = (struct list*)malloc(sizeof(struct list));
    t -> value = value;
    t -> next = NULL;

    if(value == 1)
        return t;
    else{
        t -> next = genera_lista_din(value -1);
    }
}

struct list *static_pointer_to_list;

int main(){

    struct list *pointer_to_list = genera_lista_din(1); //<- è un memory leak

    pointer_to_list = genera_lista_din(2);

    static_pointer_to_list = pointer_to_list;

    // -> siamo qua <-

    return 0;

}