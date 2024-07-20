#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int age;
    int visits;

public:
    
    Student() : name(""), age(0), visits(0) {}

   
    Student(const std::string& n, int a, int v) : name(n), age(a), visits(v) {}

    
    friend std::ostream& operator<<(std::ostream& os, const Student& s);

   
    friend std::istream& operator>>(std::istream& is, Student& s);
};


std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << "Name: " << s.name << "\nAge: " << s.age << "\nVisits: " << s.visits;
    return os;
}


std::istream& operator>>(std::istream& is, Student& s) {
    std::cout << "Enter name: ";
    is >> s.name;
    std::cout << "Enter age: ";
    is >> s.age;
    std::cout << "Enter visits: ";
    is >> s.visits;
    return is;
}

int main() {
    Student s1;

    std::cout << "Enter details for the student:\n";
    std::cin >> s1;

    std::cout << "\nStudent details:\n";
    std::cout << s1;

    return 0;
}

