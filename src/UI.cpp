#include "UI.h"

void UI::main() {
    while (true) {
        std::cout << " Текущий массив: \n";
        if (array) {
            for (int i = 0; i < std::min((int)(array->size()), 25); ++i) {
                std::cout << array->get(i) << " ";
            }
            if (array->size() > 25) std::cout << "...\n";
        } else {
            std::cout << "Пустой\n";
        }
        std::cout << "\n";
        std::cout << "   1. Создать массив\n";
        std::cout << "   2. Сортировка выбором\n";
        std::cout << "   3. Быстрая сортировка\n";
        std::cout << "   4. Сортировка Шелла\n";
        std::cout << "   5. Визуализация сортировки выбором\n";
        std::cout << "   6. Визуализация быстрой сортировки\n";
        std::cout << "   7. Визуализация сортировки Шелла\n";
        std::cout << "   8. Выход\n";
        
        int choice;
        std::cin >> choice;
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
                exit(0);
                break;
            default:
                std::cout << "   Ошибка ввода\n";
                break;
        }
    }
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
