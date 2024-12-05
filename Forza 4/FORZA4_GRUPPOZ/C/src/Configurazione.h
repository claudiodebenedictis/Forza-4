#ifndef CONFIGURAZIONE_H
#define CONFIGURAZIONE_H

// Dimensioni campo da gioco
#define RIGA 9 // Numero di righe
#define COLONNA 8 // Numero di colonne

// Caratteri stampati a video
#define CARATTEREG1 'X'    // Carattere del giocatore 1
#define CARATTEREG2 'O'    // Carattere del giocatore 2
#define vuoto '.' // Carattere per uno spazio vuoto
#define CVitt 'V' // Carattere per segnare la combinazione vincente

// Valori nella matrice
#define vuotoI 0 // Valore di uno spazio vuoto
#define g1I 1    // Valore del giocatore 1
#define g2I 2    // Valore del giocatore 2
#define vI 3     // Valore per segnare la combinazione vincente

// Valori che può assumere f in gioca
#define FGioca 0    // Partita in corso
#define FG1 1       // Ha vinto il giocatore 1
#define FG2 2       // Ha vinto il giocatore 2
#define FPareggio 3 // Pareggio

// Varie
#define CN 15             // Numero dei caratteri dei nomi dei giocatori
#define NGV 4             // Numero Gettoni per la Vittoria
#define CLS system("cls") // Funzione per pulire lo schermo su windows
#define PROGRESSO_BARRA 40 //Caricamento barra

// Tipologia di Gioco
#define UvsU 1         // User contro User
#define UvsC 2         // User contro Computer
#define CvsC 3         // Computer contro Computer
#define scelta_aiuto 4 // Scelta aiuto

// Tipologia Giocatore
#define User 1
#define CPU 2

#endif // CONFIGURAZIONE_H

