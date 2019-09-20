#ifndef BITSTRING_H
#define BITSTRING_H
#include <inttypes.h>

class Bitstring {
private:
        uint64_t b1;
        uint32_t b2;
public:
        Bitstring();
        Bitstring(uint64_t b1, uint32_t b2);
        Bitstring _and(Bitstring bs2);
        Bitstring _or(Bitstring bs2);
        Bitstring _xor(Bitstring bs2);
        Bitstring _not();
        void shiftLeft(int m);
        void shiftRight(int m);
        int counter();
        bool compare(Bitstring bs2);
        bool includes(Bitstring bs2);
        void print();
};

#endif
