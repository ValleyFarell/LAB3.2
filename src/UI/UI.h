#include <iostream>
#include "../sequence/ArraySequence.h"
#include "../algorithms/ISorter.h"
#include "../generators.h"
#include "viewer.h"

#ifndef UI_H
#define UI_H

class UI {
private:
    ArraySequence<int>* array = nullptr;
    SelectionSort<int> sel_sorter;
    QuickSort<int> quick_sorter;
    ShellSort<int> shell_sorter;
    int last_sort_time;

public:
    void main();
    void array_creation();
};

#endif // UI_H
