#include <iostream>

using namespace std;

class Retangulo {
public:
    Retangulo(double _base, double _altura) : base(_base), altura(_altura) {}
    ~Retangulo() {}

    double calcularArea() const {
        return base * altura;
    }

    double calcularPerimetro() const {
        return 2 * (base + altura);
    }

    
    double getBase() const {
        return base;
    }

    double getAltura() const {
        return altura;
    }

    void setBase(double b) {
    base = b;
    }

    void setAltura(double a) {
        altura = a;
    }

private:
    double base;
    double altura;
};

int main() {
    double base, altura;

    cout << "Digite a base do retangulo: ";
    cin >> base;
    cout << "Digite a altura do retangulo: ";
    cin >> altura;

    Retangulo retangulo(base, altura);

    cout << "Base: " << retangulo.getBase() << endl;
    cout << "Altura: " << retangulo.getAltura() << endl;
    cout << "Area: " << retangulo.calcularArea() << endl;
    cout << "Perimetro: " << retangulo.calcularPerimetro() << endl;

    return 0;
}
