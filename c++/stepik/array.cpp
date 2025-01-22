#include <iostream>

// int m[10] = {};
// for (int *p = m; p <= m + 9; ++p) {
//     *p = (p - m) + 1;
// }

// int max_element (int *m, int size) {
//     int max = *m;
//     for (int i = 1; i < size; ++i) {
//         if (m[i] > max) {
//             max = m[i];
//         }
//     }
//     return max;
// }

int max_element(int *p, int *q, int *res) {
    if (p==q)
        return false;
    *res = *p;
    for (; p!= q; ++p)
        if (*p > *res)
            *res = *p;
    return true;
}

int main(){
    int m[10] = {1, 5, 9, 8, 6, 3};
    int max = 0;
    if (max_element(m, m+10, &max))
        std::cout << "Maximum = " << max << std::endl;
    return 0;
}