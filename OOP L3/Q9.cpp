#include <iostream>

class Rupees {
private:
    int rs;
    int paisa;

public:
    
    Rupees() : rs(0), paisa(0) {}

    
    Rupees(int r, int p) : rs(r), paisa(p) {}

    
    void display() const {
        std::cout << rs << " rupees " << paisa << " paisa" << std::endl;
    }

   
    friend class Dollar;
};

class Dollar {
private:
    int dol;
    int cent;

public:
   
    Dollar() : dol(0), cent(0) {}

   
    Dollar(int d, int c) : dol(d), cent(c) {}

   
    operator Rupees() const {
        
        int totalCents = dol * 100 + cent;

       
        double totalRupees = totalCents * 0.825;
        
       
        int rupees = static_cast<int>(totalRupees);
        int paisa = static_cast<int>((totalRupees - rupees) * 100);

        return Rupees(rupees, paisa);
    }

    
    void display() const {
        std::cout << dol << " dollars " << cent << " cents" << std::endl;
    }
};

int main() {
    Dollar dollarObj(10, 50); 
    Rupees rupeesObj = dollarObj; 

    std::cout << "Dollar object: ";
    dollarObj.display();

    std::cout << "Converted Rupees object: ";
    rupeesObj.display();

    return 0;
}

