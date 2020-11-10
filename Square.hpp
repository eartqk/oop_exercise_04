#ifndef SQUARE_HPP
#define SQUARE_HPP

template <typename T>
class Square {
public:
    std::pair<T, T> points[4];
    std::string name = "Square";
};

#endif
