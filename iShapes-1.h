#include "pch.h"
#ifndef iShapes_h
#define iShapes_h

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

const double pi = 3.14159;

struct Shape
{

	virtual void output(ostream& out) const = 0;
	friend ostream& operator<<(std::ostream& out, const Shape& sh);
	virtual ~Shape() {}

};




class Square : public Shape
{
protected:
	const double side;

public:
	Square(const vector<string>& tokens) : side(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {}
	void output(ostream&) const ;
};

class Rectanglee : public Shape
{
protected:
	const double length;
	const double width;

public:
	Rectanglee(const vector<string>& tokens) : length(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0), width(tokens.size() > 1 ? atof(tokens[2].c_str()) : 0) {}
	void output(ostream&) const ;
};

class Circle : public Shape
{
protected:
	const double radius;

public:
	Circle(const vector<string>& tokens) : radius(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {}
	void output(ostream&) const ;
};

class Triangle : public Shape
{
protected:
	const double side;

public:
	Triangle(const vector<string>& tokens) : side(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {}
	void output(ostream&) const ;
};

class Cube : public Square
{
public:
	Cube(const vector<string>& tokens) : Square(tokens) {}
	void output(ostream&) const ;
};

class Box : public Rectanglee
{
	const double height;

public:
	Box(const vector<string>& tokens) : Rectanglee(tokens), height(tokens.size() > 3 ? atof(tokens[3].c_str()) : 0) {}
	void output(ostream&) const ;
};

class Cylinder : public Circle
{
	const double height;

public:
	Cylinder(const vector<string>& tokens) : Circle(tokens), height(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {}
	void output(ostream&) const ;
};

class Prism : public Triangle
{
	const double height;

public:
	Prism(const vector<string>& tokens) : Triangle(tokens), height(tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0) {}
	void output(ostream&) const ;
};


ostream& roundingTwo(ostream&);

ostream& roundingOff(ostream&);

#endif /* iShapes_h */