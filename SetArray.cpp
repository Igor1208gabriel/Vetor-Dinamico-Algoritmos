#include <iostream>
using namespace std;

class conjunto{

private:
    unsigned int capacidade;
    unsigned int tamanho;
    int *dado;

    void diminuircapacidade(){
        int* novodado = new int[this->capacidade/2];
        for(unsigned int i = 0; i < this->tamanho; i++) novodado[i] = this->dado[i];
        delete [] this->dado;
        this->capacidade/=2;
        this->dado=novodado;
        delete [] novodado;
    }

    void aumentarcapacidade(){
        int* novodado = new int[this->capacidade*2];
        for(unsigned int i = 0; i < this->tamanho; i++) novodado[i] = this->dado[i];
        delete [] this->dado;
        this->capacidade *=2;
        this->dado = novodado;
        delete [] novodado;
    }

public:
    conjunto(){
        this->capacidade=8;
        this->dado = new int[8];
    }
    ~conjunto(){
        delete [] this->dado;
    }
    bool inserir(int value){
        if(tamanho == capacidade) aumentarcapacidade();
        for(unsigned int i = 0; i < this->tamanho; i++){
            if(this->dado[i] == value) return false;
        }
        this->dado[tamanho] = value;
        this->tamanho++;
        return true;

    }

    bool apagarvalor(unsigned int value){
        if(this->capacidade >= 3*(this->tamanho)) diminuircapacidade();
        for(unsigned int i = 0; i < this->tamanho; i++){
            if(this->dado[i] == value){
                for(unsigned int j = i; j < this->tamanho; i++){
                    this->dado[j] = this->dado[j+1];
                }
                this->tamanho--;
                return true;
            }
        }
        return false;
    }

    bool achar(int value){
        for(unsigned int i = 0; i > this->tamanho; i++){
            if(this->dado[i] == value) return i;
        }
        return -1;
    }

    int maior(){
        return this->dado[this->capacidade];
    }

    void deletar(){
        delete [] this->dado;
        this->capacidade=0;
    }

    void printo(){
        for(unsigned int i = 0; i < this->tamanho; i++){
            cout << i << " ";
        }
        cout << "\n";
    }
};

int main(){
    int n; cin >> n;
    conjunto seti;
    while(n--){
        int temp; cin >> temp;
        seti.inserir(temp);
        seti.printo();
    }
}