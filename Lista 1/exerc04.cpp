#include <iostream>
#include <string>

using namespace std;

class Aluno {
private:
    string nome;
    int matricula;
    float nota1;
    float nota2;
    float nota3;

public:
    Aluno(int m, string n, float n1, float n2, float n3) {
        matricula = m;
        nome = n;
        nota1 = n1;
        nota2 = n2;
        nota3 = n3;
    }

    float CalcularMedia() {
        return (nota1 + nota2 + nota3) / 3;
    }

    string Aprovado() {
        if(CalcularMedia() >= 6) {
            return "Aprovado";
        } 
        else {
            return "Reprovado";
        }
    }

    string getNome() {
        return nome;
    }

    int getMatricula() {
        return matricula;
    }
};

int main() {
    string nome;
    int matricula;
    float nota1, nota2, nota3;

    cout << "Digite o nome do aluno: ";
    cin >> nome;
    cout << "Digite a matricula do aluno: ";
    cin >> matricula;
    cout << "Digite a primeira nota do aluno: ";
    cin >> nota1;
    cout << "Digite a segunda nota do aluno: ";
    cin >> nota2;
    cout << "Digite a terceira nota do aluno: ";
    cin >> nota3;

    Aluno aluno(matricula, nome, nota1, nota2, nota3);

    cout << "O aluno " << aluno.getNome() << " de matricula " << aluno.getMatricula() << " obteve media " << aluno.CalcularMedia() << " e foi " << aluno.Aprovado() << endl;

    return 0;
}
