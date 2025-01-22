bool contains(int *m, int size, int value) {
    for (int i=0; i != size; ++i) {
        if (m[i] == value)
            return true;
    }
    return false;
}

bool contains(int *p, int *q, int value) {    // *q - следующий после нужного кол-ва элементов символ
    for (; p != q; ++p)
        if (*p == value)
            return true;
    return false;
}