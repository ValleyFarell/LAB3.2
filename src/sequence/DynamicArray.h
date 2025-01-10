#pragma once
#ifndef DYN_ARR_H
#define DYN_ARR_H
#include <utility>

template<typename T>
class DynamicArray {
private:
    T* data_ = nullptr;
    size_t size_ = 0;
public:
    DynamicArray() : data_(nullptr), size_(0) {}
    DynamicArray(size_t size, const T& item){
        data_ = new T[size];
        size_ = size;
        for (size_t i = 0; i != size; ++i) {
            data_[i] = item;
        }
    }
    DynamicArray(size_t size){
        data_ = new T[size];
        size_ = size;
        for (size_t i = 0; i != size; ++i) {
            data_[i] = T();
        }
    }
    DynamicArray(T* items, size_t count){
        data_ = new T[count];
        size_ = count;
        for (size_t i = 0; i != count; ++i) {
            data_[i] = items[i];
        }
    }
    DynamicArray(const DynamicArray<T>& other) {
        data_ = new T[other.size_];
        size_ = other.size_;
        for (size_t i = 0; i != size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    DynamicArray(DynamicArray<T>&& other) {
        data_ = new T[other.size_];
        size_ = other.size_;
        for (size_t i = 0; i != size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    const T& operator [] (size_t index) const {
        return data_[index];
    }
    T& operator [] (size_t index) {
        return data_[index];
    }
    void operator = (const DynamicArray<T>& other) {
        data_ = new T[other.size_];
        size_ = other.size_;
        for (size_t i = 0; i != size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    const T& at(size_t index) const {
        if (index >= size_) {
            return data_[index];
        }
        throw "Wrong index! Index must be in range from 0 to size of DynamicArray. ";
    }
    T& at(size_t index) {
        if (index >= size_) {
            return data_[index];
        }
        throw "Wrong index! Index must be in range from 0 to size of DynamicArray. ";
    }
    bool empty() const {
        return size_ == 0;
    }
    size_t size() const {
        return size_;
    }
    void reserve(size_t new_size) {
        T* temp = new T[size_];
        for (size_t i = 0; i != size_; ++i) {
            temp[i] = std::move(data_[i]);
        }
        data_ = new T[new_size];
        for (size_t i = 0; i != size_; ++i) {
            data_[i] = std::move(temp[i]);
        }
        size_ = new_size;
        delete[] temp;
    }
    void clear() {
        for (size_t i = 0; i != size_; ++i) {
            data_[i] = T();
        }
        size_ = 0;
    }
};

#endif