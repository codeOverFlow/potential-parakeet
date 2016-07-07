#include "../include/register.h"

void setRegisterValue(Register* r, short v) {
   r->l2 = (v & 0xf000) >> 12;
   r->l1 = (v & 0x0f00) >> 8;
   r->h2 = (v & 0x00f0) >> 4;
   r->h1 = v & 0x000f;
   r->w = v;
}

void setRegisterValueWithBigEndian(Register* r, short v) {
   r->h1 = (v & 0xf000) >> 12;
   r->h2 = (v & 0x0f00) >> 8;
   r->l1 = (v & 0x00f0) >> 4;
   r->l2 =  v & 0x000f;
   r->w = (r->l2 << 12) + (r->l1 << 8) + (r->h2 << 4) + r->h1;
}

void initRegister(Register* r) {
   setRegisterValue(r, 0);
}

short registerValue(Register* r) {
   return (r->h1 << 12) + (r->h2 << 8) + (r->l1 << 4) + r->l2;
}
