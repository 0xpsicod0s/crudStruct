#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _product {
    unsigned int id;
    char name[100];
    float price;
    unsigned int amount;
} Product;


int menu(void);
Product *createProduct(int, Product*, int*);
void *storeProduct(Product*, Product*, int*);
void readProduct(Product*, int, int);
void updateProduct(Product*, int, int);
void deleteProduct(Product*, int, int);

int main(void) {
    int quantityOfProducts = 0;
    int counter = 0;
    int selectedOption = 0;
    int readId = 0;
    Product *createdProduct = NULL;

    printf("Digite a quantidade de produtos que deseja criar: ");
    scanf("%d", &quantityOfProducts);

    Product *arrRegisteredProduct = (Product*) calloc(quantityOfProducts, sizeof(Product));

    int i = 0;
    while (true) {
        selectedOption = menu();
        if (selectedOption == 1) {
            if (i == quantityOfProducts) {
                puts("------------------------");
                printf("Todos os produtos ja foram criados\n");
                puts("------------------------");
                continue;
            }
            createdProduct = createProduct(quantityOfProducts, arrRegisteredProduct, &counter);
            storeProduct(arrRegisteredProduct, createdProduct, &counter);
            free(createdProduct);
            i++;
        } else if (selectedOption == 2) {
            printf("Digite o id referente ao produto que deseja ler: ");
            scanf("%d", &readId);
            getchar();
            readProduct(arrRegisteredProduct, readId, counter);
        } else if (selectedOption == 3) {
            printf("Digite o id referente ao produto que deseja atualizar: ");
            scanf("%d", &readId);
            getchar();
            updateProduct(arrRegisteredProduct, readId, counter);
        } else if (selectedOption == 4) {
            printf("Digite o id do produto referente ao que deseja excluir: ");
            scanf("%d", &readId);
            getchar();
            deleteProduct(arrRegisteredProduct, readId, counter);
        }
    }
    free(arrRegisteredProduct);
    arrRegisteredProduct = NULL;
    return 0;
}

int menu(void) {
    int option = 0;
    printf("=============================\n");
    printf("Digite o numero da opcao referente a desejada: \n");
    printf("[1] - Criar um novo produto\n");
    printf("[2] - Ler um produto\n");
    printf("[3] - Atualizar um produto\n");
    printf("[4] - Excluir um produto\n");
    printf("> ");
    scanf("%d", &option);
    getchar();

    if (option < 1 || option > 4) {
        printf("Opcoes validas sao somente de 1 a 4\n");
    }
    return option;
}

Product *createProduct(int quantityOfProducts, Product *arrRegisteredProduct, int *counter) {
    Product *createdProduct = (Product*) calloc(quantityOfProducts, sizeof(Product));

    if (*counter > 0) {
        arrRegisteredProduct[*counter].id = arrRegisteredProduct[*counter - 1].id + 1;
        arrRegisteredProduct[*counter].amount = arrRegisteredProduct[*counter - 1].id + 1;
    } else {
        ++arrRegisteredProduct[*counter].id;
        ++arrRegisteredProduct[*counter].amount;
    }

    createdProduct->id = arrRegisteredProduct[*counter].id;
    printf("Nome do produto: ");
    fgets(createdProduct->name, 99, stdin);
    printf("Preco do produto: ");
    scanf("%f", &createdProduct->price);
    createdProduct->amount = arrRegisteredProduct[*counter].amount;


    printf("Produto criado com sucesso!\n");
    return createdProduct;
}

void *storeProduct(Product *arrRegisteredProduct, Product *createdProduct, int *counter) {
    strcpy(arrRegisteredProduct[*counter].name, createdProduct->name);
    arrRegisteredProduct[*counter].price = createdProduct->price;
    (*counter)++;
}

void readProduct(Product *arrRegisteredProduct, int id, int counter) {
    if (id > counter || id < 0) {
        printf("ID invalido, tente outro novamente\n");
        return;
    }
    for (int i = 0; i <= counter; i++) {
        if (arrRegisteredProduct[i].id == id) {
            puts("=========================");
            printf("Informacoes do produto:\n");
            puts("=========================");
            printf("ID: %u\n", arrRegisteredProduct[i].id);
            printf("Nome: %s\n", arrRegisteredProduct[i].name);
            printf("Preco: %.2f\n", arrRegisteredProduct[i].price);
            puts("---------------------------");
        }
    }
}

void updateProduct(Product *arrRegisteredProduct, int id, int counter) {
    if (id > counter || id < 0) {
        printf("ID invalido, tente outro novamente\n");
        return;
    }
    char newName[100];
    float newPrice;
    printf("Digite o novo nome para o produto: ");
    fgets(newName, 99, stdin);
    printf("Digite o novo preco para o produto: ");
    scanf("%f", &newPrice);

    for (int i = 0; i <= counter; i++) {
        if (arrRegisteredProduct[i].id == id) {
            strcpy(arrRegisteredProduct[i].name, newName);
            arrRegisteredProduct[i].price = newPrice;
        }
    }
}

void deleteProduct(Product *arrRegisteredProduct, int id, int counter) {
    if (id > counter || id < 0) {
        printf("ID invalido, tente outro novamente\n");
        return;
    }

    for (int i = 0; i <= counter; i++) {
        if (arrRegisteredProduct[i].id == id) {
            arrRegisteredProduct[i].id = -1;
            printf("Produto com o ID %d exluido\n", id);
            return;
        }
    }

    printf("Produto com o ID %d nao encontrado\n", id);
}