#include <iostream>
class MyClass {
private:
    int secret1;
    float secret2;
    char secret3;
public:
    MyClass(int s1, float s2, char s3) : secret1(s1), secret2(s2), secret3(s3) {}
    void printMembers() const {
        std::cout << "secret1: " << secret1 << "\n";
        std::cout << "secret2: " << secret2 << "\n";
        std::cout << "secret3: " << secret3 << "\n";
    }
};
int main() {
    MyClass obj(42, 3.14f, 'A');
    // Usando reinterpret_cast para violar el encapsulamiento    
    int* ptrInt = reinterpret_cast<int*>(&obj);
    float* ptrFloat = reinterpret_cast<float*>(ptrInt + 1);
    char* ptrChar = reinterpret_cast<char*>(ptrFloat + 1);
    // Accediendo y mostrando los valores privados    
    std::cout << "Accediendo directamente a los miembros privados:\n";
    std::cout << "secret1: " << *ptrInt << "\n";
    // Accede a secret1    
    std::cout << "secret2: " << *ptrFloat << "\n";
    // Accede a secret2    
    std::cout << "secret3: " << *ptrChar << "\n";
    // Accede a secret3
    return 0;
}