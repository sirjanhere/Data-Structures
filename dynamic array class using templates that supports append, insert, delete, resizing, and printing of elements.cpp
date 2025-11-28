#include <iostream>
using namespace std;

#define INITIAL_CAPACITY 5

template <class T>
class dynamic_array {
    T *array;
    int MIN_CAPACITY = INITIAL_CAPACITY;
    int GROWTH_FACTOR = 2;
    int size;

public:
    // constructor init
    dynamic_array() {
        array = new T[MIN_CAPACITY];
        size = 0;
    }

    // append @ the end
    void append(T element) {
        if (size == MIN_CAPACITY) {
            cout << "minimum capacity original.." << MIN_CAPACITY << endl << "resized called..." << endl;
            resize();
        }
        array[size] = element;
        size++;
    }

    void deleteAt(int pos) {
        if ((pos > size) || (pos < 0)) {
            cout << "Invalid index";
            return;
        }
        cout << "Shifting elements....for emptying position: " << pos << endl;
        for (int i = pos; i <= size; i++) {
            array[i] = array[i + 1];
        }
        size--;
        cout << "element deleted ..and current size is ..." << size << endl;
    }

    void printarray() {
        cout << "Array:" << endl;
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void insertAt(T element, int pos) {
        if ((pos > size) || (pos < 0)) {
            cout << "Invalid index";
            return;
        }
        if (size == MIN_CAPACITY) {
            cout << "minimum capacity original.." << MIN_CAPACITY << endl << "resized called..." << endl;
            resize();
        }
        size++;
        cout << "inserting element: " << element << " and size after resized while entering an element.." << size << endl;
        for (int i = size - 1; i >= pos; i--) {
            if (i == pos) {
                array[i] = element;
            } else {
                array[i] = array[i - 1];
            }
        }
    }

    // returns size of array
    int length() {
        return size;
    }

    // doubles capacity if it has to and deletes reference to current array.
    void resize() {
        MIN_CAPACITY *= GROWTH_FACTOR;
        cout << "MIN_CAPACITY after resize..." << MIN_CAPACITY << endl;
        T *temp = new T[MIN_CAPACITY];
        copy(temp);
        delete[] array;
        array = temp;
    }

    // copies original array into temp
    void copy(T temp[]) {
        cout << "copying array in new array....." << endl;
        for (int i = 0; i < size; i++) {
            temp[i] = array[i];
        }
    }

    // returns element in x position.
    T get(int pos) {
        return array[pos];
    }
};

int main() {
    dynamic_array<int> dynArr;
    dynArr.append(3);
    dynArr.printarray();
    dynArr.append(4);
    dynArr.printarray();
    dynArr.append(5);
    dynArr.printarray();
    dynArr.append(4);
    dynArr.printarray();
    dynArr.append(33);
    dynArr.printarray();
    dynArr.append(3);
    dynArr.printarray();
    dynArr.deleteAt(6);
    dynArr.printarray();
    dynArr.insertAt(58, 3);
    dynArr.printarray();
    return 0;
}
