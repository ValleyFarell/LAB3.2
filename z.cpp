#include"include/tests.h"
#include"include/ISorter.h"

int main() {
    QuickSort<Person> sorter;
    test_sorting_to_csv({100, 1000, 10000, 100000}, sorter, "data.csv");
}