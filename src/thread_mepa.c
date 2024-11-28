#include "thread_mepa.h"
#include "MV_mepa.h"
#include "executaMepa.h"
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
    if (thread_mepas[i] == NULL)
      continue;
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

void freeThread(THR_mepa *thread_mepa) {
  free(thread_mepa->thrVetorPilha);
  free(thread_mepa->vetorRegBase);
  fclose(thread_mepa->log);
  free(thread_mepa);
}

int remove_thread_by_index(int index) {
  if (index == -1)
    return 0;

  thread_mepas[index] = NULL;
  size_thread_mepas--;

  return 1;
}

void remove_thread(int index, THR_mepa *thread_mepa) {
  remove_thread_by_index(index);
  freeThread(thread_mepa);
}

void *executaThreadMepa(void *arg) {
  THR_mepa *thread_mepa = (THR_mepa *)arg;

  instrucao_mepa instr_exec;
  cmd_usr cmd;

  do {
    instr_exec = executa_instr_THR_mepa(thread_mepa);
    
    if (instr_exec == para || instr_exec == sthr) {
      printf("Thread de id: %d com pid: %lu execução finalizada\n", thread_mepa->identificador, thread_mepa->thread_id);
      break;
    }
  } while (1);
}

THR_mepa *cria_THR_mepa(int *M, int *D, int i, int s,
                        int lexic_level, int identificador) {
  THR_mepa *thread_mepa = (THR_mepa *)malloc(sizeof(THR_mepa));

  // Create M for thread and link main M
  thread_mepa->mainVetorPilha = M;
  thread_mepa->thrVetorPilha = (int *)malloc(sizeof(int) * 1024);
  thread_mepa->thrVetorPilha[0] = identificador;

  // Copy D
  thread_mepa->vetorRegBase = (int *)malloc(sizeof(int) * 1024);
  memcpy(thread_mepa->vetorRegBase, D, sizeof(int) * 1024);

  thread_mepa->i = i;
  thread_mepa->memoryDesloc = s;
  thread_mepa->s = s;
  thread_mepa->vetorRegBase[lexic_level] = s + 1;
  thread_mepa->identificador = identificador;

  // Create log file
  char filename[50];
  sprintf(filename, "%d-log.txt", identificador);
  thread_mepa->log = fopen(filename, "w");
  setbuf(thread_mepa->log, NULL);

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
  remove_thread(index, thread_mepas[index]);
}