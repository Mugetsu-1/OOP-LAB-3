#include <iostream>

class Kilometer;

class Feet {
private:
    int ft;
    int inch;

public:
   
    Feet() : ft(0), inch(0) {}

   
    Feet(int f, int i) : ft(f), inch(i) {}

   
    int getFeet() const { return ft; }
    int getInches() const { return inch; }

    
    void display() const {
        std::cout << ft << " feet " << inch << " inches" << std::endl;
    }

   
    friend class Kilometer;
};

class Kilometer {
private:
    int km;
    int m;

public:
   
    Kilometer() : km(0), m(0) {}

   
    Kilometer(int k, int me) : km(k), m(me) {}

   
    Kilometer(const Feet& f) {
        
        int totalFeet = f.ft + f.inch / 12.0;
        
        double totalKilometers = totalFeet / 328.0;
        km = static_cast<int>(totalKilometers);
        m = static_cast<int>((totalKilometers - km) * 1000);
    }

    
    void display() const {
        std::cout << km << " kilometers " << m << " meters" << std::endl;
    }
};

int main() {
    Feet feetObj(984, 0); 
    Kilometer kmObj = feetObj; 

    std::cout << "Feet object: ";
    feetObj.display();

    std::cout << "Converted Kilometer object: ";
    kmObj.display();

    return 0;
}

