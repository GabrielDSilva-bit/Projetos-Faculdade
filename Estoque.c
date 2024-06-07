#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct do produto
typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

Produto* estoque = NULL;
int totalProdutos = 0;

//add produto
void adicionar_produto() {
    estoque = realloc(estoque, (totalProdutos + 1) * sizeof(Produto));
    if (estoque == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]s", estoque[totalProdutos].nome);
    printf("Digite o preço do produto: ");
    scanf("%f", &estoque[totalProdutos].preco);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &estoque[totalProdutos].quantidade);

    totalProdutos++;
    printf("Produto adicionado com sucesso!\n");
}

//quantidade
void atualizar_quantidade() {
    char nome[50];
    int novaQuantidade;

    printf("Digite o nome do produto cuja quantidade deseja atualizar: ");
    scanf(" %[^\n]s", nome);

    for (int i = 0; i < totalProdutos; i++) {
        if (strcmp(estoque[i].nome, nome) == 0) {
            printf("Quantidade atual: %d\n", estoque[i].quantidade);
            printf("Digite a nova quantidade: ");
            scanf("%d", &novaQuantidade);
            estoque[i].quantidade = novaQuantidade;
            printf("Quantidade do produto %s atualizada para %d.\n", nome, novaQuantidade);
            return;
        }
    }

    printf("Produto não encontrado!\n");
}

//listar produtos
void listar_produtos() {
    if (totalProdutos == 0) {
        printf("Não há produtos em estoque.\n");
        return;
    }

    printf("Produtos em estoque:\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("Nome: %s, Preço: %.2f, Quantidade: %d\n",
               estoque[i].nome, estoque[i].preco, estoque[i].quantidade);
    }
}

//menu para aplicação
int main() {
    int opcao;

    while (1) {
        printf("Menu:\n");
        printf("1. Adicionar produto\n");
        printf("2. Atualizar quantidade\n");
        printf("3. Listar produtos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_produto();
                break;
            case 2:
                atualizar_quantidade();
                break;
            case 3:
                listar_produtos();
                break;
            case 4:
                free(estoque);
                exit(0);
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
