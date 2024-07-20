#include <iostream>

class Number {
private:
    int value;

public:
   
    Number(int v) : value(v) {}

    
    friend Number operator-(const Number& n);

  
    void display() const {
        std::cout << value << std::endl;
    }
};


Number operator-(const Number& n) {
    return Number(-n.value);
}

int main() {
    Number num1(5);
    Number num2 = -num1;

    std::cout << "Original value: ";
    num1.display();

    std::cout << "After applying unary minus: ";
    num2.display();

    return 0;
}

