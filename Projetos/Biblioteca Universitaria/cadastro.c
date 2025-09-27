#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Livro{
    int id;
    char titulo[50];
    char autor[50];
    int ano;
};

void cadastrarLivro(struct Livro *biblioteca, int *qntd);
void listarLivros(struct Livro *biblioteca, int qntd);
struct Livro* buscarLivro(struct Livro *biblioteca, int qntd, char *titulo);

int main() {

    struct Livro biblioteca[100];

    int opcao;
    int qntd = 0;
    int *pqntd = &qntd;


    while(true){

        printf("--Ola, seja bem vindo a biblioteca PUC GO. O que deseja fazer ?--\n");
        printf("Opcao 0- Sair\nOpcao 1- cadastrar livros\nOpcao 2- Listar livros cadastrados\nOpcao 3- Buscar livro por titulo\n");
        printf("Digite a opcao desejada\n");

        scanf("%d",&opcao);

        getchar();

        if(opcao == 1){
            cadastrarLivro(biblioteca,pqntd);
            continue;
        }else if(opcao == 2){
            if(qntd == 0){
                printf("Ainda nao tem nenhum livro cadastrado!\n");
            }
            listarLivros(biblioteca,qntd);
            continue;
        }else if(opcao == 3){
            printf("Digite o nome do livro que deseja buscar.\n");
            char tituloBusca[50];

            fgets(tituloBusca,sizeof(tituloBusca),stdin);

            struct Livro* livroEncontrado = buscarLivro(biblioteca,qntd,tituloBusca);

            if(livroEncontrado != NULL){
                printf("Livo encontrado\n");
                printf("ID: %d\n",livroEncontrado->id);
                printf("Titulo: %s",livroEncontrado->titulo);
                printf("Autor: %s",livroEncontrado->autor);
                printf("Ano de publicacao: %d\n",livroEncontrado->ano);
            }else{
                printf("Livro nao encontrado. Verifique se o nome digitado esta correto !\n");
            }
        }else{
            break;
        }
    }
    return 0;
}


void cadastrarLivro(struct Livro *biblioteca, int *qntd){

    if(*qntd >= 100){
        printf("Quantidade maxima de livros antigida !\n");
    }

    struct Livro novoLivro;

    novoLivro.id = *qntd ;

    printf("Titulo:\n");

    fgets(novoLivro.titulo,sizeof(novoLivro.titulo),stdin);

    printf("Autor:\n");

    fgets(novoLivro.autor,sizeof(novoLivro.autor),stdin);

    printf("Ano de publicacao\n");
    scanf("%d",&novoLivro.ano);

    getchar();

    biblioteca[*qntd] = novoLivro;
    (*qntd)++;

}

void listarLivros(struct Livro *biblioteca, int qntd){

    printf("---Livros ja cadastrados---\n");

    for(int i = 0; i < qntd; i++){
        printf("Livro %d\n",i);
        printf("ID: %d\n",biblioteca[i].id);
        printf("titulo: %s",biblioteca[i].titulo);
        printf("Autor: %s\n",biblioteca[i].autor);
        printf("Ano de publicacao: %d\n",biblioteca[i].ano);
    }

}

struct Livro* buscarLivro(struct Livro *biblioteca, int qntd, char *titulo){
    
    struct Livro novoLivro;

    for(int i = 0; i < qntd; i++){
        if(strcmp(titulo,biblioteca[i].titulo) == 0){
            return &biblioteca[i];
        }
    }
    return NULL;
}
