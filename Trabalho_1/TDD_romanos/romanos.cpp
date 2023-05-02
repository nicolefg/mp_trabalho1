#include "romanos.hpp"
#include <iostream>
#include <unordered_map>
#include <cstring>


int romanos_para_decimal(const char* num_romano) {
    std::unordered_map<char, int> valores = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    
    int decimal = 0;
    int ultimo_valor = 0;
    
    for (int i = strlen(num_romano) - 1; i >= 0; i--) {
        int valor = valores[num_romano[i]];

        if (valor < ultimo_valor) {
            decimal -= valor; 
        } else {
            decimal += valor; 
            ultimo_valor = valor; 
        }
    }
    
    return decimal;
}
