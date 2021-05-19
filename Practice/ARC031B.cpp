#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void checker(vector<vector<char>> field, vector<vector<bool>> checked, int x, int y) {
    int nx,ny;
    for (int dx = -1; dx <= 1; dx++) for (int dy = -1; dy <= 1; dy++) {
        //cout<<"debug"<<endl;
        nx = x + dx;
        ny = y + dy;
        if (field[nx][ny] == 'o' && checked[nx][ny] == false) {
            //cout<<"nx=>"<<nx<<", ny=>"<<ny<<endl;
            checked[nx][ny] = true;
            checker(field, checked, nx, ny);
        }
    }
}

int main(void) {
    int x, y;
    vector<vector<char>> field(10, vector<char>(10, ' '));
    vector<vector<bool>> checked(10, vector<bool>(10, false));
    for (int i = 0; i < 10; ++i) for (int j = 0; j < 10; ++j) cin >> field[i][j];
    for (int dy = 0; dy < 10; ++dy) for (int dx = 0; dx < 10; ++dx) if (field[dx][dy] == 'o') {
        x = dx;
        y = dy;
        break;
    }
    //cout<<"debug"<<endl;
    checker(field, checked, x, y);
    bool ok = true;
    //cout<<"debug"<<endl;
    for (int dy = 0; dy < 10; ++dy) for (int dx = 0; dx < 10; ++dx) if (field[dx][dy] == 'o') {
        if (!checked[dx][dy]) {
            ok = false;
            break;
        }
        //cout<<"debug"<<endl;
        if (!ok) break;
    }
    int memx, memy;
    //cout<<"debug..."<<endl;
    for (int dx = 0; dx < 10; dx++) {
        for (int dy = 0; dy < 10; dy++) {
            vector<vector<char>> temp;
            temp = field;
            if (field[dx][dy] == 'x') {
                //cout<<"debug..."<<endl;
                temp[dx][dx] = 'o';
                checked = vector<vector<bool>>(10, vector<bool>(10, false));
                checker(temp, checked, dx, dx);
                cout << "debug..." << endl;

                ok = true;
                for (int dy = 0; dy < 10; ++dy) for (int dx = 0; dx < 10; ++dx) if (field[dx][dy] == 'o') {
                    if (!checked[dx][dy]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    cout << "YES" << endl;
                    return 0;
                }
                //if(ok) break;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}