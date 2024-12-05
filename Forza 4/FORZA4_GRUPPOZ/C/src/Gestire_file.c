#include "Gestire_file.h"
#include "Configurazione.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void salvaPartita(Gioco tabella[RIGA * COLONNA]) {
  FILE *fp = fopen("game.bin", "wb");
  int i = 0; 				//variabile di supporto
  while (i < RIGA * COLONNA) {
    fwrite(&tabella[i], sizeof(Gioco), 1, fp);
    i = i + 1;
  }
  fclose(fp);
}

int caricaPartita(Gioco tabella[RIGA * COLONNA]) {
  FILE *fp = fopen("game.bin", "rb");
  if (fp != NULL) {
    int i = 0;			//variabile di supporto
    while (i < RIGA * COLONNA) {
      fread(&tabella[i], sizeof(Gioco), 1, fp);
      i = i + 1;
    }
    fclose(fp);
    return 1; // restituisci 1 se il gioco e' stato caricato
  } else {
    return 0; // restituisci 0 se il file di gioco non e' stato aperto o caricato
  }
}
