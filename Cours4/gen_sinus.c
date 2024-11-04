 
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
    for (int i = 0; i < table_size_sinus; i++) {
        table_sinus[i] = sin(2.f * M_PI * i/(float)table_size_sinus);
    }
    
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
    int i;
    for (i = 0; i < nframes; i++) {
        output[i] = table_sinus[phase_sinus];
        phase_sinus = phase_sinus + 1;
        if (phase_sinus == table_size_sinus) {
            phase_sinus = 0;
        }
    }
}

/* Retourne 1 echantillon et gestion de la phase */
float process_one_sample_sinus()
{
    float res = table_sinus[phase_sinus];
    phase_sinus = phase_sinus + 1;
    if (phase_sinus == table_size_sinus) {
        phase_sinus = 0;
    }
    return res;
}

void display_sinus()
{
    int i;
    for (i = 0; i < table_size_sinus; i++) {
        printf("Sample %f\n", table_sinus[i]);
    }
}

int main()
{
    init_sinus(44100, 2000);
    display_sinus();
    
    // Simuler l'audio: génère une séquence de 500 samples
    printf("==================\n");
    printf("Simuler l'audio\n");
    
    for (int i = 0; i < 500; i++) {
        printf("Sample %f\n", process_one_sample_sinus());
    }
}
