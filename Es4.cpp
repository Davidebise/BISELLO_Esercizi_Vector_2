#include <vector>
#include <iostream>
using  namespace std;
void Swap(int* a, int* b) {
    int temp= *a;
    *a= *b;
    *b=temp;
}
int main() {
    srand(time(NULL));
    vector<int> numeri;
    int numeroInput;

    for (int i = 0; i < 10; i++) {
        cout<<"Inserisci numero "<<i+1<<":"<<endl;
        cin>>numeroInput;
        numeri.push_back(numeroInput);
    }
    for (int i = 0; i < 20; i++) {
        Swap(&numeri[(rand()%numeri.size())], &numeri[(rand()%numeri.size())]);
    }
    int somma=0;
    for (auto x: numeri) {
        somma+=x;
        cout<<x<<" ";
    }
    cout<<"Somma: "<<somma<<endl;
    return 0;
}

