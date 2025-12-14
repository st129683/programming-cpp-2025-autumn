#include <iostream>
#include <stdexcept>

template <class T>
class Array {
private:
    static const int DEFAULT_SIZE = 10;
    T* array;
    int size;

public:
    Array() : size(DEFAULT_SIZE) {
        array = new T[size];
    }

    Array(T* b, int arraySize) : size(arraySize) {
        array = new T[size];
        for (int i = 0; i < size; ++i) {
            array[i] = b[i];
        }
    }

    ~Array() {
        delete[] array;
    }

    void show() {
        for (int i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    T minimum() {
        if (size == 0) {
            throw std::runtime_error("Array is empty");
        }

        T minValue = array[0];
        for (int i = 1; i < size; ++i) {
            if (array[i] < minValue) {
                minValue = array[i];
            }
        }
        
        return minValue;
    }

    T minimum(Array<T>& m) {
        T thisMin = this->minimum();
        T otherMin = m.minimum();
        
        return (thisMin < otherMin) ? thisMin : otherMin;
    }
};

int main() {
    int data1[] = {1, 2, 3, 4, 5};
    int data2[] = {6, 7, 8, 9, 10};
    
    Array<int> arr1(data1, 5);
    Array<int> arr2(data2, 5);
    
    std::cout << "Array 1: ";
    arr1.show();
    
    std::cout << "Array 2: ";
    arr2.show();
    
    int result = arr1.minimum(arr2);
    std::cout << "Minimum of minimums: " << result << std::endl;
    
    return 0;
}
