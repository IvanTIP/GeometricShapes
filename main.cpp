#include <iostream>
#include <cmath>
class CommonData {
 private:
    double X = 0.0;
    double Y = 0.0;
    double leftUpX = 0.0;
    double leftUpY = 0.0;
    double rightBottomX = 0.0;
    double rightBottomY = 0.0;
    enum color {
        RED = 1,
        BLUE = 2,
        GREEN = 4,
        NONE = 8
    };
  public:
    void setXY (double inX, double inY) {
        X = inX;
        Y = inY;
    }

    void setDescribingRectangle (double inLeftUpX, double inLeftUpY, double inRightBottomX, double inRightBottomY) {
        leftUpX = inLeftUpX;
        leftUpY = inLeftUpY;
        rightBottomX = inRightBottomX;
        rightBottomY = inRightBottomY;
    }

    double getX () {
        return X;
    }
    double  getY () {
        return Y;
    }

    color getRColor () {
        return RED;
    }
    color getGColor () {
        return GREEN;
    }
    color getBColor () {
        return BLUE;
    }
    color getNColor () {
        return NONE;
    }

    void show (double s, int inClrStatus) {
        std::cout << "Square: " << s << std::endl;
        std::cout << "Color: ";
        if (inClrStatus == RED) {
            std::cout << "red" << std::endl;
        } else if (inClrStatus == BLUE) {
            std::cout << "blue" << std::endl;
        } else if (inClrStatus == GREEN) {
            std::cout << "green" << std::endl;
        } else if (inClrStatus == NONE) {
            std::cout << "none" << std::endl;
        }
        std::cout << "Coordinates of the upper-left corner of the describing rectangle:" << std::endl;
        std::cout << "  x = " << leftUpX << std::endl;
        std::cout << "  y = " << leftUpY << std::endl;
        std::cout << "Coordinates of the lower right corner of the describing rectangle:" << std::endl;
        std::cout << "  x = " << rightBottomX << std::endl;
        std::cout << "  y = " << rightBottomY << std::endl;
    }

};

class Circle : public CommonData {
  private:
    int clrStatus = 0;
    double radius = 0.0;
  public:
    double square () {
        return atan(1.0) * 4.0 * radius;
    }
    void showInfo () {
        std::cout << "Figure type: CIRCLE" << std::endl;
        show(square(), clrStatus);
    }
    void setData () {
        double x,y;
        std::string color = "unknown";
        std::cout << "Enter the coordinates of the center:" << std::endl;
        std::cout << "x = ";
        std::cin >> x;
        std::cout << "y = ";
        std::cin >> y;
        setXY(x, y);
        std::cout << "Enter the radius:" << std::endl;
        std::cout << "r = ";
        std::cin >> radius;
        std::cout << "Choose the color (red/green/blue/none): ";
        std::cin >> color;
        if (color == "red") {
            clrStatus = clrStatus | getRColor();
        } else if (color == "green") {
            clrStatus = clrStatus | getGColor();
        } else if (color == "blue") {
            clrStatus = clrStatus | getBColor();
        } else if (color == "none") {
            clrStatus = clrStatus | getNColor();
        }
        setDescribingRectangle(getX() - radius, getY() + radius, getX() + radius, getY() - radius);
    }
};

class Square : public CommonData {
private:
    int clrStatus = 0;
    double edgeLength = 0.0;
public:
    double square () {
        return std::pow(edgeLength,2);
    }
    void showInfo () {
        std::cout << "Figure type: SQUARE" << std::endl;
        show(square(), clrStatus);
    }
    void setData () {
        double x,y;
        std::string color = "unknown";
        std::cout << "Enter the coordinates of the center:" << std::endl;
        std::cout << "x = ";
        std::cin >> x;
        std::cout << "y = ";
        std::cin >> y;
        setXY(x, y);
        std::cout << "Enter the length of the edge:" << std::endl;
        std::cin >> edgeLength;
        std::cout << "Choose the color (red/green/blue/none): ";
        std::cin >> color;
        if (color == "red") {
            clrStatus = clrStatus | getRColor();
        } else if (color == "green") {
            clrStatus = clrStatus | getGColor();
        } else if (color == "blue") {
            clrStatus = clrStatus | getBColor();
        } else if (color == "none") {
            clrStatus = clrStatus | getNColor();
        }
        setDescribingRectangle(getX() - edgeLength/2.0, getY() + edgeLength/2.0, getX() + edgeLength/2.0, getY() - edgeLength/2.0);
    }
};

class Triangle : public CommonData {
private:
    int clrStatus = 0;
    double edgeLength = 0.0;
public:
    double square () {
        return std::pow(edgeLength,2) * std::sqrt(3)/4;
    }
    void showInfo () {
        std::cout << "Figure type: TRIANGLE" << std::endl;
        show(square(), clrStatus);
    }
    void setData () {
        double x,y;
        std::string color = "unknown";
        std::cout << "Enter the coordinates of the center:" << std::endl;
        std::cout << "x = ";
        std::cin >> x;
        std::cout << "y = ";
        std::cin >> y;
        setXY(x, y);
        std::cout << "Enter the length of thr edge:" << std::endl;
        std::cin >> edgeLength;
        std::cout << "Choose the color (red/green/blue/none): ";
        std::cin >> color;
        if (color == "red") {
            clrStatus = clrStatus | getRColor();
        } else if (color == "green") {
            clrStatus = clrStatus | getGColor();
        } else if (color == "blue") {
            clrStatus = clrStatus | getBColor();
        } else if (color == "none") {
            clrStatus = clrStatus | getNColor();
        }
        setDescribingRectangle(getX() - edgeLength/2.0, getY() + (std::sqrt(3) * edgeLength) / 3, getX() + edgeLength/2.0, getY() - (std::sqrt(3) * edgeLength) / 6);
    }
};

class Rectangle : public CommonData {
private:
    int clrStatus = 0;
    double width = 0.0;
    double height = 0.0;
public:
    double square () {
        return width * height;
    }
    void showInfo () {
        std::cout << "Figure type: RECTANGLE" << std::endl;
        show(square(), clrStatus);
    }
    void setData () {
        double x,y;
        std::string color = "unknown";
        std::cout << "Enter the coordinates of the center:" << std::endl;
        std::cout << "x = ";
        std::cin >> x;
        std::cout << "y = ";
        std::cin >> y;
        setXY(x, y);
        std::cout << "Enter the width:" << std::endl;
        std::cin >> width;
        std::cout << "Enter the height:" << std::endl;
        std::cin >> height;
        std::cout << "Choose the color (red/green/blue/none): ";
        std::cin >> color;
        if (color == "red") {
            clrStatus = clrStatus | getRColor();
        } else if (color == "green") {
            clrStatus = clrStatus | getGColor();
        } else if (color == "blue") {
            clrStatus = clrStatus | getBColor();
        } else if (color == "none") {
            clrStatus = clrStatus | getNColor();
        }
        setDescribingRectangle(getX() - width/2.0, getY() + height/2.0, getX() + width/2.0, getY() - height/2.0);
    }
};

int main() {
    std::string figure;
    std::cout << "Enter your figure: ";
    std::cin >> figure;
    if (figure == "circle") {
        Circle* circle = new Circle;
        circle->setData();
        circle->showInfo();
        delete circle;
    } else if (figure == "square") {
        Square* square = new Square;
        square->setData();
        square->showInfo();
        delete square;
    } else if (figure == "triangle") {
        Triangle* triangle = new Triangle;
        triangle->setData();
        triangle->showInfo();
        delete triangle;
    } else if (figure == "rectangle") {
        Rectangle* rectangle = new Rectangle;
        rectangle->setData();
        rectangle->showInfo();
        delete rectangle;
    }
    return 0;
}
