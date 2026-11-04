#ifndef TECLADO_H
#define TECLADO_H

#include <conio.h>
#include <iostream>
#include <string>
#include <cctype>

class Teclado {
private:
    static std::string leer(const std::string& mensaje, int maximo, bool soloNumeros) {
        std::string texto;
        std::cout << mensaje;
        while (true) {
            int c = _getch();

            if (c == 0 || c == 224) {   // teclas especiales (flechas, etc.)
                _getch();
                continue;
            }
            if (c == 13) {              // Enter: exige al menos un caracter
                if (texto.empty()) continue;
                if (texto.back() == ' ') {
                    texto.pop_back();
                    std::cout << "\b \b";
                }
                break;
            }
            if (c == 8) {               // Backspace
                if (!texto.empty()) {
                    texto.pop_back();
                    std::cout << "\b \b";
                }
                continue;
            }
            if ((int)texto.size() >= maximo) continue;

            bool permitido;
            if (soloNumeros) {
                permitido = (c >= '0' && c <= '9');
            } else {
                permitido = (c < 128 && std::isalpha(c)) ||
                            (c == ' ' && !texto.empty() && texto.back() != ' ');
            }
            if (permitido) {
                texto += (char)c;
                std::cout << (char)c;
            }
        }
        std::cout << "\n";
        return texto;
    }

public:
    static std::string ingresarNumeros(const std::string& mensaje, int maximo) {
        return leer(mensaje, maximo, true);
    }

    static std::string ingresarLetras(const std::string& mensaje, int maximo) {
        return leer(mensaje, maximo, false);
    }

    static int ingresarEntero(const std::string& mensaje, int maximo) {
        return std::stoi(ingresarNumeros(mensaje, maximo));
    }

    // Cedula ecuatoriana: 10 digitos, provincia 01-24 o 30, tercer digito < 6, modulo 10
    static bool cedulaValida(const std::string& c) {
        if (c.size() != 10) return false;
        int provincia = (c[0] - '0') * 10 + (c[1] - '0');
        if (!((provincia >= 1 && provincia <= 24) || provincia == 30)) return false;
        if (c[2] - '0' >= 6) return false;

        int suma = 0;
        for (int i = 0; i < 9; i++) {
            int d = c[i] - '0';
            if (i % 2 == 0) {
                d *= 2;
                if (d > 9) d -= 9;
            }
            suma += d;
        }
        int verificador = (10 - suma % 10) % 10;
        return verificador == c[9] - '0';
    }
};

#endif