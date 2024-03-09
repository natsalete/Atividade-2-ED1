#include <iostream>
#define MAX_FUNCIONARIO 10

using namespace std;

/*Uma loja precisa controlar a folha de pagamento de seus funcionários. Os atributos de um funcionário são nome,
    cargo, salário base, benefícios e descontos.Criar uma struct para a loja e cadastrar uma lista de no
    máximo 10 funcionários com os campos acima e depois mostre os dados de cada um deles, com o salário
    liquido de cada um. O cálculo do salário líquido é: salário base + benefícios – descontos.
    Criar operações também para exibir a média salarial da loja e exibir quem recebe o maior salário.*/

struct funcionario{
    string nome;
    string cargo;
    double salarioBase;
    int beneficio;
    int desconto;
    double sLiquido;

    void ler(){
        cin.ignore();
        cout << "Nome : ";
        getline(cin, nome);
        cout << "Cargo: ";
        getline(cin, cargo);
        cout << "Salario base: R$ ";
        cin >> salarioBase;
        cout << "Beneficio em %: ";
        cin >> beneficio;
        cout << "Descontos em %: ";
        cin >> desconto;
    }


    void imprimir(){
        cout << "Nome : " << nome << endl;
        cout << "Cargo: " << cargo << endl;
        cout << "Salario base: R$" << salarioBase << endl;
        cout << "Beneficio: " << beneficio << "%" << endl;
        cout << "Descontos: " << desconto << "%" << endl;
        cout << "Salario liquido: R$" << salarioLiquido() << endl << endl;
    }

    double salarioLiquido(){
        sLiquido = salarioBase + (salarioBase * beneficio / 100) - (salarioBase * desconto / 100);

        return sLiquido;
    }
};

struct loja{
    funcionario funcionarios[MAX_FUNCIONARIO];
    int qtdFuncionario = 0;

    void cadastrar() {
        if (qtdFuncionario >= MAX_FUNCIONARIO) {
            cout << "Numero max de funcionarios atingido!" << endl;
            return;
        }
        funcionarios[qtdFuncionario].ler();
        qtdFuncionario++;
    }

    void listar(){
        if (qtdFuncionario == 0) {
            cout << "Nenhum funcionario cadastrado! " << endl;
            return;
        }
        for (int i = 0; i < qtdFuncionario; i++) {
            cout << "Funcionario: " << i+1 << endl;
            funcionarios[i].imprimir();
        }
    }


    void imprimirMediaSalarial(){
        if (qtdFuncionario == 0) {
            cout << "Nenhum funcionario cadastrado! " << endl;
            return;
        }

        int mediaBase = 0, mediaLiquida;
        for (int i = 0; i < qtdFuncionario; i++) {
            mediaBase += funcionarios[i].salarioBase;
            mediaLiquida += funcionarios[i].sLiquido;
        }
        mediaBase /= qtdFuncionario;
        mediaLiquida /= qtdFuncionario;

        cout << "Media de Salario Base : " << mediaBase << endl << endl;
        cout << "Media de Salario Liquido : " << mediaLiquida << endl;
    }

    void imprimirMaiorSalario() {
        if (qtdFuncionario == 0) {
            cout << "Nenhum funcionario cadastrado! " << endl;
            return;
        }


        int maiorBase = 0, posicaoBase = -1;
        int maiorLiquido = 0, posicaoLiquido = -1;
        for (int i = 0; i < qtdFuncionario; i++) {
            if (funcionarios[i].salarioBase > maiorBase) {
                maiorBase = funcionarios[i].salarioBase;
                posicaoBase = i;
            }
            if (funcionarios[i].sLiquido > maiorLiquido) {
                maiorLiquido = funcionarios[i].sLiquido;
                posicaoLiquido = i;
            }
        }
        cout << "Funcionario com maior salario base:" << endl;
        funcionarios[posicaoBase].imprimir();
        cout << endl << "Funcionario com maior salario liquido:" << endl;
        funcionarios[posicaoLiquido].imprimir();
    }


};

int main(){
    loja l;
    int opcao;

    do{
        cout << "------------------------------------------" << endl;
        cout << "       MENU CONTROLE LOJA" << endl;
        cout << "1. Cadastrar funcionario." << endl;
        cout << "2. Listar funcionarios ." << endl;
        cout << "3. Medias Salariais." << endl;
        cout << "4. Funcionario(s) com maior salario(s)." << endl;
        cout << "5. Sair." << endl << endl;

        cin >> opcao;

        switch(opcao){
            case 1:
                l.cadastrar();
                break;
            case 2:
                l.listar();
                break;
            case 3:
                l.imprimirMediaSalarial();
                break;
            case 4:
                l.imprimirMaiorSalario();
                break;

        };

    }while(opcao != 5);

    return 0;
}
