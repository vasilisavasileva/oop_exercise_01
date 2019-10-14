#include <iostream>
#include "Bitstring.h"


int main(){
  int m, n;
  bool l;
  std::cout << "Введите значения строки 1\n";
  Bitstring BS1;
  BS1.read(std::cin);
  std::cout << "Введите значения строки 2\n";
  Bitstring BS2;
  BS2.read(std::cin);
  std::cout << "Введите количество битов для сдвига\n";
  std::cin >> n;
  std::cout << "Первая строка\n";
  BS1.print(std::cout);
  std::cout << "Вторая строка\n";
  BS2.print(std::cout);
  std::cout << "and\n";
  BS1._and(BS2).print(std::cout);
  std::cout << "or\n";
  BS1._or(BS2).print(std::cout);
  std::cout << "xor\n";
  BS1._xor(BS2).print(std::cout);
  std::cout << "not\n";
  BS1._not().print(std::cout);
  std::cout << "BS1 shiftleft\n";
  BS1.shiftLeft(n).print(std::cout);
  std::cout << "BS2 shiftleft\n";
  BS2.shiftLeft(n).print(std::cout);
  std::cout << "BS1 shiftRight\n";
  BS1.shiftRight(n).print(std::cout);
  std::cout << "BS2 shiftRight\n";
  BS2.shiftRight(n).print(std::cout);
  std::cout << "count units BS1\n";
  m = BS1.counter();
  std::cout << m << std::endl;
  std::cout << "count units BS2\n";
  m = BS2.counter();
  std::cout << m << std::endl;
  std::cout << "comparing units\n";
  l = BS1.compare(BS2);
  std::cout << l << std::endl;
  std::cout << "includes BS1 BS2\n";
  l = BS1.includes(BS2);
  std::cout<< l << std::endl;
  return 0;
}