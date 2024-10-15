
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* Generateur de rampe */

float* table_rampe;
int table_size_rampe;
int phase_rampe;

/* Création et remplissage de la table avec un période du signal */
void init_rampe(int sample_rate, int freq)
{
    table_size_rampe = (int)((float)sample_rate / (float)freq);
    printf("table_size_rampe: %d\n", table_size_rampe);
    
    /* Alloue dynamiquement une table. */
    table_rampe = (float*)malloc(table_size_rampe * sizeof(float));
    
    /* Remplit la table */
    // A COMPLETER

    /* Initialise la phase */
    phase_rampe = 0;
}

void destroy_rampe()
{
    /* Desalloue le tableau. */
    free(table_rampe);
}

/* Copie 'nframes' echantillons de la table dans le buffer output et gestion de la phase */
void process_rampe(float* output, int nframes)
{
    // A COMPLETER
}
/* Retourne 1 echantillon et gestion de la phase */
float process_one_sample_rampe()
{
    // A COMPLETER
}

void display_rampe()
{
    // A COMPLETER
}

int main()
{
    init_rampe(44100, 200);
    display_rampe();
    
    // Simuler l'audio: génère une séquence de 500 samples
    printf("==================\n");
    printf("Simuler l'audio\n");
    
    // A COMPLETER
}
