#include "Array.hpp"

int main() {
    // Test default constructor
    Array<int> intArray1;
    std::cout << "Default constructed array size: " << intArray1.getSize() << std::endl;

    // Test constructor with size
    Array<double> doubleArray(5);
    for (unsigned int i = 0; i < doubleArray.getSize(); i++) {
        doubleArray[i] = i * 3.14;
    }
    std::cout << "Contents of doubleArray: ";
    for (unsigned int i = 0; i < doubleArray.getSize(); i++) {
        std::cout << doubleArray[i] << " ";
    }
    std::cout << std::endl;

    // Test copy constructor
    Array<int> intArray2(intArray1); // Should be empty
    Array<char> charArray('z');
    Array<char> charArray2(charArray); // Should contain 'z'

    std::cout << "Copied intArray2 size: " << intArray2.getSize() << std::endl;
    std::cout << "Copied charArray2: ";
    for (unsigned int i = 0; i < charArray2.getSize(); i++) {
        std::cout << charArray2[i];
    }
    std::cout << std::endl;

    // // Test assignment operator
    // intArray1 = doubleArray; // Assign different types (if types are assignable)
    // std::cout << "intArray1 after assignment: ";
    // for (unsigned int i = 0; i < intArray1.getSize(); i++) {
    //     std::cout << intArray1[i] << " ";
    // }
    // std::cout << std::endl;

    // Test out-of-bounds access
    try {
        intArray1[10] = 42; // Should trigger exception
    } catch (const Array<int>::IndexOutOfBounds& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

