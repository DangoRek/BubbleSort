#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 200000
int comparationCount = 0;
int swapCount = 0;

void bubbleSort(int vet[])
{
  int i, j, aux;

  for(i=0; i<N; i++)
  {
      for(j=0; j<N-1-i; j++)//-1 para melhor performace
      {
        comparationCount++;
        if (vet[j]>vet[j+1])//compara elemento do vetor com o da frente
        {//troca
  	      aux = vet[j+1];
          vet[j+1] = vet [j];
          vet[j] = aux;
          swapCount++;
        }
      }
  }
}

int main(void) {
  clock_t t;
  t = clock();

  int v[N], i;
  for (i=0; i<N; i++){//vetor aleatorio (mais interessante)
    v[i] = rand()%100;
    printf("%d,", v[i]);
  }

  //for (i=0; i<N; i++){//previamente ordenado
  //  v[i] = i;
  //  printf("%d,", v[i]);
  //}

  //for (i=0; i<N; i++){//previamente ordenado inversamente
  //  v[i] = N-i-1;
  //  printf("%d,", v[i]);
  //}

  printf("\n\n\n\n");
  bubbleSort(v);

  for (i=0; i<N; i++){
    printf("%d,", v[i]);
  }

  printf("\nForam feitas %d comparações", comparationCount);
  printf("\nForam feitas %d trocas", swapCount);
  t = clock()-t;
  printf("\nTempo de operação:%f",t);
  return 0;
}