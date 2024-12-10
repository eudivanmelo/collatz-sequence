#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

const long long MAX = 1000000;
vector<long long> memo(MAX, 0);

long long collatz(long long n) {
    if (n == 1) // Como n = 1, logo a sequencia termina
        return 1;

    if (n < MAX && memo[n] != 0)  // Corrigido para garantir que n não ultrapasse MAX
        return memo[n];

    long long steps = 1; // Passo começa em 1 para considerar o passo atual
    if (n % 2 == 0){
        steps += collatz(n / 2);
    } else {
        steps += collatz((3 * n) + 1);
    }
    
    if (n < MAX) {
        memo[n] = steps;  // Armazene o resultado apenas se n estiver dentro do limite
    }

    return steps;
}

int main() {
     // Inicia o cronômetro antes da execução
    auto start = chrono::high_resolution_clock::now();

    memo[0] = 1; // Inicializa a tabela com o valor conhecido

    int maxSteps = 0;
    long long maxNum = 0;

    for (long long i = 2; i < 1000000; i++) {
        int steps = collatz(i);
        if (steps > maxSteps) {
            maxSteps = steps;
            maxNum = i;
        }
    }

    // Para o cronômetro após a execução
    auto end = chrono::high_resolution_clock::now();

    cout << "O número que gera a sequência mais longa é: " << maxNum << endl;
    cout << "Comprimento da sequência: " << maxSteps << endl;

    std::chrono::duration<double, std::milli> duration_ms = end - start;
    cout << "Tempo de execução: " << (duration_ms.count() / 1000) << " segundos" << std::endl;

    return 0;
}