#include  "pch.h"
#include "iShapes-1.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

#include <cmath>
#include <iomanip>
#include <cstdlib>

ostream& roundingTwo(ostream& out)
{
    out.setf(ios::fixed);
    out.precision(2);
    return out;
}

ostream& roundingOff(ostream& out)
{
    out.unsetf(ios::fixed);
    out.precision(6);
    return out;
}
ostream& operator<<(ostream& out, const Shape& sh) {
    sh.output(out);
    return out;
}

void Square::output(ostream& out) const
{
    const double perimeter = side * 4;
    const double area = side * side;

    out << "Square side=" << side << roundingTwo;
    out << " area=" << area << " perimeter=" << perimeter << roundingOff << endl;
}

void Rectanglee::output(ostream& out) const
{
    const double perimeter = (2 * length) + (2 * width);
    const double area = width * length;

    out << "Rectangle length=" << length << " width=" << width << roundingTwo;
    out << " area=" << area << " perimeter=" << perimeter << roundingOff << endl;
}

void Circle::output(ostream& out) const
{
    const double perimeter = (2 * pi) * radius;
    const double area = pi * (radius * radius);

    out << "Circle radius=" << radius << roundingTwo;
    out << " area=" << area << " perimeter= " << perimeter << roundingOff << endl;
}

void Triangle::output(ostream& out) const
{
    const double perimeter = side * 3;
    const double area = ((sqrt(3) / 4) * (side * side));

    out << "Triangle side=" << side << roundingTwo;
    out << " area=" << area << " perimeter=" << perimeter << roundingOff << endl;
}

void Cube::output(ostream& out) const
{
    const double volume = side * side * side;
    const double surfaceArea = 6 * (side * side);

    out << "Cube side=" << side << roundingTwo;
    out << " surface area=" << surfaceArea << " volume=" << volume << roundingOff << endl;
}

void Box::output(ostream& out) const
{
    const double surfaceArea = (2 * length * width) + (2 * width * height) + (2 * length * height);
    const double volume = length * width * height;

    out << "Box length=" << length << " width=" << width << " height=" << height << roundingTwo;
    out << " surface area=" << surfaceArea << " volume=" << volume << roundingOff << endl;
}

void Cylinder::output(ostream& out) const
{
    const double volume = pi * (radius * radius) * height;
    const double surfaceArea = (2 * pi * (radius * radius)) + (2 * pi * radius * height);

    out << "Cylinder radius=" << radius << " height=" << height << roundingTwo;
    out << " surface area=" << surfaceArea << " volume=" << volume << roundingOff << endl;
}

void Prism::output(ostream& out) const
{
    const double volume = side * height;
    const double surfaceArea = volume + (2);
    

    out << "Prism side=" << side << " height=" << height << roundingTwo;
    out << " surface area=" << surfaceArea << " volume=" << volume << roundingOff << endl;
}