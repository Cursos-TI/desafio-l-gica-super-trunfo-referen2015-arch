#include <stdio.h>
#include <stdlib.h>

int main() {
    int jogadoropcao1, jogadoropcao2;
    float valor1a, valor2a, valor1b, valor2b;
    char atributo1[30], atributo2[30];
    char unidade1[30], unidade2[30];

    // Primeira carta
    int codigodacarta;
    char siglas[10];
    char nomedopais[50];
    int populacao;
    float area, pib;
    int pontosturisticos;
    float densidade1, pibpercapita1;

    // Segunda carta
    int codigodacarta2;
    char siglas2[10];
    char nomedopais2[50];
    int populacao2;
    float area2, pib2;
    int pontosturisticos2;
    float densidade2, pibpercapita2;

    printf("SUPER TRUNFO DE PAÍSES\n\n");
    printf("Vamos comparar alguns atributos de países.\n");
    printf("O nome do país não poderá ter caracter especial.\n");
    printf("Depois de cadastrar as cartas, selecione dois atributos de 1 a 6.\n");
    printf("Os atributos serão somados.\n");
    printf("Vence o país que tiver o valor da soma maior.\n");
    

    // ===== Primeira Carta =====
    printf("\nCadastro da primeira carta:\n");
    printf("Insira a sigla do país: "); scanf("%s", siglas);
    printf("Insira o número da carta: "); scanf("%d", &codigodacarta);
    printf("Insira o nome do país: "); scanf(" %[^\n]", nomedopais);
    printf("Insira o número de habitantes (População): "); scanf("%d", &populacao);
    printf("Insira o tamanho do país (km²): "); scanf("%f", &area);
    printf("Insira o PIB (em bilhões de reais): "); scanf("%f", &pib);
    printf("Insira a quantidade de Pontos Turísticos: "); scanf("%d", &pontosturisticos);

    densidade1 = populacao / area;
    pibpercapita1 = pib / populacao;

    // ===== Segunda Carta =====
    printf("\nCadastro da segunda carta:\n");
    printf("Insira a sigla do país: "); scanf("%s", siglas2);
    printf("Insira o número da carta: "); scanf("%d", &codigodacarta2);
    printf("Insira o nome do país: "); scanf(" %[^\n]", nomedopais2);
    printf("Insira o número de habitantes (População): "); scanf("%d", &populacao2);
    printf("Insira o tamanho do país (km²): "); scanf("%f", &area2);
    printf("Insira o PIB (em bilhões de reais): "); scanf("%f", &pib2);
    printf("Insira a quantidade de Pontos Turísticos: "); scanf("%d", &pontosturisticos2);

    densidade2 = populacao2 / area2;
    pibpercapita2 = pib2 / populacao2;

    // ===== Escolha dos atributos =====
    printf("\nEscolha dois atributos para comparar (1 a 6):\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per capita\n");

    printf("\nDigite o primeiro atributo: "); scanf("%d", &jogadoropcao1);
    printf("Digite o segundo atributo: "); scanf("%d", &jogadoropcao2);

    // Verificações
    if (jogadoropcao1 < 1 || jogadoropcao1 > 6 || jogadoropcao2 < 1 || jogadoropcao2 > 6) {
        printf("\nOPÇÃO INVÁLIDA! Escolha números entre 1 e 6.\n");
        return 1;
    }

    if (jogadoropcao1 == jogadoropcao2) {
        printf("\nVocê escolheu o mesmo atributo duas vezes. Selecione dois atributos diferentes.\n");
        return 1;
    }

    // ===== Atributo 1 =====
    switch (jogadoropcao1) {
        case 1: valor1a = populacao; valor2a = populacao2; sprintf(atributo1, "População"); sprintf(unidade1, "habitantes"); break;
        case 2: valor1a = area; valor2a = area2; sprintf(atributo1, "Área"); sprintf(unidade1, "km²"); break;
        case 3: valor1a = pib; valor2a = pib2; sprintf(atributo1, "PIB"); sprintf(unidade1, "bilhões de reais"); break;
        case 4: valor1a = pontosturisticos; valor2a = pontosturisticos2; sprintf(atributo1, "Pontos Turísticos"); sprintf(unidade1, "pontos"); break;
        case 5: valor1a = densidade1; valor2a = densidade2; sprintf(atributo1, "Densidade Populacional"); sprintf(unidade1, "hab/km²"); break;
        case 6: valor1a = pibpercapita1; valor2a = pibpercapita2; sprintf(atributo1, "PIB per capita"); sprintf(unidade1, "bilhões/habitante"); break;
    }

    // ===== Atributo 2 =====
    switch (jogadoropcao2) {
        case 1: valor1b = populacao; valor2b = populacao2; sprintf(atributo2, "População"); sprintf(unidade2, "habitantes"); break;
        case 2: valor1b = area; valor2b = area2; sprintf(atributo2, "Área"); sprintf(unidade2, "km²"); break;
        case 3: valor1b = pib; valor2b = pib2; sprintf(atributo2, "PIB"); sprintf(unidade2, "bilhões de reais"); break;
        case 4: valor1b = pontosturisticos; valor2b = pontosturisticos2; sprintf(atributo2, "Pontos Turísticos"); sprintf(unidade2, "pontos"); break;
        case 5: valor1b = densidade1; valor2b = densidade2; sprintf(atributo2, "Densidade Populacional"); sprintf(unidade2, "hab/km²"); break;
        case 6: valor1b = pibpercapita1; valor2b = pibpercapita2; sprintf(atributo2, "PIB per capita"); sprintf(unidade2, "bilhões/habitante"); break;
    }

    // ===== Comparação Final =====
    float soma1, soma2;

    if (jogadoropcao1 == 5 && jogadoropcao2 == 5) {
        soma1 = valor1a + valor1b;
        soma2 = valor2a + valor2b;

        printf("\nComparação de cartas (Atributos: %s / %s):\n", atributo1, atributo2);
        printf("Carta 1 - %s - %s: %.2f %s / %s: %.2f %s - SOMA = %.2f\n",
               nomedopais, atributo1, valor1a, unidade1, atributo2, valor1b, unidade2, soma1);
        printf("Carta 2 - %s - %s: %.2f %s / %s: %.2f %s - SOMA = %.2f\n",
               nomedopais2, atributo1, valor2a, unidade1, atributo2, valor2b, unidade2, soma2);

        printf("\nResultado: %s\n",
            soma1 < soma2 ? nomedopais : soma2 < soma1 ? nomedopais2 : "O jogo está empatado!!!");

        if (soma1 != soma2)
            printf("Carta %d - %s venceu!!!\n", soma1 < soma2 ? 1 : 2, soma1 < soma2 ? nomedopais : nomedopais2);
    }
    else if (jogadoropcao1 == 5 || jogadoropcao2 == 5) {
        soma1 = (jogadoropcao1 == 5 ? -valor1a : valor1a) + (jogadoropcao2 == 5 ? -valor1b : valor1b);
        soma2 = (jogadoropcao1 == 5 ? -valor2a : valor2a) + (jogadoropcao2 == 5 ? -valor2b : valor2b);

        printf("\nComparação de cartas (Atributos: %s / %s):\n", atributo1, atributo2);
        printf("Carta 1 - %s - %s: %.2f %s / %s: %.2f %s - SOMA = %.2f\n",
               nomedopais, atributo1, valor1a, unidade1, atributo2, valor1b, unidade2, soma1);
        printf("Carta 2 - %s - %s: %.2f %s / %s: %.2f %s - SOMA = %.2f\n",
               nomedopais2, atributo1, valor2a, unidade1, atributo2, valor2b, unidade2, soma2);

        printf("\nResultado: %s\n",
            soma1 > soma2 ? nomedopais : soma2 > soma1 ? nomedopais2 : "O jogo está empatado!!!");

        if (soma1 != soma2)
            printf("Carta %d - %s venceu!!!\n", soma1 > soma2 ? 1 : 2, soma1 > soma2 ? nomedopais : nomedopais2);
    }
    else {
        soma1 = valor1a + valor1b;
        soma2 = valor2a + valor2b;

        printf("\nComparação de cartas (Atributos: %s / %s):\n", atributo1, atributo2);
        printf("Carta 1 - %s - %s: %.2f %s / %s: %.2f %s - SOMA = %.2f\n",
               nomedopais, atributo1, valor1a, unidade1, atributo2, valor1b, unidade2, soma1);
        printf("Carta 2 - %s - %s: %.2f %s / %s: %.2f %s - SOMA = %.2f\n",
               nomedopais2, atributo1, valor2a, unidade1, atributo2, valor2b, unidade2, soma2);

        printf("\nResultado: %s\n",
            soma1 > soma2 ? nomedopais : soma2 > soma1 ? nomedopais2 : "O jogo está empatado!!!");

        if (soma1 != soma2)
            printf("Carta %d - %s venceu!!!\n", soma1 > soma2 ? 1 : 2, soma1 > soma2 ? nomedopais : nomedopais2);
    }
    return 0;
}