#ifndef REGISTER_H
#define REGISTER_H

typedef struct Register Register;

struct Register {
   short w;
   char h1;
   char h2;
   char l1;
   char l2;
};

void initRegister(Register* r);
void setRegisterValue(Register* r, short v);
void setRegisterValueWithBigEndian(Register* r, short v);
short registerValue(Register* r);

#endif
