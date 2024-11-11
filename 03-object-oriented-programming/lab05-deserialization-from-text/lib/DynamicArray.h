#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template <typename T>
class DynamicArray {
private:
    T* data;
    int capacity;
    int count;

    void resize(int newCapacity) {
        T* newData = new T[newCapacity];
        for (int i = 0; i < count; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray() : data(new T[2]), capacity(2), count(0) {}

    ~DynamicArray() {
        delete[] data;
    }

    void add(const T& item) {
        if (count == capacity) {
            resize(capacity * 2);
        }
        data[count++] = item;
    }

    T& get(int index) const {
        return data[index];
    }

    int size() const {
        return count;
    }
};

#endif
