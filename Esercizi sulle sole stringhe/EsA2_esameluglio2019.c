#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

void rightshift(char*, int);


void rightshift(char src[], int n){
	
    int lunghezza, i = 0;
    char *ris;

    lunghezza = strlen(src);
    
    ris = (char*)malloc((lunghezza+1)*sizeof(char));

    i=0;

    //Ciclo per scrivere le prime n lettere
    while(i < n){
        ris[i] = src[lunghezza - n + i];
        i++;
    }

    //Ciclo per scrivere le restanti lettere
    for(i; i<lunghezza; i++)
        ris[i] = src[i-n];

    //Metto il terminatore di stringa
    ris[i] = '\0';

    //Metto il valore di ris in src
    i = 0;
    while (src[i] != '\0'){
        src[i] = ris[i];
        i++;
    }

    //Rendo la prima lettera maiuscola e le restanti minuscole
    i = 0;
    while (src[i] != '\0'){
        if(i==0){
            if(src[i] >= 97)
                src[i] = src[i]-32;
        } 
        else{
            if(src[i] <= 90)
                src[i] = src[i]+32;
        }
        i++;
    }
}


int main()
{ char src[N];
  int num;

  printf("Inserisci una stringa: ");
  scanf("%s",src);
   
  printf("\n Inserisci un numero positivo minore della lunghezza della stringa ");
  do{
	  scanf("%d",&num);	
  }while(num<=0 || num>strlen(src));
  rightshift(src,num);
  printf("\n Stringa con shift a destra di %d posizioni: %s", num, src);

  printf("\n\n");
 
  return(0);
}