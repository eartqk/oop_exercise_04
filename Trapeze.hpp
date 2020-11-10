#ifndef TRAPEZE_HPP
#define TRAPEZE_HPP

template <typename T>
class Trapeze {
public:
    std::pair<T, T> points[4];
    std::string name = "Trapeze";
};

#endif
