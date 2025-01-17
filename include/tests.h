#include <iostream>
#include <cassert>
#include <chrono>
#include "Person.h"
#include "generators.h"
#include "ISorter.h"

#ifndef TESTS
#define TESTS

void test_sorting_persons(ISorter<Person>& sorter, int amount);
void test_sorting_to_csv(int amount, int delta, ISorter<int>& sorter, const std::string& filename);
void sort_test(ISorter<int>& sorter, int size, bool is_random);
void quick_sort_test(int size, bool is_random);
void shell_sort_test(int size, bool is_random);
void sel_sort_test(int size, bool is_random);
void fcs_comp_test();
void run_all_tests();

#endif // TESTS
