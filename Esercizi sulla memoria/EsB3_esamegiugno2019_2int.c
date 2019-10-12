#include <stdio.h>
#include <stdlib.h>

void f() {
   long var4;
   //siamo qua
}

void g(long* var3) {
    f();
}

long *var0;

int main() {
    
    {
        //Memory leak
        long *leak = (long*)malloc(sizeof(long));
        *leak = 2021;
    }

    var0 = (long*)malloc(sizeof(long));
    *var0 = 2021;
    
    long var1 = 0;

    long *var2 = (long*)malloc(sizeof(long));
    *var2 = 2020;

    g(var2);

    return 0;
}
