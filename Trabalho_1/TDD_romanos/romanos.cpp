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
    int repeticoes = 0;
    char ultimo_caractere = '\0';
    
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
            repeticoes = 0; // reinicia a contagem de repetições
        } else {
            decimal += valor; // adiciona o valor atual ao decimal
            ultimo_valor = valor; // atualiza o último valor
            
            // verifica se o valor atual é igual ao valor anterior
            if (valor == ultimo_valor) {
                repeticoes++; // incrementa a contagem de repetições
                if (repeticoes > 2) {
                    return -1; // retorna -1 para mais de 3 repetições seguidas
                }
            } else {
                repeticoes = 0; // reinicia a contagem de repetições
            }
        }
        
        // verifica se o caractere atual é igual ao último caractere e se é um dos caracteres proibidos
        if (num_romano[i] == ultimo_caractere && (num_romano[i] == 'V' || num_romano[i] == 'L' || num_romano[i] == 'D')) {
            return -1; // retorna -1 para casos proibidos
        }
        
        // atualiza o último caractere
        ultimo_caractere = num_romano[i];
    }
    
    return decimal;
}

