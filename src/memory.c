#include "memory.h"

int *resolveThrMemory(int desloc, THR_mepa *thread_mepa) {
  if (desloc > thread_mepa->memoryDesloc) {
    return &(thread_mepa->thrVetorPilha[desloc - thread_mepa->memoryDesloc - 1]);
  } else {
    return &(thread_mepa->mainVetorPilha[desloc]);
  }
}

int *memorySolver(int desloc, THR_mepa *thread_mepa) {
  if (thread_mepa == NULL) {
    return &(mv_mepa_M[desloc]);
  } else {
    return resolveThrMemory(desloc, thread_mepa);
  }
}