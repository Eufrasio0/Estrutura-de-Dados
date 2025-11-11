#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadinalu.h"

void criarLista(ListaAluno *l) {
    l->inicio = NULL;
    l->tam = 0;
}
void imprimirAluno(Aluno l){
        printf("MATRICULA: %d\n", l.matricula);
        printf("NOME: %s\n", l.nome);
        printf("PRIMEIRA NOTA: %.2f\n", l.nota1);
        printf("SEGUNDA NOTA: %.2f\n", l.nota2);
}
int listaVazia(ListaAluno *l) {
    return (l->inicio == NULL);
}

int tamanhoLista(ListaAluno *l) {
    return l->tam;
}
void ReceberDados(Aluno *a) {
    printf("Digite matricula: ");
    scanf("%d", &a->matricula);
    getchar();
    printf("Digite nome: ");
    fgets(a->nome, 30, stdin);
    a->nome[strcspn(a->nome, "\n")] = '\0';
    printf("Digite Nota1: ");
    scanf("%f", &a->nota1);
    printf("Digite Nota2: ");
    scanf("%f", &a->nota2);
}
int obterAlunoPos(ListaAluno *l, int pos, Aluno *a) {
    No *aux = l->inicio;
    int i = 0;
    while(aux != NULL && i < pos) {
        aux = aux->prox;
        i++;
    }
    if(aux == NULL){
        printf("POSICAO FORA DA LISTA\n");
        return 0;
    }
    *a = aux->estudante;
    return 1;
}

int obterAlunoNome(ListaAluno *l, char *nome, Aluno *a) {
    if (l == NULL || l->inicio == NULL || nome == NULL || a == NULL) {
        return 0;
    }
    No *aux = l->inicio;
    while (aux != NULL && strcmp(aux->estudante.nome, nome) != 0) {
        aux = aux->prox;
    }
    if (aux == NULL) {
        return 0;
    }
    *a = aux->estudante;
    return 1;
}

int obterAlunoMat(ListaAluno *l, int matricula, Aluno *a) {
    if (l == NULL || l->inicio == NULL || a == NULL) {
        return 0;
    }
    No *aux = l->inicio;
    while (aux != NULL && aux->estudante.matricula != matricula) {
        aux = aux->prox;
    }
    if (aux == NULL) {
        return 0;
    }
    *a = aux->estudante;
    return 1;
}

int obterPosicaoMat(ListaAluno *l, int mat) {
    No *aux = l->inicio;
    int pos = 0;
    while(aux != NULL) {
        if(aux->estudante.matricula == mat){
            return pos;
        }
        aux = aux->prox;
        pos++;
    }
    return -1;
}

int inserirAlunoOrdenado(ListaAluno *l, Aluno a) {
    No *novo = (No*)malloc(sizeof(No));
    novo->estudante = a;
    novo->prox = NULL;
    if(listaVazia(l) || a.matricula < l->inicio->estudante.matricula) {
        novo->prox = l->inicio;
        l->inicio = novo;
        l->tam++;
        return;
    }
    No *aux = l->inicio;
    while(aux->prox != NULL && aux->prox->estudante.matricula < a.matricula) {
        aux = aux->prox;
    }
    if(aux->estudante.matricula == a.matricula ||
       (aux->prox && aux->prox->estudante.matricula == a.matricula)) {
        free(novo);
        return 1;
    }
    novo->prox = aux->prox;
    aux->prox = novo;
    l->tam++;
}
int InserirNoFinal(ListaAluno *l, Aluno a){
    No *novo = (No *) malloc(sizeof(No));
    novo->estudante = a;
    novo->prox = NULL;

    if (listaVazia(l)){
        l->inicio = novo;
        return 1;
    }

    No *aux = l->inicio;
    while(aux->prox!=NULL){
        aux=aux->prox;
    }
    aux->prox = novo;
    return 1;
}

void RemoverAlunoPos(ListaAluno *l, int pos) {
    if (l->inicio == NULL) {
        printf("LISTA VAZIA\n");
        return;
    }
    No *atual = l->inicio;
    No *ant = NULL;
    int cont = 0;
    if (pos == 0) {
        l->inicio = atual->prox;
        free(atual);
        l->tam--;
        printf("Aluno removido da posicao 0.\n");
        return;
    }
    while (atual != NULL && cont < pos) {
        ant = atual;
        atual = atual->prox;
        cont++;
    }
    if (atual == NULL) {
        printf("Posição inexistente.\n");
        return;
    }
    ant->prox = atual->prox;
    free(atual);
    l->tam--;
    printf("Aluno removido da posicao %d.\n", pos);
}
int removerAlunoMat(ListaAluno *l, int mat) {
    if (l == NULL || listaVazia(l)) {
        printf("\nLISTA VAZIA\n");
        return 0;
    }
    No *atual = l->inicio;
    No *ant = NULL;
    while (atual != NULL && atual->estudante.matricula != mat) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        printf("\nALUNO INEXISTENTE (matrícula %d)\n", mat);
        return 0;
    }
    if (ant == NULL) {
        l->inicio = atual->prox;
    } else {
        ant->prox = atual->prox;
    }
    free(atual);
    l->tam--;
    printf("\nAluno com matricula %d removido com sucesso!\n", mat);
    return 1;
}
void exibirLista(ListaAluno *l) {
    if (listaVazia(l)) {
        printf("\nLista vazia!\n");
        return;
    }

    No *aux = l->inicio;
    printf("\n------ LISTA DE ALUNOS ------\n");
    while (aux != NULL) {
        printf("\n-------------------------\n");
        printf(" Matricula : %d\n", aux->estudante.matricula);
        printf(" Nome      : %s\n", aux->estudante.nome);
        printf(" Nota 1    : %.2f\n", aux->estudante.nota1);
        printf(" Nota 2    : %.2f\n", aux->estudante.nota2);
        printf("---------------------------\n");
        aux = aux->prox;
    }
}


void liberarLista(ListaAluno *l) {
    No *aux = l->inicio;
    while(aux != NULL) {
        No *temp = aux->prox;
        free(aux);
        aux = temp;
    }
    l->inicio = NULL;
    l->tam = 0;
}

void menu() {
    printf("\n------ MENU -------\n");
    printf("1 - Exibir Lista\n");
    printf("2 - Exibir numero de alunos\n");
    printf("3 - Remover aluno\n");
    printf("4 - Obter dados\n");
    printf("5 - Inserir\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
}

void menuObter(){
    printf("\n 1 - Obter dados informando a posicao\n");
    printf(" 2 - Obter dados informando o nome\n");
    printf(" 3 - Obter dados informando a matricula\n");
    printf(" 4 - Obter posição informando a matricula\n");
    printf("Escolha: ");
}

void menuRemover(){
    printf(" 1 - Remover informando a posicao\n");
    printf(" 2 - Remover informando a matricula\n");
    printf("Escolha: ");
}
void menuInserir(){
    printf("\n 1 - Inserir no final (SE ESCOLHER ESSA OPCAO E A LISTA JA ESTIVER DEFINIDA\n ELA SERA RESETADA E MUDARA PARA O ESTADO DE ORDEM POR CHEGADA)\n");
    printf("\n 2 - Inserir de forma ordenada por matricula(SE ESCOLHER ESSA OPCAO E A LISTA JA ESTIVER DEFINIDA\n ELA SERA RESETADA E SEGUIRA A ORDEM POR VALOR DE MATRICULA)\n");
    printf("Escolha: ");
}

