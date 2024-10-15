 
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* Generateur sinus */

float* table_sinus;
int table_size_sinus;
int phase_sinus;

/* Création et remplissage de la table avec un période du signal */
void init_sinus(int sample_rate, int freq)
{
    table_size_sinus = (int)((float)sample_rate / (float)freq);
    printf("table_size_sinus: %d\n", table_size_sinus);
    
    /* Alloue dynamiquement une table. */
    table_sinus = (float*)malloc(table_size_sinus * sizeof(float));
    
    /* Remplit la table */
    // A COMPLETER
    
    /* Initialise la phase */
    phase_sinus = 0;
}

void destroy_sinus()
{
    /* Desalloue le tableau. */
    free(table_sinus);
}

/* Copie 'nframes' echantillons de la table dans le buffer output et gestion de la phase */
void process_sinus(float* output, int nframes)
{
    // A COMPLETER
}

/* Retourne 1 echantillon et gestion de la phase */
float process_one_sample_sinus()
{
    // A COMPLETER
}

void display_sinus()
{
    // A COMPLETER
}

int main()
{
    init_sinus(44100, 200);
    display_sinus();
    
    // Simuler l'audio: génère une séquence de 500 samples
    printf("==================\n");
    printf("Simuler l'audio\n");
    
    // A COMPLETER
}
