#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadinalu.h"

int main() {
    ListaAluno lista;
    criarLista(&lista);
    int opcao, mat, pos;
    int verifi = 0;
    Aluno a;
    do {
        menu();
        scanf("%d", &opcao);
        getchar();
        switch(opcao) {
            case 1:
               exibirLista(&lista);
                break;

            case 2:
                printf("\nTotal de alunos cadastrados: %d\n", tamanhoLista(&lista));
                break;

            case 3:
              menuRemover();
              {
                  scanf("%d", &opcao);
                  if(opcao == 1){
                        printf("\nDigite a posicao do aluno que deseja remover\n");
                        scanf("%d", &pos);
                        RemoverAlunoPos(&lista, pos);
                        break;
                  } else if(opcao == 2){
                       printf("\nDigite a matricula do aluno que deseja remover\n");
                        scanf("%d", &mat);
                        removerAlunoMat(&lista, mat);
                        break;
                  } else {
                      printf("Opção invalida!\n");
                      break;
                  }
              }

            case 4:
                {
                Aluno a;
                menuObter();
                scanf("%d", &opcao);
                if(opcao == 4){
                        printf("\nDigite a matricula do aluno que deseja saber a posicao na lista:\n");
                        scanf("%d", &mat);
                        pos = obterPosicaoMat(&lista, mat);
                        if (pos != -1)
                            printf("Aluno encontrado na posicao %d.\n", pos);
                        else
                            printf("Aluno nao encontrado!\n");
                        break;
                } else if (opcao == 1){
                        printf("\nDigite a posicao do aluno que deseja saber os dados:\n");
                        scanf("%d", &pos);
                        if(obterAlunoPos(&lista,pos,&a) == 0){
                                break;
                        }else {
                            imprimirAluno(a);
                            break;
                        }
                    } else if (opcao == 2){
                        char nome[30];
                        printf("Digite nome do aluno procurado: ");
                        getchar();
                        fgets(nome, sizeof(nome), stdin);
                        nome[strcspn(nome, "\n")] = '\0';
                        if(obterAlunoNome(&lista, nome, &a) == 0){
                                printf("ALUNO NAO ENCONTRADO\n");

                        } else{
                            imprimirAluno(a);
                            break;
                        }
                    } else if(opcao == 3) {
                        printf("\nDigite a matricula do aluno que deseja saber os dados:\n");
                        scanf("%d", &mat);
                        if(obterAlunoMat(&lista,mat,&a) == 0){
                                printf("MATRICULA FORA DA LISTA\n");
                            break;
                        }else {
                            imprimirAluno(a);
                            break;
                        }
                    } else {
                        printf("OPÇÃO INVALIDA\n");
                        break;
                    }
                    break;
                }
          case 5: {
                    if (verifi == 0) {
                        printf("\n--- LISTA VAZIA, DEFINA A NATUREZA QUE A LISTA IRA SEGUIR ---\n");
                    }
                    else if (verifi == 1) {
                        printf("\n--- LISTA ORDENADA POR ORDEM DE CHEGADA ---\n");
                    }
                    else if (verifi == 2) {
                        printf("\n--- LISTA ORDENADA POR VALOR DE MATRÍCULA ---\n");
                    }
                    menuInserir();
                    scanf("%d", &opcao);
                    getchar();
                    if (opcao == 1) {
                        if (verifi == 0 || verifi == 1) {
                            ReceberDados(&a);
                            InserirNoFinal(&lista, a);
                            verifi = 1;
                        }
                        else {
                            liberarLista(&lista);
                            ReceberDados(&a);
                            InserirNoFinal(&lista, a);
                            verifi = 1;
                        }
                    }

                    else if (opcao == 2) {
                        if (verifi == 0 || verifi == 2) {
                            ReceberDados(&a);
                            inserirAlunoOrdenado(&lista, a);
                            verifi = 2;
                        }
                        else {
                            liberarLista(&lista);
                            ReceberDados(&a);
                            inserirAlunoOrdenado(&lista, a);
                            verifi = 2;
                        }
                    }
                    else {
                        printf("\n OPCAO INVALIDA!\n");
                    }
                }
                break;
            case 0:
                printf("\nFIM DO PROGRAMA...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while(opcao != 0);

    liberarLista(&lista);
    return 0;
}
