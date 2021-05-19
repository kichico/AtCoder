#include <iostream>
#include <vector>

int main(void) {
    int A1, A2, A3, A4;
    std::cin >> A1 >> A2 >> A3 >> A4;
    std::vector<int> A(4);
    A = { A1,A2,A3,A4 };
    int i = 1;
    int min = A[0];
    while (true) {
        if (i > 3) break;
        if (min > A[i]) min = A[i];
        i++;
    }
    std::cout << min << std::endl;
    return 0;
}