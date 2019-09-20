
#include <iostream>
#include "Bitstring.h"


int main(){
  uint64_t a;
  uint32_t b;
  int m, n;
  bool l;
  std::cout << "Введите значения строки 1\n";
    std::cin >> a >> b;
  Bitstring BS1 = Bitstring(a, b);
  std::cout << "Введите значения строки 2\n";
    std::cin >> a >> b;
  Bitstring BS2 = Bitstring(a, b);
  std::cout << "Введите количество битов для сдвига\n";
  std::cin >> n;
  Bitstring BS3;
  std::cout << "Первая строка\n";
  BS1.print();
  std::cout << "Вторая строка\n";
  BS2.print();
  std::cout << "and\n";
  BS3 = BS1._and(BS2);
  BS3.print();
  std::cout << "or\n";
  BS3 = BS1._or(BS2);
  BS3.print();
  std::cout << "xor\n";
  BS3 = BS1._xor(BS2);
  BS3.print();
  std::cout << "not\n";
  BS3 = BS1._not();
  BS3.print();
  std::cout << "BS1 shiftleft\n";
  BS1.shiftLeft(n);
  BS1.print();
  std::cout << "BS2 shiftleft\n";
  BS2.shiftLeft(n);
  BS2.print();
   std::cout << "BS1 shiftRight\n";
  BS1.shiftRight(n);
  BS1.print();
  std::cout << "BS2 shiftRight\n";
  BS2.shiftRight(n);
  BS2.print();
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
