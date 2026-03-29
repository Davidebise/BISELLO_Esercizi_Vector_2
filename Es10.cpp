#include <vector>
#include <iostream>
using namespace std;
void GeneraNumeri(vector<vector<int>>* matrix) {
    int n;  //numero random

    //assegno la matrice
    matrix->assign(5, vector<int>(5, 0));
    //divide in 5 righe ognuna di un vector di 5 elementi, ognugno inizializzato totalemtne a 0

    //serve per accedere attraverso [x][y] (senza aver prima inizializzato gli elementi con pushback
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            n = (rand() % 10)+1;
            (*matrix)[i][j] = n;
        }
    }
}
void OperazioneNumeri(vector<int>* vettore) {
    int sommaNumeriPari=0;
    int n;
    for (auto it=vettore->begin(); it!=vettore->end(); ) {
        n= *it;
        if (n%2==1) {
            it = vettore->erase(it);
        }
        else {
            sommaNumeriPari+=n;
            it++;
        }
    }
    vettore->push_back(sommaNumeriPari);
    for (auto x:*vettore) {
        cout<<x<<" ";
    }
    cout<<endl;
}
int main() {
    srand(time(NULL));
    vector<vector<int>> matrice;
    GeneraNumeri(&matrice);

    cout<<"Matrice:"<<endl;
    for (int i =0;i<matrice.size();i++) {
        cout<<"vector numero "<<i;
        cout<<endl;
        for (auto x: matrice[i]) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    vector<int> riga1=matrice[0];
    vector<int> riga2=matrice[1];
    vector<int> riga3=matrice[2];
    vector<int> riga4=matrice[3];
    vector<int> riga5=matrice[4];

    OperazioneNumeri(&riga1);
    OperazioneNumeri(&riga2);
    OperazioneNumeri(&riga3);
    OperazioneNumeri(&riga4);
    OperazioneNumeri(&riga5);

}



