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

void exibirLista(ListaAluno* l);
void criarLista(ListaAluno* l);
void imprimirAluno(Aluno l);
int inserirAlunoOrdenado(ListaAluno* l, Aluno a);
int InserirNoFinal(ListaAluno* l, Aluno a);
void liberarLista(ListaAluno* l);
int listaVazia(ListaAluno* l);
void menu();
void menuInserir();
void menuObter();
void menuRemover();
int obterAlunoMat(ListaAluno* l, int matricula, Aluno* a);
int obterAlunoNome(ListaAluno* l, char* nome, Aluno* a);
int obterAlunoPos(ListaAluno* l, int pos, Aluno* a);
int obterPosicaoMat(ListaAluno* l, int mat);
void ReceberDados(Aluno* a);
int removerAlunoMat(ListaAluno* l, int mat);
void RemoverAlunoPos(ListaAluno* l, int pos);
int tamanhoLista(ListaAluno* l);
#endif


