#include "ISorter.h"

template<typename T>
void SelectionSort<T>::selection_sort(ArraySequence<T>* seq, int (*cmp)(const T&, const T&)) {
    for (size_t i = 0; i < seq->size() - 1; ++i) {
        size_t mn = i;
        for (size_t j = i + 1; j < seq->size(); ++j) {
            if (cmp(seq->get(j), seq->get(mn))) {
                mn = j;
            }
        }
        std::swap(seq->get(mn), seq->get(i));
    }
}

template<typename T>
ArraySequence<T>* SelectionSort<T>::sort(ArraySequence<T>* seq, int (*cmp)(const T&, const T&)) {
    selection_sort(seq, cmp);
    return seq;
}

template<typename T>
ArraySequence<T>* SelectionSort<T>::sort(ArraySequence<T>* seq) {
    selection_sort(seq, this->default_cmp);
    return seq;
}

template<typename T>
long long QuickSort<T>::gen_rand(long long l, long long r) {
    return l + rand() % (r - l);
}

template<typename T>
int QuickSort<T>::partition(ArraySequence<T>* seq, long long l, long long r, int (*cmp)(const T&, const T&)) {
    T pivot = seq->get(r);
    long long i = (l - 1);
    
    for (long long j = l; j <= r - 1; j++) {
        if (!cmp(pivot, seq->get(j))) {
            i++;
            std::swap(seq->get(i), seq->get(j));
        }
    }
    std::swap(seq->get(i + 1), seq->get(r));
    return (i + 1);
}

template<typename T>
void QuickSort<T>::q_sort(ArraySequence<T>* seq, long long l, long long r, int (*cmp)(const T&, const T&)) {
    if (l >= r) return;
    long long pivot_index = gen_rand(l, r);
    std::swap(seq->get(pivot_index), seq->get(r));

    long long tmp = partition(seq, l, r, cmp);

    q_sort(seq, l, tmp - 1, cmp);
    q_sort(seq, tmp + 1, r, cmp);
}

template<typename T>
ArraySequence<T>* QuickSort<T>::sort(ArraySequence<T>* seq, int (*cmp)(const T&, const T&)) {
    q_sort(seq, 0, seq->size() - 1, cmp);
    return seq;
}

template<typename T>
ArraySequence<T>* QuickSort<T>::sort(ArraySequence<T>* seq) {
    q_sort(seq, 0, seq->size() - 1, this->default_cmp);
    return seq;
}

template<typename T>
void ShellSort<T>::insertion(int item, ArraySequence<int>& seq) {
    size_t i = seq.size() - 1;
    seq.append(item);
    while (seq[i] > seq[i + 1])
        std::swap(seq[i], seq[i + 1]);
}

template<typename T>
ArraySequence<int> ShellSort<T>::pratt_sequence(size_t n) {
    ArraySequence<int> seq;
    bool flag = true;
    for (int i = 1; i <= n / 2; i *= 2) {
        for (int j = 1; j * i <= n / 2; j *= 3) {
            insertion(i * j, seq);
        }
    }
    return seq;
}

template<typename T>
void ShellSort<T>::insertion_sort_by_step(ArraySequence<T>* seq, int step, int (*cmp)(const T&, const T&)) {
    for (int i = step; i < seq->size(); i += step) {
        for (int j = i; j >= step && cmp(seq->get(j), seq->get(j - step)); j -= step) {
            std::swap(seq->get(j), seq->get(j - step));
        }
    }
}

template<typename T>
void ShellSort<T>::shell_sort(ArraySequence<T>* seq, int (*cmp)(const T&, const T&)) {
    ArraySequence<int> prt_seq = pratt_sequence(seq->size());
    for (int d = prt_seq.size() - 1; d >= 0; d--) {
        int step = prt_seq[d];
        insertion_sort_by_step(seq, step, cmp);
    }
}

template<typename T>
ArraySequence<T>* ShellSort<T>::sort(ArraySequence<T>* seq, int (*cmp)(const T&, const T&)) {
    shell_sort(seq, cmp);
    return seq;
}

template<typename T>
ArraySequence<T>* ShellSort<T>::sort(ArraySequence<T>* seq) {
    shell_sort(seq, this->default_cmp);
    return seq;
}