#include <stdio.h>

#define LUNGHEZZA_VETTORE 10
	
int cercaValore(int vettore[], int val);
int calcolaMax(int vettore[]);
int calcolaMin(int vettore[]);
int valorePiuFrequente(int vettore[]);
float calcolaMedia(int vettore[]);

int main(void) {
    int n, i, posizione;
    int vettore[LUNGHEZZA_VETTORE];
    
    printf("Inserimento dei %i interi che compongono il vettore...\n",LUNGHEZZA_VETTORE);
    for (i = 0; i < LUNGHEZZA_VETTORE; i++) {
        printf("Inserire l'intero in posizione %i: ", (i+1));
        scanf("%i", &vettore[i]);
    }
    
    printf("\nMassimo inserito nel vettore: %i\n", calcolaMax(vettore));
    printf("Minimo inserito nel vettore: %i\n", calcolaMin(vettore));
    printf("Valore piu' frequentemente inserito nel vettore: %i\n", valorePiuFrequente(vettore));
    printf("Media dei valori inseriti nel vettore: %g\n", calcolaMedia(vettore));
        
    do {
        printf("Inserire un numero da cercare nel vettore (0 per terminare): ");
        scanf("%i",&n);
        if (n != 0) {
            posizione = cercaValore(vettore,n);
            if (posizione > -1)
                printf("Il numero %i si trova in posizione %i\n", n, posizione+1);
            else
                printf("Il numero %i non e' presente nel vettore\n", n);
        }
    } while (n != 0);
    
    return 0;
}

int calcolaMax(int vettore[]){
    int i, max = vettore[0];

    for(i = 0; i < LUNGHEZZA_VETTORE; i++){
        if(max < vettore[i])
            max = vettore[i];
    }

    return max;
}

int calcolaMin(int vettore[]){
    int i, min = vettore[0];

    for(i = 0; i < LUNGHEZZA_VETTORE; i++){
        if(min > vettore[i])
            min = vettore[i];
    }

    return min;
}

int valorePiuFrequente(int vettore[]){
    int i, j, quantidin = 0, quantista = 0, valfreq;

    for(i = 0; i< LUNGHEZZA_VETTORE; i++){
        for(j = 0; j < LUNGHEZZA_VETTORE; j++){
            if(vettore[j] == vettore[i])
                quantidin++;
        }
        if(quantidin > quantista){
                quantista = quantidin;
                valfreq = vettore[i];
            }
        quantidin = 0;
    }

    return valfreq;

}

float calcolaMedia(int vettore[]){
    int i;
    float somma, media;

    for(i = 0; i < LUNGHEZZA_VETTORE; i++)
        somma = somma+ vettore[i];
    
    media = somma/LUNGHEZZA_VETTORE;

    return media;
}
//se esiste restituisce la posizione, se non esiste restituisce -1
int cercaValore(int vettore[], int val){
    int i;

    for(i = 0; i< LUNGHEZZA_VETTORE; i++){
        if(vettore[i] == val)
            return i;
    }

    return -1;
}



