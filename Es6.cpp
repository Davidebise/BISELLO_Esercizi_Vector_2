#include <vector>
#include <iostream>

using  namespace std;
int main() {
    srand(time(NULL));
    vector<int> vettore;    //mucchi di banane
    for (int i=0; i<5; i++) {
        vettore.push_back((rand() % 30)+1);
        cout<<vettore[i]<<" ";
    }
    cout<<endl;
    int numeroBaneneTotale = 0;
    int numeroRandom;

    while (vettore.size() >0) {
        numeroRandom = rand()%vettore.size();
        int ban = vettore[numeroRandom];
        if (ban!=1) {
            ban/=2; //prende la metà
        }
        //se è una bananaa, col /2 diventa =0, errore
        cout<<"banane grabbate: "<<ban<<" dal mucchio " <<numeroRandom+1<<endl;
        numeroBaneneTotale += ban;
        vettore[numeroRandom] -= ban; //toglie la metà dal counter originale (o l'unica se era solo 1)
        if (vettore[numeroRandom] == 0) {   //se vuoto
            vettore.erase(vettore.begin()+numeroRandom);
            cout<<"mucchio tolto"<<endl;
            cout<<"vettore attuale:"<<endl;
            for (auto x : vettore) {
                cout<<x<<" ";
            }
            cout<<endl;
        }

    }
    cout<<"Banane totali: "<<numeroBaneneTotale<<endl;

}