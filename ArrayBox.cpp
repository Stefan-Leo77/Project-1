#ifndef ARRAY_BOX_CPP_
#define ARRAY_BOX_CPP_

#include "ArrayBox.hpp"

template <typename T>
ArrayBox<T>::ArrayBox() : capacity_(64), size_(0) {
    items_ = new T[capacity_];
}

template <typename T>
ArrayBox<T>::ArrayBox(const int& capacity) : size_(0) {
    // Use 64 if capacity is not positive
    if (capacity <= 0) {
        capacity_ = 64;
    } else {
        capacity_ = capacity;
    }
    
    items_ = new T[capacity_];
}

template <typename T>
int ArrayBox<T>::size() const {
    return size_;
}

template <typename T>
int ArrayBox<T>::capacity() const {
    return capacity_;
}

template <typename T>
int ArrayBox<T>::getIndexOf(const std::string& type, int start, int end) const {
    // Check if the parameters are valid
    if (start < 0 || start >= size_ || end < 0 || end > size_ || start >= end) {
        return -1;
    }
    
    // Search for the item
    for (int i = start; i < end; i++) {
        if (items_[i].getType() == type) {
            return i;
        }
    }
    
    // Item not found
    return -1;
}

template <typename T>
bool ArrayBox<T>::addItem(const T& item) {
    int item_size = item.size();
    
    // Check if there's enough space
    if (size_ + item_size > capacity_) {
        return false;
    }
    
    // Add the item to the leftmost non-occupied space
    for (int i = 0; i < item_size; i++) {
        items_[size_ + i] = item;
    }
    
    // Update size
    size_ += item_size;
    
    return true;
}

template <typename T>
bool ArrayBox<T>::remove(const std::string& type) {
    // Find the first instance of the item
    int index = getIndexOf(type, 0, size_);
    
    // If not found, return false
    if (index == -1) {
        return false;
    }
    
    // Get the size of the item to remove
    int item_size = items_[index].size();
    
    // Shift elements over by the size of the removed item
    for (int i = index; i + item_size < size_; i++) {
        items_[i] = items_[i + item_size];
    }
    
    // Set the now unused spaces to default-initialized objects
    for (int i = size_ - item_size; i < size_; i++) {
        items_[i] = T();
    }
    
    // Update size
    size_ -= item_size;
    
    return true;
}

template <typename T>
int ArrayBox<T>::count(const std::string& type) const {
    int count = 0;
    int pos = 0;
    
    while (pos < size_) {
        if (items_[pos].getType() == type) {
            count++;
            pos += items_[pos].size();
        } else {
            pos++;
        }
    }
    
    return count;
}

template <typename T>
bool ArrayBox<T>::contains(const std::string& type) const {
    return getIndexOf(type, 0, size_) != -1;
}

template <typename T>
ArrayBox<T>::~ArrayBox() {
    delete[] items_;
}

#endif // ARRAY_BOX_CPP_