#include <iostream>
#include <string>
#include <vector>

#define PI 3.141592653589793

enum class ShapeColour {
    NONE, BLACK, BLUE, GREEN, AQUA, RED, MAGENTA, YELLOW, WHITE
}; //Идентификаторы цвета

std::string shapeColorName[9] {
    "none", "black", "blue", "green", "aqua", "red", "magenta", "yellow", "white"
}; //Текстовое описание цвета

ShapeColour getColour(std::string inColourName) {
    //Найдем цвет в массиве, накастуем значение
    for (int i = 0; i<9; i++) {
        if (inColourName == shapeColorName[i]) return static_cast<ShapeColour>(i);
    }
    //Если не нашли, то присвоим цвет ShapeColour::NONE
    std::cout << "Unknown colour. Colour sets up to none\n";
    return ShapeColour::NONE;
}

enum class ShapeID {
    Circle_ID, Triangle_ID, Rectangle_ID, Square_ID
}; //Идентификаторы фигур

std::string shapeName[4] {
   "circle", "triangle", "rectangle", "square"
}; //Текстовое описание фигуры

typedef struct {
    int top = 0;
    int left = 0;
} point; //Структура Точка

class Shape {
public:
    point center;
    point *apexes = nullptr;
    int height;
    int width;
    ShapeColour colour = ShapeColour::NONE;
    virtual void getInfo() = 0;
    virtual ~Shape() {};
    static Shape* createShape(ShapeID inId);
};

class Triangle : public Shape {
public:
    const int apexcount = 3;
    Triangle();
    void getInfo();
};

Triangle::Triangle() {
    int number;
    std::string inColour;
    std::cout << "Enter bottom side width: ";
    std::cin >> number;
    this -> width = number;
    std::cout << "Enter triangle height: ";
    std::cin >> number;
    this -> height = number;
    std::cout << "Enter coordinate of center (top): ";
    std::cin >> number;
    this -> center.top = number;
    std::cout << "Enter coordinate of center (left): ";
    std::cin >> number;
    this -> center.left = number;
    std::cout << "Enter shape colour (default - none): ";
    std::cin >> inColour;
    this->colour = getColour(inColour);
    this->apexes = new point[apexcount];
    this->apexes[0].left = center.left - (width/2);
    this->apexes[0].top = center.top - (height/2);
    this->apexes[1].left = center.left + (width/2);
    this->apexes[1].top = center.top - (height/2);
    this->apexes[2].left = center.left;
    this->apexes[2].top = center.top + (height/2);
    std::cout << "Triangle created.\n";
}

void Triangle::getInfo() {
    std::cout << "Triangle:\n";
    std::cout << "  colour: " << shapeColorName[static_cast<int>(colour)] << std::endl;
    std::cout << "  width: " << width << std::endl;
    std::cout << "  height: " << height << std::endl;
    std::cout << "  area: " << PI * pow(double(width)/2, 2) << std::endl;
    std::cout << "  apexes:\n";
    for (int i=0; i<apexcount; i++) {
        std::cout << "    a"<< i <<": " << this->apexes[i].left <<"l " << this -> apexes[i].top << "t\n";
    }
};

class Quadrilateral : public Shape {
public:
    const int apexcount = 4;
};

class Rectangle : public Quadrilateral {
public:
    Rectangle();
    void getInfo();
};


Rectangle::Rectangle() {
    int number;
    std::string inColour;
    std::cout << "Enter width: ";
    std::cin >> number;
    this -> width = number;
    std::cout << "Enter height: ";
    std::cin >> number;
    this -> height = number;
    std::cout << "Enter coordinate of center (top): ";
    std::cin >> number;
    this -> center.top = number;
    std::cout << "Enter coordinate of center (left): ";
    std::cin >> number;
    this -> center.left = number;
    std::cout << "Enter shape colour (default - none): ";
    std::cin >> inColour;
    this->colour = getColour(inColour);
    this->apexes = new point[apexcount];
    this->apexes[0].left = center.left - (width/2);
    this->apexes[0].top = center.top - (height/2);
    this->apexes[1].left = center.left + (width/2);
    this->apexes[1].top = center.top - (height/2);
    this->apexes[2].left = center.left + (width/2);
    this->apexes[2].top = center.top + (height/2);
    this->apexes[3].left = center.left - (width/2);
    this->apexes[3].top = center.top + (height/2);
    std::cout << "Rectangle created\n";
}

void Rectangle::getInfo() {
    std::cout << "Rectangle:\n";
    std::cout << "  colour: " << shapeColorName[static_cast<int>(colour)] << std::endl;
    std::cout << "  width: " << width << std::endl;
    std::cout << "  height: " << height << std::endl;
    std::cout << "  area: " << width * height << std::endl;
    std::cout << "  apexes:\n";
    for (int i=0; i<apexcount; i++) {
        std::cout << "    a"<< i <<": " << this->apexes[i].left <<"l " << this -> apexes[i].top << "t\n";
    }
}

class Square : public Quadrilateral {
public:
    Square();
    void getInfo();
};

Square::Square() {
    int number;
    std::string inColour;
    std::cout << "Enter width: ";
    std::cin >> number;
    this -> width = this -> height = number;
    std::cout << "Enter coordinate of center (top): ";
    std::cin >> number;
    this -> center.top = number;
    std::cout << "Enter coordinate of center (left): ";
    std::cin >> number;
    this -> center.left = number;
    std::cout << "Enter shape colour (default - none): ";
    std::cin >> inColour;
    this->colour = getColour(inColour);
    this->apexes = new point[apexcount];
    this->apexes[0].left = center.left - (width/2);
    this->apexes[0].top = center.top - (height/2);
    this->apexes[1].left = center.left + (width/2);
    this->apexes[1].top = center.top - (height/2);
    this->apexes[2].left = center.left + (width/2);
    this->apexes[2].top = center.top + (height/2);
    this->apexes[3].left = center.left - (width/2);
    this->apexes[3].top = center.top + (height/2);
    std::cout << "Square created\n";
};

void Square::getInfo() {
    std::cout << "Square:\n";
    std::cout << "  colour: " << shapeColorName[static_cast<int>(colour)] << std::endl;
    std::cout << "  width: " << height << std::endl;
    std::cout << "  area: " << width * height << std::endl;
    std::cout << "  apexes:\n";
    for (int i=0; i<apexcount; i++) {
        std::cout << "    a"<< i <<": " << this->apexes[i].left <<"l " << this -> apexes[i].top << "t\n";
    }
}

class Circle : public Shape {
public:
    Circle();
    void getInfo();
};

Circle::Circle() {
    int number;
    std::string inColour;
    std::cout << "Enter diameter: ";
    std::cin >> number;
    this -> width = number;
    std::cout << "Enter coordinate (top): ";
    std::cin >> number;
    this -> center.top = number;
    std::cout << "Enter coordinate (left): ";
    std::cin >> number;
    this -> center.left = number;
    std::cout << "Enter shape colour (default - none): ";
    std::cin >> inColour;
    this->colour = getColour(inColour);
    std::cout << "Circle created\n";
}

void Circle::getInfo() {
    std::cout << "Circle:\n";
    std::cout << "  colour: " << shapeColorName[static_cast<int>(colour)] << std::endl;
    std::cout << "  diameter: " << width << std::endl;
    std::cout << "  area: " << PI * pow(double(width)/2, 2) << std::endl;
};

Shape* Shape::createShape(ShapeID inId) {
    Shape * p;
    switch (inId)
    {
        case ShapeID::Circle_ID:
            p = new Circle();
            break;
        case ShapeID::Triangle_ID:
            p = new Triangle();
            break;
        case ShapeID::Rectangle_ID:
            p = new Rectangle();
            break;
        case ShapeID::Square_ID:
            p = new Square();
            break;
        default: p = nullptr;
    }
    return p;
}

int main() {
    std::cout << "Shape hierarchy!" << std::endl;
    std::cout << "--------------------------------------------------\n";
    std::cout << "Create the set of shapes\n";
    std::cout << "--------------------------------------------------\n";
    std::string command;
    std::vector<Shape *> shapeList;
    do {
        std::cout << "Command list:\n";
        std::cout << "  tringle - for creation of triangle\n";
        std::cout << "  square - for creation of square\n";
        std::cout << "  rectangle - for creation of rectangle\n";
        std::cout << "  circle - for creation of circle\n\n";
        std::cout << "  list - for show info about created shapes\n";
        std::cout << "  exit - for ending program\n";
        std::cout << "CLI> ";
        std::cin >> command;
        if (command == "circle") {
            shapeList.push_back(Shape::createShape(ShapeID::Circle_ID));
        } else if (command == "triangle") {
            shapeList.push_back(Shape::createShape(ShapeID::Triangle_ID));
        } else if (command == "rectangle") {
            shapeList.push_back(Shape::createShape(ShapeID::Rectangle_ID));
        } else if (command == "square") {
            shapeList.push_back(Shape::createShape(ShapeID::Square_ID));
        } else if (command == "list") {
            for (int i=0; i<shapeList.size(); i++) {
                shapeList[i]->getInfo();
            }
        }

    } while (command != "exit");
    for (int i=shapeList.size()-1; i>=0; i--) {
        delete shapeList[i];
        shapeList.pop_back();
    }
    return 0;
}
