#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>

#ifndef PLOTS
#define PLOTS

const int WIDTH = 800;
const int HEIGHT = 600;

class Plot {
public:
    Plot(float xScale, float yScale)
        : xScale(xScale), yScale(yScale) {}

    void draw_axes(sf::RenderWindow &window) {
        // Ось X
        sf::Vertex xAxis[] = {
            sf::Vertex(sf::Vector2f(0, HEIGHT / 2), sf::Color::White),
            sf::Vertex(sf::Vector2f(WIDTH, HEIGHT / 2), sf::Color::White)
        };
        window.draw(xAxis, 2, sf::Lines);

        // Ось Y
        sf::Vertex yAxis[] = {
            sf::Vertex(sf::Vector2f(WIDTH / 2, 0), sf::Color::White),
            sf::Vertex(sf::Vector2f(WIDTH / 2, HEIGHT), sf::Color::White)
        };
        window.draw(yAxis, 2, sf::Lines);

        // Градуировка по оси X
        for (float x = -WIDTH / 2; x <= WIDTH / 2; x += xScale) {
            sf::Vertex tick[] = {
                sf::Vertex(sf::Vector2f(WIDTH / 2 + x, HEIGHT / 2 - 5), sf::Color::White),
                sf::Vertex(sf::Vector2f(WIDTH / 2 + x, HEIGHT / 2 + 5), sf::Color::White)
            };
            window.draw(tick, 2, sf::Lines);
        }

        // Градуировка по оси Y
        for (float y = -HEIGHT / 2; y <= HEIGHT / 2; y += yScale) {
            sf::Vertex tick[] = {
                sf::Vertex(sf::Vector2f(WIDTH / 2 - 5, HEIGHT / 2 - y), sf::Color::White),
                sf::Vertex(sf::Vector2f(WIDTH / 2 + 5, HEIGHT / 2 - y), sf::Color::White)
            };
            window.draw(tick, 2, sf::Lines);
        }
    }

    void draw_graph(sf::RenderWindow &window, const std::vector<float> &x_array, const std::vector<float> &y_array) {
        if (x_array.size() != y_array.size()) {
            std::cerr << "Error: x_array and y_array must have the same size." << std::endl;
            return;
        }

        sf::VertexArray graph(sf::PrimitiveType::LineStrip, x_array.size());

        for (size_t i = 0; i < x_array.size(); ++i) {
            graph[i].position = sf::Vector2f(WIDTH / 2 + x_array[i], HEIGHT / 2 - y_array[i]);
            graph[i].color = sf::Color::Red;
        }

        window.draw(graph);
    }

private:
    float xScale;
    float yScale;
};

#endif