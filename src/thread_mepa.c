#include "thread_mepa.h"
#include "MV_mepa.h"
#include <pthread.h>
#include <unistd.h>

THR_mepa *thread_mepas[TAM_THR];
int size_thread_mepas = 0;

int add_thread(THR_mepa *thread_mepa) {
  if (size_thread_mepas < 24) {
    for (int i = 0; i < TAM_THR; i++) {
      if (thread_mepas[i] == NULL) {
        thread_mepas[i] = thread_mepa;
        size_thread_mepas++;
        
        return 1;
      }
    }
  }

  return 0;
}

int find_thread_by_identifier(int identificador) {
  for (int i = 0; i < TAM_THR; i++) {
    if (thread_mepas[i]->identificador == identificador) {
      return i;
    }
  }

  return -1;
}

int find_thread(THR_mepa *thread_mepa) {
  for (int i = 0; i < TAM_THR; i++) {
    if (thread_mepas[i] == thread_mepa) {
      return i;
    }
  }

  return -1;
}

int remove_thread_by_index(int index) {
  if (index == -1)
    return 0;

  thread_mepas[index] = NULL;
  size_thread_mepas--;

  return 1;
}

int remove_thread(THR_mepa *thread_mepa) {
  int index = find_thread(thread_mepa);

  return remove_thread_by_index(index);
}

void *executaThreadMepa(void *arg) {
  THR_mepa *thread_mepa = (THR_mepa *)arg;

  instrucao_mepa instr_exec;

  do {
    instr_exec = executa_instr_THR_mepa(thread_mepa);
    // if (plc->interativo)
    //   imprime_estado_MV_mepa_interativo();
    // else
    //  imprime_estado_MV_mepa_batch();

    if (instr_exec == para || instr_exec == sthr) {
      printf("Thread %i execução finalizada\n", (int)thread_mepa->thread_id);
      break;
    }

    // if (plc->interativo) {
    //   cmd = le_comando();
    //   if (cmd == resume)
    //     plc->interativo = 0;
    // }
    // } while (cmd != sair);
  } while (1);
}

THR_mepa *cria_THR_mepa(int *M, int *D, instStruct *I, int tam_i, int i,
                        int s, int identificador) {
  THR_mepa *thread_mepa = (THR_mepa *)malloc(sizeof(THR_mepa));

  // copia vetor pilha
  thread_mepa->vetorPilha = (int *)malloc(sizeof(int) * 1024);
  memcpy(thread_mepa->vetorPilha, M, sizeof(int) * s);
  // copia verot reg base
  thread_mepa->vetorRegBase = (int *)malloc(sizeof(int) * 1024);
  memcpy(thread_mepa->vetorRegBase, D, sizeof(int) * 1024);
  thread_mepa->vetorInstr = I;
  thread_mepa->tam_i = tam_i;
  thread_mepa->i = i;
  thread_mepa->s = s;
  thread_mepa->identificador = identificador;

  return thread_mepa;
}

void inicia_THR_mepa(THR_mepa *thread_mepa) {
  add_thread(thread_mepa);

  pthread_create(&(thread_mepa->thread_id), NULL, executaThreadMepa,
                 thread_mepa);
}

void espera_encerrar_THR_mepa(int identificador) {
  int index = find_thread_by_identifier(identificador);

  if (index == -1)
    return;

  pthread_join(thread_mepas[index]->thread_id, NULL);

  remove_thread(thread_mepas[index]);
}