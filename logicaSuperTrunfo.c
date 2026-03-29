#include <stdio.h>

int main() {
    char estado1, estado2;
    // Aumentamos o codecard para 4 ou 5 para caber "A01" + o caractere nulo \0
    char codecard1[5], codecard2[5], namecity1[50], namecity2[50];
    int pontosturisticos1, pontosturisticos2, opcao;
    float areacity1, areacity2, pibcity1, pibcity2;

    // População como unsigned long int
    unsigned long int populationcity1, populationcity2;

    // Variáveis para cálculos
    float densidadeCity1, densidadeCity2, pibPerCaptaCity1, pibPerCaptaCity2;
    double superpodercarta1, superpodercarta2;

    // --- CADASTRO CARTA 1 ---
    printf("-------------- Cadastro Carta 1 --------------\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código (ex: A01): ");
    scanf("%s", codecard1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", namecity1);
    printf("População: ");
    scanf("%lu", &populationcity1); // %lu é o formatador para unsigned long
    printf("Área (km²): ");
    scanf("%f", &areacity1);
    printf("PIB: ");
    scanf("%f", &pibcity1);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontosturisticos1);

    // --- CADASTRO CARTA 2 ---
    printf("\n-------------- Cadastro Carta 2 --------------\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Código: ");
    scanf("%s", codecard2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", namecity2);
    printf("População: ");
    scanf("%lu", &populationcity2); // %lu aqui também
    printf("Área (km²): ");
    scanf("%f", &areacity2);
    printf("PIB: ");
    scanf("%f", &pibcity2);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontosturisticos2);

    // --- ÁREA DE CÁLCULO ---

    // Atenção: Densidade = População / Área (e não o contrário)
    densidadeCity1 = (float)populationcity1 / areacity1;
    densidadeCity2 = (float)populationcity2 / areacity2;

    // PIB per Capita = PIB / População
    // Como o PIB está em bilhões no seu exemplo, o resultado será proporcional
    pibPerCaptaCity1 = (pibcity1 * 1000000000.0) / populationcity1;
    pibPerCaptaCity2 = (pibcity2 * 1000000000.0) / populationcity2;

    // Super poder: Soma de todos os atributos (Densidade entra invertida)
    superpodercarta1 = (float)populationcity1 + areacity1 + pibcity1 + (float)pontosturisticos1 + pibPerCaptaCity1 + (1.0f / densidadeCity1);
    superpodercarta2 = (float)populationcity2 + areacity2 + pibcity2 + (float)pontosturisticos2 + pibPerCaptaCity2 + (1.0f / densidadeCity2); 

    // --- EXIBIÇÃO ---
      printf("\n-------------------------------------------\n");

    printf("Carta 1:\n");
    printf("Estado: %c\nCódigo: %s\nNome: %s\nPopulação: %lu\nÁrea: %.2f km²\nPIB: %.2f bilhões de reais\nPontos Turísticos: %d\nDensidade Populacional: %.2f\nPIB per Capta: %.2f\n ",
           estado1, codecard1, namecity1, populationcity1, areacity1, pibcity1, pontosturisticos1, densidadeCity1, pibPerCaptaCity1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\nCódigo: %s\nNome: %s\nPopulação: %lu\nÁrea: %.2f km²\nPIB: %.2f bilhões de reais\nPontos Turísticos: %d\nDensidade Populacional: %.2f\nPIB per Capta: %.2f\n ",
           estado2, codecard2, namecity2, populationcity2, areacity2, pibcity2, pontosturisticos2, densidadeCity2, pibPerCaptaCity2);

    printf("\n-------------------------------------------\n");

    printf("\n--- COMPARAÇÃO DE CARTAS (Atributos) ---\n");
    printf("Escolha quais atributos você deseja comparar:\n");

        printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n6. PIB per Capta\n");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                if (populationcity1 > populationcity2){
                    printf("Carta 1 é superior em população!\n");
                } else if(populationcity1 == populationcity2){
                    printf("As cartas têm a mesma população!\n");
                } else {
                    printf("Carta 2 é superior em população!\n");
                }
                break;
            case 2:
                if(areacity1 > areacity2){
                    printf("Carta 1 é superior em área!\n");
                } else if(areacity1 == areacity2){
                    printf("As cartas têm a mesma área!\n");
                } else {
                    printf("Carta 2 é superior em área!\n");
                }
                break;
            case 3:
                if(pibcity1 > pibcity2){
                    printf("Carta 1 é superior em PIB!\n");
                } else if(pibcity1 == pibcity2){
                    printf("As cartas têm o mesmo PIB!\n");
                } else {
                    printf("Carta 2 é superior em PIB!\n");
                }
                break;
            case 4:
                if(pontosturisticos1 > pontosturisticos2){
                    printf("Carta 1 é superior em pontos turísticos!\n");
                } else if(pontosturisticos1 == pontosturisticos2){
                    printf("As cartas têm o mesmo número de pontos turísticos!\n");
                } else {
                    printf("Carta 2 é superior em pontos turísticos!\n");
                }
                break;
            case 5:
                if(densidadeCity1 > densidadeCity2){
                    printf("Carta 2 é superior em densidade populacional");
                } else if(densidadeCity1 == densidadeCity2){
                    printf("As cartas têm a mesma densidade populacional!\n");
                } else{
                    printf("Carta 1 é superior em densidade populacional");
                }
                break;
            case 6:
                if(pibPerCaptaCity1 > pibPerCaptaCity2){
                    printf("Carta 1 é superior em PIB per Capta!\n");
                } else if(pibPerCaptaCity1 == pibPerCaptaCity2){
                    printf("As cartas têm o mesmo PIB per Capta!\n");
                } else {
                    printf("Carta 2 é superior em PIB per Capta!\n");
                }
                break;
            default:
                printf("Opção inválida! Por favor, escolha um número entre 1 e 6.\n");
                break;
        }

        printf("\n--- COMPARAÇÃO DE CARTAS (Super Poder) ---\n");
        if(superpodercarta1 > superpodercarta2){
            printf("\nCarta 1 Venceu!!\n");
        } else if(superpodercarta1 == superpodercarta2){
            printf("\nAs cartas têm o mesmo super poder!\n");
        } else {
            printf("\nCarta 2 Venceu!!\n");
        }

    return 0;
}