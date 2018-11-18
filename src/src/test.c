#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "array.h"

void print_array_of_int(varr_t V);

int main(void)
{
	varr_t V = get_varr();
	V = init_varr(V, 	/* Array variabile */
				  3, 	/* Dimensione iniziale */
				  10, 	/* Dimensione blocco */
				  50, 	/* Dimensione massima */
				  1); 	/* Dimensione minima */
	if(!is_initialized(V))
		printf("Impossibile inizializzare l'array variabile.\n");
	print_array_of_int(V);
	printf("\n");

	int is_exit = 0;
	while(!is_exit)
	{
		int cmd;

		print_array_of_int(V);
		printf("1: Aggiungi blocchi.\n"
			   "2: Rimuovi blocchi.\n"
			   "3: Inizializza.\n"
			   "4: Imposta initial_dim.\n"
			   "5: Imposta block.\n"
			   "6: Imposta max_dim.\n"
			   "7: Imposta min_dim.\n"
			   "8: Imposta locazione.\n"
			   "9: Stampa locazione.\n"
			   "10: Exit.\n"
			   "\n"
			   "Inserisci comando: ");
		scanf("%d", &cmd);


		switch(cmd)
		{
			case 1:
				{
					unsigned int n;

					printf("Numero di blocchi da aggiungere: \n");
					scanf("%u", &n);
					V = add_blocks(V, n);
				}
			break;

			case 2:
				{
					unsigned int n;

					printf("Numero di blocchi da eliminare: \n");
					scanf("%u", &n);
					V = remove_blocks(V, n);
				}
			break;

			case 3:
				{
					unsigned int initial_dim, block, max_dim, min_dim;

					printf("Inizializzazione:\n"
						   "Dimensione iniziale: ");
					scanf("%u", &initial_dim);
					printf("Blocco: \n");
					scanf("%u", &block);
					printf("Dimensione massima: \n");
					scanf("%u", &max_dim);
					printf("Dimensione minima: \n");
					scanf("%u", &min_dim);

					V = init_varr(V, initial_dim, block, max_dim, min_dim);

				}
			break;

			case 4:
				{
					unsigned int initial_dim;

					printf("Dimensione iniziale: ");
					scanf("%u", &initial_dim);
					V = set_initial_dim(V, initial_dim);
				}
			break;

			case 5:
				{
					unsigned int block;

					printf("Blocco: ");
					scanf("%u", &block);
					V = set_block(V, block);
				}
			break;

			case 6:
				{
					unsigned int max_dim;

					printf("Dimensione iniziale: ");
					scanf("%u", &max_dim);
					V = set_max_dim(V, max_dim);
				}
			break;

			case 7:
				{
					unsigned int min_dim;

					printf("Dimensione minima: ");
					scanf("%u", &min_dim);
					V = set_min_dim(V, min_dim);
				}
			break;

			case 8:
				{
					unsigned int index;
					int *val;

					printf("Inserisci indice: \n");
					scanf("%u", &index);
					val = malloc(sizeof(int));
					printf("Inserisci valore: \n");
					scanf("%d", val);
					if(set_loc(V, index, val))
						printf("Inserimento riuscito\n");
					else
						printf("Inserimento NON riuscito\n");

				}
			break;

			case 9:
				{
					unsigned int index;
					int *val;

					printf("Inserisci indice: \n");
					scanf("%u", &index);
					if(val = get_loc(V, index))
						printf("%u: %d\n", index, *((int *) val));
					else
						printf("%u: NULL\n", index);
				}
			break;

			case 10:
				{
					destroy_varr(V);
					is_exit = 1;
				}
			break;

			default:
				printf("Sei un cazzone\n");
		}

		printf("\n");
	}


	return 0;
}

void print_array_of_int(varr_t V)
{
	struct varr *varr = (struct varr *) V;
	printf("[n_blocks = \t %u\n"
		   "initial_dim = \t %u\n"
		   "block = \t %u\n"
		   "max_dim = \t %u\n"
		   "min_dim = \t %u\n"
		   "initialized = \t %d\n"
		   "length = \t %u]\n", varr->n_blocks, varr->initial_dim, varr->block, varr->max_dim, varr->min_dim, varr->initialized, get_length(varr));

	unsigned int i;
	printf("Valori:\n");
	short err_length;
	unsigned int length = get_length(varr);

	for(i = 0; i < length; i++)
	{
		int *val = get_loc(varr, i);
		if(val)
			printf("%u: %d\n", i, *val);
		else
			printf("%u: NULL\n", i);
	}
}