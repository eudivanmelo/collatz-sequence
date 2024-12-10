#include <iostream>
#include <unordered_map>
#include <chrono>

using namespace std;

unordered_map<long long, int> memo;

int collatz(long long n) {
    if (n == 1) return 1;
    if (memo.count(n)) return memo[n];

    int steps = 1 + collatz(n % 2 == 0 ? n / 2 : 3 * n + 1);
    memo[n] = steps;
    return steps;
}

int main() {
     // Inicia o cronômetro antes da execução
    auto start = chrono::high_resolution_clock::now();

    memo[1] = 1; // Inicializa a tabela com o valor conhecido

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