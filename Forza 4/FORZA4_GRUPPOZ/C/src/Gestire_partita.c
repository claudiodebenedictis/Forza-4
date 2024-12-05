#include "Gestire_partita.h"
#include "Configurazione.h"
#include "Gestire_aiuto.h"
#include "Gestire_file.h"
#include "Gestire_menu.h"
#include "Gestire_stampa.h"
#include "Gioco.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>     // Per la funzione usleep

void giocare_senza_salvataggio(char NUMERO1[CN], char NUMERO2[CN], int tg1, int tg2) {
  Gioco tabella[RIGA * COLONNA];
  int t = 1, f, nt = 0, r, c, g = g2I;
  char scelta;

  f = FGioca;

  azzera(tabella);

  do {
    CLS;

    stampaTitolo();
    g = giocatoreP(g);
    t = g == g1I
            ? 1
            : 0; // In questo modo, t sarà aggiornato a ogni turno del gioco,
                 // alternando tra 1 e 0, e il messaggio corretto sarà stampato.
    printf("g=%d   tg=%d\n", g, g == g1I ? tg1 : tg2);
    printf("Mossa numero: %d\n", ++nt);
    if (t)
      printf("E' il turno di %s (%c)\n\n", NUMERO1, CARATTEREG1);
    else
      printf("E' il turno di %s (%c)\n\n", NUMERO2, CARATTEREG2);
    stampa(tabella);

    // Se gioca l'utente
    if ((g == 1 && tg1 == User) || (g == 2 && tg2 == User)) {
      while (1) {
        do {
          printf("In che colonna vuoi mettere il gettone? (Per aprire opzioni "
                 "premi 0): ");
          int risultato = scanf("%d", &c);

          // Pulisce il buffer di input
          while (getchar() != '\n')
            ;

          if (risultato == 1 && c >= 0) {
            break; // L'utente ha inserito un numero valido, quindi esce dal
                   // ciclo
          } else {
            printf("Input non valido. Per favore, inserisci un numero.\n");
          }
        } while (1);

        if (c == 0) {
          do {
            printf("Vuoi salvare, uscire o tornare al menu'? (q/m/s): ");
            scanf(" %c", &scelta);
            // Pulisce il buffer di input
            while (getchar() != '\n')
              ;
          } while (scelta != 'q' && scelta != 'm' && scelta != 's' &&
                   scelta != 'Q' && scelta != 'M' && scelta != 'S');

          if (scelta == 'q' || scelta == 'Q') {

            printf("Arrivederci!\n");
            exit(0);
          } else if (scelta == 'm' || scelta == 'M') {
        	  //ciclo for per caricare la barra di caricamento
        	for (int p = 0; p <= 100; ++p) {
        	        mostrare_caricamento_barra(p);
        	         usleep(20000); // Aggiungi una pausa per l'animazione
        	   }
        	putchar('\n'); // Vai a capo alla fine dell'animazione
            return;
          } else if (scelta == 's' || scelta == 'S') {
            salvaPartita(tabella);
            printf("Partita salvata correttamente! \n ");
          }
        }
        c--;

        if (c < 0 || c >= COLONNA)
          continue;
        r = inserisci(tabella, c);
        if (r != -1)
          break;
      }
    } else { // Se gioca il computer
      c = mossaPC(tabella, g, giocatoreP(g));
      r = inserisci(tabella, c); // mossaPc ritorna una colonna valida e con spazio
      tabella[r * COLONNA + c].righe = g;
      printf("\nc = %d \n", c + 1);
    }

    tabella[r * COLONNA + c].righe = g;
    f = controllaF(tabella, g, r, c, 1) ? g : f;
    if (nt == RIGA * COLONNA && f == 0) {
      f = FPareggio;
      break;
    }
  } while (!f);

  CLS;
  stampaTitolo();
  stampa(tabella);
  if (f == 1) {
    printf("\n\nHa vinto %s (%c)", NUMERO1 , CARATTEREG1);
  } else if (f == 2) {
    printf("\n\nHa vinto %s (%c)", NUMERO2, CARATTEREG2);
  } else if (f == 3) {
    printf("\n\nPareggio");
  }
}

void  giocare_con_Salvataggio(char NUMERO1[CN], char NUMERO2[CN], int tg1, int tg2, Gioco tabella[RIGA * COLONNA]) {
  int t = 1, f, nt = 0, r, c, g = g2I;

  char scelta;
  f = FGioca;

  do {
    CLS;
    t = g == g2I
            ? 1
            : 0; // In questo modo, t sarà aggiornato a ogni turno del gioco,
                 // alternando tra 1 e 0, e il messaggio corretto sarà stampato.
    stampaTitolo();
    g = giocatoreP(g);
    printf("g=%d   tg=%d\n", g, g == g1I ? tg1 : tg2);
    printf("Mossa numero: %d\n", ++nt);
    if (t)
      printf("E' il turno di %s (%c)\n\n", NUMERO1, CARATTEREG1);
    else
      printf("E' il turno di %s (%c)\n\n", NUMERO2, CARATTEREG2);
    stampa(tabella);

    // Se gioca l'utente
    if ((g == 1 && tg1 == User) || (g == 2 && tg2 == User)) {
      while (1) {
        do {
          printf("In che colonna vuoi mettere il gettone? (Per aprire opzioni "
                 "premi 0): ");
          int risultato = scanf("%d", &c);

          // Pulisce il buffer di input
          while (getchar() != '\n')
            ;

          if (risultato == 1 && c >= 0) {
            break; // L'utente ha inserito un numero valido, quindi esce dal
                   // ciclo
          } else {
            printf("Input non valido. Per favore, inserisci un numero.\n");
          }
        } while (1);
        if (c == 0) {
          do {
            printf("Vuoi salvare, uscire o tornare al menu'? (q/m/s): ");
            scanf(" %c", &scelta);
            // Pulisce il buffer di input
            while (getchar() != '\n')
              ;
          } while (scelta != 'q' && scelta != 'm' && scelta != 's' &&
                   scelta != 'Q' && scelta != 'M' && scelta != 'S');

          if (scelta == 'q' || scelta == 'Q') {
            printf("Arrivederci!\n");
            exit(0);
          } else if (scelta == 'm' || scelta == 'M') {
        	  //ciclo for per caricare la barra di caricamento
        	  for (int p = 0; p <= 100; ++p) {
        	            mostrare_caricamento_barra(p);
        	          usleep(20000); // Aggiungi una pausa per l'animazione
        	      }
        	      putchar('\n'); // Vai a capo alla fine dell'animazione
            return;    //serve per uscire da tutto il ciclo e tornare nel main
          } else if (scelta == 's' || scelta == 'S') {
            salvaPartita(tabella);
            printf("Partita salvata correttamente! \n ");
          }
        }
        c--;

        if (c < 0 || c >= COLONNA)
          continue;
        r = inserisci(tabella, c);
        if (r != -1)
          break;
      }
    } else { // Se gioca il computer
      c = mossaPC(tabella, g, giocatoreP(g));
      r = inserisci(tabella, c); // mossaPc ritorna una colonna valida e con spazio
      tabella[r * COLONNA + c].righe = g;
      printf("\nc = %d \n", c + 1);
    }

    tabella[r * COLONNA + c].righe = g;
    f = controllaF(tabella, g, r, c, 1) ? g : f;
    if (nt == RIGA * COLONNA && f == 0) {
      f = FPareggio;
      break;
    }
  } while (!f);

  CLS;
  stampaTitolo();
  stampa(tabella);
  if (f == 1) {
    printf("\n\nHa vinto %s (%c)", NUMERO1 , CARATTEREG1);
  } else if (f == 2) {
    printf("\n\nHa vinto %s (%c)", NUMERO2 , CARATTEREG2);
  } else if (f == 3) {
    printf("\n\nPareggio");
  }
}

int mossaPC(Gioco tabella[RIGA * COLONNA], int gp, int ga) {
  int r, c, cas, g, i;

  // Supporto
  Gioco tabella2[RIGA * COLONNA];
  r = 0;
  while (r < RIGA) {
    c = 0;
    while (c < COLONNA) {
      tabella2[r * COLONNA + c] = tabella[r * COLONNA + c];
      c = c + 1;
    }
    r = r + 1;
  }

  printf("mossaPC ( m, %d, %d )", gp, ga);

  // 1° ciclo Controlla se può vincere
  // 2° ciclo controlla se l'avversario può vincere
  i = 0;
  while (i < 2) {
    g = (i ? ga : gp);
    c = 0;
    while (c < COLONNA) {
      r = inserisci(tabella2, c);
      tabella2[r * COLONNA + c].righe = g;
      printf("\n  c=%d  r=%d controllaF( m, %d, %d, %d, 0)=%d", c, r, g, r, c,
             controllaF(tabella2, g, r, c, 0));
      if (r != -1 && controllaF(tabella2, g, r, c, 0))
        return c;
      tabella2[r * COLONNA + c].righe = vuotoI;
      c = c + 1;
    }
    i = i + 1;
    ;
  }

  while (1) // Controlla se nella colonna casuale c'è spazio
    if (inserisci(tabella2, cas = rand() % COLONNA) != -1)
      return cas;
}

int giocatoreP(int g) { return g == g1I ? g2I : g1I; }

int esiste(int r, int c) {
  if (r >= 0 && r < RIGA && c >= 0 && c <COLONNA)
    return 1;
  return 0;
}

void azzera(Gioco tabella[RIGA * COLONNA]) {
  int i = 0;
  while (i < RIGA * COLONNA) {
    tabella[i].righe = 0;
    tabella[i].colonne = 0;
    i = i + 1;
  }
}

int inserisci(Gioco tabella[RIGA * COLONNA], int c) {
  int i = RIGA - 1;
  while (i >= 0) {
    if (tabella[i * COLONNA + c].righe == vuotoI)
      return i;
    i = i - 1;
    ;
  }
  return -1;
}

int controllaF(Gioco tabella[RIGA * COLONNA], const int g, const int r, const int c,
               const int e) {
  int x, ret = 0, i, ok;

  // Controllo diagonale \ ___
  if (esiste(r - 1, c - 1) && tabella[(r - 1) * COLONNA + c - 1].righe == g)
    if ((x = controllaF(tabella, g, r - 1, c - 1, e)) != 0)
      ret = ret || x;
  if (r < RIGA - (NGV - 1) && c < COLONNA - (NGV - 1)) {
    ok = 1;
    i = 0;
    while (i < NGV &&
           (ok *= (tabella[r * COLONNA + c].righe == tabella[(r + i) * COLONNA + c + i].righe ||
                   tabella[(r + i) * COLONNA + c + i].righe == vI))) {
      i = i + 1;
    }
    if (ok) {
      if (e) {
        i = 0;
        while (esiste(r + i, c + i) && tabella[(r + i) * COLONNA + c + i].righe == g) {
          tabella[(r + i) * COLONNA + c + i].righe = vI;
          i = i + 1;
        }
      }
      ret = 1;
    }
  }

  // Controllo diagonale /  ___
  if (esiste(r + 1, c - 1) && tabella[(r + 1) * COLONNA + c - 1].righe == g)
    if ((x = controllaF(tabella, g, r + 1, c - 1, e)) != 0)
      ret = ret || x;
  if (r > (NGV - 2) && c < COLONNA - (NGV - 2)) {
    ok = 1;
    i = 0;
    while (i < NGV &&
           (ok *= (tabella[r * COLONNA + c].righe == tabella[(r - i) * COLONNA + c + i].righe) ||
                  tabella[(r - i) * COLONNA + c + i].righe == vI)) {
      i = i + 1;
    }
    if (ok) {
      if (e) {
        i = 0;
        while (esiste(r - i, c + i) && tabella[(r - i) * COLONNA + c + i].righe == g) {
          tabella[(r - i) * COLONNA + c + i].righe = vI;
          i = i + 1;
        }
      }
      ret = 1;
    }
  }

  // Controllo riga
  if (esiste(r, c - 1) && tabella[r * COLONNA + c - 1].righe == g)
    if ((x = controllaF(tabella, g, r, c - 1, e)) != 0)
      ret = ret || x;
  if (c < COLONNA - (NGV - 1)) {
    ok = 1;
    i = 0;
    while (i < NGV && (ok *= (tabella[r * COLONNA + c].righe == tabella[r * COLONNA + c + i].righe ||
                              tabella[r * COLONNA + c + i].righe == vI))) {
      i = i + 1;
    }
    if (ok) {
      if (e) {
        i = 0;
        while (esiste(r, c + i) && tabella[r * COLONNA + c + i].righe == g) {
          tabella[r * COLONNA + c + i].righe = vI;
          i = i + 1;
        }
      }
      ret = 1;
    }
  }

  // Controllo colonna
  if (r < RIGA - (NGV - 1)) {
    ok = 1;
    i = 0;
    while (i < NGV && (ok *= (tabella[r * COLONNA + c].righe == tabella[(r + i) * COLONNA + c].righe ||
                              tabella[(r + i) * COLONNA + c].righe == vI))) {
      i = i + 1;
    }
    if (ok) {
      if (e) {
        i = 0;
        while (i < NGV) { // Non serve controllare se sono più di 4
          tabella[(r + i) * COLONNA + c].righe = vI;
          i = i + 1;
        }
      }
      ret = 1;
    }
  }

  return ret;
}

void Struttura_gioco(int tipoGioco, char scelta, int *tg1, int *tg2, Gioco *tabella,
                     char *NUMERO1, char *NUMERO2) {
  if (tipoGioco == UvsU)
    *tg1 = *tg2 = User;
  else if (tipoGioco == UvsC) {
    *tg1 = User;
    *tg2 = CPU;
  } else
    *tg1 = *tg2 = CPU;

  // ciclo do per chiedere all'utente di caricare la partita o no
  int flag = 0;
  do {
    printf("Vuoi caricare una partita precedentemente salvata? (s/n): ");
    scanf(" %c", &scelta);
    while (getchar() != '\n')
      ; // Pulisce il buffer di input

    // Controlla se l'input dell'utente è valido
    if (scelta != 's' && scelta != 'n' && scelta != 'S' && scelta != 'N') {
      printf("Input non valido. Per favore, inserisci 'si' o 'no'.\n");
    }
  } while (scelta != 's' && scelta != 'n' && scelta != 'S' && scelta != 'N');

  if (scelta == 's' || scelta == 'S') {
    int partitaCaricata = caricaPartita(tabella);
    if (partitaCaricata) {
    	//ciclo per caricamento barra
    	for (int p = 0; p <= 100; ++p) {
    	          mostrare_caricamento_barra(p);
    	        usleep(100000); // Aggiungi una pausa per l'animazione
    	    }
    	    putchar('\n'); // Vai a capo alla fine dell'animazione

      printf("Partita precedentemente salvata caricata con successo!\n");
      flag = 1;
    } else {
      printf("Nessuna partita salvata trovata.\n");
      printf("Premi qualsiasi tasto per iniziare a giocare...");
      getchar();
      while ((getchar()) != '\n')
        ; // Svuota il buffer di input
    }
  }

  if (flag == 1) {
    giocare_con_Salvataggio(NUMERO1, NUMERO2, *tg1, *tg2, tabella);
  } else {
    giocare_senza_salvataggio(NUMERO1, NUMERO2, *tg1, *tg2);
  }
}
