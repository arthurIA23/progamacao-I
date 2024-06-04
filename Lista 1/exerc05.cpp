#include <iostream>
#include <string>

using namespace std;

class Funcionario {
    private:
        string nome;
        string cargo;
        float salario;

    public:
        Funcionario(string _nome, string _cargo, float _salario) : nome(_nome), cargo(_cargo), salario(_salario) {}

    float calcularSalLiquido(float imposto, float beneficios) {
        if(cargo == "gerente") {
            return salario - (salario * imposto) + beneficios;
        } 
        else if (cargo == "estoquista") {
            return salario - (salario * imposto);
        }
        else if (cargo == "caixa") {
            return salario - (salario * imposto) + beneficios;
        }
        else {
            return salario - (salario * imposto);
        }
    }

    float getSalario() {
        return salario;
    }

    string getNome() {
        return nome;
    }

    string getCargo() {
        return cargo;
    }
};

int main() {
    string nome, cargo;
    float salario, imposto, beneficios;

    cout << "Digite o nome do funcionario: ";
    cin >> nome;
    cout << "Digite o cargo do funcionario: ";
    cin >> cargo;
    cout << "Digite o salario do funcionario: ";
    cin >> salario;
    cout << "Digite o imposto do funcionario: ";
    cin >> imposto;
    cout << "Digite os beneficios do funcionario: ";
    cin >> beneficios;

    Funcionario funcionario(nome, cargo, salario);

    cout << "Nome: " << funcionario.getNome() << endl;
    cout << "Cargo: " << funcionario.getCargo() << endl;
    cout << "Salario liquido: " << funcionario.calcularSalLiquido(imposto, beneficios) << endl;

    return 0;
}