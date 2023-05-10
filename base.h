#ifndef BASE_H
#define BASE_H

class BaseShape2D {
public:
    BaseShape2D() = default;
    virtual double area() = 0;
    virtual void operator*(double rhs) = 0;
};

#endif // BASE_H
