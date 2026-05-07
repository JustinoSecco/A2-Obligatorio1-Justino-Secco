#include <string>
#include <iostream>

using namespace std;

int hashLlave(char llave){
    return llave - 'a';
}

int hashPuerta(char puerta){
    return puerta - 'A';
}

void agregarLlave(int llavesGuardadas[], char llave){ 
    int posLlave = hashLlave(llave);
    llavesGuardadas[posLlave]++;
}

void quitarLlave(int llavesGuardadas[], char puerta){
    int posLlave = hashPuerta(puerta);
    llavesGuardadas[posLlave]--;
}

bool buscarLlave(int llavesGuardadas[], char puerta){
    int posLlave = hashPuerta(puerta);
    bool estaLaLlave = llavesGuardadas[posLlave] > 0;
    return estaLaLlave;
}

int main()
{
    int cantSalas;
    cin >> cantSalas;

    string cadenaLlavePuerta;
    cin >> cadenaLlavePuerta;

    int llavesExtrasNecesarias = 0;

    int llavesGuardadas[26];
    for (int i = 0; i < 26; i++) {
    llavesGuardadas[i] = 0;
    }

    for (int i = 0; i < cadenaLlavePuerta.length(); i += 2){
        char llaveActual = cadenaLlavePuerta[i];
        char sigPuerta = cadenaLlavePuerta[i + 1];
        agregarLlave(llavesGuardadas, llaveActual);
        if(buscarLlave(llavesGuardadas, sigPuerta)){ 
            quitarLlave(llavesGuardadas, sigPuerta); 
        }
        else{
            llavesExtrasNecesarias++;
        }
    }

    cout << llavesExtrasNecesarias;
}
