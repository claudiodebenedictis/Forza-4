#ifndef GESTIRE_MENU_H
#define GESTIRE_MENU_H

#include "main.h"
#include "Configurazione.h"
#include "Gestire_aiuto.h"
#include "Gestire_file.h"
#include "Gestire_partita.h"
#include "Gioco.h"

void menu(Gioco tabella[RIGA * COLONNA], char NUMERO1[CN], char NUMERO2[CN], int *tipoGioco, int *tg1, int *tg2);
void menuPrincipale(Gioco tabella[RIGA * COLONNA], char NUMERO1[CN], char NUMERO2[CN], int *tipoGioco, int *tg1, int *tg2);
void mostrare_caricamento_barra(int p);

#endif // GESTIRE_MENU_H
