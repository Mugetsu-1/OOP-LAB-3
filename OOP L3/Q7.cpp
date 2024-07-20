#include <iostream>

class Distance {
private:
    int feet;
    int inches;

    
    void normalize() {
        if (inches >= 12) {
            feet += inches / 12;
            inches = inches % 12;
        }
    }

public:
    
    Distance() : feet(0), inches(0) {}

   
    Distance(int f, int i) : feet(f), inches(i) {
        normalize();
    }

   
    friend bool operator<=(const Distance& d1, const Distance& d2);

    
    void display() const {
        std::cout << feet << " feet " << inches << " inches" << std::endl;
    }
};


bool operator<=(const Distance& d1, const Distance& d2) {
    int totalInches1 = d1.feet * 12 + d1.inches;
    int totalInches2 = d2.feet * 12 + d2.inches;
    return totalInches1 <= totalInches2;
}

int main() {
    Distance d1(5, 9); 
    Distance d2(6, 2); 

    std::cout << "Distance 1: ";
    d1.display();

    std::cout << "Distance 2: ";
    d2.display();

    if (d1 <= d2) {
        std::cout << "Distance 1 is less than or equal to Distance 2." << std::endl;
    } else {
        std::cout << "Distance 1 is greater than Distance 2." << std::endl;
    }

    return 0;
}

