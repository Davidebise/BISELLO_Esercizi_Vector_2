#include <iostream>
#include <vector>

using namespace std;
void ScambiaColore(char * a, char * b) {
    char temp = *a;
    *a = *b;
    *b = temp;

}
int main() {
    srand(time(NULL));

    vector<char> vettore = {'A','B','A','C','B','D','C','C','D','E','D','E','E','F','G'};
    while (vettore.size() >10) {
        ScambiaColore(&vettore[rand()%vettore.size()], &vettore[rand()%vettore.size()]);

        for (auto x: vettore) {
            cout<<x<<" ";
        }
        cout<<endl;

        for (int i = 0; i < vettore.size()-2; i++) {
            if (vettore[i] == vettore[i+1] && vettore[i+2]==vettore[i+1]) {
                cout<<"rimuove tripletta di colore consecutivi: "<<vettore[i]<<endl;
                vettore.erase(vettore.begin()+i+2);
                vettore.erase(vettore.begin()+i+1);
                vettore.erase(vettore.begin()+i);
                break;
            }
        }


    }
    cout<<"FINE (<=10 ellementi)"<<endl;
    for (auto x: vettore) {
        cout<<x<<" ";
    }
    cout<<endl;
}

