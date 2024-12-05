#include "Gestire_menu.h"
#include "Configurazione.h"
#include "Gestire_stampa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> // Per la funzione usleep


void menu(Gioco tabella[RIGA * COLONNA], char NUMERO1[CN], char NUMERO2[CN], int *tipoGioco, int *tg1, int *tg2) {


  do {
    stampaTitolo();
    printf("\n\t 1. User vs User");
    printf("\n\t 2. User contro Computer");
    printf("\n\t 3. Computer contro Computer");
    printf("\n\t 4. Aiuto e Regole");
    printf("\n\n   Scegli la modalita' di gioco: ");
   
    int risultato = scanf("%d", tipoGioco);    //variabile di supporto
    // Pulisce il buffer di input
      while (getchar() != '\n');

      if (risultato == 1 && *tipoGioco >= 1 && *tipoGioco <= scelta_aiuto) {
          if (*tipoGioco == scelta_aiuto) {
              printf("\n");
              aiuto(); // apre aiuto
          }
      } else {
          printf("Input non valido. Per favore, inserisci un numero tra 1 e 4.\n");
      }
  } while (*tipoGioco < 1 || *tipoGioco > 3);
  //ciclo per caricamento barra

  for (int p = 0; p <= 100; ++p) {
            mostrare_caricamento_barra(p);
          usleep(1500); 			// Aggiungi una pausa per l'animazione
      }
  putchar('\n'); // Vai a capo alla fine dell'animazione
  CLS;
  if (*tipoGioco != CvsC) {
    printf("Inserisci il nome del giocatore:\n   ");
    scanf("%s", NUMERO1);
    fflush(stdin);
    if (*tipoGioco == UvsU) {
      printf("Inserisci il nome del secondo giocatore:\n   ");
      scanf("%15s", NUMERO2);
      fflush(stdin);
    } else
      strcpy(NUMERO2, "CPU1");
  } else {
    strcpy(NUMERO1, "CPU1");
    strcpy(NUMERO2, "CPU2");
  }
}

void menuPrincipale(Gioco tabella[RIGA * COLONNA], char NUMERO1[CN], char NUMERO2[CN], int *tipoGioco, int *tg1, int *tg2) {
  char scelta;

  stampaTitolo();
  do{
    CLS;
   stampaTitolo();
  printf("Benvenuto nel gioco! Vuoi iniziare a giocare? (s/n): ");
      scelta = getchar();
      while (getchar() != '\n'); // Pulisce il buffer di input
  } while (scelta != 's' && scelta != 'n' && scelta != 'S' && scelta != 'N');

  if (scelta == 's' || scelta == 'S') {

	  //ciclo per caricamento barra
	  for (int p = 0; p <= 100; ++p) {
	            mostrare_caricamento_barra(p);
	          usleep(1500); // Aggiungi una pausa per l'animazione
	      }
	      putchar('\n'); // Vai a capo alla fine dell'animazione
	  CLS;
      menu(tabella, NUMERO1 , NUMERO2 , tipoGioco, tg1, tg2);
  } else {
      printf("Arrivederci!\n");
      exit(0);
  }

}

void mostrare_caricamento_barra(int p) {
    putchar('\r');
    printf("Caricamento... [");
    for (int i = 0; i < PROGRESSO_BARRA; ++i) {
        if (i < p * PROGRESSO_BARRA / 100)
            putchar('=');
        else
            putchar(' ');
    }
    printf("] %d%%", p);
    fflush(stdout); // Forza la stampa immediata sulla console
}
