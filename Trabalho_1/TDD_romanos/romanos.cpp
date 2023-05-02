// Copyright (c) 2023, Nicole Ferreira Gomes
#include "romanos.hpp"
#include <iostream>
#include <unordered_map>
#include <cstring>

using std::unordered_map;
using std::strlen;
// Associação dos valores decimais aos algarismos romanos
int romanos_para_decimal(char const * num_romano) {
    unordered_map<char, int> mapeamento_simbolos = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}};
    int resultado = 0;
    int tamanho_num_romano = strlen(num_romano);

// Identificação de casos inválidos com algarismos repetidos
    if (strstr(num_romano, "IIII") != nullptr)
    { return -1; }
    else if (strstr(num_romano, "XXXX") != nullptr)
    { return -1; }
    else if (strstr(num_romano, "CCCC") != nullptr)
    { return -1; }
    else if (strstr(num_romano, "VV") != nullptr)
    { return -1; }
    else if (strstr(num_romano, "LL") != nullptr)
    { return -1; }
    else if (strstr(num_romano, "DD") != nullptr)
    { return -1; }

// Identificação de casos inválidos com algarismos
// fora do alfabeto de números romanos
    for (int i = 0; i < tamanho_num_romano; i++) {
        if (mapeamento_simbolos.find(num_romano[i]) ==
        mapeamento_simbolos.end()) {
            return -1;
        }
        int valor_atual = mapeamento_simbolos[num_romano[i]];

// Identificação de casos inválidos com algarismos em combinação errada
        if (i < tamanho_num_romano - 1 &&
        mapeamento_simbolos[num_romano[i+1]] > valor_atual) {
            if (valor_atual == 1 && (num_romano[i+1] ==
                'V' || num_romano[i+1] == 'X')) {
                resultado -= valor_atual;
            } else if (valor_atual == 10 && (num_romano[i+1] ==
                       'L' || num_romano[i+1] == 'C')) {
                resultado -= valor_atual;
            } else if (valor_atual == 100 && (num_romano[i+1] ==
                      'D' || num_romano[i+1] == 'M')) {
                resultado -= valor_atual;
            } else {
                return -1;
            }

        } else {
            resultado += valor_atual;
        }
    }

    return resultado;
}

