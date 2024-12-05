#ifndef GESTIRE_STAMPA_H
#define GESTIRE_STAMPA_H

#include "Gioco.h"
#include "main.h"
#include "Configurazione.h"
#include "Gestire_aiuto.h"
#include "Gestire_file.h"
#include "Gestire_menu.h"

void stampaTitolo(void);
void stampaRigaPiena(void);
void stampa(Gioco tabella[RIGA * COLONNA]);
char stampaCasella(int x);

#endif // Gestire_stampa_H
