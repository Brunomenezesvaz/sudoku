#include <stdio.h>

int main(void) {
  //atividade sudoku
  int opt, ilin, icol, val, i, j, acc=0, tmp;
  int a, b, iq;
  int matrix[9][9];
  for(i=0; i<9; i++){
    for(j=0; j<9; j++){
      scanf("%d ", &matrix[i][j]);
    }
  }
  do{
     scanf("%d ", &opt);//ler operador
     acc=0;

    if(opt==1){
      scanf("%d %d %d", &ilin, &icol, &val);//leitura dos indices e novo valor
      matrix[ilin][icol] = val;//igualo a nova posição dada pelos indices ao valor
    }

    else if(opt==2){
      scanf("%d ", &ilin);
      for(a=0; a<9; a++){
        for(b=0; b<9; b++){
          tmp=matrix[a][b];//crio uma temporaria que ira armazenar os valores da posição da matriz para fins de comparação
          for(i=ilin; i<ilin+1; i++){
            for(j=0; j<9; j++){
              if(matrix[i][j]==tmp){//comparação e caso sejam iguais, haverá um aumento no contador
                acc++;
              }
            }
          }
        }
      }
      if(acc==0){printf("N\n");}//caso o contador não mova, não há numeros repetidos senão haverá
      else{printf("S\n");}
    }

    else if(opt==3){
      scanf("%d ", &icol);
      for(a=0; a<9; a++){//mesma logica anterior
        for(b=0; b<9; b++){
          tmp=matrix[a][b];
          for(i=0; i<9; i++){
            for(j=icol; j<icol+1; j++){
              if(matrix[i][j]==tmp){
                acc++;
              }
            }
          }
        }
      }
      if(acc==0){printf("N \n");}
      else{printf("S \n");}
      }

    else if(opt==4){
      scanf("%d", &iq);
      for(a=0; a<9; a++){
        for(b=0; b<9; b++){
          tmp=matrix[a][b];
          if(iq<7){
            for(i=iq; i<iq+3; i++){//para quadrantes menores que 7 o limite do loop será o indice mais 3, fechando uma matriz 3x3
              for(j=iq; j<iq+3; j++){
                if(matrix[i][j]==tmp){
                  acc++;
                }
              }
            }
          }
          else{
            for(i=iq; i<iq-3; i--){
                for(j=iq; j<iq-3; j--){ //para os valores maiores que 7 o quadrante so pode ser feito com as linhas e colunas inferiores
                  if(matrix[i][j]==tmp){
                    acc++;
                  }
                }
              }
            }
          }
        }
      if(acc==0){printf("N \n");}
      else{printf("S \n");}
    }
    else if(opt==5){
      for(a=0; a<9; a++){
        for(b=0; b<9; b++){
          tmp=matrix[a][b];//mesma logica anterior aplicada na matriz inteira
          for(i=0; i<9; i++){
            for(j=0; j<9; j++){
              if(matrix[i][j]==tmp){
                acc++;
              }
            }
          }
        }
      }
    if(acc==0){printf("N \n");}
    else{printf("S \n");}
    }
    else{
        for(i=0; i<9; i++){
            if (i % 3 == 0 && i != 0){//caso o indice da linha seja divisel por 3, já que queremos varias matrizes 3x3, porem diferente de zero, já que esse faz parte do primeiro quadrante irá imprimir também um \n
                printf("\n");
                }
            for(j=0; j<9; j++){
                if (j % 3 == 0 && j != 0){//mesma logica das linhas mas para as colunos e irá imprimir um espaço
                    printf(" ");
                }
                printf("%d", matrix[i][j]);
            }
            printf("\n");//salta de linha
        }
    }
  }while(opt!=0);


  return 0;
}
