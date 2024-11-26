#ifndef THREAD_MEPA_H
#define THREAD_MEPA_H

#include "MV_mepa.h"

#define TAM_THR 24

typedef struct THR_mepa {
  int *mainVetorPilha;
  int *thrVetorPilha;
  int *vetorRegBase;
  int i;
  int s;

  int memoryDesloc;
  int identificador;

  pthread_t thread_id;
  FILE *log;
} THR_mepa;

THR_mepa *cria_THR_mepa(int *M, int *D, int i, int s, int lexic_level,
                        int identificador);
void inicia_THR_mepa(THR_mepa *thread_mepa);
void espera_encerrar_THR_mepa(int identificador);

#endif