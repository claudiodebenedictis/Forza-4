#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int convert(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return -1;
    }
}

// Funzione che analizza una sottostringa di str e la interpreta come un numero in base base
// Restituisce il numero intero corrispondente, oppure -1 se la sottostringa non contiene un numero valido
// end è un puntatore a intero che viene utilizzato per restituire l'indice del primo carattere non usato della stringa str
int parse_number(char *str, int len, int base, int *end) {
    int num = 0;
    int pos = 0;
    int max_num = -1;

    // Analizza i caratteri della sottostringa finché non si raggiunge la fine o si incontra un trattino (-)
    while (pos < len && str[pos] != '-') {
        // Converte il carattere corrente in una cifra nella base specificata
        int digit = convert(str[pos]);
        if (digit == -1 || digit >= base) { // Verifica che sia una cifra valida per la base scelta
            return -1; // Numero non valido, esce dalla funzione con valore di errore (-1)
        }

        // Aggiorna il valore numerico moltiplicando per la base prima di aggiungere la cifra corrente
        num = num * base + digit;
        pos++;

        if (num > max_num) { // Aggiorna il massimo trovato se necessario
            max_num = num;
        }
    }

    // Se end è un puntatore valido, restituisce l'indice del primo carattere non utilizzato della stringa str
    if (end != NULL) {
        *end = pos;
    }

    // Verifica che il massimo valore numerico trovato sia valido per la base scelta
    int temp_max = max_num;
    while (temp_max > 0) {
        int digit = temp_max % base;
        if (digit >= base) { // Verifica che ci sia una cifra valida nella rappresentazione numerica della base scelta
            return -1; // Numero non valido, esce dalla funzione con valore di errore (-1)
        }
        temp_max /= base;
    }

    return max_num; // Restituisce il valore numerico del massimo trovato nella sottostringa analizzata
}
int max_number(char *str, int len, int base) {
    char *pos = str;
    int max_num = -1;

	// Analizza le sottostringhe separate dal trattino (-)
    while (*pos != '\0') {
        // Cerca l'indice del primo trattino (-) nella sottostringa corrente
        char *end_pos = strchr(pos, '-');

        if (end_pos == NULL) { // Se non c'è nessun trattino (-), siamo all'ultima sottostringa della stringa originale
            end_pos = pos + strlen(pos);
        }

        // Interpreta la sottostringa corrente come un numero in base base
        int num = parse_number(pos, end_pos - pos, base, NULL);

        if (num == -1) { // Se il numero non è valido, esce dalla funzione con valore di errore (-1)
            return -1;
        }

        if (num > max_num) { // Aggiorna il massimo trovato se necessario
            max_num = num;
        }

        pos = end_pos + 1; // Passa alla sottostringa successiva (dopo il trattino (-))
    }

    return max_num; // Restituisce il massimo trovato
}

int main() {
	// Chiede all'utente di inserire la base della rappresentazione numerica
	int base;
	printf("Inserisci la base: ");
	fflush(stdout); // Serve a forzare l'output del messaggio precedente prima di leggere l'input dell'utente
	scanf("%d", &base);

	if (base < 2 || base > 9) { // Verifica che la base sia compresa tra 2 e 9 (inclusi)
		printf("Base non valida\n");
		return 1; // Termina il programma con valore di errore (1)
	}

	FILE* fp = fopen("file.txt", "r"); // Apre il file in lettura

	if(fp == NULL){ // Verifica che l'apertura del file sia andata a buon fine
		printf("Error opening file\n");
		return 2; // Termina il programma con valore di errore (2)
	}

	char buffer[100];

	if(fgets(buffer, 100, fp)==NULL){ // Legge una riga dal file e verifica che ci sia almeno un carattere letto
		printf("Error reading file\n");
		fclose(fp); // Chiude il file aperto in precedenza
		return 3; // Termina il programma con valore di errore (3)
	}

	int max = max_number(buffer, strlen(buffer), base); // Cerca il massimo numero presente nella riga letta dal file

	if(max == -1){ // Verifica che ci siano numeri validi nella riga letta dal file
    	printf("-1");
   } else {
    	printf("Maximum number is %d\n", max); // Stampa il massimo trovato
   }

   fclose(fp); // Chiude il file aperto in precedenza

   return 0; // Termina il programma con valore di successo (0)
}
