#ifndef SORTS_H
#define SORTS_H

#include <random>
#include "../src/sequence/ArraySequence.h"

template<typename T>
class ISorter {
public:
    virtual ArraySequence<T>* sort(ArraySequence<T>* seq, int (*cmp)(const T&, const T&)) = 0;
    virtual ArraySequence<T>* sort(ArraySequence<T>* seq) = 0;
    static int default_cmp(const T& a, const T& b) { return a < b; };
};

template<typename T>
class SelectionSort : public ISorter<T> {
public:
    ArraySequence<T>* sort(ArraySequence<T>* seq, int (*cmp)(const T&, const T&)) override;
    ArraySequence<T>* sort(ArraySequence<T>* seq) override;

private:
    void selection_sort(ArraySequence<T>* seq, int (*cmp)(const T&, const T&));
};

template<typename T>
class QuickSort : public ISorter<T> {
public:
    ArraySequence<T>* sort(ArraySequence<T>* seq, int (*cmp)(const T&, const T&)) override;
    ArraySequence<T>* sort(ArraySequence<T>* seq) override;

private:
    long long gen_rand(long long l, long long r);
    int partition(ArraySequence<T>* seq, long long l, long long r, int (*cmp)(const T&, const T&));
    void q_sort(ArraySequence<T>* seq, long long l, long long r, int (*cmp)(const T&, const T&));
};

template<typename T>
class ShellSort : public ISorter<T> {
public:
    ArraySequence<T>* sort(ArraySequence<T>* seq, int (*cmp)(const T&, const T&)) override;
    ArraySequence<T>* sort(ArraySequence<T>* seq) override;

private:
    void insertion_sort_by_step(ArraySequence<T>* seq, int step, int (*cmp)(const T&, const T&));
    void shell_sort(ArraySequence<T>* seq, int (*cmp)(const T&, const T&));
    ArraySequence<int> pratt_sequence(size_t n);
    void insertion(int item, ArraySequence<int>& seq);
};

#endif // SORTS_H
