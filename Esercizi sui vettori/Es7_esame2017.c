#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3

void stampa_matrice(float M[N][N]){
	int i,j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%2.1f ", M[i][j]);
		}
		printf("\n");
	}
};

void inizializza(float M[N][N]);
void kernel(float M[N][N]);

void main(){
	float M[N][N];
	inizializza(M);
	printf("La matrice e':\n");
	stampa_matrice(M);
	
	kernel(M);
	printf("La nuova matrice e':\n");
	stampa_matrice(M);
}

void inizializza(float M[N][N]){

    srand(time(NULL));

    int i,j;
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
            M[i][j] = rand() % 100 +1;

};

void kernel(float M[N][N]){
    
    float somma[N][N];

    int i,j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
            somma[i][j] = M[i][j];
            if(i+1 <=N-1)
                somma[i][j] += M[i+1][j];
            if(j+1 <=N-1)
                somma[i][j] += M[i][j+1];
            if(i-1 >=0)
                somma[i][j] += M[i-1][j];
            if(j-1 >=0)
                somma[i][j] += M[i][j-1];
            if(i-1 >=0 && j-1 >=0)
                somma[i][j] += M[i-1][j-1];
            if(i-1 >=0 && j+1 <=N-1)
                somma[i][j] += M[i-1][j+1];
            if(i+1 <=N-1 && j+1 <=N-1)
                somma[i][j] += M[i+1][j+1];
            if(i+1 <=N-1 && j-1 >=0)
                somma[i][j] += M[i+1][j-1];
        }
    }

    for(i=0; i<N; i++){
		for(j=0; j<N; j++){  
            if((i > 0 && i < N) && (j > 0 && j < N))
                M[i][j] = somma[i][j]/9;
            else if((i > 0 && i < N) || (j > 0 && j < N))
                M[i][j] = somma[i][j]/6;
            else
                M[i][j] = somma[i][j]/4;
        }
    }
};
