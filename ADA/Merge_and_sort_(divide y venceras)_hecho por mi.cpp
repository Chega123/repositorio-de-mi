
#include <iostream>
#include <vector>
using namespace std;

int merge_and_count(vector<int>& arr, int fin, int medio, int inicio) {
    int izq = medio - inicio + 1;
    int der = fin - medio;

    vector<int> arrDer(der);
    vector<int> arrIzq(izq);

    for (int i = 0; i < izq; i++) {
        arrIzq[i] = arr[inicio + i];
    }
    for (int j = 0; j < der; j++) {
        arrDer[j] = arr[medio + 1 + j];
    }

    int i = 0, j = 0, k = inicio;
    int suma = 0;
    while (i < izq && j < der) {
        if (arrIzq[i] <= arrDer[j]) {
            arr[k] = arrIzq[i];
            i++;
        }
        else {
            arr[k] = arrDer[j];
            suma += izq - i; //es el i ese q va reduciendo 
            j++;
        }
        k++;
    }

    while (i < izq) {
        arr[k] = arrIzq[i];
        i++; k++;
    }

    while (j < der) {
        arr[k] = arrDer[j];
        j++; k++;
    }

    return suma;
}


int sort_and_count(vector<int>& arr, int inicio,int fin) {
    if (fin - inicio<=0) {
        return (0);
    }
    // dividir
    int mitad = inicio + (fin - inicio) / 2;
    int ra = sort_and_count(arr, inicio, mitad);
    int rb = sort_and_count(arr, mitad + 1, fin);
    int r = merge_and_count(arr, fin, mitad, inicio);
    return ra + rb + r;
}

int main() {
    vector<int> lista = { 3, 7, 10, 14, 18, 19, 2, 11, 16, 17, 23, 25 };
    int respuesta = sort_and_count(lista, 0, lista.size() - 1);
    cout << respuesta;
}