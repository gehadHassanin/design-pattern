/**
 * @file shape_operations.cpp
 * @author 
 * @brief 
 * @version 0.1
 * @date 2025-10-16
 * 
 * @copyright Copyright (c) 2025
 * 
 * 
 */

#include "shape_operations.h"

#include <math.h>

Circule::Circule() : radius_(0) {}

Circule::Circule(float rad) : radius_(rad) {}

void Circule::Accept(ShapeVisitor& visitor) {
    visitor.Visit(*this);
}

void Circule::SetRadius(float rad) { radius_ = rad; }

float Circule::GetRadius() { return radius_; }


Triangle::Triangle() : length_(0), width_(0) {}

Triangle::Triangle(float len, float wid) : 
    length_(len), width_(wid) {}

void Triangle::Accept(ShapeVisitor& visitor) {
    visitor.Visit(*this);
}

void Triangle::SetLength(float len) { length_ = len; }

void Triangle::SetWidth(float wid) { width_ = wid; }

float Triangle::GetLength() { return length_; }

float Triangle::GetWidth() { return width_; }


Square::Square() : length_(0) {}

Square::Square(float len) : length_(len) {}

void Square::Accept(ShapeVisitor& visitor) {
    visitor.Visit(*this);
}

void Square::SetLength(float len) { length_ = len; }

float Square::GetLength() { return length_; }


CalculateArea::CalculateArea() : total_area_(0) {}

void CalculateArea::Visit(Circule& circule) {
    total_area_ += M_PI * pow(circule.GetRadius(), 2);
}

void CalculateArea::Visit(Triangle& triangle) {
    total_area_ += triangle.GetLength() * triangle.GetWidth();
}

void CalculateArea::Visit(Square& square) {
    total_area_ += pow(square.GetLength(), 2);
}

double CalculateArea::GetTotalArea() { return total_area_; }
