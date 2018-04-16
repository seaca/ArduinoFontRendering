#include "ringBuf.h"
#include <Wire.h> // I2C

#define SLAVE_ID 198

volatile RingBuffer ringBufIn;

void setup() {
  Wire.begin(SLAVE_ID);
  Wire.onReceive(rcvHdr);
  Wire.onRequest(reqHdr);
}

void loop() {
  
  delay(100);
}

void rcvHdr(int num){
  while (Wire.available()){
    ringBuf.push(Wire.read());
  }
}

void reqHdr(){
  while(ringBuf.size()){
    byte tmp;
    ringBuf.pop(&tmp);
    Wire.write(tmp);
  }
}

