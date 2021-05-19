#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    int A, B;
    cin >> A >> B;
    vector<int> sa(3), sb(3);
    //cout<<"A=>"<<A<<endl;
    for (int i = 0; i < 3; ++i) {
        if (i == 0) {
            sa[i] = A / 100;
            sb[i] = B / 100;
            A -= sa[i] * 100;
            B -= sb[i] * 100;
        }
        else if (i == 1) {
            sa[i] = A / 10;
            sb[i] = B / 10;
            A -= sa[i] * 10;
            B -= sb[i] * 10;
        }
        else {
            sa[i] = A;
            sb[i] = B;
        }
    }
    int suma = 0, sumb = 0;
    for (int i = 0; i < 3; ++i) {
        suma += sa[i];
        sumb += sb[i];
        cout << "suma=>" << suma << endl;
    }
    if (suma >= sumb) cout << suma << endl;
    else cout << sumb << endl;
    return 0;
}