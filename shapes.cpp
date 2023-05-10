#define _USE_MATH_DEFINES // for M_PI
#include "base.h"         // Header file with abstract base class
#include <iostream>       // cout, endl
#include <vector>         // Vector
#include <cmath>          // Square root and cos^-1
#include <iomanip>        // To use setprecision to reduce decimals in the triangle angles

using namespace std;

/// @brief Rectangle, inherits from BaseShape2D, uses two sides to determine area.
class Rectangle: public BaseShape2D {
    public:
        double area() {
            return width * height;
        }

        void operator*(double scaleFactor) override {
            width *= scaleFactor;
            height *= scaleFactor;
        }

        void setSides(double widthInput, double heightInput) {
            width = widthInput;
            height = heightInput;
        }

        vector<double> getSides() {
            return vector<double>{width, height};
        }

    protected:
        double width;
        double height;
};

/// @brief Square, inherits from Rectangle and uses only side, not width and height.
class Square: public Rectangle {
    public:
        double getSides() {
            return width;
        }

        void setSides(double side) {
            Rectangle::setSides(side, side);
        }
};

/// @brief Triangle, inherits from BaseShape2D, uses three sides A, B and C.
class Triangle: public BaseShape2D {
    public:
        vector<double> getSides() {
            return vector<double>{sideA, sideB, sideC};
        }

        void setSides(double a, double b, double c) {
            sideA = a;
            sideB = b;
            sideC = c;
        }

        void operator*(double scaleFactor) override {
            sideA *= scaleFactor;
            sideB *= scaleFactor;
            sideC *= scaleFactor;
        }

        double area() override {
            double s = (sideA + sideB + sideC) / 2;
            return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
        }

        vector<double> getAngles() {
            double angle1 = calculateAngle(sideB, sideC, sideA);
            double angle2 = calculateAngle(sideA, sideC, sideB);
            double angle3 = calculateAngle(sideA, sideB, sideC);
            angle1 = angle1 * 180.0 / M_PI;
            angle2 = angle2 * 180.0 / M_PI;
            angle3 = angle3 * 180.0 / M_PI;
            return vector<double>{angle1, angle2, angle3};
        }

    private:
        double sideA;
        double sideB;
        double sideC;
        double calculateAngle(double side1, double side2, double side3) {
            double value = acos((side1 * side1 + side2 * side2 - side3 * side3) / (2 * side1 * side2));
            return value;
        }
};

class Circle: BaseShape2D {
    public:
        double getRadius(){
            return radius;
        }

        void setRadius(double radiusInput) {
            radius = radiusInput;
        }

        double area() {
            return (M_PI * radius * radius);
        }

        double circumference() {
            return (M_PI * 2 * radius);
        }

        void operator*(double scaleFactor) override {
            radius *= scaleFactor;
        }

    private:
        double radius;
};

int main(){
    //Rectangle
    Rectangle rectangle;
    rectangle.setSides(4,5);
    cout << "\u001b[32mRectangle unscaled:\u001b[0m" << endl;
    cout << "Rectangle area: " << rectangle.area() << endl;
    cout << "Rectangle width: " << rectangle.getSides()[0] << endl;
    cout << "Rectangle height: " << rectangle.getSides()[1] << endl;

    rectangle * 2;
    cout << "\u001b[32mRectangle scaled with 2:\u001b[0m" << endl;
    cout << "Rectangle area: " << rectangle.area() << endl;
    cout << "Rectangle width: " << rectangle.getSides()[0] << endl;
    cout << "Rectangle height: " << rectangle.getSides()[1] << endl;

    rectangle * 0.25;
    cout << "\u001b[32mRectangle scaled with 0.25:\u001b[0m" << endl;
    cout << "Rectangle area: " << rectangle.area() << endl;
    cout << "Rectangle width: " << rectangle.getSides()[0] << endl;
    cout << "Rectangle height: " << rectangle.getSides()[1] << "\n" << endl;

    //Square
    Square square;
    square.setSides(5);
    cout << "\u001b[32mSquare unscaled:\u001b[0m" << endl;
    cout << "Square area: " << square.area() << endl;
    cout << "Square sides: " << square.getSides() << endl;

    square * 2;
    cout << "\u001b[32mSquare scaled with 2:\u001b[0m" << endl;
    cout << "Square area: " << square.area() << endl;
    cout << "Square sides: " << square.getSides() << endl;

    square * 0.25;
    cout << "\u001b[32mSquare scaled with 0.25:\u001b[0m" << endl;
    cout << "Square area: " << square.area() << endl;
    cout << "Square sides: " << square.getSides() << "\n" << endl;
    
    //Triangle
    Triangle triangle;
    triangle.setSides(8, 15, 17);
    cout << "\u001b[32mTriangle unscaled:\u001b[0m" << endl;
    cout << "Triangle area: " << triangle.area() << endl;
    cout << "Triangle sides: "
         << triangle.getSides()[0] << ", "
         << triangle.getSides()[1] << ", "
         << triangle.getSides()[2] << endl;
    cout << "Triangle angles: " << fixed << setprecision(2)
         << triangle.getAngles()[0] << "deg, " << fixed << setprecision(2)
         << triangle.getAngles()[1] << "deg, " << fixed << setprecision(2)
         << triangle.getAngles()[2] << "deg" << endl;

    triangle * 2;
    cout << "\u001b[32mTriangle scaled with 2:\u001b[0m" << endl;
    cout << "Triangle area: " << triangle.area() << endl;
    cout << "Triangle sides: "
         << triangle.getSides()[0] << ", "
         << triangle.getSides()[1] << ", "
         << triangle.getSides()[2] << endl;
    cout << "Triangle angles: " << fixed << setprecision(2)
         << triangle.getAngles()[0] << "deg, " << fixed << setprecision(2)
         << triangle.getAngles()[1] << "deg, " << fixed << setprecision(2)
         << triangle.getAngles()[2] << "deg" << endl;

    triangle * 0.25;
    cout << "\u001b[32mTriangle scaled with 0.25:\u001b[0m" << endl;
    cout << "Triangle area: " << triangle.area() << endl;
    cout << "Triangle sides: "
         << triangle.getSides()[0] << ", "
         << triangle.getSides()[1] << ", "
         << triangle.getSides()[2] << endl;
    cout << "Triangle angles: " << fixed << setprecision(2)
         << triangle.getAngles()[0] << "deg, " << fixed << setprecision(2)
         << triangle.getAngles()[1] << "deg, " << fixed << setprecision(2)
         << triangle.getAngles()[2] << "deg\n" << endl;

    //Circle
    Circle circle;
    circle.setRadius(1);
    cout << "\u001b[32mCircle unscaled\u001b[0m" << endl;
    cout << "Circle area: " << circle.area() << endl;
    cout << "Circle circumference: " << circle.circumference() << endl;

    circle * 2;
    cout << "\u001b[32mCircle scaled with 2:\u001b[0m" << endl;
    cout << "Circle area: " << circle.area() << endl;
    cout << "Circle circumference: " << circle.circumference() << endl;

    circle * 0.25;
    cout << "\u001b[32mCircle scaled with 0.25:\u001b[0m" << endl;
    cout << "Circle area: " << circle.area() << endl;
    cout << "Circle circumference: " << circle.circumference() << "\n" << endl;

    cout << "Press any key to exit" << endl;
    cin.get();
}