/*
 ============================================================================
 Name        : esercitazione 22-03-2023
 Author      : 
 Version     :
 Copyright   :
 Description : prendere in input da un file di testo una sequenza di caratteri e verificare se la sequenza è palindroma
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int Verifica_Palindroma (char *sequenza) //funzione che verifica se la sequenza di caratteri è palindroma
{
	int dimensione=strlen(sequenza);
	int pos1=0;
	int verifica=0; //0=falso 1=vero
	int pos2=dimensione-1;
	while (pos1<dimensione/2)
	{
		while (pos2>1)
		{
			if (sequenza[pos1]==sequenza[pos2])
			{
				verifica=1;
			}
			else
			{
				verifica=0;
			}
			pos2=pos2-1;
		}
		pos1=pos1+1;
	}
	return verifica;

}
int main ()
{
	FILE *fp;
	char filename []="input.txt";
	char input[100]; //dimensione fissata

	//apri file in lettura
	fp=fopen(filename, "r");
	if(fp==NULL)
	{
		printf("impossibile aprire il file %s.\n",filename);
		exit(1);
	}

	//leggi la sequenza di caratteri alfanumerici dal file
	fgets(input, 100, fp);

	//chiudi il file
	fclose (fp);

	//stampa la sequenza risultante
	printf("la sequenza attuale è: ");
	printf("%s\n",input);

	//ritorna e stampa il valore di verifica palindroma
	int verifica = Verifica_Palindroma(input);
	printf("Verifica:%d", verifica);
	return 0;
}
