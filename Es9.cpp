#include <iostream>
#include <vector>
using namespace std;

int main() {
    srand(time(NULL));
    vector<string> vettore;
    vector<int> numeroScherziPerPersona;
    vettore.push_back("A");
    vettore.push_back("B");
    vettore.push_back("C");
    vettore.push_back("D");

    for (int i = 0; i < vettore.size(); i++) {
        numeroScherziPerPersona.push_back(0);
    }

    int mittente, destinatario;
    while (vettore.size() >1) {
        do {

            mittente = rand()%vettore.size();
            destinatario = rand()%vettore.size();

        }while (mittente==destinatario);

        for (int i = 0; i < numeroScherziPerPersona.size(); i++) {
            if (i != destinatario)
                numeroScherziPerPersona[i] = 0; //resetta  il contatore degli altri (per fare in modo che siano consecutivi)
        }

        numeroScherziPerPersona[destinatario]++;
        cout<<vettore[mittente]<<" fa scerzo a " << vettore[destinatario]<<" count: "<<numeroScherziPerPersona[destinatario]<<endl;

        if (numeroScherziPerPersona[destinatario]>=3) {
            cout<<vettore[destinatario]<<" quitta il game"<<endl;
            vettore.erase(vettore.begin()+destinatario);
            numeroScherziPerPersona.erase(numeroScherziPerPersona.begin()+destinatario);
        }

    }
    if (!vettore.empty())
        cout<<"Rimasto: "<<vettore.back()<<endl;
    else
        cout<<"vector vuoto";

    return 0;
}