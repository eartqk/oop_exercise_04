#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

template <typename T>
class Rectangle {
public:
    std::pair<T, T> points[4];
    std::string name = "Rectangle";
};

#endif
