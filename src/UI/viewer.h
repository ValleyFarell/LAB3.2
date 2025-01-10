#include <iostream>
#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>

#ifndef VIEWER_H
#define VIEWER_H

void selection_sort(std::vector<int>& arr, sf::RenderWindow& window);
int partition(std::vector<int>& arr, sf::RenderWindow& window, int low, int high);
void quick_sort(std::vector<int>& arr, sf::RenderWindow& window, int low, int high);
void quick_sort_view(std::vector<int>& arr, sf::RenderWindow& window);
void shell_sort(std::vector<int>& arr, sf::RenderWindow& window);
void sort_visualizator(void (*sort_viewer)(std::vector<int>&, sf::RenderWindow&));

#endif // VIEWER_H
