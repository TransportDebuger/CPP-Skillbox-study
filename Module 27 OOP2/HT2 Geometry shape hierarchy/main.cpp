#include <iostream>
#include <string>
#include <map>

enum class ShapeColour {
    NONE, BLACK, BLUE, GREEN, AQUA, RED, MAGENTA, YELLOW, WHITE
}; //Идентификаторы цвета

std::string shapeColorName[9] {
    "none", "black", "blue", "green", "aqua", "red", "magenta", "yellow", "white"
}; //Текстовое описание цвета

enum class ShapeID {
    Circle_ID, Triangle_ID, Rectangle_ID, Square_ID
}; //Идентификаторы фигур

std::string shapeName[4] {
   "circle", "triangle", "rectangle", "square"
}; //Текстовое описание фигуры

typedef struct {
    int top=0;
    int left=0;
} point; //Структура Точка

class Shape {
public:
    point center;
    int amountOfPoints=0;
    ShapeColour colour = ShapeColour::NONE;
};

class Triangle : public Shape {

};

class Quadrilateral : public Shape {
    
};

class Rectangle : public Quadrilateral {

};

class Square : public Quadrilateral {
    
};

class Circle : public Shape {
public:
    int radius;
};

int main() {
    std::cout << "Shape hierarchy!" << std::endl;
    
    return 0;
}
