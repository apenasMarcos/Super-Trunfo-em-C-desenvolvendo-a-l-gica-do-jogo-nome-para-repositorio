#include <stdio.h>

// Definição das cartas (exemplo fixo)
typedef struct {
    char nome[50];
    char estado[3];
    unsigned long populacao;
    float area;
    float pib; // em bilhões
    int pontosTuristicos;
    float densidade; // calculada
} Carta;

// Função para mostrar o menu de atributos disponíveis e retorna a escolha
int mostrarMenu(int excluido) {
    printf("\nEscolha o atributo para comparação:\n");
    if (excluido != 1) printf("1 - População\n");
    if (excluido != 2) printf("2 - Área\n");
    if (excluido != 3) printf("3 - PIB\n");
    if (excluido != 4) printf("4 - Número de pontos turísticos\n");
    if (excluido != 5) printf("5 - Densidade demográfica\n");
    printf("Digite a opção desejada: ");

    int opcao;
    scanf("%d", &opcao);

    // Verifica se a opção é válida e não é a excluída
    if (opcao < 1 || opcao > 5 || opcao == excluido) {
        printf("Opção inválida! Tente novamente.\n");
        return -1;
    }

    return opcao;
}

// Função para obter o valor do atributo da carta, usado para soma e comparação
float valorAtributo(Carta c, int atributo) {
    switch(atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidade;
        default: return 0.0f;
    }
}

// Função para exibir o nome do atributo
const char* nomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Número de pontos turísticos";
        case 5: return "Densidade demográfica";
        default: return "Atributo desconhecido";
    }
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Cidade A", "SP", 12300000, 1521.11, 500.5, 150, 0.0f};
    Carta carta2 = {"Cidade B", "RJ", 8000000, 1200.5, 450.3, 130, 0.0f};

    // Calcula densidade demográfica (população / área)
    carta1.densidade = (float)carta1.populacao / carta1.area;
    carta2.densidade = (float)carta2.populacao / carta2.area;

    int escolha1 = -1, escolha2 = -1;

    // Escolha do primeiro atributo
    do {
        escolha1 = mostrarMenu(-1);
    } while (escolha1 == -1);

    // Escolha do segundo atributo (não pode ser igual ao primeiro)
    do {
        escolha2 = mostrarMenu(escolha1);
    } while (escolha2 == -1);

    // Exibição dos dados escolhidos
    printf("\nComparação entre %s (%s) e %s (%s):\n", carta1.nome, carta1.estado, carta2.nome, carta2.estado);
    printf("Atributo 1: %s\n", nomeAtributo(escolha1));
    printf("%s: %.2f\n", carta1.nome, valorAtributo(carta1, escolha1));
    printf("%s: %.2f\n\n", carta2.nome, valorAtributo(carta2, escolha1));

    printf("Atributo 2: %s\n", nomeAtributo(escolha2));
    printf("%s: %.2f\n", carta1.nome, valorAtributo(carta1, escolha2));
    printf("%s: %.2f\n\n", carta2.nome, valorAtributo(carta2, escolha2));

    // Comparação dos atributos individualmente
    int vencedor1 = 0; // 0 = empate, 1 = carta1, 2 = carta2
    int vencedor2 = 0;

    // Para densidade, vence menor valor; para os outros vence maior valor
    if (escolha1 == 5) {
        vencedor1 = (valorAtributo(carta1, escolha1) < valorAtributo(carta2, escolha1)) ? 1 :
                    (valorAtributo(carta1, escolha1) > valorAtributo(carta2, escolha1)) ? 2 : 0;
    } else {
        vencedor1 = (valorAtributo(carta1, escolha1) > valorAtributo(carta2, escolha1)) ? 1 :
                    (valorAtributo(carta1, escolha1) < valorAtributo(carta2, escolha1)) ? 2 : 0;
    }

    if (escolha2 == 5) {
        vencedor2 = (valorAtributo(carta1, escolha2) < valorAtributo(carta2, escolha2)) ? 1 :
                    (valorAtributo(carta1, escolha2) > valorAtributo(carta2, escolha2)) ? 2 : 0;
    } else {
        vencedor2 = (valorAtributo(carta1, escolha2) > valorAtributo(carta2, escolha2)) ? 1 :
                    (valorAtributo(carta1, escolha2) < valorAtributo(carta2, escolha2)) ? 2 : 0;
    }

    // Soma dos valores (para soma, densidade soma direto mesmo)
    float soma1 = valorAtributo(carta1, escolha1) + valorAtributo(carta1, escolha2);
    float soma2 = valorAtributo(carta2, escolha1) + valorAtributo(carta2, escolha2);

    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nome, soma1);
    printf("%s: %.2f\n\n", carta2.nome, soma2);

    // Determinar vencedor final baseado na soma
    if (soma1 > soma2) {
        printf("Resultado final: Carta 1 (%s) venceu!\n", carta1.nome);
    } else if (soma2 > soma1) {
        printf("Resultado final: Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("Resultado final: Empate!\n");
    }

    return 0;
}
