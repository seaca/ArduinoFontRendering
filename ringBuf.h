#ifndef RINGBUFH
#define RINGBUFH

#include <arduino.h>
#define RBUFSIZE 32

class RingBuffer{
  byte *buf;
  int top, btm;

public:
  RingBuffer(){
    buf = new byte[RBUFSIZE];
    top = btm = 0;
  }
  
  ~RingBuffer(){
    delete[] buf;
  }

  // ret: success -> 0, failed-> -1
  int push(byte din);
  // ret: success -> 0, failed-> -1
  int pop(byte *dout);
  int size();
};



#endif
