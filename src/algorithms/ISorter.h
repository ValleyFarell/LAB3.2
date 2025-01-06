#ifndef SORTS
#define SORTS

#include <random>

#include"../sequence/ArraySequence.h"

template<typename T>
class ISorter {
public:
    virtual ArraySequence<T>* sort(ArraySequence<T>* seq, int (*cmp)(const T&,const T&)) = 0;
    virtual ArraySequence<T>* sort(ArraySequence<T>* seq) = 0;
    static int default_cmp(const T& a, const T& b) { return a < b; };
};

template<typename T>
class SelectionSort : public ISorter<T> {
private:
    void selection_sort(ArraySequence<T>* seq, int (*cmp)(const T&,const T&)) {
        for (size_t i = 0; i < seq->size() - 1; ++i)
        {
            size_t mn = i;
            for (size_t j = i + 1; j < seq->size(); ++j) {
                if (cmp(seq->get(j), seq->get(mn))) {
                    mn = j;
                }
            }
            std::swap(seq->get(mn), seq->get(i));
        }
    }
public:
    ArraySequence<T>* sort(ArraySequence<T>* seq, int (*cmp)(const T&,const T&)) {
        selection_sort(seq, cmp);
        return seq;
    }
    ArraySequence<T>* sort(ArraySequence<T>* seq) {
        selection_sort(seq, this->default_cmp);
        return seq;
    }
};

template<typename T>
class QuickSort : public ISorter<T> {
private:
    long long gen_rand(long long l, long long r) {
        return l + rand() % (r - l);
    }
    int partition(ArraySequence<T>* seq, long long l, long long r, int (*cmp)(const T&,const T&)) {
        T pivot = seq->get(r); 
    
        long long i = (l - 1); 
    
        for (long long j = l; j <= r - 1; j++) 
        {
            if (!cmp(pivot, seq->get(j))) {
                i++; 
                std::swap(seq->get(i), seq->get(j));
            }
        }
        std::swap(seq->get(i + 1), seq->get(r));
        return (i + 1);
    }
    void q_sort(ArraySequence<T>* seq, long long l, long long r, int (*cmp)(const T&,const T&)) {
        if (l >= r) return;
        long long pivot_index = gen_rand(l, r);
        // long long pivot_index = (l + r) / 2;
        std::swap(seq->get(pivot_index), seq->get(r));

        long long tmp = partition(seq, l, r, cmp);

        q_sort(seq, l, tmp - 1, cmp);
        q_sort(seq, tmp + 1, r, cmp);
    }
public:
    ArraySequence<T>* sort(ArraySequence<T>* seq, int (*cmp)(const T&,const T&)) {
        q_sort(seq, 0, seq->size() - 1, cmp);
        return seq;
    }
    ArraySequence<T>* sort(ArraySequence<T>* seq) {
        q_sort(seq, 0, seq->size() - 1, this->default_cmp);
        return seq;
    }
};

template<typename T> 
class ShellSort : public ISorter<T> {
private:
    void insertion(int item, ArraySequence<int>& seq) {
        size_t i = seq.size() - 1;
        seq.append(item);
        while(seq[i] > seq[i + 1])
            std::swap(seq[i], seq[i + 1]);
    }
    ArraySequence<int> pratt_sequence(size_t n) {
        ArraySequence<int> seq;
        bool flag = true;
        for (int i = 1; i <= n / 2; i *= 2) {
            for (int j = 1; j * i <= n / 2; j *= 3) {
                insertion(i * j, seq);
            }
        }
        return seq;
    }
    void insertion_sort_by_step(ArraySequence<T>* seq, int step, int (*cmp)(const T&,const T&)) {
        for (int i = step; i < seq->size(); i += step) {
            for (int j = i; j >= step && cmp(seq->get(j), seq->get(j - step)); j -= step) {
                std::swap(seq->get(j), seq->get(j - step));
            }
        }
    }
    void shell_sort(ArraySequence<T>* seq, int (*cmp)(const T&,const T&)) {
        ArraySequence<int> prt_seq = pratt_sequence(seq->size());
        for(int d = prt_seq.size() - 1; d >= 0; d--) {
            int step = prt_seq[d];
            insertion_sort_by_step(seq, step, cmp);
        }
    }
public:
    ArraySequence<T>* sort(ArraySequence<T>* seq, int (*cmp)(const T&,const T&)) {
        shell_sort(seq, cmp);
        return seq;
    }
    ArraySequence<T>* sort(ArraySequence<T>* seq) {
        shell_sort(seq, this->default_cmp);
        return seq;
    }
};
#endif