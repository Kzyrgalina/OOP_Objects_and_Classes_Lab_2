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

class ExtraPoint: public Point{
protected:
    int z; 
public:
    ExtraPoint(): Point() { // конструктор без параметров
        std::cout << "Constr ExtraPoint()\n";
        //x = 0;
        //y = 0;
        z = 0;
    }

    ExtraPoint(int x, int y, int z): Point() { // конструктор с параметрами
        std::cout << "Constr ExtraPoint(int x, int y, int z)\n";
        //this->x = x;
        //this->y = y;
        this->y = z;
    }
    ExtraPoint(const ExtraPoint& p) : Point(x, y) { // копирующий конструктор (переносит всне свойства)
        std::cout << "Constr copy ExtraPoint(const Point &p)\n";
        x = p.x;
        y = p.y;
        z = p.z;
    }
    ~ExtraPoint() {
        //std::cout << " ~Point()\n";
        printf("~Point(%d, %d, %d)\n", x, y, z);
    }
    void move(int dx, int dy, int dz){
        x += dx;
        y += dy;
        z += dz;
    }
    void reset();
    void changeZ(int newz) {
        z = newz;
    }
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
        //Point *p1 = new Point(1,2);
        //Point *p2 = new Point(10, 20);
        //Point* p3 = new Point(*p2);

        ExtraPoint* ep = new ExtraPoint(1, 2, 3);
        

    //методы
        //p1->reset();
        //p1->move(10, 10);
        
    //удаляем сами, чтобы увидеть работу деструкторов
        //delete p1;
        //delete p2;
        //delete p3;
        delete ep;
    }
    

    std::cout << "Hello World!\n";
}
