#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <algorithm>

using namespace std;
void printVector(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main() {
    vector<string> names = {
        "Luna", "Oliver", "Leo", "Milo", "Bella",
        "Simba", "Chloe", "Loki", "Lucy", "Nala",
        "Tom", "Pallina", "Birba", "Romeo", "Minù",
        "Felix", "Zelda", "Oscar", "Maya", "Chicco",
        "Briciola", "Dante", "Gasperino", "Isis", "Kiki"
    };
    vector<string> cats;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {  //inizializzo il vector con nomi casuali
        if (i==8) {
            cats.push_back("Milo");
        }else {
            cats.push_back(names[rand()%names.size()]);
        }
    }
    string temp=cats[0];
    for (int i=0;i<10;i++) {
        rotate(cats.begin(), cats.begin() + 1, cats.end());
        printVector(cats);
        if (cats[cats.size()-1][0] == 'M') {
            cats.insert(cats.begin(), names[rand()%names.size()]);
        }
        this_thread::sleep_for((chrono::seconds(1)));
    }


    return 0;
}