#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

// Абстрактний клас для трикутників
class Triangle {
public:
    virtual double calculateMedian(int side) const = 0;
    virtual double parallelMidline(int side) const = 0;
    virtual double inscribedRadius() const = 0;
    virtual double circumscribedRadius() const = 0;
    virtual ~Triangle() {}
};

// Клас трикутника за трьома сторонами
class TriangleBySides : public Triangle {
protected:
    double a, b, c;

public:
    TriangleBySides(double sideA, double sideB, double sideC)
        : a(sideA), b(sideB), c(sideC) {}

    double calculateMedian(int side) const override {
        if (side == 1) {
            return 0.5 * sqrt(2 * (b * b + c * c) - a * a);
        }
        else if (side == 2) {
            return 0.5 * sqrt(2 * (a * a + c * c) - b * b);
        }
        else {
            return 0.5 * sqrt(2 * (a * a + b * b) - c * c);
        }
    }

    double parallelMidline(int side) const override {
        if (side == 1) return 0.5 * a;
        if (side == 2) return 0.5 * b;
        return 0.5 * c;
    }

    double inscribedRadius() const override {
        double s = (a + b + c) / 2;
        return sqrt((s - a) * (s - b) * (s - c) / s);
    }

    double circumscribedRadius() const override {
        double s = (a + b + c) / 2;
        return (a * b * c) / (4 * sqrt(s * (s - a) * (s - b) * (s - c)));
    }
};

// Клас трикутника за трьома вершинами
class TriangleByVertices : public Triangle {
protected:
    double x1, y1, x2, y2, x3, y3;

    double distance(double x1, double y1, double x2, double y2) const {
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }

public:
    TriangleByVertices(double px1, double py1, double px2, double py2, double px3, double py3)
        : x1(px1), y1(py1), x2(px2), y2(py2), x3(px3), y3(py3) {}

    double calculateMedian(int side) const override {
        double a = distance(x1, y1, x2, y2);
        double b = distance(x2, y2, x3, y3);
        double c = distance(x1, y1, x3, y3);
        if (side == 1) {
            return 0.5 * sqrt(2 * (b * b + c * c) - a * a);
        }
        else if (side == 2) {
            return 0.5 * sqrt(2 * (a * a + c * c) - b * b);
        }
        else {
            return 0.5 * sqrt(2 * (a * a + b * b) - c * c);
        }
    }

    double parallelMidline(int side) const override {
        double a = distance(x1, y1, x2, y2);
        double b = distance(x2, y2, x3, y3);
        double c = distance(x1, y1, x3, y3);
        if (side == 1) return 0.5 * a;
        if (side == 2) return 0.5 * b;
        return 0.5 * c;
    }

    double inscribedRadius() const override {
        double a = distance(x1, y1, x2, y2);
        double b = distance(x2, y2, x3, y3);
        double c = distance(x1, y1, x3, y3);
        double s = (a + b + c) / 2;
        return sqrt((s - a) * (s - b) * (s - c) / s);
    }

    double circumscribedRadius() const override {
        double a = distance(x1, y1, x2, y2);
        double b = distance(x2, y2, x3, y3);
        double c = distance(x1, y1, x3, y3);
        double s = (a + b + c) / 2;
        return (a * b * c) / (4 * sqrt(s * (s - a) * (s - b) * (s - c)));
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TriangleBySides triangle1(3, 4, 5);
    cout << "Медіана до сторони a: " << triangle1.calculateMedian(1) << endl;
    cout << "Середня лінія, паралельна стороні a: " << triangle1.parallelMidline(1) << endl;
    cout << "Радіус вписаного кола: " << triangle1.inscribedRadius() << endl;
    cout << "Радіус описаного кола: " << triangle1.circumscribedRadius() << endl;

    TriangleByVertices triangle2(0, 0, 3, 0, 0, 4);
    cout << "Медіана до сторони a: " << triangle2.calculateMedian(1) << endl;
    cout << "Середня лінія, паралельна стороні a: " << triangle2.parallelMidline(1) << endl;
    cout << "Радіус вписаного кола: " << triangle2.inscribedRadius() << endl;
    cout << "Радіус описаного кола: " << triangle2.circumscribedRadius() << endl;

    return 0;
}
