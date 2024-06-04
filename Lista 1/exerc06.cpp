#include <iostream>
#include <string>

class Funcionario {
public:
    Funcionario(std::string nome = "", std::string cargo = "", double salario = 0.0)
        : nome(nome), cargo(cargo), salario(salario) {}

    virtual ~Funcionario() {}

    void addAumento(double valor) {
        salario += valor;
    }

    virtual double GanhoAnual() const {
        return salario * 12;
    }

    virtual void exibirDados() const {
        std::cout << "Nome: " << nome << std::endl;
        std::cout << "Cargo: " << cargo << std::endl;
        std::cout << "Salário: " << salario << std::endl;
        std::cout << "Ganho Anual: " << GanhoAnual() << std::endl;
    }

protected:
    std::string nome;
    std::string cargo;
    double salario;
};

class Assistente : public Funcionario {
public:
    Assistente(std::string nome = "", std::string cargo = "", double salario = 0.0, int matricula = 0)
        : Funcionario(nome, cargo, salario), matricula(matricula) {}

    int getMatricula() const {
        return matricula;
    }

    void setMatricula(int matricula) {
        this->matricula = matricula;
    }

    void exibirDados() const override {
        Funcionario::exibirDados();
        std::cout << "Matrícula: " << matricula << std::endl;
    }

protected:
    int matricula;
};

class Tecnico : public Assistente {
public:
    Tecnico(std::string nome = "", std::string cargo = "", double salario = 0.0, int matricula = 0, double bonusSalarial = 0.0)
        : Assistente(nome, cargo, salario, matricula), bonusSalarial(bonusSalarial) {}

    double GanhoAnual() const override {
        return (salario + bonusSalarial) * 12;
    }

    void exibirDados() const override {
        Assistente::exibirDados();
        std::cout << "Bônus Salarial: " << bonusSalarial << std::endl;
        std::cout << "Ganho Anual (com bônus): " << GanhoAnual() << std::endl;
    }

private:
    double bonusSalarial;
};

class Administrativo : public Assistente {
public:
    Administrativo(std::string nome = "", std::string cargo = "", double salario = 0.0, int matricula = 0, std::string turno = "", double adicionalNoturno = 0.0)
        : Assistente(nome, cargo, salario, matricula), turno(turno), adicionalNoturno(adicionalNoturno) {}

    double GanhoAnual() const override {
        if (turno == "Noturno") {
            return (salario + adicionalNoturno) * 12;
        }
        return salario * 12;
    }

    void exibirDados() const override {
        Assistente::exibirDados();
        std::cout << "Turno: " << turno << std::endl;
        if (turno == "Noturno") {
            std::cout << "Adicional Noturno: " << adicionalNoturno << std::endl;
        }
        std::cout << "Ganho Anual: " << GanhoAnual() << std::endl;
    }

private:
    std::string turno;
    double adicionalNoturno;
};

int main() {
    int opcao = 1;

    while (opcao == 1) {
        std::cout << "Deseja cadastrar um novo funcionário? (1 - Sim, outro número para Não)" << std::endl;
        std::cin >> opcao;

        if (opcao == 1) {
            std::string nome, cargo;
            double salario;
            int matricula;

            std::cout << "Digite o nome do funcionário: ";
            std::cin >> nome;
            std::cout << "Digite o salário do funcionário: ";
            std::cin >> salario;
            std::cout << "O funcionário é um assistente? (1 - Sim, outro valor para Não)" << std::endl;
            int ehAssistente;
            std::cin >> ehAssistente;

            if (ehAssistente == 1) {
                cargo = "Assistente";
                std::cout << "Digite a matrícula do assistente: ";
                std::cin >> matricula;

                int tipoAssistente;
                std::cout << "Digite o tipo de assistente (1 - Técnico, 2 - Administrativo, outro número para Nenhum): " << std::endl;
                std::cin >> tipoAssistente;

                if (tipoAssistente == 1) {
                    double bonusSalarial;
                    std::cout << "Digite o bônus salarial do assistente técnico: ";
                    std::cin >> bonusSalarial;

                    Tecnico tecnico(nome, cargo, salario, matricula, bonusSalarial);
                    tecnico.exibirDados();
                } else if (tipoAssistente == 2) {
                    double adicionalNoturno = 0.0;
                    std::string turno;

                    std::cout << "Digite o turno do assistente administrativo (\"D\" para Diurno ou \"N\" para Noturno): " << std::endl;
                    std::cin >> turno;

                    if (turno == "N" || turno == "n") {
                        turno = "Noturno";
                        std::cout << "Digite o adicional noturno do assistente administrativo: ";
                        std::cin >> adicionalNoturno;
                    } else {
                        turno = "Diurno";
                    }

                    Administrativo administrativo(nome, cargo, salario, matricula, turno, adicionalNoturno);
                    administrativo.exibirDados();
                } else {
                    Assistente assistente(nome, cargo, salario, matricula);
                    assistente.exibirDados();
                }
            } else {
                std::cout << "Digite o cargo do funcionário: ";
                std::cin >> cargo;
                Funcionario funcionario(nome, cargo, salario);
                funcionario.exibirDados();
            }
        } else {
            std::cout << "Cabou..." << std::endl;
        }
    }

    return 0;
}
