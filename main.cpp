/*
Артамонов Олег Алексеевич М8О-208Б-19
github.com/eartqk/oop_exercise_04
Вариант 18
Фигуры: квадрат, прямоугольник, трапеция

Необходимо реализовать две шаблонных функции: print, square

Создать программу, которая позволяет:
    Создает набор фигур согласно варианту задания (как минимум по одной фигуре
    каждого типа с координатами типа int и координатами типа double).
    Сохраняет фигуры в std::tuple
    Печатает на экран содержимое std::tuple с помощью шаблонной функции print.
    Вычисляет суммарную площадь фигур в std::tuple и выводит значение на экран.
*/

#include <cmath>
#include <iostream>
#include <string>
#include <tuple>

#include "Rectangle.hpp"
#include "Square.hpp"
#include "Trapeze.hpp"

// Figure read
template <typename T>
void readFigure(T& figure)
{
    int n = 4;
    for (int i = 0; i < n; ++i) {
        std::cin >> figure.points[i].first >> figure.points[i].second;
    }
}

// Tuple print
// Template if we came to the end of the tuple
template <typename T, size_t index>
typename std::enable_if<index == std::tuple_size<T>::value, void>::type print(T&)
{
}

// Template to print all figures from tuple
template <typename T, size_t index>
    typename std::enable_if < index<std::tuple_size<T>::value, void>::type print(T& tp)
{
    auto figure = std::get<index>(tp);
    std::cout << "Vertices of " << figure.name << ":\t";
    printVertices(figure);
    print<T, index + 1>(tp);
}

// Template to print vertices of figure
template <typename T>
void printVertices(T& figure)
{
    for (auto v : figure.points)
        std::cout << " (" << v.first << ", " << v.second << ") ";
    std::cout << std::endl;
}

// Square calculations
template <class T, size_t index>
double square(T& tuple)
{
    auto figure = std::get<index>(tuple);
    double value = figureArea(figure);
    if constexpr ((index + 1) < std::tuple_size<T>::value) {
        return value + square<T, index + 1>(tuple);
    }
    return value;
}

// Square of the figure according to the Gauss formula
template <class T>
auto figureArea(T& figure)
{
    double area = 0;
    area += (figure.points[0].first * figure.points[1].second +
             figure.points[1].first * figure.points[2].second +
             figure.points[2].first * figure.points[3].second +
             figure.points[3].first * figure.points[0].second -
             figure.points[1].first * figure.points[0].second -
             figure.points[2].first * figure.points[1].second -
             figure.points[3].first * figure.points[2].second -
             figure.points[0].first * figure.points[3].second);
    return std::fabs(area) / 2.0;
}

void Help()
{
    std::cout << "0) Help.\n";
    std::cout << "1) Add Square.\n";
    std::cout << "2) Add Rectangle.\n";
    std::cout << "3) Add Trapeze.\n";
    std::cout << "4) Print all the vertices of tuple's figures.\n";
    std::cout << "5) Print total square of tuple's figures.\n";
    std::cout << "6) Exit.\n";
}

int main()
{
    Help();
    std::tuple<Square<double>, Rectangle<int>, Trapeze<double>> tp;
    int cmd;
    int flag = 1;
    while (flag) {
        std::cin >> cmd;
        switch (cmd) {
        case 0: {
            Help();
            break;
        }
        case 1: // Add square
        {
            readFigure(std::get<0>(tp));
            std::cout << std::get<0>(tp).name << " successfully added" << '\n';
            break;
        }
        case 2: // Add rectangle
        {
            readFigure(std::get<1>(tp));
            std::cout << std::get<1>(tp).name << " successfully added" << '\n';
            break;
        }
        case 3: // Add trapeze
        {
            readFigure(std::get<2>(tp));
            std::cout << std::get<2>(tp).name << " successfully added" << '\n';
            break;
        }
        case 4: // Print all vertices
        {
            print<decltype(tp), 0>(tp);
            break;
        }
        case 5: // Total square
        {
            std::cout << "Total area of tuple figures: " << square<decltype(tp), 0>(tp)
                      << '\n';
            break;
        }
        case 6: {
            flag = 0;
            std::cout << "Exit..." << '\n';
            break;
        }
        }
    }
    return 0;
}
