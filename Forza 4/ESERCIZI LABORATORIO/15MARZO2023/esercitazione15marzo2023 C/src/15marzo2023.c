/*
 ============================================================================
 Name        : 15marzo2023.c
 Author      : de benedictis claudio
 Version     :
 Copyright   :
 Description : input da file sequenza di caratteri e sostituisce caratteri compresi tra () con asterischi
 ============================================================================
 */
//programma che prende in input un file di testo con dentro una sequenza di caratteri, sostituisce tutti i caratteri presenti tra parentesi tonde con un *
//questo programma e' incompleto dato che dovrebbe dare un'asterisco solo per i caratteri all'interno della parentesi es:[(abc)=(*)]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int conta_parentesi_chiuse(char *sequenza) {
    int count = 0;
    int i = 0;
    while (sequenza[i] != '\0') {
        if (sequenza[i] == ')') {
            count++;
        }
        i++;
    }
    return count;
}
int valida_parentesi(char *sequenza) {
    int count = 0;
    int i = 0;
    while (sequenza[i] != '\0') {
        if (sequenza[i] == '(') {
            count++;
        } else if (sequenza[i] == ')') {
            count--;
            if (count < 0) {
                return 0; // parentesi chiuse senza parentesi aperte
            }
        }
        i++;
    }
    if (count == 0) {
        return 1; // tutte le parentesi aperte sono state chiuse
    } else {
        return 0; // ci sono parentesi aperte senza parentesi chiuse
    }
}
int conta_asterischi(char *sequenza) {
    int asterischi = 0;
    int i = 0;
    while (sequenza[i] != '\0') {
        if (sequenza[i] == '*') {
            asterischi++;
        }
        i++;
    }
    return asterischi;
}
void sostituzione(char *input) {
    char *puntatore_input = input;
    int lunghezza_input = strlen(input);
    int inside_parentesi = 0;
    int i=0;
    while(i <lunghezza_input) {
        if (input[i] == '(') {
        	inside_parentesi = 1;
            *puntatore_input++= input[i];
        } else if (input[i] == ')') {
        	inside_parentesi= 0;
            *puntatore_input++= input[i];
        } else if (inside_parentesi) {
            *puntatore_input++= '*';
        } else {
            *puntatore_input++ = input[i];
        }
        i++;
    }

    *puntatore_input= '\0'; // Aggiungi il carattere terminatore di stringa
}

int main() {
    FILE *fp;
    char filename[] = "input.txt";
    char input[100]; //Dimensione fissata

    // Apri il file in lettura
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Impossibile aprire il file %s.\n", filename);
        exit(1);
    }

    // Leggi la sequenza di caratteri alfanumerici dal file
    fgets(input, 100, fp);

    // Chiudi il file
    fclose(fp);

    // Verifica se la sequenza di parentesi è valida
    if (!valida_parentesi(input)) {
           printf("La sequenza di parentesi non è valida.\n");
           exit(1);
       }

    // Sostituisci le sottosequenze tra parentesi tonde con un asterisco
    sostituzione(input);

    // Stampa la sequenza risultante
    printf("La sequenza attuale e':\n");
    printf("%s\n", input);
    int num_asterischi = conta_asterischi(input);
    int num_parentesi=conta_parentesi_chiuse(input);
    printf("\nIl numero di asterischi presenti nella sequenza sono: %d\n", num_asterischi);
    printf("\nIl numero di asterischi validi dovrebbero essere: %d\n",num_parentesi);
    return 0;
}
