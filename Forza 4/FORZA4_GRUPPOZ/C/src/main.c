#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>     // Per la funzione usleep
#include "main.h"
#include "Configurazione.h"
#include "Gestire_aiuto.h"
#include "Gestire_file.h"
#include "Gestire_partita.h"
#include "Gioco.h"
#include "Gestire_menu.h"


int main(int argc, char *argv[]) {
  char NUMERO1[CN] = "Giocatore A", NUMERO2[CN] = "Giocatore B", r,scelta;
  Gioco tabella[RIGA * COLONNA];
  int tipoGioco = 0, tg1, tg2;
 do {
    srand(time(NULL));
    CLS;
    menuPrincipale(tabella, NUMERO1 , NUMERO2 , &tipoGioco, &tg1, &tg2);
    // Chiamata alla funzione Struttura_gioco
    Struttura_gioco(tipoGioco, scelta, &tg1, &tg2, tabella, NUMERO1 , NUMERO2);

    do {
      printf("\n \n Vuoi tornare al menu' o uscire dal gioco? (m/q) ");
      scanf(" %c", &scelta);

      // Pulisce il buffer di input
      while (getchar() != '\n');

      // Controlla se l'input dell'utente è valido
      if (scelta != 'm' && scelta != 'M' && scelta != 'q' && scelta != 'Q') {
        printf("Input non valido. Per favore, inserisci 'm' o 'q'.\n");
      }
    } while (scelta != 'm' && scelta != 'M' && scelta != 'q' && scelta != 'Q');

    if(scelta == 'q' || scelta == 'Q') printf("\n \n Grazie per aver giocato dal gruppo Z!");  
  } while (scelta == 'm' || scelta == 'M');

  return 0;
}
