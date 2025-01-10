#include "viewer.h"

void selection_sort(std::vector<int>& arr, sf::RenderWindow& window) {
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < n; ++j) {
            window.clear(sf::Color::Black);
            for (size_t k = 0; k < n; ++k) {
                sf::RectangleShape rectangle(sf::Vector2f(10, arr[k]));
                rectangle.setPosition(k * 12, window.getSize().y - arr[k]);
                if (k == j) rectangle.setFillColor(sf::Color::Red);
                else if (k == minIndex) rectangle.setFillColor(sf::Color::Green);
                else rectangle.setFillColor(sf::Color::White);
                window.draw(rectangle);
            }
            window.display();
            sf::sleep(sf::milliseconds(50));

            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[minIndex], arr[i]);
    }
}

int partition(std::vector<int>& arr, sf::RenderWindow& window, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        window.clear(sf::Color::Black);
        for (size_t k = 0; k < arr.size(); ++k) {
            sf::RectangleShape rectangle(sf::Vector2f(10, arr[k]));
            rectangle.setPosition(k * 12, window.getSize().y - arr[k]);
            if (k != high) rectangle.setFillColor(sf::Color::White);
            else rectangle.setFillColor(sf::Color::Green);
            window.draw(rectangle);
        }
        window.display();
        sf::sleep(sf::milliseconds(50));

        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quick_sort(std::vector<int>& arr, sf::RenderWindow& window, int low, int high) {
    if (low < high) {
        int pi = partition(arr, window, low, high);

        quick_sort(arr, window, low, pi - 1);
        quick_sort(arr, window, pi + 1, high);
    }
}

void quick_sort_view(std::vector<int>& arr, sf::RenderWindow& window) {
    quick_sort(arr, window, 0, arr.size() - 1);
}

void shell_sort(std::vector<int>& arr, sf::RenderWindow& window) {
    size_t n = arr.size();
    size_t gap = n / 2;

    while (gap > 0) {
        for (size_t i = gap; i < n; ++i) {
            size_t j = i;
            while (j >= gap && arr[j] < arr[j - gap]) {
                window.clear(sf::Color::Black);
                for (size_t k = 0; k < n; ++k) {
                    sf::RectangleShape rectangle(sf::Vector2f(10, arr[k]));
                    rectangle.setPosition(k * 12, window.getSize().y - arr[k]);
                    if (k % gap) rectangle.setFillColor(sf::Color::White);
                    else rectangle.setFillColor(sf::Color::Green);
                    window.draw(rectangle);
                }
                window.display();
                sf::sleep(sf::milliseconds(50));

                std::swap(arr[j], arr[j - gap]);
                j -= gap;
            }
        }
        gap /= 2;
    }
}

void sort_visualizator(void (*sort_viewer)(std::vector<int> &, sf::RenderWindow &)) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    const int arraySize = 30;
    std::vector<int> arr(arraySize);

    for (int& value : arr) {
        value = std::rand() % 300 + 1;
    }

    sf::RenderWindow window(sf::VideoMode(arraySize * 12, 400), "Sorting Visualization");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sort_viewer(arr, window);

        window.clear(sf::Color::Black);
        for (size_t j = 0; j < arr.size(); ++j) {
            sf::RectangleShape rectangle(sf::Vector2f(10, arr[j]));
            rectangle.setPosition(j * 12, window.getSize().y - arr[j]);
            rectangle.setFillColor(sf::Color::White);
            window.draw(rectangle);
        }
        window.display();
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
        }
    }
}
