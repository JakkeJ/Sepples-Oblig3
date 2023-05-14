#define _USE_MATH_DEFINES // for M_PI
#include "base.h"         // Header file with abstract base class
#include <iostream>       // cout, endl
#include <vector>         // Vector
#include <cmath>          // Square root and cos^-1
#include <iomanip>        // To use setprecision to reduce decimals in the triangle angles

using namespace std;

/// @brief Rectangle, inherits from BaseShape2D, uses two sides to determine area.
/// @brief Takes two inputs in the constructor, width and height.
class Rectangle: virtual BaseShape2D {
    public:
        Rectangle(double widthInput, double heightInput) {
            width = widthInput;
            height = heightInput;
        }

        /// @brief Returns the area of the rectangle.
        double area() override {
            return width * height;
        }

        /// @brief Scales the objects sidelengths
        void operator*(double scaleFactor) override {
            width *= scaleFactor;
            height *= scaleFactor;
        }

        /// @brief Sets the sides of the rectangle.
        void setSides(double widthInput, double heightInput) {
            width = widthInput;
            height = heightInput;
        }

        /// @brief Returns the sides of the rectangle.
        vector<double> getSides() {
            return vector<double>{width, height};
        }

    protected:
        double width;
        double height;
};

/// @brief Square, inherits from Rectangle and uses only side, not width and height.
/// @brief Constructor takes one input, which is the sidelength.
class Square: public Rectangle {
    public:
        Square(double sideInput): Rectangle(sideInput, sideInput) {}

        /// @brief Returns the sides of the square
        double getSides() {
            return width;
        }

        /// @brief Set the sides of the square
        void setSides(double side) {
            Rectangle::setSides(side, side);
        }
    
    private:
        double side;
};

/// @brief Triangle, inherits from BaseShape2D, uses three sides A, B and C.
class Triangle: virtual BaseShape2D {
    public:

        /// @brief Returns the sides of the triangle.
        /// @return Side A, Side B, Side C
        vector<double> getSides() {
            return vector<double>{sideA, sideB, sideC};
        }

        /// @brief Sets the sides of the triangle.
        /// @param a Side A
        /// @param b Side B
        /// @param c Side C
        void setSides(double a, double b, double c) {
            sideA = a;
            sideB = b;
            sideC = c;
        }

        /// @brief Scales the objects sidelengths
        void operator*(double scaleFactor) override {
            sideA *= scaleFactor;
            sideB *= scaleFactor;
            sideC *= scaleFactor;
        }

        /// @brief Returns the area of the triangle.
        double area() override {
            double s = (sideA + sideB + sideC) / 2;
            return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
        }

        /// @brief Returns all the angles of the triangle.
        /// @param degrees Boolean, true if the output should be in degrees, otherwise radians.
        /// @return Angles between B and C, A and C, A and B in this order.
        vector<double> getAngles(bool degrees) {
            double angle1 = calculateAngle(sideB, sideC, sideA);
            double angle2 = calculateAngle(sideA, sideC, sideB);
            double angle3 = calculateAngle(sideA, sideB, sideC);
            if (degrees) {
                angle1 = angle1 * 180.0 / M_PI;
                angle2 = angle2 * 180.0 / M_PI;
                angle3 = angle3 * 180.0 / M_PI;
            }
            return vector<double>{angle1, angle2, angle3};
        }

    private:

        double sideA;
        double sideB;
        double sideC;
        
        /// @brief Calculates the angle between two sides of the triangle, Law of Cosines.
        /// @param side1 One of the adjacent sides you where you want to find the angle.
        /// @param side2 The other adjacent side of where you want to find the angle.
        /// @param side3 The opposite side of your angle.
        /// @return Returns radians.
        double calculateAngle(double side1, double side2, double side3) {
            double value = acos((side1 * side1 + side2 * side2 - side3 * side3) / (2 * side1 * side2));
            return value;
        }
};

/// @brief Circle, inherits from BaseShape2D, uses radius.
class Circle: virtual BaseShape2D {
    public:

        /// @brief Sets the radius of the circle.
        void setRadius(double radiusInput) {
            radius = radiusInput;
        }

        /// @brief Returns the radius of the circle.
        double getRadius(){
            return radius;
        }

        /// @brief Returns the area of the circle.
        double area() {
            return (M_PI * radius * radius);
        }

        /// @brief Returns the circumference of the circle.
        double circumference() {
            return (M_PI * 2 * radius);
        }

        /// @brief Scales the radius of the circle.
        void operator*(double scaleFactor) override {
            radius *= scaleFactor;
        }

    private:

        double radius;
};