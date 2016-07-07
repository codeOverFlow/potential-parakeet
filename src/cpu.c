#include "../include/cpu.h"

void initCpu(Cpu* cpu) {
   cpu->pc = ENTRY_POINT;
   cpu->sp = 0;
   cpu->flags = 0;
   for (int i = 0; i < NB_REGISTER; i++) {
      Register r;
      initRegister(&r);
      cpu->r[i] = r;
   }
   memset(cpu->stack, 0, STACK_DEPTH);
   memset(cpu->memory, 0, MEMORY_SIZE);
}
