#ifndef LISTADINALU_H
#define LISTADINALU_H

typedef struct aluno {
    int matricula;
    char nome[30];
    float nota1, nota2;
} Aluno;

typedef struct no {
    Aluno estudante;
    struct no *prox;
} No;

typedef struct lista {
    No *inicio;
    int tam;
} ListaAluno;

void criarLista(ListaAluno *l);
int listaVazia(ListaAluno *l);
int tamanhoLista(ListaAluno *l);
int obterAlunoPos(ListaAluno *l, int pos, Aluno *a);
int obterPosicaoMat(ListaAluno *l, int mat);
int inserirAlunoOrdenado(ListaAluno *l, Aluno a);
int removerAlunoMat(ListaAluno *l, int mat);
void RemoverAlunoPos (ListaAluno *l, int pos);
void exibirLista(ListaAluno *l);
void liberarLista(ListaAluno *l);
int InserirNoFinal(ListaAluno *l, Aluno a);
void menu();
#endif

