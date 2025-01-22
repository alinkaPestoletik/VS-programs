void swap(int a[], int b[]) {
	int t = *a;
	*a = *b;
	*b = t;
}

void rotate(int a[], unsigned size, int shift) {
	while (shift--)	for (int * p = a; p < a + size - 1; ++p) swap(p, p + 1);
}

int a[] = {2, 4, 7, 8};
int main() {
    rotate(a, 4, 2);
    return 0;
}
