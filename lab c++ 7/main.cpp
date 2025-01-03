#include <iostream>

using namespace std;

class Shape {
protected:
    int first_dimension;
    int second_dimension;
public:
    int get_first_dimension() { return first_dimension; }
    int get_second_dimension() { return second_dimension; }
    void set_first_dimension(int m) { first_dimension = m; }
    void set_second_dimension(int n) { second_dimension = n; }
    virtual float area() = 0; // Pure virtual function
};

class Triangle : public Shape {
public:
    Triangle(int h, int l) { first_dimension = h; second_dimension = l; }
    float area() { return 0.5 * first_dimension * second_dimension; }
};

class Rectangle : public Shape {
public:
    Rectangle(int h, int l) { first_dimension = h; second_dimension = l; }
    float area() { return first_dimension * second_dimension; }
};

class Circle : public Shape {
public:
    Circle(int r) { first_dimension = r; second_dimension = r; }
    float area() { return 3.14 * first_dimension * first_dimension; }
};

class Square : public Rectangle {
public:
    Square(int r) : Rectangle(r, r) {}
};

class GeoShape {
private:
    Shape* shapes[5];
public:
    GeoShape(Shape* a1, Shape* a2, Shape* a3, Shape* a4, Shape* a5) {
        shapes[0] = a1;
        shapes[1] = a2;
        shapes[2] = a3;
        shapes[3] = a4;
        shapes[4] = a5;
    }
    void total() {
        float total_area = 0;
        for (int i = 0; i < 5; i++) {
            total_area += shapes[i]->area();
        }
        cout << "Total area: " << total_area << endl;
    }
};

class DynamicGeoShape {
private:
    Shape** shapes;
    int number_of_shapes;
public:
    DynamicGeoShape(int number_of_shapes1, Shape** shapes1) {
        number_of_shapes = number_of_shapes1;
        shapes = new Shape*[number_of_shapes];
        for (int i = 0; i < number_of_shapes; i++) {
            shapes[i] = shapes1[i];
        }
    }
    void total() {
        float total_area = 0;
        for (int i = 0; i < number_of_shapes; i++) {
            total_area += shapes[i]->area();
        }
        cout << "Total area (dynamic): " << total_area << endl;
    }
    ~DynamicGeoShape() {
        delete[] shapes;
    }
};

int main() {
    Triangle t(10, 5);
    Rectangle r(10, 5);
    Circle c(5);
    Square s(5);

    GeoShape gs(&t, &r, &c, &s, &s);
    gs.total();

    Shape* shape_array[5] = { &t, &r, &c, &s, &s };
    DynamicGeoShape dgs(5, shape_array);
    dgs.total();

    cout << "Triangle area: " << t.area() << endl;
    cout << "Rectangle area: " << r.area() << endl;
    cout << "Circle area: " << c.area() << endl;
    cout << "Square area: " << s.area() << endl;

    return 0;
}
