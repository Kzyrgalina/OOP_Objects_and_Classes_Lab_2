#include <iostream>
#include <conio.h>

// создание класса
class Rectangle {
protected:
    int width, length; // два атрибута
public: 
    Rectangle() { // конструктор без параметров
            std::cout << "Constr Rectangle()\n";
            width = 0;
            length = 0;
    }

    Rectangle(int width, int length) { // конструктор с параметрами
        std::cout << "Constr Rectangle(int x, int y)\n";
        this->width = width;
        this->length = length;
    }
    Rectangle(const Rectangle &p) { // копирующий конструктор (переносит всне свойства)
        std::cout << "Constr copy Rectangle(const Rectangle &p)\n";
        width = p.width;
        length = p.length;    
    }
    ~Rectangle() {
        //std::cout << " ~Rectangle()\n";
        printf("~Rectangle(%d, %d)\n", width, length);
    }
    void move(int dx, int dy) {
        width += dx;
        length += dy;
    }
    void reset();
};

class Parallelepiped: public Rectangle{
protected:
    int height; 
public:
    Parallelepiped(): Rectangle() { // конструктор без параметров
        std::cout << "Constr Parallelepiped()\n";
        //width = 0;
        //length = 0;
        height = 0;
    }

    Parallelepiped(int x, int y, int z): Rectangle() { // конструктор с параметрами
        std::cout << "Constr Parallelepiped(int x, int y, int z)\n";
        //this->width = width;
        //this->length = length;
        this->length = z;
    }
    Parallelepiped(const Parallelepiped& p) : Rectangle(width, length) { // копирующий конструктор (переносит всне свойства)
        std::cout << "Constr copy Parallelepiped(const Point &p)\n";
        width = p.width;
        length = p.length;
        height = p.height;
    }
    ~Parallelepiped() {
        //std::cout << " ~Rectangle()\n";
        printf("~Parallelepiped(%d, %d, %d)\n", width, length, height);
    }
    void move(int dx, int dy, int dz){
        width += dx;
        length += dy;
        height += dz;
    }
    void reset();
    void changeZ(int newz) {
        height = newz;
    }
};

class ExtraRectangle {
protected:
    Rectangle *r1;
    Rectangle *r2;

public:
    ExtraRectangle() { // конструктор без параметров
        std::cout << "Constr ExtraRectangle()\n";
        r1 = new Rectangle;
        r2 = new Rectangle;
    }

    ExtraRectangle(int width1, int length1, int width2, int length2) { // конструктор с параметрами
        std::cout << "Constr ExtraRectangle(int width1, int length1, int width2, int length2)\n";
        r1 = new Rectangle(width1,length1);
        r2 = new Rectangle(width2,length2);
    }
    ExtraRectangle(const ExtraRectangle& p) { // копирующий конструктор (переносит всне свойства)
        std::cout << "Constr copy Rectangle(const ExtraRectangle &p)\n";
        r1 = new Rectangle(*(p.r1));
        r2 = new Rectangle(*(p.r2));
    }
    ~ExtraRectangle() {
        //std::cout << " ~Rectangle()\n";
        delete r1;
        delete r2;
        //printf("~ExtraRectangle(%d, %d)\n", width, length);
        printf("~ExtraRectangle()\n");
    }
};


void Rectangle::reset() {
    width = 0;
    length = 0;
}

int main()
{
    {
    // статически
    //Rectangle p; 
    //Rectangle p2(10, 20);
    //Rectangle p3(p2);

    // динамическое создание
        //Rectangle *p1 = new Rectangle(1,2);
        //Rectangle *p2 = new Rectangle(10, 20);
        //Rectangle* p3 = new Rectangle(*p2);

        //Rectangle* ep = new Parallelepiped(4, 5, 6);
        

    //методы
        //p1->reset();
        //p1->move(10, 10);
        
    //удаляем сами, чтобы увидеть работу деструкторов
        //delete p1;
        //delete p2;
        //delete p3;
        //delete ep;

    // композиции
        ExtraRectangle *er1 = new ExtraRectangle;
        ExtraRectangle *er2 = new ExtraRectangle(*er1);
        ExtraRectangle* er3 = new ExtraRectangle(1, 2, 3, 4);

        delete(er1);
        delete(er2);
        delete(er3);
    }
    std::cout << "Hello World!\n";
}
