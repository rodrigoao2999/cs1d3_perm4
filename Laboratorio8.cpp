#include <iostream>
#include <random>
#include <math.h>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;


bool witness(int a, int n);
bool millerRabin(int n, int s);
int primoCandidato(int b);
int GeneradorDePrimo(int b);
int potencia(int a, int b, int p);
int EnteroAleatorio(int a, int b);

int main()
{   
    int opc;
    int tem = 0, con = 0, j = 0, s = 2, n;

    cout << "Seleccione el ejercicio que desea visualizar: " << endl;
    cout << "\n* Presione (1) para ver el ejercicio 1" << endl;
    cout << "* Presione (2) para ver el ejercicio 2" << endl;
    cout << "\nIngrese su opcion: ";
    cin >> opc;

    if (opc ==1)
    {
        system("cls");

        cout << "EJERCICIO 1: " << endl;
        cout << "Implementar MILLER-RABIN(n, s). Colocar el algoritmo en el README.md con una breve  explicacion.  Encontrar  todos  los  primos  de  3  cifras  utilizando  este  algoritmo.\n\n";
        

        for (int a = 101; a < 1000; a += 2)
        {
            if (!millerRabin(a, s)) {
                con++;
                if (tem == 11) {
                    cout << a << "\n";
                    tem = 0;
                    continue;
                }
                else
                    cout << a << " / ";
                tem++;
            }

        }


        cout << "\n\n" << "Se han encontrado [" << con << "] primos de 3 cifras en el rango de [101 - 999] (s = " << s << ")" << "\n";
    }
    else
    {
        system("cls");
        cout << "\nEJERCICIO 2: " << endl;
        cout << "Implementar GENERATE-PRIME(b). Colocar el algoritmo en el README.md con una breve  explicacion.  Encontrar  100  primos  distintos  de  10  bits  utilizando  este  algoritmo.  " << "\n\n";
        con = 0;
        vector<int> respuesta;
        while (respuesta.size() != 100) {
            n = GeneradorDePrimo(10);
            if (n % 2 != 0)
            {
                if (!(find(respuesta.begin(), respuesta.end(), n) != respuesta.end())) {
                    respuesta.push_back(n);
                    con++;
                }
            }
        }
        for (int i = 0; i < respuesta.size(); i++) {
            if (j == 20)
            {
                cout << "\n";
                j = 0;
            }j++;
            cout << respuesta[i] << " / ";
        }
        cout << "\n\n Se encontraron " << con << " numeros primos diferentes de 10 bits." << endl;
    }
    

   
}


int EnteroAleatorio(int a, int b)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(a, b);
    return distr(gen);
}

int primoCandidato(int b)
{
    int n = EnteroAleatorio(0, pow(2, b));
    int m = pow(2, (b - 5)) + 1;
    n = n | m;
    return n;
}

bool millerRabin(int n, int s)
{
    int a;
    for (int i = 1; i <= s; i++)
    {
        a = EnteroAleatorio(1, n - 1);
        if (witness(a, n))
            return 1;
    }
    return false;
}

bool witness(int a, int n)
{
    int sup = 1, t = 0, u = 1;
    bool found = 0;
    while (sup * 2 <= n - 1) {
        t++; sup = sup * 2;
        while (sup * u <= n - 1) {
            if (sup * u == n - 1 && u % 2 != 0) {
                found = 1;
                break;
            }
            u++;
        }
        if (found)
            break;
        u = 0;
    }
    if (!found)
        return 0;
    int pre_x = potencia(a, u, n), x;
    if (pre_x == 1 || pre_x == n - 1)
        return 0;
    for (int i = 1; i < t; i++) {
        x = potencia(pre_x, 2, n);
        if (x == n - 1)
            return 0;
        pre_x = x;
    }
    return 1;
}

int potencia(int a, int b, int p) {
    int respuesta = 1;
    while (b)
    {
        if (b & 1) {
            respuesta = int(respuesta * 1ll * a % p);
            --b;
        }
        else {
            a = int(a * 1ll * a % p);
            b >>= 1;
        }
    }
    return respuesta;
}

int GeneradorDePrimo(int b)
{
    int s = 32;
    int n = primoCandidato(b);
    while (millerRabin(n, s))
        n += 2;
    return n;
}