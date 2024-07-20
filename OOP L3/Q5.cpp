#include <iostream>

class Height {
private:
    int meter;
    int centimeter;

public:
    
    Height() : meter(0), centimeter(0) {}

    
    Height(int m, int cm) : meter(m), centimeter(cm) {}

   
    friend Height operator+(const Height& h1, const Height& h2);

    
    void display() const {
        std::cout << meter << " meters and " << centimeter << " centimeters" << std::endl;
    }

   
    void normalize() {
        meter += centimeter / 100;
        centimeter = centimeter % 100;
    }
};


Height operator+(const Height& h1, const Height& h2) {
    Height result;
    result.meter = h1.meter + h2.meter;
    result.centimeter = h1.centimeter + h2.centimeter;
    result.normalize();
    return result;
}

int main() {
    Height h1(2, 80); 
    Height h2(1, 45); 

    Height h3 = h1 + h2;

    std::cout << "Height 1: ";
    h1.display();

    std::cout << "Height 2: ";
    h2.display();

    std::cout << "Height 3 (sum of Height 1 and Height 2): ";
    h3.display();

    return 0;
}

