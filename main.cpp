#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// Función que voltea los primeros k pancakes de la pila
void voltear(string& pancakes, int k) {
    int i = 0, j = k - 1;
    while (i < j) {
        char temp = pancakes[i];
        pancakes[i] = pancakes[j];
        pancakes[j] = temp;
        i++;
        j--;
    }
}

// Función que verifica si está ordenada
bool esta_ordenada(string pancakes) {
    for (int i = 1; i < pancakes.size(); i++) {
        if (pancakes[i] < pancakes[i-1]) {
            return false;
        }
    }
    return true;
}

// Función que genera los sucesores de una configuración
vector<string> generar_sucesores(string pancakes) {
    vector<string> sucesores;
    for (int i = 1; i <= pancakes.size(); i++) {
        string sucesor = pancakes;
        voltear(sucesor, i);
        sucesores.push_back(sucesor);
    }
    return sucesores;
}

// Función que genera una cadena aleatoria de caracteres que representen los pancakes a ordenar
string generar_caracteres_aleatorios(int n) {
    string pancakes = "";
    unordered_set<char> chars_set;
    srand(time(NULL));
    while (chars_set.size() < n) {
        char c = 'a' + rand() % 26;
        if (chars_set.find(c) == chars_set.end()) {
            chars_set.insert(c);
            pancakes += c;
        }
    }
    return pancakes;
}

// Función que implementa la heuristica
int h4(const string& pancakes, const string& target) {
    int c = 0;
    for (int i = 0; i < pancakes.size(); i++) {
        if (pancakes[i] != target[i])
            c++;
        if (i < pancakes.size()-1 && abs(pancakes[i]-pancakes[i+1]) > 1)
            c++;
    }
    return c;
}

// Función que realiza la búsqueda A*
void a_star(string pancakes) {
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> cola;
    unordered_set<string> visitados;
    int count = 0;
    string target = pancakes;
    sort(target.begin(), target.end());
    cola.push({h4(pancakes, target), pancakes});
    visitados.insert(pancakes);
    while (!cola.empty()) {
        string curr_pancakes = cola.top().second;
        cola.pop();
        count++;
        if (curr_pancakes == target) {
            cout << "Solucion encontrada: " << curr_pancakes << endl;
            cout << "Numero de nodos visitados: " << count << endl;
            return;
        }
        vector<string> sucesores = generar_sucesores(curr_pancakes);
        for (string sucesor : sucesores) {
            if (visitados.find(sucesor) == visitados.end()) {
                cola.push({h4(sucesor, target), sucesor});
                visitados.insert(sucesor);
                count++;
            }
        }
    }
    cout << "No se encontro solucion." << endl;
    cout << "Numero de nodos visitados: " << count << endl;
}

//Funcion principal
int main() {
    int n;
    cout << "Ingrese el numero de caracteres de pancakes: ";
    cin >> n;
    string pancakes = generar_caracteres_aleatorios(n);
    cout << "Pila de pancakes original: " << pancakes << endl;
    a_star(pancakes);
    return 0;
}
