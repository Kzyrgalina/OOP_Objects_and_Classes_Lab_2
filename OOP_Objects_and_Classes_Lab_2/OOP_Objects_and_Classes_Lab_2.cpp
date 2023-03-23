#include <iostream>
#include <conio.h>

// создание класса
class Point {
protected:
    int x, y; // два атрибута
public: 
    Point() { // конструктор без параметров
            std::cout << "Constr Point()\n";
            x = 0;
            y = 0;
    }

    Point(int x, int y) { // конструктор с параметрами
        std::cout << "Constr Point(int x, int y)\n";
        this->x = x;
        this->y = y;
    }
    Point(const Point &p) { // копирующий конструктор (переносит всне свойства)
        std::cout << "Constr copy Point(const Point &p)\n";
        x = p.x;
        y = p.y;    
    }
    ~Point() {
        //std::cout << " ~Point()\n";
        printf("~Point(%d, %d)\n", x, y);
    }
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
    void reset();
};


void Point::reset() {
    x = 0;
    y = 0;
}

int main()
{
    {
    // статически
    //Point p; 
    //Point p2(10, 20);
    //Point p3(p2);

    // динамическое создание
        Point *p1 = new Point(1,2);
        //Point *p2 = new Point(10, 20);
        //Point* p3 = new Point(*p2);


    //методы
        //p1->reset;
        p1->move(10, 10);
        
    //удаляем сами, чтобы увидеть работу деструкторов
        delete p1;
        //delete p2;
        //delete p3;
    }
    

    std::cout << "Hello World!\n";
}
