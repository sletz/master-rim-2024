
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* Generateur de créneau */

float* table_square;
int table_size_square;
int phase_square;

/* Création et remplissage de la table avec un période du signal */
void init_square(int sample_rate, int freq)
{
    table_size_square = (int)((float)sample_rate / (float)freq);
    printf("table_size_square: %d\n", table_size_square);
    
    /* Alloue dynamiquement une table. */
    table_square = (float*)malloc(table_size_square * sizeof(float));
    
    /* Remplit la table */
    int i;
    // Génération de la 1° moitié
    for (i = 0; i < table_size_square/2; i = i + 1) {
        table_square[i] = -1.f;
    }
    // Génération de la 2° moitié
    for (i = table_size_square/2; i < table_size_square; i = i + 1) {
        table_square[i] = 1.f;
    }

    /* Initialise la phase */
    phase_square = 0;
}

void destroy_square()
{
    /* Desalloue le tableau. */
    free(table_square);
}

/* Copie 'nframes' echantillons de la table dans le buffer output et gestion de la phase */
void process_square(float* output, int nframes)
{
    int i;
    for (i = 0; i < nframes; i++) {
        output[i] = table_square[phase_square];
        phase_square = phase_square + 1;
        if (phase_square == table_size_square) {
            phase_square = 0;
        }
    }
}

/* Retourne 1 echantillon et gestion de la phase */
float process_one_sample_square()
{
    float res = table_square[phase_square];
    phase_square = phase_square + 1;
    if (phase_square == table_size_square) {
        phase_square = 0;
    }
    return res;
}

void display_table_square()
{
    int i;
    for (i = 0; i < table_size_square; i++) {
        printf("Sample %f\n", table_square[i]);
    }
}

int main()
{
    init_square(44100, 200);
    display_table_square();
    
    // Simuler l'audio: génère une séquence de 500 samples
    printf("==================\n");
    printf("Simuler l'audio\n");
    
    // A COMPLETER
}
