#include "shapes.h"

int main(){
    //Rectangle
    Rectangle rectangle(4,5);
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
    Square square(1);
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
    cout << "Triangle angles: "
         << fixed << setprecision(2) << triangle.getAngles(true)[0] << "deg, "
         << fixed << setprecision(2) << triangle.getAngles(true)[1] << "deg, "
         << fixed << setprecision(2) << triangle.getAngles(true)[2] << "deg" << endl;

    triangle * 2;
    cout << "\u001b[32mTriangle scaled with 2:\u001b[0m" << endl;
    cout << "Triangle area: " << triangle.area() << endl;
    cout << "Triangle sides: "
         << triangle.getSides()[0] << ", "
         << triangle.getSides()[1] << ", "
         << triangle.getSides()[2] << endl;
    cout << "Triangle angles: "
         << fixed << setprecision(2) << triangle.getAngles(true)[0] << "deg, "
         << fixed << setprecision(2) << triangle.getAngles(true)[1] << "deg, "
         << fixed << setprecision(2) << triangle.getAngles(true)[2] << "deg" << endl;

    triangle * 0.25;
    cout << "\u001b[32mTriangle scaled with 0.25:\u001b[0m" << endl;
    cout << "Triangle area: " << triangle.area() << endl;
    cout << "Triangle sides: "
         << triangle.getSides()[0] << ", "
         << triangle.getSides()[1] << ", "
         << triangle.getSides()[2] << endl;
    cout << "\u001b[33mTriangle angles: "
         << fixed << setprecision(2) << triangle.getAngles(false)[0] << "rad, "
         << fixed << setprecision(2) << triangle.getAngles(false)[1] << "rad, "
         << fixed << setprecision(2) << triangle.getAngles(false)[2] << "rad\u001b[0m" << endl;
    cout << "Triangle angles: "
         << fixed << setprecision(2) << triangle.getAngles(true)[0] << "deg, "
         << fixed << setprecision(2) << triangle.getAngles(true)[1] << "deg, "
         << fixed << setprecision(2) << triangle.getAngles(true)[2] << "deg\n" << endl;

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

    return 0;
}