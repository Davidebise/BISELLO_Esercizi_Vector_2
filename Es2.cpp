    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;
    void DuplicateVector(vector<int> &v) {
        int size = v.size();
        for (int i = 0; i < size; i++) {
            if (v[i] % 2 == 0) {
                v.push_back(v[i]);
            }
        }
        cout << endl;
    }
    void printVector(vector<int> v) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    int main() {
        vector<int> vettore={6,4,7,12,9,21,67,54,56,43,42,65,14,};
        auto it=vettore.begin();
            do {
                it = find_if(vettore.begin(), vettore.end(), [](const int i) {
                return i % 7 == 0;
            });
                if (it != vettore.end()) {
                    vettore.erase(it);
                    DuplicateVector(vettore);
                }
            }while (it != vettore.end() && vettore.size()<50);

        printVector(vettore);
        return 0;
    }