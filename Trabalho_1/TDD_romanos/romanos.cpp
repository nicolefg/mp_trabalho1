#include "romanos.hpp"
#include <iostream>
#include <unordered_map>
#include <cstring>


int romanos_para_decimal(const char* num_romano) {
    // mapeia cada símbolo romano para seu valor decimal
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
    
    // percorre o número romano da direita para a esquerda
    for (int i = strlen(num_romano) - 1; i >= 0; i--) {
        // verifica se o caractere atual é um símbolo romano válido
        if (valores.find(num_romano[i]) == valores.end()) {
            return -1; // retorna -1 para casos inválidos
        }
        
        // obtém o valor decimal do símbolo romano atual
        int valor = valores[num_romano[i]];
        
        // verifica se o valor atual é menor ou maior que o valor anterior
        if (valor < ultimo_valor) {
            decimal -= valor; // subtrai o valor atual do decimal
        } else {
            decimal += valor; // adiciona o valor atual ao decimal
            ultimo_valor = valor; // atualiza o último valor
        }
    }
    
    return decimal;
}
