#include <iostream>

class Student {
private:
    int visits;

public:
    
    Student(int v = 0) : visits(v) {}

    
    Student operator++(int) {
        Student temp = *this; 
        visits++; 
        return temp; 
    }

   
    void display() const {
        std::cout << "Number of visits: " << visits << std::endl;
    }
};

int main() {
    Student s1(5);

    std::cout << "Before increment:" << std::endl;
    s1.display();

    s1++; 

    std::cout << "After postfix increment:" << std::endl;
    s1.display();

    return 0;
}

