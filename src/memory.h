#ifndef MEMORY_H
#define MEMORY_H

#include "MV_mepa.h"
#include "thread_mepa.h"

#define M(desloc) *memorySolver(desloc, thread_mepa)

int *memorySolver(int desloc, THR_mepa *thread_mepa);

#endif