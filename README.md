# Super Trunfo - Comparação Avançada de Cartas

## Descrição

Este projeto implementa um jogo de Super Trunfo em C que permite a comparação dinâmica entre duas cartas de países, utilizando dois atributos numéricos escolhidos pelo jogador. O sistema oferece menus interativos para seleção dos atributos e aplica regras específicas de comparação para determinar a carta vencedora.

## Funcionalidades

- Duas cartas pré-definidas com atributos:
  - Nome do país
  - Estado
  - População
  - Área
  - PIB
  - Número de pontos turísticos
  - Densidade demográfica (calculada automaticamente)

- Menu interativo para escolha de dois atributos distintos para comparação.

- Regras de comparação:
  - Para todos os atributos, vence a carta com maior valor.
  - Para Densidade Demográfica, vence a carta com o menor valor.

- Soma dos valores dos dois atributos para decidir o vencedor final.

- Tratamento de empate entre as cartas.

- Mensagens claras e organizadas para exibição do resultado.

- Validação das entradas do usuário no menu, evitando escolhas inválidas.

## Estrutura do Código

- `struct Carta`: representa as cartas com seus atributos.
- Função `mostrarMenu`: exibe o menu dinâmico de atributos disponíveis.
- Função `valorAtributo`: retorna o valor do atributo escolhido para uma carta.
- Função `nomeAtributo`: retorna o nome do atributo baseado na opção escolhida.
- Lógica de comparação com `switch`, `if-else` aninhados e operador ternário para clareza e elegância.
- Cálculo da densidade demográfica automaticamente.

## ▶️ Como Executar

1. Compile o código:
   ```bash
   gcc cartas_cidades.c -o cartas

2. Execute:
  ```bash
  ./cartas./cartas
## Objetivos do Projeto

- Exercitar estruturas de decisão (if-else, switch) e operadores ternários em C.
- Desenvolver menus interativos e dinâmicos.
- Implementar lógica de comparação complexa com múltiplos critérios.
- Praticar validação de entrada e tratamento de erros.
- Produzir código legível, organizado e bem comentado.

---

**Este projeto é uma evolução dos desafios anteriores, integrando cadastro de cartas e comparação avançada com múltiplos atributos.**
