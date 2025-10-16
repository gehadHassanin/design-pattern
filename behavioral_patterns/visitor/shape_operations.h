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

#ifndef BEHAVIORAL_PATTERNS_VISITOR_SHAPE_OPERATIONS_H_
#define BEHAVIORAL_PATTERNS_VISITOR_SHAPE_OPERATIONS_H_


class Circule;
class Triangle;
class Square;

class ShapeVisitor {
 public:
    virtual void Visit(Circule& circule) = 0;
    virtual void Visit(Triangle& triangle) = 0;
    virtual void Visit(Square& square) = 0;
};

class Shape {
 public:
    virtual void Accept(ShapeVisitor& visitor) = 0;
};

class Circule : public Shape {
 public:
    Circule();
    Circule(float rad);
    void Accept(ShapeVisitor& visitor) override;
    void SetRadius(float rad);
    float GetRadius();
 private:
   float radius_;
};

class Triangle : public Shape {
 public:
    Triangle();
    Triangle(float len, float wid);
    void Accept(ShapeVisitor& visitor) override;
    void SetLength(float len);
    void SetWidth(float wid);
    float GetLength();
    float GetWidth();
 private:
    float length_;
    float width_;
};

class Square : public Shape {
 public:
    Square();
    Square(float len);
    void Accept(ShapeVisitor& visitor) override;
    void SetLength(float len);
    float GetLength();
 private:
    float length_;
};

class CalculateArea : public ShapeVisitor {
 public:
    CalculateArea();
    void Visit(Circule& circule) override;
    void Visit(Triangle& triangle) override;
    void Visit(Square& square) override;
    double GetTotalArea();
 private:
    double total_area_;
};

#endif  //  BEHAVIORAL_PATTERNS_VISITOR_SHAPE_OPERATIONS_H_