#pragma once
#ifndef ARRAY
#define ARRAY
#include"DynamicArray.h"

template<class T>
class ArraySequence {
private:
    DynamicArray<T> data_;
    size_t capacity_;
    size_t size_;
public:
    ArraySequence(const ArraySequence<T>& array) {
        data_ = array.data_;
        size_ = array.size_;
        capacity_ = array.capacity_;
    }
    ArraySequence(T* items, size_t count) {
        DynamicArray<T> tmp_arr(items, count);
        data_ = tmp_arr;
        size_ = count;
        capacity_ = size_ * 2;
    }
    ArraySequence(size_t size) {
        capacity_ = size * 2;
        size_ = size;
        data_ = DynamicArray<T>(capacity_);
    }
    ArraySequence() {
        size_ = 0;
        capacity_ = 1;
        this->data_ = DynamicArray<T>();
    }
    T front() const {
        return data_[0];
    }
    T back() const {
        return data_[size_ - 1];
    }
    size_t size() const {
        return size_;
    }
    ArraySequence<T>*append(T item) {
        if (size_ + 1 == capacity_) {
            data_.reserve(capacity_ * 2);
            capacity_ *= 2;
        }
        data_[size_] = item;
        size_ ++;
        return this;
    }

    ArraySequence<T>*insert(T item, size_t index) {
        if (size_ + 1 == capacity_) {
            data_.reserve(capacity_ * 2);
            capacity_ *= 2;
        }
        for (size_t i = index + 1; i <= size_; ++i) {
            data_[i] = std::move(data_[i - 1]);
        }
        data_[index] = std::move(item);
        size_++;
        return this;
    }

    T& operator [] (size_t index) {
        return data_[index];
    }
    T& get(size_t index) {
        return data_[index];
    }
};
#endif