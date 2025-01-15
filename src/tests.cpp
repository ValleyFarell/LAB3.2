#include "../include/tests.h"

void sort_test(ISorter<int>& sorter, int size, bool is_random) {
    ArraySequence<int>* array;
    
    if (is_random) {
        array = generate_random_integers(size, -10, 10);
    } else {
        array = generate_increasing_integers(size);
    }

    auto start = std::chrono::high_resolution_clock::now();
    sorter.sort(array);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << typeid(sorter).name() << (is_random ? " (random): " : " (increasing): ") 
              << duration.count() << " ms for " << size << " elements." << std::endl;

    for (int i = 1; i < size; ++i) {
        assert(array->get(i) >= array->get(i - 1));
    }

    std::cout << typeid(sorter).name() << (is_random ? " (random) test passed successfully!" : " (increasing) test passed successfully!") << std::endl;
}

void quick_sort_test(int size, bool is_random) {
    QuickSort<int> sorter;
    sort_test(sorter, size, is_random);
}

void shell_sort_test(int size, bool is_random) {
    ShellSort<int> sorter;
    sort_test(sorter, size, is_random);
}

void sel_sort_test(int size, bool is_random) {
    SelectionSort<int> sorter;
    sort_test(sorter, size, is_random);
}

void fcs_comp_test() {
    Person person1;
    Person person2;
    person1.name = "b";
    person2.name = "a";
    assert(fcs_cmp(person1, person2) == false);
    std::cout << "Person comparator test passed successfully!\n";
}

void run_all_tests() {
    quick_sort_test(100000, true);
    shell_sort_test(10000, true);
    sel_sort_test(1000, true);
    std::cout << "\n";
    quick_sort_test(10, false);
    shell_sort_test(10000, false);
    sel_sort_test(1000, false);
    std::cout << "\n";
    fcs_comp_test();
    std::cout << "All tests are successfully passed!\n\n";
}

void test_sorting_persons(ISorter<Person>& sorter, int amount) {
    ArraySequence<Person>* persons = generate_persons(amount);

    auto start = std::chrono::high_resolution_clock::now();

    persons = sorter.sort(persons, fcs_cmp);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Sorting " << amount << " persons took " << elapsed.count() << " seconds." << std::endl;

    delete persons;
}

void test_sorting_to_csv(const std::vector<int>& sizes, ISorter<Person>& sorter, const std::string& filename) {
    std::ofstream csv_file(filename);
    if (!csv_file.is_open()) {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
        return;
    }

    csv_file << "Size,Time(s)" << std::endl;

    for (int size : sizes) {
        ArraySequence<Person>* persons = generate_persons(size);

        auto start = std::chrono::high_resolution_clock::now();

        SelectionSort<Person> sorter;
        persons = sorter.sort(persons, fcs_cmp);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        csv_file << size << "," << elapsed.count() << std::endl;

        delete persons;
    }
}