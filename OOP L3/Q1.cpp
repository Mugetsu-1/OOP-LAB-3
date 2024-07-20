#include <iostream>
#include <cstring> 

class MyString {
private:
    char* str; 
public:
    
    MyString(const char* s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    
    MyString(const MyString& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    
    ~MyString() {
        delete[] str;
    }

    
    MyString operator+(const MyString& other) const {
        char* newStr = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(newStr, str);
        strcat(newStr, other.str);
        
        MyString result(newStr);
        delete[] newStr; 
        return result;
    }

    
    void display() const {
        std::cout << str;
    }
};

int main() {
    MyString s1("Hello, ");
    MyString s2("world!");
    MyString s3 = s1 + s2;

    s3.display(); 

    return 0;
}

