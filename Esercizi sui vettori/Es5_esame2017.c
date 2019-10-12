#include <stdio.h>
#include <stdlib.h>

#define N 3

void stampa_matrice(int M[N][N]){
	int i,j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%i ", M[i][j]);
		}
		printf("\n");
	}
};
void stampa_vettore(float * a, int length){
	int i;
	for(i=0; i<length; i++){
		printf("%f ", a[i]);
	}
	printf("\n");
};

float * media_colonne(int M[N][N]);
float * media_righe(int M[N][N]);
void somma(float * C, float * R, float * S,int length);

void main(){
	int M[N][N] = { {1,3,6}, {2,4,8}, {5,7,9} };
	printf("La matrice e':\n");
	stampa_matrice(M);
	
	printf("La media sulle colonne e':\n");
	float * C = media_colonne(M);
	stampa_vettore(C,N);
	
	printf("La media sulle righe e':\n");
	float * R = media_righe(M);
	stampa_vettore(R,N);
	
	printf("La somma di C end R e':\n");
	float S[N];
	somma(C,R,S,N);
	stampa_vettore(S,N);

}

float * media_colonne(int M[N][N]){

    float *somma, *media;
    int i, j;

    media = (float*)malloc(N*sizeof(float));
    somma = (float*)malloc(N*sizeof(float));

    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            somma[i]=somma[i]+M[i][j];
        media[i]=somma[i]/N;
    }
    
    return media;



};

float * media_righe(int M[N][N]){

    float *somma, *media;
    int i, j;

    media = (float*)malloc(N*sizeof(float));
    somma = (float*)malloc(N*sizeof(float));

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            somma[j]=somma[j]+M[i][j];
            
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            media[i]=somma[i]/N;
    
    return media;

};

void somma(float * C, float * R, float * S,int length){

    if(length == 0)
        return;
    *S = *C + *R;
    somma(C+1, R+1, S+1, length-1);

};

