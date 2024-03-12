#include <iostream>
#define MAX_TAMANHO 20
#define MAX_CONJUNTO 10
#include <vector>
#include <algorithm>

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

    void conjuntoVazio(){
        tamanho = 0;
        cout << "Conjunto vazio criado!" << endl;
    }

    void ler(){
        do{
            cout << "Digite o tamanho do conjunto: ";
            cin >> tamanho;
        }while(tamanho <= 0 || tamanho > 20);

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

    void criarConjuntoVazio(){
        if(qtdConjuntos == MAX_CONJUNTO){
            cout << "Limite de conjuntos atingido!" << endl;
            return;
        }
       c[qtdConjuntos].conjuntoVazio();
       qtdConjuntos++;
    }

    void lerConjunto(){
        if(qtdConjuntos == MAX_CONJUNTO){
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

        cout << "Dos conjuntos cadastrados quais deseja unir ? | Obs: Escolha dois conjuntos!" << endl;
        for (int i = 0; i < qtdConjuntos; i++) {
            cout << "Conjunto " << i + 1 << ": { ";
            c[i].imprimir();
        }

        int opcaoA, opcaoB;


        do{
            cin >> opcaoA;
            if(opcaoA <= 0 || opcaoA > qtdConjuntos){
                cout << "Escolha um Conjunto disponivel!!" << endl;
            }
        }while(opcaoA <= 0|| opcaoA > qtdConjuntos);

        do{
            cin >> opcaoB;
            if(opcaoB <= 0 || opcaoB > qtdConjuntos){
                cout << "Escolha um Conjunto disponivel!!" << endl;
            }else if(opcaoB == opcaoA){
                cout << "Escolha um Conjunto diferente!" << endl;
            }
        }while(opcaoB <= 0 || opcaoB > qtdConjuntos || opcaoB == opcaoA);


        vector<int>resultadoUniao;
        for(int i = 0; i < c[opcaoA-1].tamanho; i++){
            resultadoUniao.push_back(c[opcaoA-1].conjunto[i]);
        }

        for(int i = 0; i < c[opcaoB-1].tamanho ; i++){
            resultadoUniao.push_back(c[opcaoB-1].conjunto[i]);

        }

        sort(resultadoUniao.begin(), resultadoUniao.end());

        for(int i = 0; i < resultadoUniao.size(); i++){
          for(int j = i+1; j < resultadoUniao.size(); j++){
                if(resultadoUniao[i] == resultadoUniao[j]){
                   resultadoUniao.erase(resultadoUniao.begin()+i);
                   break;
                }
            }
        }

        cout << "Conjunto " << opcaoA << " U Conjuto " << opcaoB << ": { ";
        for(int i = 0; i < resultadoUniao.size(); i++){
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

        cout << "Dos conjuntos cadastrados quais deseja fazer a intersecao ? | Obs: Escolha dois conjuntos!" << endl;
        for (int i = 0; i < qtdConjuntos; i++) {
            cout << "Conjunto " << i + 1 << ": { ";
            c[i].imprimir();
        }

        int opcaoA, opcaoB;
        do{
            cin >> opcaoA;
            if(opcaoA <= 0 || opcaoA > qtdConjuntos){
                cout << "Escolha um Conjunto disponivel!!" << endl;
            }
        }while(opcaoA <= 0|| opcaoA > qtdConjuntos);

        do{
            cin >> opcaoB;
            if(opcaoB <= 0 || opcaoB > qtdConjuntos){
                cout << "Escolha um Conjunto disponivel!!" << endl;
            }else if(opcaoB == opcaoA){
                cout << "Escolha um Conjunto diferente!" << endl;
            }
        }while(opcaoB <= 0 || opcaoB > qtdConjuntos || opcaoB == opcaoA);


        int resultadoIntersecao[20], cont = 0;
        for(int i = 0; i < c[opcaoA-1].tamanho; i++){
            for(int j = 0; j < c[opcaoB-1].tamanho; j++){
                if(c[opcaoA-1].conjunto[i] == c[opcaoB-1].conjunto[j]){
                    resultadoIntersecao[cont] = c[opcaoA-1].conjunto[i];
                    cont++;
                }
            }
        }

        cout << "Conjunto " << opcaoA << " & Conjuto " << opcaoB << " : { ";
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
        cout << "1. Criar conjunto vazio." << endl;
        cout << "2. Ler os dados de um conjunto." << endl;
        cout << "3. Unir  os dois conjuntos." << endl;
        cout << "4. Fazer intersecao dos dois conjuntos." << endl;
        cout << "5. Imprimir conjuntos." << endl;
        cout << "6. Sair ." << endl << endl;

        cin >> opcao;

        switch(opcao){
            case 1:
                conj.criarConjuntoVazio();
                break;
            case 2:
                conj.lerConjunto();
                break;
            case 3:
                conj.unir();
                break;
            case 4:
                conj.intersecao();
                break;
            case 5:
                conj.imprimirConjunto();
                break;

        };

    }while(opcao != 6);


    return 0;
}


