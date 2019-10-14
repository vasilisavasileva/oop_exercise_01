#include "Bitstring.h"
#include <iostream>
#include <inttypes.h>

Bitstring::Bitstring(){                                                                                                                                                     this->b1 = 0;
  this->b2 = 0;
}

Bitstring::Bitstring(uint64_t b1, uint32_t b2){
  this->b1 = b1;
  this->b2 = b2;
}

Bitstring Bitstring::_and(const Bitstring& bs2) const{                                                                                                                      Bitstring bs3{(this->b1)&(bs2.b1),(this->b2)&(bs2.b2)};                                                                                                                   return bs3;
}

Bitstring Bitstring::_or(const Bitstring& bs2) const{
  Bitstring bs3{(this->b1)|(bs2.b1),(this->b2)|(bs2.b2)};
  return bs3;
}

Bitstring Bitstring::_xor(const Bitstring& bs2) const{
  Bitstring bs3{(this->b1)^(bs2.b1),(this->b2)^(bs2.b2)};                                                                                                                   return bs3;
}

Bitstring Bitstring::_not() const{
  Bitstring bs3{~(this->b1),~(this->b2)};
  return bs3;
}

Bitstring Bitstring::shiftLeft(int m) const{
  uint32_t a,t2 = b2;                                                                                                                                                       uint64_t t1 = b1;                                                                                                                                                         a = 1;                                                                                                                                                                    a <<= 31;                                                                                                                                                                 for(int i = 0; i < m; i++){                                                                                                                                                 if((t2&a) > 0){  
      t1 <<= 1;                                                                                                                                                                 t2 <<= 1;
      t1 = t1 + 1;
    }
    else{                                                                                                                                                                       t1 <<= 1;                                                                                                                                                                 t2 <<= 1;
    }                                                                                                                                                                       }
return Bitstring(t1,t2);
}

Bitstring Bitstring::shiftRight(int m) const{
  uint64_t a,t1 = b1;
  uint32_t b,t2 = b2;                                                                                                                                                       b = 1;                                                                                                                                                                    b <<= 31;                                                                                                                                                                 a = 1;                                                                                                                                                                    for(int i = 0; i < m; i++){                                                                                                                                                 if((t1&a) > 0){                                                                                                                                                             t1 >>= 1;      
 t2 >>= 1;
      t2 = t2 + b;
    }
    else{
      t1 >>= 1;
      t2 >>= 1;                                                                                                                                                             }
  }
return Bitstring(t1,t2);
}

int Bitstring::counter() const{
  uint64_t a = 1;                                                                                                                                                           uint32_t b = 1;                                                                                                                                                           uint64_t l;                                                                                                                                                               uint32_t l1;                                                                                                                                                              int count = 0;
                                                                                                                                                                            for(int i = 0; i < 63; i++){                                                                                                                                                l = (this->b1)&a;                                                                                                                                                         if(l != 0){   
  ++count;
    }                                                                                                                                                                         a <<= 1;
  }
  for(int i = 0; i < 32; i++){                                                                                                                                                l1 = (this->b2)&b;                                                                                                                                                        if(l1 != 0){                                                                                                                                                                ++count;                                                                                                                                                                }
    b <<= 1;
  }
  return count;
}


bool Bitstring::compare(const Bitstring& bs2) const{                                                                                                                        int a = this->counter();                                                                                                                                                  int b = bs2.counter();                                                                                                                                                    if(a == b)                                                                                                                                                                  return true;                                                                                                                                                            return false;         
}

bool Bitstring::includes(const Bitstring& BS2) const{
  if(((this->b1)&(BS2.b1)) == BS2.b1)                                                                                                                                         if(((this->b2)&(BS2.b2)) == BS2.b2)                                                                                                                                         return true;                                                                                                                                                          return false;

}


void Bitstring::print(std::ostream& out) const{

        uint64_t a = 1;
        a<<=63;                                                                                                                                                                   uint32_t b = 1;                                                                                                                                                           b <<=31;                                                                                                                                                                  for(int i = 0;i<64;i++){                                                                                                                                                          out<< ((a & this->b1) > 0);                                                                                                                                               a>>=1;
        }
        for(int i = 0;i<32;i++){
                out<< ((b & this->b2) > 0);
                b>>=1;                                                                                                                                                            }
        out<<std::endl;
}

void Bitstring::read(std::istream& in){
  in >> b1 >> b2;
}