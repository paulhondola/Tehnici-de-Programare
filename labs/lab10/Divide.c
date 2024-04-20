#include <stdio.h>

#define MAX 100 // gradul maxim al polinoamelor sursa

int a[MAX], b[MAX], c[2 * MAX];
int n, m;

// citeste un polinom de grad n
void citire(int *v, int n)
{
    int i;
    for (i = n; i >= 0; i--)
    {
        printf("x^%d=", i);
        scanf("%d", &v[i]);
    }
}

// afiseaza un polinom de grad n
void afisare(int *v, int n)
{
    int i;
    for (i = n; i >= 0; i--)
    {
        if (i != n)
            putchar('+');
        printf("%dx^%d", v[i], i);
    }
    putchar('\n');
}

// calculeaza coeficientul de grad k al inmultirii polinoamelor a si b
void coeficient(int k)
{
    int i;
    for (i = 0; i <= n; i++)
    {
        int j = k - i;
        if (j >= 0 && j <= m)
            c[k] += a[i] * b[j];
    }
}

int main()
{
    printf("n=");
    scanf("%d", &n);
    citire(a, n);
    printf("m=");
    scanf("%d", &m);
    citire(b, m);
    afisare(a, n);
    afisare(b, m);
    int k;
    for (k = 0; k <= n + m; k++)
        coeficient(k);
    afisare(c, n + m);
    return 0;
}
