#include <iostream>

using namespace std;

class Circulo {
private:
    double raio;

public:
    Circulo(double r):raio(r) {}
    ~Circulo(){};


    double calcularArea() {
        return 3.14 * raio * raio;
    }

        double calcularPerimetro() {
        return 2 * 3.14 * raio;
    }

    double getRaio() {
        return raio;
    }

    void setRaio(double r) {
        raio = r;
    }
};

int main() {
    double raio;

    cout << "Digite o raio do circulo: ";
    cin >> raio;

    Circulo circulo(raio);
    std::cout << "Raio: " << circulo.getRaio() << std::endl;
    std::cout << "Area: " << circulo.calcularArea() << std::endl;
    std::cout << "Perimetro: " << circulo.calcularPerimetro() << std::endl;

    return 0;
}
