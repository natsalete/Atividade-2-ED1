#include <iostream>
#include <ctime>
#define MAX_CLIENTE 50

using namespace std;

/*Criar uma struct para armazenar um cliente, contendo os seguintes dados:
nome, data de nascimento, idade e sexo. O sexo é apenas uma letra (M ou F) e a data de nascimento deve ser armazenada numa struct de data, com 3 inteiros (dia, mês e ano). A idade deve ser calculada quando a data de nascimento for lida, e não solicitada ao usuário. Guarde a data atual numa variável da struct de data e crie uma função para calcular a idade.

Após isso, criar um menu com 2 opções: cadastrar cliente e listar clientes. Na primeira, um cliente deve ser lido e na segunda exibidos todos os clientes em ordem de cadastro.
Trate para que seu aplicativo armazene no máximo 50 clientes ao mesmo tempo.
*/

struct dataNascimento{
    int dia;
    int mes;
    int ano;
    int diasNasc, diasAtual, idade;
    int diaAtual, mesAtual, anoAtual;

    void lerDataNascimento(){
        cout << "Digite o dia em que nasceu: " << endl;
        cin >> dia;
        cout << "Digite o mes em que nasceu: " << endl;
        cin >> mes;
        cout << "Digite o ano em que nasceu: " << endl;
        cin >> ano;

    }

    void calcularIdade() {
        time_t t;
        struct tm infoTempo;

        time(&t);
        infoTempo = *localtime(&t);

        diaAtual = infoTempo.tm_mday;
        mesAtual = infoTempo.tm_mon + 1; // Meses são de 0 a 11
        anoAtual = infoTempo.tm_year + 1900; // Ano atual - 1900

        idade = calIdade();

    }

    int calIdade(){
        diasNasc = dia + (mes * 30) + (ano * 365);

        diasAtual = diaAtual + (mesAtual * 30) + (anoAtual * 365);

        idade = (diasAtual - diasNasc) / 365;

        return idade;
    }

};

struct cliente{
    dataNascimento data;
    string nome;
    char sexo;

    void ler(){
        cout << "Digite seu nome: " << endl;
        cin >> nome;

        data.lerDataNascimento();
        data.calcularIdade();

        cout << "Digite seu sexo:" << endl;
        cin >> sexo;
    }

    void imprimir(){
        cout << "Nome: " << nome << endl;
        cout << "Data de nascimento: " << data.dia << "/" << data.mes << "/" << data.ano << endl;
        cout << "Idade: " << data.idade << endl;
        cout << "Sexo: " << sexo << endl << endl;
    }


};


int main(){
    cliente c[MAX_CLIENTE];
    int qtdClientes = 0;

    int opcao;

    do{
        cout << endl;
        cout << "MENU" << endl << endl;
        cout << "1.Cadastrar cliente."<< endl;
        cout << "2.Listar clientes." << endl;
        cout << "3.Sair" << endl;

        cin >> opcao;

        switch(opcao) {
            case 1:
                if (qtdClientes >= MAX_CLIENTE) {
                    cout << "Numero maximo de cadastro atingido." << endl;
                    break;
                }
                c[qtdClientes].ler();
                qtdClientes++;
                break;
            case 2:
                 if (qtdClientes == 0) {
                    cout << "Nenhum cliente cadastrado!" << endl;
                    break;
                }

                for(int i = 0; i < qtdClientes; i++){
                    cout << "Cliente " << i+1 << ": " << endl;
                    c[i].imprimir();
                }

                break;
            };

    }while (opcao != 3);

    return 0;
}

