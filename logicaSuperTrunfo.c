#include <stdio.h>
#include <stdlib.h>

int main() {
    int jogadoropcao1, computadoropcao1;
    float valor1, valor2;
    char atributo[30];

    // Primeira carta
    int codigodacarta;
    char siglas[10];
    char nomedacidade[50];
    int populacao;
    float area;
    float pib;
    int pontosturisticos;
    float densidade1, pibpercapita1;

    // Segunda carta
    int codigodacarta2;               
    char siglas2[10];           
    char nomedacidade2[50];    
    int populacao2;            
    float area2;               
    float pib2;                
    int pontosturisticos2;     
    float densidade2, pibpercapita2;

    // Exibe título do programa na tela
    printf("SUPER TRUNFO DE PAÍSES\n\n");

    // Instruções para o usuário
    printf("Vamos Inserir os dados das cartas do SUPER TRUNFO DE PAÍSES? \n");
    printf("As cartas trarão informações sobre CIDADES. \n");
    printf("O nome da CIDADE não poderá ter caracter especial. \n");
    printf("Os ESTADOS serão representados por suas siglas. \n");
    printf("A numeração das cartas iniciará com o número 01 e a última terá o número 08. \n\n");
    
    // ===== Primeira Carta =====
    printf("\nVamos cadastrar a primeira carta. \n\n");
    printf("Insira a sigla do Estado: ");
    scanf("%s", siglas);
    printf("Insira o número da carta: ");
    scanf("%d", &codigodacarta);
    printf("Insira o nome da cidade: ");
    scanf(" %[^\n]", nomedacidade);
    printf("Insira o número de habitantes (População): ");
    scanf("%d", &populacao);
    printf("Insira o tamanho do país (km²): ");
    scanf("%f", &area);
    printf("Insira o PIB (em bilhões de reais): ");
    scanf("%f", &pib);
    printf("Insira a quantidade de Pontos Turísticos: ");
    scanf("%d", &pontosturisticos);

    densidade1 = populacao / area;
    pibpercapita1 = pib / populacao;

    // ===== Segunda Carta =====
    printf("\nVamos cadastrar a segunda carta. \n\n");
    printf("Insira a sigla do Estado: ");
    scanf("%s", siglas2);
    printf("Insira o número da carta: ");
    scanf("%d", &codigodacarta2);
    printf("Insira o nome da cidade: ");
    scanf(" %[^\n]", nomedacidade2);
    printf("Insira o número de habitantes (População): ");
    scanf("%d", &populacao2);
    printf("Insira o tamanho do país (km²): ");
    scanf("%f", &area2);
    printf("Insira o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Insira a quantidade de Pontos Turísticos: ");
    scanf("%d", &pontosturisticos2);

    densidade2 = populacao2 / area2;
    pibpercapita2 = pib2 / populacao2;

    // ===== Escolha do atributo =====
    printf("\nEscolha o atributo para comparar (1 a 6):\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per capita\n");
    printf("\nDigite aqui a sua opção: ");
    scanf("%d", &jogadoropcao1);

    if (jogadoropcao1 < 1 || jogadoropcao1 > 6) {
        printf("\nOPÇÃO INVÁLIDA!!! OS NÚMEROS VÁLIDOS VÃO DE 1 A 6.\n");
        return 1;
    }

    computadoropcao1 = jogadoropcao1;  // computador escolhe o mesmo atributo

    // Determinar valores e nomes dos atributos
    switch (jogadoropcao1) {
    case 1:
        valor1 = populacao;
        valor2 = populacao2;
        sprintf(atributo, "População");
        break;
    case 2:
        valor1 = area;
        valor2 = area2;
        sprintf(atributo, "Área");
        break;
    case 3:
        valor1 = pib;
        valor2 = pib2;
        sprintf(atributo, "PIB");
        break;
    case 4:
        valor1 = pontosturisticos;
        valor2 = pontosturisticos2;
        sprintf(atributo, "Pontos Turísticos");
        break;
    case 5:
        valor1 = densidade1;
        valor2 = densidade2;
        sprintf(atributo, "Densidade Populacional");
        break;
    case 6:
        valor1 = pibpercapita1;
        valor2 = pibpercapita2;
        sprintf(atributo, "PIB per capita");
        break;
    }

    // Mostrar comparação
    printf("\nComparação de cartas (Atributo: %s):\n", atributo);
    printf("Carta 1 - %s - %s: %.2f\n", nomedacidade, atributo, valor1);
    printf("Carta 2 - %s - %s: %.2f\n", nomedacidade2, atributo, valor2);

    // Comparação e resultado
    if (jogadoropcao1 == 5) { 
        // Para densidade, o menor vence
        if (valor1 < valor2)
            printf("\nResultado: Carta 1 (%s) venceu!\n", nomedacidade);
        else if (valor2 < valor1)
            printf("\nResultado: Carta 2 (%s) venceu!\n", nomedacidade2);
        else
            printf("\nResultado: O jogo está empatado!\n");
    } else { 
        // Para os demais atributos, o maior vence
        if (valor1 > valor2)
            printf("\nResultado: Carta 1 (%s) venceu!\n", nomedacidade);
        else if (valor2 > valor1)
            printf("\nResultado: Carta 2 (%s) venceu!\n", nomedacidade2);
        else
            printf("\nResultado: O jogo está empatado!\n");
    }

    return 0;
}