#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

   
    void normalize() {
        minutes += seconds / 60;
        seconds %= 60;
        hours += minutes / 60;
        minutes %= 60;
    }

public:
    
    Time() : hours(0), minutes(0), seconds(0) {}

   
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

   
    friend Time operator+(const Time& t1, const Time& t2);

    
    void display() const {
        std::cout << (hours < 10 ? "0" : "") << hours << ":"
                  << (minutes < 10 ? "0" : "") << minutes << ":"
                  << (seconds < 10 ? "0" : "") << seconds << std::endl;
    }
};


Time operator+(const Time& t1, const Time& t2) {
    Time result;
    result.hours = t1.hours + t2.hours;
    result.minutes = t1.minutes + t2.minutes;
    result.seconds = t1.seconds + t2.seconds;
    result.normalize(); 
    return result;
}

int main() {
    int h1, m1, s1, h2, m2, s2;

    std::cout << "Enter first time period (HH MM SS): ";
    std::cin >> h1 >> m1 >> s1;

    std::cout << "Enter second time period (HH MM SS): ";
    std::cin >> h2 >> m2 >> s2;

    Time t1(h1, m1, s1);
    Time t2(h2, m2, s2);

    Time t3 = t1 + t2; 

    std::cout << "First time period: ";
    t1.display();

    std::cout << "Second time period: ";
    t2.display();

    std::cout << "Sum of the two time periods: ";
    t3.display();

    return 0;
}

