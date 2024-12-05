#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Gestire_stampa.h"
#include "main.h"
#include "Configurazione.h"
#include "Gestire_aiuto.h"
#include "Gestire_file.h"
#include "Gestire_partita.h"
#include "Gioco.h"
#include "Gestire_menu.h"


void stampaTitolo(void) {

	  FILE *file = fopen("titolo.txt", "r");
	  if (file == NULL) {
	    printf("Non riesco a trovare il file 'titolo.txt'. Assicurati che il file "
	           "esista.\n");
	    return;
	  }

	  char c; 				//variabile di supporto
	  while ((c = fgetc(file)) != EOF) {
	    putchar(c);
	  }
	  printf("\n");
	  printf("\n");

	    fclose(file);
	  printf("\n");

}
void stampaRigaPiena() {
  int j = 1;
  printf("   |");
  while (j <= COLONNA) {
    printf("---|");
    j++;
  }
  printf("\n");
}

void stampa(Gioco tabella[RIGA * COLONNA]) {
  int i = 0, j;
  printf("\n");
  stampaRigaPiena();

  while (i < RIGA) {
    printf("   |");
    j = 0;
    while (j < COLONNA) {
      printf(" %c |", stampaCasella(tabella[i * COLONNA + j].righe));
      j = j + 1;
    }
    printf("\n");
    stampaRigaPiena();
    i = i + 1;
  }

  stampaRigaPiena();
  printf("   |");
  j = 1;
  while (j <= COLONNA) {
    printf(" %d |", j);
    j = j + 1;
  }
  printf("\n");
  stampaRigaPiena();
  printf("\n");
}

char stampaCasella(int x) {
  char c;
  if (x == 0) {
    c = vuoto;
  } else if (x == 1) {
    c = CARATTEREG1;
  } else if (x == 2) {
    c = CARATTEREG2;
  } else if (x == 3) {
    c = CVitt;
  }
  return c;
}
