#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void printVector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main() {
    vector<int> zombies={6,4,7,12,9,23,67};
    auto it=zombies.begin();
    while (zombies.size()>1) {
        for(int i=0;i<zombies.size();i++) {

            if (i!=zombies.size()-1) {
                zombies[i + 1]-=zombies[i]/2;
            }else {
                zombies[0]-=zombies[zombies.size()-1]/2;
            }
        }
        do {
            it = find_if(zombies.begin(), zombies.end(), [](const int i) {
            return i<=0;
        });
            if (it != zombies.end() && *it<=0) {
                zombies.erase(it);
            }
        }while (it != zombies.end());
        printVector(zombies);
    }

    return 0;
}