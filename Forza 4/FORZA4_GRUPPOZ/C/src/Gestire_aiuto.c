#include "Gestire_aiuto.h"
#include "Configurazione.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void aiuto() {
  char scelta;
  FILE *file = fopen("regole.txt", "r");
  if (file == NULL) {
    printf("Non riesco a trovare il file 'regole.txt'. Assicurati che il file "
           "esista.\n");
    return;
  }

  char c; 				//variabile di supporto
  while ((c = fgetc(file)) != EOF) {
    putchar(c);
  }
  printf("\n");
  printf("\n");
  printf("Premi qualsiasi tasto per tornare a giocare...");
  scanf(" %c", &scelta);
  while ((getchar()) != '\n') // Svuota il buffer di input
    fclose(file); 
  printf("\n");
  system("cls");
}
