# Conjectura de Collatz - Programa para Encontrar a Sequência Mais Longa

Este programa calcula a sequência de Collatz mais longa para números abaixo de 1 milhão. O programa determina o número que gera a sequência mais longa e o comprimento dessa sequência.

## Visão Geral do Problema

A conjectura de Collatz afirma que, começando com qualquer número inteiro positivo, se o número for par, divide-se por 2, e se for ímpar, multiplica-se por 3 e adiciona-se 1. Esse processo é repetido para cada novo número gerado, e, eventualmente, todas as sequências são acreditadas a alcançar o número 1.

## Funcionalidade

O programa encontra o número abaixo de 1 milhão que gera a sequência de Collatz mais longa. Ele utiliza memoização para armazenar os comprimentos das sequências dos números já calculados, o que acelera significativamente o processo.

## Fluxo de Execução

1. **Cálculo da Sequência de Collatz**: A função `collatz(long long n)` calcula recursivamente o número de passos necessários para chegar a 1 para qualquer número `n`, seguindo as regras da Conjectura de Collatz.
2. **Memoização**: Para evitar recalcular os passos para números que já foram processados, é utilizado um `unordered_map` chamado `memo`. Esse mapa armazena o número de passos de cada `n` encontrado.
3. **Otimização**: O programa começa inicializando `memo[1] = 1`, já que a sequência para o número 1 é conhecida. Enquanto itera de 2 até 999.999, ele calcula os passos e mantém o controle do número que gera a sequência mais longa.
4. **Medição de Desempenho**: O programa usa a biblioteca `chrono` do C++ para medir e exibir o tempo gasto na execução.

## Bibliotecas Usadas

- **`unordered_map`**: Parte da biblioteca padrão do C++, é usada para armazenar e acessar de maneira eficiente os valores. Ela permite acesso em tempo constante (em média), tornando-se ideal para a memoização usada neste programa.
  
- **`chrono`**: Biblioteca usada para medir intervalos de tempo. É usada para capturar o tempo de execução do programa, fornecendo uma medição precisa do tempo gasto no cálculo das sequências de Collatz.

## Explicação do Código

- A função `collatz(long long n)` calcula o número de passos necessários para chegar a 1 usando recursão. Caso `n` já tenha sido calculado e armazenado na tabela hash `memo`, a função retorna o resultado armazenado.
- A função `main()` executa um laço de 2 até 999.999, chamando a função `collatz()` para cada número e mantendo o controle do número com o maior número de passos e o valor correspondente.
- O tempo de execução é capturado usando `chrono::high_resolution_clock` e impresso em segundos.

## Resultados

- **Número que gera a sequência mais longa**: `837799`
- **Comprimento da sequência**: `525`
- **Tempo de execução**: `1.6 segundos`

## Saída Esperada

```
O número que gera a sequência mais longa é: 837799
Comprimento da sequência: 525
Tempo de execução: 0.0227779 segundos
```

## Desempenho

O programa calcula eficientemente a sequência de Collatz mais longa para números até 1 milhão em **aproximadamente 0.02 segundos** utilizando memoização. O uso de um `unordered_map` garante que resultados previamente calculados sejam reutilizados, reduzindo significativamente cálculos redundantes e melhorando o desempenho.