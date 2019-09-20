#include "Bitstring.h"
#include <iostream>
#include <inttypes.h>

Bitstring::Bitstring(){
  this->b1 = 0;
  this->b2 = 0;
}

Bitstring::Bitstring(uint64_t b1, uint32_t b2){
  this->b1 = b1;
  this->b2 = b2;
}

Bitstring Bitstring::_and(Bitstring bs2){
  Bitstring bs3{(this->b1)&(bs2.b1),(this->b2)&(bs2.b2)};
  return bs3;
}

Bitstring Bitstring::_or(Bitstring bs2){
  Bitstring bs3{(this->b1)|(bs2.b1),(this->b2)|(bs2.b2)};
  return bs3;
}

Bitstring Bitstring::_xor(Bitstring bs2){
  Bitstring bs3{(this->b1)^(bs2.b1),(this->b2)^(bs2.b2)};
  return bs3;
}

Bitstring Bitstring::_not(){
  Bitstring bs3{~(this->b1),~(this->b2)};
  return bs3;
}

void Bitstring::shiftLeft(int m){
  uint32_t a;
  a = 1;
  a <<= 31;
  for(int i = 0; i < m; i++){
    if(((this->b2)&a) > 0){
      this->b1 <<= 1;
       this->b2 <<= 1;
      this->b1 = this->b1 + 1;
    }
    else{
      this->b1 <<= 1;
      this->b2 <<= 1;
    }
  }
}

void Bitstring::shiftRight(int m){
  uint64_t a;
  uint32_t b;
  b = 1;
  b <<= 31;
  a = 1;
  for(int i = 0; i < m; i++){
    if(((this->b1)&a) > 0){
      this->b1 >>= 1;
      this->b2 >>= 1;
      this->b2 = this->b2 + b;
        }
    else{
      this->b1 >>= 1;
      this->b2 >>= 1;
  }
  }
}

int Bitstring::counter(){
  uint64_t a = 1;
  uint32_t b = 1;
  uint64_t l;
  uint32_t l1;
  int count = 0;

  for(int i = 0; i < 63; i++){
    l = (this->b1)&a;
    if(l != 0){
      ++count;
    }
    a <<= 1;
     }
  for(int i = 0; i < 32; i++){
    l1 = (this->b2)&b;
    if(l1 != 0){
      ++count;
    }
    b <<= 1;
  }
  return count;
}


bool Bitstring::compare(Bitstring bs2){
  int a = this->counter();
  int b = bs2.counter();
  if(a == b)
    return true;
  return false;

}
bool Bitstring::includes(Bitstring BS2){
  if(((this->b1)&(BS2.b1)) == BS2.b1)
    if(((this->b2)&(BS2.b2)) == BS2.b2)
      return true;
  return false;

}


void Bitstring::print(){

        uint64_t a = 1;
        a<<=63;
        uint32_t b = 1;
        b <<=31;
        for(int i = 0;i<64;i++){
                std::cout<< ((a & this->b1) > 0);
                a>>=1;
        }
        for(int i = 0;i<32;i++){
                std::cout<< ((b & this->b2) > 0);
                   b>>=1;
        }
        std::cout<<std::endl;
}

