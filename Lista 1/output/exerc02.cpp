#include <iostream>
#include <string>

using namespace std;

class ContaBancaria {
public:
    ContaBancaria() {}
    ~ContaBancaria() {}

    void setSaldo(float _saldo) {
        saldo = _saldo;
    }

    void setValor(float _valor) {
        valor = _valor;
    }

    float Deposito(float valor) {
        saldo += valor;
        return saldo;
    }

    float Saque(float valor) {
        if (valor > saldo) {
            cout << "Saldo insuficiente." << endl;
            return saldo;
        }
        saldo -= valor;
        return saldo;
    }

    float getSaldo() const {
        return saldo;
    }

private:
    float saldo;
    float valor;
};

int main() {
    ContaBancaria conta;
    float saldo, valor;
    int numeroConta;
    string nome;
    int operacao = 0;

    cout << "Digite o numero da conta: ";
    cin >> numeroConta;
    cout << "Digite o nome do titular da conta: ";
    cin >> nome;
    cout << "Digite o saldo inicial da conta: ";
    cin >> saldo;

    conta.setSaldo(saldo);

    while (operacao != 3) {
        cout << "\nEscolha a operacao:\n";
        cout << "1. Deposito\n";
        cout << "2. Saque\n";
        cout << "3. Sair\n";
        cout << "Operacao: ";
        cin >> operacao;

        if (operacao == 1) {
            cout << "Digite o valor do deposito: ";
            cin >> valor;
            conta.Deposito(valor);
            cout << "Saldo apos deposito: " << conta.getSaldo() << endl;
        } else if (operacao == 2) {
            cout << "Digite o valor do saque: ";
            cin >> valor;
            conta.Saque(valor);
            cout << "Saldo apos saque: " << conta.getSaldo() << endl;
        } else if (operacao == 3) {
            cout << "Saindo..." << endl;
        } else {
            cout << "Operacao invalida. Tente novamente." << endl;
        }
    }

    return 0;
}
