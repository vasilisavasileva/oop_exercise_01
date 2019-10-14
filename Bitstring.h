#ifndef BITSTRING_H
#define BITSTRING_H
#include <inttypes.h>
#include <iostream>
class Bitstring {
private:
        uint64_t b1;
        uint32_t b2;
public:
        Bitstring();
        Bitstring(uint64_t b1, uint32_t b2);
        Bitstring _and(const Bitstring& bs2) const;
        Bitstring _or(const Bitstring& bs2) const;
        Bitstring _xor(const Bitstring& bs2) const;
        Bitstring _not() const;
        Bitstring shiftLeft(int m) const;
        Bitstring shiftRight(int m) const;
        int counter() const;
        bool compare(const Bitstring& bs2) const;
        bool includes(const Bitstring& bs2) const;
        void print(std::ostream& out) const;
        void read(std::istream& in);
};

#endif