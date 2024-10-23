#ifndef THREAD_MEPA_H
#define THREAD_MEPA_H

#include "MV_mepa.h"

#define TAM_THR 24

typedef struct THR_mepa {
  int *vetorPilha;
  int *vetorRegBase;
  instStruct *vetorInstr;
  int tam_i;
  int i;
  int s;

  int identificador;

  pthread_t thread_id;
} THR_mepa;

THR_mepa *cria_THR_mepa(int *M, int *D, instStruct *I, int tam_i, int i, int s,
                        int identificador);
void inicia_THR_mepa(THR_mepa *thread_mepa);
void espera_encerrar_THR_mepa(int identificador);

#endif