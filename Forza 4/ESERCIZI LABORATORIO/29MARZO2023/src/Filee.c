#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int Palindroma_caseS(char *sequenza) {
    int lunghezza = strlen(sequenza);
    int i = 0;
    int j = lunghezza - 1;
    while(i < j) {
        // Salta caratteri non alfabetici all'inizio e alla fine della sequenza
        while (!isalpha(sequenza[i]) && i < j) {
            i++;
        }
        while (!isalpha(sequenza[j]) && i < j) {
            j--;
        }
        // Confronta i caratteri alfabetici alla stessa posizione
        if ((sequenza[i]>=65)&&(sequenza[j]<=90)&&(sequenza[i]>=48)&&(sequenza[i]<=57)&&(sequenza[i]>=97)&&(sequenza[i]<=122) ) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main() {
    FILE *fp;
    char filename[] = "input.txt";
    char *file_content = NULL;
    long file_size;

    // Apri il file in lettura
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Impossibile aprire il file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Ottieni la dimensione del file
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    // Alloca la memoria necessaria per contenere il contenuto del file
    file_content = (char*) malloc(file_size + 1);
    if (file_content == NULL) {
        printf("Errore nell'allocazione di memoria\n");
        exit(EXIT_FAILURE);
    }

    // Leggi il contenuto del file e chiudi il file
    fread(file_content, file_size, 1, fp);
    fclose(fp);

    // Aggiungi il carattere terminatore di stringa
    file_content[file_size] = '\0';

    // Verifica se la stringa letta è palindroma
    if (Palindroma_caseS(file_content)) {
        printf("Il contenuto del file %s è palindromo\n", filename);
    } else {
        printf("Il contenuto del file %s non è palindromo\n", filename);
    }

    // Libera la memoria allocata per il contenuto del file
    free(file_content);

    return 0;
}
