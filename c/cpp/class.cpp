#include <iostream>

class Car {
private:
  int x;

public:
  void print() {
    int x = 10;
    std::cout << "Car" << x << std::endl;
  }
};

class MyClass {
private:
  int y;
  Car car;

public:
  void print() { car.print(); }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  MyClass teste;
  // teste.print();
}
