#include "ringBuf.h"

int RingBuffer::push(byte din){
  if (this->size() >= RBUFSIZE) return -1;
  buf[top++] = din;
  top %= RBUFSIZE;
  return 0;
}

int RingBuffer::pop(byte *dout){
  if (this->size() == 0) return -1;
  *dout = buf[btm++];
  btm %= RBUFSIZE;
  return 0;
}

int RingBuffer::size(){
  return top>=btm ? top-btm : RBUFSIZE-(btm-top); 
}

