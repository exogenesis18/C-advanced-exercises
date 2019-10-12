#include <stdio.h>
#include <stdlib.h>

void g() {
   long var4;
   //siamo qua
}

void f(long* var3) {
    g();
}

long *var0;

int main() {
    
    {
        //Memory leak
        long *leak = (long*)malloc(sizeof(long));
        *leak = 2021;

        leak = (long*)malloc(sizeof(long));
        *leak = 2021;
    }

    var0 = (long*)malloc(sizeof(long));
    *var0 = 2020;
    
    long var1 = 0;

    long *var2 = (long*)malloc(sizeof(long));
    *var2 = 2020;

    f(var2);

    return 0;
}
