
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* Generateur de sawtooth */

float* table_sawtooth;
int table_size_sawtooth;
int phase_sawtooth;

/* Création et remplissage de la table avec un période du signal */
void init_sawtooth(int sample_rate, int freq)
{
    table_size_sawtooth = (int)((float)sample_rate / (float)freq);
    printf("table_size_sawtooth: %d\n", table_size_sawtooth);
    
    /* Alloue dynamiquement une table. */
    table_sawtooth = (float*)malloc(table_size_sawtooth * sizeof(float));
    
    /* Remplit la table */
    for (int i = 0; i < table_size_sawtooth; i = i + 1) {
        table_sawtooth[i] = (2.f * i/(float)table_size_sawtooth) - 1.f;
    }

    /* Initialise la phase */
    phase_sawtooth = 0;
}

void destroy_sawtooth()
{
    /* Desalloue le tableau. */
    free(table_sawtooth);
}

/* Copie 'nframes' echantillons de la table dans le buffer output et gestion de la phase */
void process_sawtooth(float* output, int nframes)
{
    int i;
    for (i = 0; i < nframes; i++) {
        output[i] = table_sawtooth[phase_sawtooth];
        phase_sawtooth = phase_sawtooth + 1;
        if (phase_sawtooth == table_size_sawtooth) {
            phase_sawtooth = 0;
        }
    }
}
/* Retourne 1 echantillon et gestion de la phase */
float process_one_sample_sawtooth()
{
    float res = table_sawtooth[phase_sawtooth];
    phase_sawtooth = phase_sawtooth + 1;
    if (phase_sawtooth == table_size_sawtooth) {
        phase_sawtooth = 0;
    }
    return res;
}

void display_sawtooth()
{
    int i;
    for (i = 0; i < table_size_sawtooth; i++) {
        printf("Sample %f\n", table_sawtooth[i]);
    }
}

int main()
{
    init_sawtooth(44100, 200);
    display_sawtooth();
    
    // Simuler l'audio: génère une séquence de 500 samples
    printf("==================\n");
    printf("Simuler l'audio\n");
    
    for (int i = 0; i < 500; i++) {
        printf("Sample %f\n", process_one_sample_sawtooth());
    }
}
