#ifndef CPU_H
#define CPU_H

#include "constants.h"
#include "register.h"

#include <string.h>

typedef struct Cpu {
   short pc;
   short sp;
   Register r[NB_REGISTER];
   short stack[STACK_DEPTH];
   char flags;
   char memory[MEMORY_SIZE];
} Cpu;

void initCpu(Cpu* cpu);

#endif
