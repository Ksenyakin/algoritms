#include<iostream>
#include <stdio.h> 
#include <cstring>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
void Karatsuba(int n, int* c, int* a, int* b)
{
    if (n <= 8)
    {
        forn(i, 2 * n)
            c[i] = 0;
        forn(i, n)
            forn(j, n)
            c[i + j] += a[i] * b[j];
        return;
    }
    int k = n / 2;
    int* f = new int[n];
    int* a12 = new int[k];
    int* b12 = new int[k];

    Karatsuba(k, c, a, b);
    Karatsuba(k, c + n, a + k, b + k);
    forn(i, k)
    {
        a12[i] = a[i] + a[i + k];
        b12[i] = b[i] + b[i + k];
    }
    Karatsuba(k, f, a12, b12);
    forn(i, n)
        f[i] -= c[i] + c[i + n];
    forn(i, n)
        c[i + k] += f[i];
}
const int N = 20;
int a[N], b[N], c[2 * N];
void read(int* a)
{
    static char s[N + 1];
    gets_s(s);
    int k = 0;
    for (int i = strlen(s) - 1; i >= 0; i--)
        a[k++] = s[i] - '0';
}
void out(int n, int* a) {
    forn(i, n)
        printf("%d", a[n - i - 1]);
}
int main() {
    read(a);
    read(b);
    Karatsuba(N, c, a, b);
    forn(i, 2 * N)
        if (c[i] >= 10)
            c[i + 1] += c[i] / 10, c[i] %= 10;
    out(2 * N, c);
}
