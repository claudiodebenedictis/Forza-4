#ifndef GESTIRE_PARTITA_H
#define GESTIRE_PARTITA_H

#include "main.h"
#include "Configurazione.h"
#include "Gestire_aiuto.h"
#include "Gestire_file.h"
#include "Gioco.h"
#include "Gestire_menu.h"


void  giocare_senza_Salvataggio(char NUMERO1[CN], char NUMERO2[CN], int tg1, int tg2);
void  giocare_con_Salvataggio(char NUMERO1[CN], char NUMERO2[CN], int tg1, int tg2, Gioco tabella[RIGA * COLONNA]);
int mossaPC(Gioco tabella[RIGA * COLONNA], int gp, int ga);
int giocatoreP(int g);
int esiste(int r, int c);
void azzera(Gioco tabella[RIGA * COLONNA]);
int inserisci(Gioco tabella[RIGA * COLONNA], int c);
int controllaF(Gioco tabella[RIGA * COLONNA], const int g, const int r, const int c, const int e);
void Struttura_gioco(int tipoGioco, char scelta, int* tg1, int* tg2, Gioco* tabella, char* NUMERO1, char* NUMERO2);

#endif // GESTIRE_PARTITA_H
