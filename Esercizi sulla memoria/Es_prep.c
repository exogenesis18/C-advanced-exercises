#include <stdio.h>
#include <stdlib.h>

int *dangling(){
    int *tmp;
    return &*tmp;
}

int *var0;

int main(){

    int var1 = 0;

    int *var2 = (int*)malloc(sizeof(int));
    *var2 = 2020;

    var0 = dangling();

    int *var3 = var2;

    printf("Heap:\n");
    {   
        int *leak = (int*)malloc(sizeof(int));
        *leak = 2021;

        printf("Il valore %i è contenuto nell'indirizzo %p (Memory leak)\n", *leak, leak);

        leak = (int*)malloc(sizeof(int));
        *leak = 2021;

        printf("Il valore %i è contenuto nell'indirizzo %p (Memory leak)\n", *leak, leak);
    }
    printf("Il valore %i è contenuto nell'indirizzo %p\n", *var2, var2);

    printf("Data:\n");
    printf("Il valore di var0 è %p e il suo indirizzo è %p (Dangling pointer)\n", var0, &var0);

    printf("Stack:\n");
    printf("Il valore di var1 è %i e il suo indirizzo è %p\n", var1, &var1);
    printf("Il valore di var2 è %p e il suo indirizzo è %p\n", var2, &var2);
    printf("Il valore di var3 è %p e il suo indirizzo è %p\n\n\n", var3, &var3);

    return 0;
}