#include <iostream>
#define MAX_TAMANHO 20
#define MAX_CONJUNTO 2

using namespace std;

/*Você deverá implementar um tipo abstrato de dados Conjunto para representar conjuntos de números inteiros.
Seu tipo abstrato deverá armazenar os elementos do conjunto e o seu tamanho n.
Considere que o tamanho máximo de um conjunto é 20 elementos e use arranjos de 1 dimensão (vetores) para a sua implementação.
Seu TAD deve possuir procedimentos (ou funções quando for o caso) para:
a. criar um conjunto vazio;
b. ler os dados de um conjunto;
c. fazer a união de dois conjuntos;
d. fazer a interseção de dois conjuntos;
e. imprimir um conjunto */

struct Conjunto{
    int conjunto[MAX_TAMANHO];
    int tamanho;

    Conjunto(){
        tamanho = 0;
    }

    void ler(){
        cout << "Digite o tamanho do conjunto: ";
        cin >> tamanho;

        cout << "Digite os elementos do conjunto de tamanho " << tamanho << ": ";
        for(int i = 0; i < tamanho; i++){
            cin >> conjunto[i];
        }
    }

    void imprimir(){
        for(int i = 0; i < tamanho; i++){
            cout << conjunto[i] << " ";
        }
        cout << "}" << endl;
    }
};

struct TDA{
    Conjunto c[MAX_CONJUNTO];
    int qtdConjuntos = 0;

    void lerConjunto(){
        if(qtdConjuntos == 2){
            cout << "Limite de conjuntos atingido!" << endl;
            return;
        }
        cout << "Conjunto " << qtdConjuntos + 1 << " :" << endl;
        c[qtdConjuntos].ler();
        qtdConjuntos++;
    }

    void unir(){

        if(qtdConjuntos == 0){
            cout << "Necessario ler dois conjunto para fazer a uniao!!" << endl;
            return;
        }else if (qtdConjuntos < 2){
            cout << "Necessario ler outro conjunto para fazer a uniao!!" << endl;
            return;
        }

        int resultadoUniao[40];
        for(int i = 0; i < c[0].tamanho; i++){
            resultadoUniao[i] = c[0].conjunto[i];
        }

        int j = 0;
        for(int i = c[0].tamanho; i < c[1].tamanho + c[0].tamanho; i++){
            resultadoUniao[i] = c[1].conjunto[j];
            j++;
        }

        cout << "Conjunto 1 U Conjuto 2: { ";
        for(int i = 0; i < c[1].tamanho + c[0].tamanho; i++){
            cout << resultadoUniao[i] << " ";
        }

        cout << "}" << endl;
    }

    void intersecao(){

        if(qtdConjuntos == 0){
            cout << "Necessario ler dois conjunto para fazer a intersecao!!" << endl;
            return;
        }else if (qtdConjuntos < 2){
            cout << "Necessario ler outro conjunto para fazer a intersecao!!" << endl;
            return;
        }

        int resultadoIntersecao[20], cont = 0;
        for(int i = 0; i < c[0].tamanho; i++){
            for(int j = 0; j < c[1].tamanho; j++){
                if(c[0].conjunto[i] == c[1].conjunto[j]){
                    resultadoIntersecao[cont] = c[0].conjunto[i];
                    cont++;
                }
            }
        }

        cout << "Conjunto 1 & Conjuto 2: { ";
        for(int i = 0; i < cont; i++){
            cout << resultadoIntersecao[i] << " ";
        }

        cout << "}" << endl;
    }

    void imprimirConjunto(){

        if(qtdConjuntos == 0){
            cout << "Nao a conjuntos para imprimir!" << endl;
            return;
        }

        for (int i = 0; i < qtdConjuntos; i++) {
            cout << "Conjunto " << i + 1 << ": { ";
            c[i].imprimir();
        }
    }

};




int main(){
    TDA conj;

    int opcao;

    do{
        cout << "------------------------------------------" << endl;
        cout << "       MENU" << endl;
        cout << "1. Ler os dados de um conjunto." << endl;
        cout << "2. Unir  os dois conjuntos." << endl;
        cout << "3. Fazer intersecao dos dois conjuntos." << endl;
        cout << "4. Imprimir conjuntos." << endl;
        cout << "5. Sair ." << endl << endl;

        cin >> opcao;

        switch(opcao){
            case 1:
                conj.lerConjunto();
                break;
            case 2:
                conj.unir();
                break;
            case 3:
                conj.intersecao();
                break;
            case 4:
                conj.imprimirConjunto();
                break;

        };

    }while(opcao != 5);


    return 0;
}


