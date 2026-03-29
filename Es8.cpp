#include <iostream>
#include <vector>
using namespace std;
int main() {
    bool continua=true;
    vector<int> vettore = {55,20,30,40,25,35,50,60,15,45,10,70,25,30,40};

    while (!vettore.empty()) {
        continua=false;

        cout<<"Inizio"<<endl;
        for (auto x : vettore) {
            cout<<x<<" ";
        }
        cout<<endl;

        for (int i=0;i<vettore.size();i++) {
            vettore[i]=2*vettore[i];

            if (i!=0)
                vettore[i-1]-=vettore[i-1]/3;
            else
                vettore[vettore.size()-1]-=vettore[vettore.size()-1]/3;    //quello prima del primo è l'ultimo

        }

        cout<<"Dopo /3 e x2"<<endl;
        for (auto x : vettore) {
            cout<<x<<" ";
        }
        cout<<endl;

        for (int i=0;i<vettore.size();i++) {
            if (vettore[i] >100) {
                continua=true;
                cout<<"Mostro in "<<i<<" esplode"<<endl;

                int idxAttale =i;
                int idxPrima, idxDopo;

                //controlla se è il primo
                if (i!=0)
                    idxPrima = i-1;
                else    //altrimenti prende l'ultimo
                    idxPrima = vettore.size()-1;

                //controlla se è ultimo
                if (i!=vettore.size()-1)
                    idxDopo = i+1;
                else //altrimentei prende il primo
                    idxDopo = 0;

                //li mette in ordine per toglierlo
                //stesso motivo degli es. precedenti
                if (idxDopo<idxAttale)
                    swap(idxDopo, idxAttale);
                if (idxDopo<idxPrima)
                    swap(idxDopo, idxPrima);
                if (idxAttale < idxPrima)
                    swap(idxAttale, idxPrima);

                if (vettore.size()<=3) {
                    vettore.clear();
                    cout<<"tolti gli ultimi 3";
                    return 0;
                }
                vettore.erase(vettore.begin()+idxDopo);
                vettore.erase(vettore.begin()+idxAttale);
                vettore.erase(vettore.begin()+idxPrima);

            }

        }

        cout<<"Fine"<<endl;
        for (auto x:vettore) {
            cout<<x<<" ";
        }
        cout<<endl;
        cout<<endl;
    }

    return 0;

}