#ifndef GESTIRE_FILE_H
#define GESTIRE_FILE_H

#include "Gioco.h"
#include "main.h"
#include "Configurazione.h"
#include "Gestire_aiuto.h"
#include "Gestire_partita.h"
#include "Gioco.h"
#include "Gestire_menu.h"

void salvaPartita(Gioco tabella[RIGA * COLONNA]);
int caricaPartita(Gioco tabella[RIGA * COLONNA]);

#endif // GESTIRE_FILE_H
