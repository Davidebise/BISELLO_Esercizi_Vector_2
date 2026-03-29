#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> robot = {1, 1, 2, 2, 4};
    while (robot.size() > 1) {
        for(int r : robot) {
            cout << r << " ";
        }
        cout << endl;

        for (int i = 0; i < robot.size(); i++) {
            robot[i]*=2;
        }

        int posAttuale;
        for (int i = 0; i < robot.size(); i++) {
            posAttuale = i;
            for (int j = 0; j < robot.size(); j++) {
                if (i !=j && robot[posAttuale]==robot[j]) {    //prima controlla se non è lo stesso robot che si autoconfontra

                    //per evitare di togliere quello con indice <
                    //e far scalare a sfalsare tutti gli altri
                    //controllo quello con index > e così al max si incasinano quelli dopo
                    int maxx = max(i,j);
                    int minn = min(i,j);
                    robot.erase(robot.begin()+maxx);
                    robot.erase(robot.begin()+minn);
                    i=0;    //deve ricominciare dall' inizio perchè ora è diverso
                    break;
                }
            }
        }


    }
    if (robot.size()>0)
        cout<<"Rimasto robot: "<<to_string(robot.back())<<endl;
    else
        cout<<"Nessun robot vivo";

    return 0;
}
