
#include "../include/UI.h"
#include "../include/tests.h"
void UI::main() {
    while (true) {
        std::cout << " Текущий массив:";
        if (array) {
            std::cout << "\n";
            for (int i = 0; i < std::min((int)(array->size()), 25); ++i) {
                std::cout << array->get(i) << " ";
            }
            if (array->size() > 25) std::cout << "...\n";
        } else {
            std::cout << " пустой\n";
        }
        std::cout << "\n";
        std::cout << "   1. Создать массив\n";
        std::cout << "   2. Сортировка выбором\n";
        std::cout << "   3. Быстрая сортировка\n";
        std::cout << "   4. Сортировка Шелла\n";
        std::cout << "   5. Визуализация сортировки выбором\n";
        std::cout << "   6. Визуализация быстрой сортировки\n";
        std::cout << "   7. Визуализация сортировки Шелла\n";
        std::cout << "   8. Тест сортировок\n";
        std::cout << "   9. Выход\n";
        
        int choice;
        std::cin >> choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "   Ошибка ввода! Введите число.\n";
            continue;
        }
        switch (choice) {
            case 1:
                array_creation();
                break;
            case 2:
                if (array)
                    sel_sorter.sort(array);
                else 
                    std::cout << "   Массив пуст!\n";
                break;
            case 3:
                if (array)  
                    quick_sorter.sort(array);
                else 
                    std::cout << "   Массив пуст!\n";
                break;
            case 4:
                if (array)
                    shell_sorter.sort(array);
                else 
                    std::cout << "   Массив пуст!\n";
                break;
            case 5:
                sort_visualizator(selection_sort);
                break;
            case 6:
                sort_visualizator(quick_sort_view);
                break;
            case 7:
                sort_visualizator(shell_sort);
                break;
            case 8:
                int amount, delta;
                std::cout << "   Введите размер данных: ";
                std::cin >> amount;
                std::cout << "   Введите шаг данных: ";
                std::cin >> delta;

                std::cout << "   Статистика: \n";
                sort_comparator(amount, delta);
                break;
            case 9:
                exit(0);
                break;
            default:
                std::cout << "   Ошибка ввода\n";
                break;
        }
    }
}

void UI::sort_comparator(int amount, int delta) {
    SelectionSort<int> sort1;
    ShellSort<int> sort2;
    QuickSort<int> sort3;
    test_sorting_to_csv(amount, delta, sort1, "./plots/sel_sort/selection_sort_performance.csv");
    test_sorting_to_csv(amount, delta, sort2, "./plots/shell_sort/shell_sort_performance.csv");
    test_sorting_to_csv(amount, delta, sort3, "./plots/quick_sort/quick_sort_performance.csv");
    std::cout << "Selection sort:\n";
    print_CSV("./plots/sel_sort/selection_sort_performance.csv");
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Shell sort:\n";
    print_CSV("./plots/shell_sort/shell_sort_performance.csv");
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Quick sort:\n";
    print_CSV("./plots/quick_sort/quick_sort_performance.csv");
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "   График загружен в plots/Graphic.png\n";
    system("python ./utils/make_plots.py");
}

void UI::print_CSV(const std::string& filename) {
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        for (const auto& item : row) {
            std::cout << "    " << item << " ";
        }
        std::cout << std::endl;
    }

    file.close();
}

void UI::array_creation() {
    std::cout << "   Введите размер массива: ";
    int size;
    std::cin >> size;
    std::cout << "   1. Заполнить случайными числами\n";
    std::cout << "   2. Заполнить самостоятельно\n";
    std::cout << "   3. Выход\n";
    
    int choice;
    std::cin >> choice;
    if (array) delete array;

    switch (choice) {
        case 1:
            array = generate_random_integers(size, INT32_MIN + 1, INT32_MAX);
            std::cout << "   Массив создан\n";
            break;
        case 2:
            array = new ArraySequence<int>(size);
            std::cout << "   Массив: ";
            for (int i = 0; i != size; ++i) {
                int tmp;
                std::cin >> tmp;
                array->get(i) = tmp;
            }
            std::cout << "   Массив создан\n";
            break;
        case 3:
            delete array;
            array = nullptr;
            break;
        default:
            array = nullptr;
            std::cout << "   Ошибка ввода\n";
            break;
    }
}
