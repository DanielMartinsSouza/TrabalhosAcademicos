#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

#define TAM 10000 //constante para tamanho do vetor

int buscabinaria(int a[], int item, int low, int high){
    if (high <= low)
        return (item > a[low])?  (low + 1): low;
 
    int mid = (low + high)/2;
 
    if(item == a[mid])
        return mid+1;
 
    if(item > a[mid])
        return buscabinaria(a, item, mid+1, high);
    return buscabinaria(a, item, low, mid-1);
}
 

void BinaryinsertionSort(int a[], int n){
    int i, local, j, k, seleciona;
 
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        seleciona = a[i];
 
        // find localation where seleciona should be inserted
        local = buscabinaria(a, seleciona, 0, j);
 
        // Move all elements after localation to create space
        while (j >= local)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = seleciona;
    }
}


//Funï¿½ï¿½o para executar o mergesort
void intercala (int p, int q, int r, int v[]) {
  int i, j, k;
  int w[100000];

  i = p; 
  j = q;
  k = 0;

  while (i < q && j <= r) {
    if (v[i] <= v[j])  
      w[k++] = v[i++];
    else  
      w[k++] = v[j++];
  }
  
  while (i < q)  
    w[k++] = v[i++];

  while (j <= r)  
    w[k++] = v[j++];

  for (i = p; i <= r; i++)  
    v[i] = w[i-p];
}


void mergesort (int p, int r, int v[]) {
  if (p < r) {
    int q = (p + r)/2;
    mergesort (p, q, v);
    mergesort (q+1, r, v);
    intercala (p, q+1, r, v);
  }
}


void Quick(int vetor[], int inicio, int fim){
   
   int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) Quick(vetor, inicio, j);
   if(i < fim) Quick(vetor, i, fim);   

}


void heapsort(int *vet, int n) {
	int i, tmp;

	for (i = (n / 2); i >= 0; i--) {
		peneira(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) {
		tmp = vet[0];
		vet[0] = vet[i];
		vet[i] = tmp;
		peneira(vet, 0, i-1);
	}
}

//Funï¿½ï¿½o para usar o heapsort
void peneira(int *vet, int raiz, int fundo) {
	int pronto, filhoMax, tmp;

	pronto = 0;
	while ((raiz*2 <= fundo) && (!pronto)) {
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		}
		else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
			filhoMax = raiz * 2;
		}
		else {
			filhoMax = raiz * 2 + 1;
		}

	if (vet[raiz] < vet[filhoMax]) {
		tmp = vet[raiz];
		vet[raiz] = vet[filhoMax];
		vet[filhoMax] = tmp;
		raiz = filhoMax;
    }
	else {
      pronto = 1;
	}
  }
}

//Struct para armazenar os dados, Usado no bucketSort 
struct bucket{
    int count;
    int* valor;
};


int compareInteiro(const void* a, const void* b){
    int x = *((int*)a), y =  *((int*)b);
    if (x == y)
    {
        return 0;
    }
    else if (x < y)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

 
void bucketSort(int array[],int n){
    struct bucket buckets[3];
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        buckets[i].count = 0;
        buckets[i].valor = (int*)malloc(sizeof(int) * n);
    }
    
    for (i = 0; i < n; i++)
    {
        if (array[i] < 0)
        {
            buckets[0].valor[buckets[0].count++] = array[i];
        }
        else if (array[i] > 10)
        {
            buckets[2].valor[buckets[2].count++] = array[i];
        }
        else
        {
            buckets[1].valor[buckets[1].count++] = array[i];
        }
    }
    for (k = 0, i = 0; i < 3; i++)
    {
        
        qsort(buckets[i].valor, buckets[i].count, sizeof(int), &compareInteiro);
        for (j = 0; j < buckets[i].count; j++)
        {
            array[k + j] = buckets[i].valor[j];
        }
        k += buckets[i].count;
        free(buckets[i].valor);
    }
}
 

void selection_sort(int num[], int tam) { 
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++) 
  {
     min = i;
     for (j = (i+1); j < tam; j++) {
       if(num[j] < num[min]) 
         min = j;
     }
     if (i != min) {
       aux = num[i];
       num[i] = num[min];
       num[min] = aux;
     }
  }
}


void insertionSort(int arr[], int size){
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void BubbleSort(int vetor[], int tamanho){
	int aux, i, j;
	for(j=tamanho-1; j>=1; j--){
		for(i=0; i<j; i++){
			if(vetor[i]>vetor[i+1]){
				aux=vetor[i];
                    vetor[i]=vetor[i+1];
                    vetor[i+1]=aux;
            }
        }
    }
}


int main(){
	
	clock_t t; //variï¿½vel para armazenar tempo
	int vetor[100000]; //vetor com 100000 posiï¿½ï¿½es
	int vetor2[10000]; //vetor com 10000 posiï¿½ï¿½es
	int vetor3[1000]; //vetor com 1000 posiï¿½ï¿½es
	int vetor4[100]; //vetor com 100 posiï¿½ï¿½es
	int vetor5[10]; // vetor com 10 posiï¿½ï¿½es
	int v[10] = {9,8,6,1,5,2,6,4,0,6}, i,j,k,n;; //Usado para testar
	int v2[10] = {7, 9, 4, 3, 6, 1, 18, 2, 10, 5}; //Usado para testar
	
    
    //Manipulando arquivos txt
    FILE *file;
	file = fopen("C:\\Users\\T-GAMER\\Desktop\\Teste.csv","w"); //Cria arquivo caso nï¿½o exista
	fprintf(file,"Analise de desempenho de algoritmos de Ordenaï¿½ï¿½o em ms\n");//Escreve no arquivo
	
	//Vetor Tamanho 10
	fprintf(file,"\nVetor de Tamanho 10\n");
	printf("\nVetor de Tamanho 10\n");
    
    //BinaryinsertionSort
   
    printf("\nCriando Vetor\n");
    for(i=0;i<10;i++){    	
    	vetor5[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: BinaryInsertionSort\n");
	t = 0;
	t = clock(); //armazena tempo
    BinaryinsertionSort(vetor5, 10);
   	t = clock() - t; //tempo final - tempo inicial
   	printf("Vetor ordenado\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Milisegundos
	fprintf(file, "BinaryInsertionSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo
    
    
    //MergeSort
    printf("\nCriando Vetor\n");
    for(i=0;i<10;i++){    	
    	vetor5[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: MergeSort\n");
	t = 0;
	t = clock(); //armazena tempo
   	mergesort(0, 10-1, vetor5);
   	t = clock() - t; //tempo final - tempo inicial
   	printf("Vetor ordenado\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Milisegundos
	fprintf(file, "MergeSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo

    
    //QuickSort  
   	printf("\nCriando Vetor\n");
    for(i=0;i<10;i++){    	
    	vetor5[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: QuickSort\n");
	t = 0;
	t = clock(); //armazena tempo
   	Quick(vetor5, 0, 10-1);
   	t = clock() - t; //tempo final - tempo inicial	
   	printf("Vetor ordenado:\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Milisegundos
	fprintf(file, "QuickSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo


	//Execuï¿½ï¿½o HeapSort

	printf("\nCriando Vetor\n");
    for(i=0;i<10;i++){    	
    	vetor5[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: HeapSort\n");
	t = 0;    
	t = clock(); //armazena tempo    
	heapsort(vetor5,10);
	t = clock() - t; //tempo final - tempo inicial	
	printf("Ordenado\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	fprintf(file, "HeapSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo

	
	//Execuï¿½ï¿½o do BucketSort
	printf("\nCriando Vetor\n");
    for(i=0;i<10;i++){    	
    	vetor5[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: BucketSort\n");
	t = 0;    
	t = clock(); //armazena tempo    
	bucketSort(vetor5,10);
	t = clock() - t; //tempo final - tempo inicial
	printf("Ordenado\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	fprintf(file, "BucketSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo

	
	//Execuï¿½ï¿½o do selection_sort    
	printf("\nCriando Vetor\n");
    for(i=0;i<10;i++){    	
    	vetor5[i] = rand();//Cria um vetor com numeros aleatorios
	} 
	printf("Ordenando Vetor: SelectionSort\n");  
	t = 0; 
	t = clock(); //armazena tempo
 	selection_sort(vetor5,10);//Faz a ordenaï¿½ï¿½o do vetor
 	t = clock() - t; //tempo final - tempo inicial
	
 	printf("Vetor ordenado\n");
 	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
 	fprintf(file, "SelectionSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo


	
	
	//Execuï¿½ï¿½o do insertionSort    

	printf("\nCriando Vetor\n");
    for(i=0;i<10;i++){    	
    	vetor5[i] = rand();//Cria um vetor com numeros aleatorios
	} 
	printf("Ordenando Vetor: InsertionSort\n"); 
	t = 0;  
	t = clock(); //armazena tempo
 	insertionSort(vetor5,10);//Faz a ordenaï¿½ï¿½o do vetor
 	t = clock() - t; //tempo final - tempo inicial 
 	
	
 	printf("Vetor ordenado\n");
 	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
 	fprintf(file, "InsertionSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo
 	
	    
	//Execuï¿½ï¿½o do BubbleSort    
	printf("\nCriando Vetor\n");
    for(i=0;i<10;i++){    	
    	vetor5[i] = rand();//Cria um vetor com numeros aleatorios
	} 
	printf("Ordenando Vetor: BubbleSort\n"); 
	t = 0;  
	t = clock(); //armazena tempo
 	BubbleSort(vetor5,10);//Faz a ordenaï¿½ï¿½o do vetor
 	t = clock() - t; //tempo final - tempo inicial 
 	
 	printf("Vetor ordenado\n");
 	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
 	fprintf(file, "BubbleSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo
	
	
	//Vetor Tamanho 100
	fprintf(file,"\nVetor de Tamanho 100\n");
	printf("\nVetor de Tamanho 100\n");
    
    //BinaryinsertionSort
   
    printf("Criando Vetor\n");
    for(i=0;i<100;i++){    	
    	vetor4[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: BinaryInsertionSort\n");
	t = 0;
	t = clock(); //armazena tempo
    BinaryinsertionSort(vetor4, 100);
   	t = clock() - t; //tempo final - tempo inicial
   	printf("Vetor ordenado\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Milisegundos
	fprintf(file, "BinaryInsertionSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo
    
    
    //MergeSort
    printf("\nCriando Vetor\n");
    for(i=0;i<100;i++){    	
    	vetor4[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: MergeSort\n");
	t = 0;
	t = clock(); //armazena tempo
   	mergesort(0, 100-1, vetor4);
   	t = clock() - t; //tempo final - tempo inicial
   	printf("Vetor ordenado\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Milisegundos
	fprintf(file, "MergeSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo

    
    //QuickSort  
   	printf("\nCriando Vetor\n");
    for(i=0;i<100;i++){    	
    	vetor4[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: QuickSort\n");
	t = 0;
	t = clock(); //armazena tempo
   	Quick(vetor4, 0, 100-1);
   	t = clock() - t; //tempo final - tempo inicial	
   	printf("Vetor ordenado:\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Milisegundos
	fprintf(file, "QuickSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo


	//Execuï¿½ï¿½o HeapSort

	printf("\nCriando Vetor\n");
    for(i=0;i<100;i++){    	
    	vetor4[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: HeapSort\n"); 
	t = 0;   
	t = clock(); //armazena tempo    
	heapsort(vetor4,100);
	t = clock() - t; //tempo final - tempo inicial	
	printf("Ordenado\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	fprintf(file, "HeapSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo

	
	//Execuï¿½ï¿½o do BucketSort
	printf("\nCriando Vetor\n");
    for(i=0;i<100;i++){    	
    	vetor4[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: BucketSort\n"); 
	t = 0;   
	t = clock(); //armazena tempo    
	bucketSort(vetor4,100);
	t = clock() - t; //tempo final - tempo inicial
	printf("Ordenado\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	fprintf(file, "BucketSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo

	
	//Execuï¿½ï¿½o do selection_sort    
	printf("\nCriando Vetor\n");
    for(i=0;i<100;i++){    	
    	vetor4[i] = rand();//Cria um vetor com numeros aleatorios
	} 
	printf("Ordenando Vetor: SelectionSort\n"); 
	t = 0;  
	t = clock(); //armazena tempo
 	selection_sort(vetor4,100);//Faz a ordenaï¿½ï¿½o do vetor
 	t = clock() - t; //tempo final - tempo inicial
	
 	printf("Vetor ordenado\n");
 	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
 	fprintf(file, "SelectionSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo


	
	
	//Execuï¿½ï¿½o do insertionSort    

	printf("\nCriando Vetor\n");
    for(i=0;i<100;i++){    	
    	vetor4[i] = rand();//Cria um vetor com numeros aleatorios
	} 
	printf("Ordenando Vetor: InsertionSort\n"); 
	t = 0;  
	t = clock(); //armazena tempo
 	insertionSort(vetor4,100);//Faz a ordenaï¿½ï¿½o do vetor
 	t = clock() - t; //tempo final - tempo inicial 
 	
	
 	printf("Vetor ordenado\n");
 	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
 	fprintf(file, "InsertionSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo
 	
	    
	//Execuï¿½ï¿½o do BubbleSort    
	printf("\nCriando Vetor\n");
    for(i=0;i<100;i++){    	
    	vetor4[i] = rand();//Cria um vetor com numeros aleatorios
	} 
	printf("Ordenando Vetor: BubbleSort\n"); 
	t = 0;  
	t = clock(); //armazena tempo
 	BubbleSort(vetor4,100);//Faz a ordenaï¿½ï¿½o do vetor
 	t = clock() - t; //tempo final - tempo inicial 
 	
 	printf("Vetor ordenado\n");
 	
 	printf("Valores ordenados\n");
 	for(i = 0; i < 100; i++){
  		printf("%d ", vetor4[i]);
 	}
 	
 	printf("\nTempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
 	fprintf(file, "BubbleSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo
		
	
	
	
	//Vetor Tamanho 1000
	fprintf(file,"\nVetor de Tamanho 1000\n");
	printf("\nVetor de Tamanho 1000\n");
    
    //BinaryinsertionSort
   
    printf("Criando Vetor\n");
    for(i=0;i<1000;i++){    	
    	vetor3[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: BinaryInsertionSort\n");
	t = 0;
	t = clock(); //armazena tempo
    BinaryinsertionSort(vetor3, 1000);
   	t = clock() - t; //tempo final - tempo inicial
   	printf("Vetor ordenado\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Milisegundos
	fprintf(file, "BinaryInsertionSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo
    
    
    //MergeSort
    printf("\nCriando Vetor\n");
    for(i=0;i<1000;i++){    	
    	vetor3[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: MergeSort\n");
	t = 0;
	t = clock(); //armazena tempo
   	mergesort(0, 1000-1, vetor3);
   	t = clock() - t; //tempo final - tempo inicial
   	printf("Vetor ordenado\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Milisegundos
	fprintf(file, "MergeSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo

    
    //QuickSort  
   	printf("\nCriando Vetor\n");
    for(i=0;i<1000;i++){    	
    	vetor3[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: QuickSort\n");
	t = 0;
	t = clock(); //armazena tempo
   	Quick(vetor3, 0, 1000-1);
   	t = clock() - t; //tempo final - tempo inicial	
   	printf("Vetor ordenado:\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Milisegundos
	fprintf(file, "QuickSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo


	//Execuï¿½ï¿½o HeapSort

	printf("\nCriando Vetor\n");
    for(i=0;i<1000;i++){    	
    	vetor3[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: HeapSort\n"); 
	t = 0;   
	t = clock(); //armazena tempo    
	heapsort(vetor3,1000);
	t = clock() - t; //tempo final - tempo inicial	
	printf("Ordenado\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	fprintf(file, "HeapSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo

	
	//Execuï¿½ï¿½o do BucketSort
	printf("\nCriando Vetor\n");
    for(i=0;i<1000;i++){    	
    	vetor3[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: BucketSort\n"); 
	t = 0;   
	t = clock(); //armazena tempo    
	bucketSort(vetor3,1000);
	t = clock() - t; //tempo final - tempo inicial
	printf("Ordenado\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	fprintf(file, "BucketSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo

	
	//Execuï¿½ï¿½o do selection_sort    
	printf("\nCriando Vetor\n");
    for(i=0;i<1000;i++){    	
    	vetor3[i] = rand();//Cria um vetor com numeros aleatorios
	} 
	printf("Ordenando Vetor: SelectionSort\n");
	t = 0;   
	t = clock(); //armazena tempo
 	selection_sort(vetor3,1000);//Faz a ordenaï¿½ï¿½o do vetor
 	t = clock() - t; //tempo final - tempo inicial
	
 	printf("Vetor ordenado\n");
 	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
 	fprintf(file, "SelectionSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo


	
	
	//Execuï¿½ï¿½o do insertionSort    

	printf("\nCriando Vetor\n");
    for(i=0;i<1000;i++){    	
    	vetor3[i] = rand();//Cria um vetor com numeros aleatorios
	} 
	printf("Ordenando Vetor: InsertionSort\n"); 
	t = 0;  
	t = clock(); //armazena tempo
 	insertionSort(vetor3,1000);//Faz a ordenaï¿½ï¿½o do vetor
 	t = clock() - t; //tempo final - tempo inicial 
 	
	
 	printf("Vetor ordenado\n");
 	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
 	fprintf(file, "InsertionSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo
 	
	    
	//Execuï¿½ï¿½o do BubbleSort    
	printf("\nCriando Vetor\n");
    for(i=0;i<1000;i++){    	
    	vetor3[i] = rand();//Cria um vetor com numeros aleatorios
	} 
	printf("Ordenando Vetor: BubbleSort\n");   
	t = 0;
	t = clock(); //armazena tempo
 	BubbleSort(vetor3,1000);//Faz a ordenaï¿½ï¿½o do vetor
 	t = clock() - t; //tempo final - tempo inicial 
 	
 	printf("Vetor ordenado\n");
 	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
 	fprintf(file, "BubbleSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo
	
	
	
	//Vetor Tamanho 10000
	fprintf(file,"\nVetor de Tamanho 10000\n");
	printf("\nVetor de Tamanho 10000\n");
    
    //BinaryinsertionSort
   
    printf("Criando Vetor\n");
    for(i=0;i<10000;i++){    	
    	vetor2[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: BinaryInsertionSort\n");
	t = 0;
	t = clock(); //armazena tempo
    BinaryinsertionSort(vetor2, 10000);
   	t = clock() - t; //tempo final - tempo inicial
   	printf("Vetor ordenado\n");
   	
   	
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Milisegundos
	fprintf(file, "BinaryInsertionSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo
    
    
    //MergeSort
    printf("\nCriando Vetor\n");
    for(i=0;i<10000;i++){    	
    	vetor2[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: MergeSort\n");
	t = 0;
	t = clock(); //armazena tempo
   	mergesort(0, 10000-1, vetor2);
   	t = clock() - t; //tempo final - tempo inicial
   	printf("Vetor ordenado\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Milisegundos
	fprintf(file, "MergeSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo

    
    //QuickSort  
   	printf("\nCriando Vetor\n");
    for(i=0;i<10000;i++){    	
    	vetor2[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: QuickSort\n");
	t = 0;
	t = clock(); //armazena tempo
   	Quick(vetor2, 0, 10000-1);
   	t = clock() - t; //tempo final - tempo inicial	
   	printf("Vetor ordenado:\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Milisegundos
	fprintf(file, "QuickSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo


	//Execuï¿½ï¿½o HeapSort

	printf("\nCriando Vetor\n");
    for(i=0;i<10000;i++){    	
    	vetor2[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: HeapSort\n");  
	t = 0;  
	t = clock(); //armazena tempo    
	heapsort(vetor2,10000);
	t = clock() - t; //tempo final - tempo inicial	
	printf("Ordenado\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	fprintf(file, "HeapSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo

	
	//Execuï¿½ï¿½o do BucketSort
	printf("\nCriando Vetor\n");
    for(i=0;i<10000;i++){    	
    	vetor2[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: BucketSort\n");  
	t = 0;  
	t = clock(); //armazena tempo    
	bucketSort(vetor2,10000);
	t = clock() - t; //tempo final - tempo inicial
	printf("Ordenado\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	fprintf(file, "BucketSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo

	
	//Execuï¿½ï¿½o do selection_sort    
	printf("\nCriando Vetor\n");
    for(i=0;i<10000;i++){    	
    	vetor2[i] = rand();//Cria um vetor com numeros aleatorios
	} 
	printf("Ordenando Vetor: SelectionSort\n"); 
	t = 0;  
	t = clock(); //armazena tempo
 	selection_sort(vetor2,10000);//Faz a ordenaï¿½ï¿½o do vetor
 	t = clock() - t; //tempo final - tempo inicial
	
 	printf("Vetor ordenado\n");
 	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
 	fprintf(file, "SelectionSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo


	
	
	//Execuï¿½ï¿½o do insertionSort    

	printf("\nCriando Vetor\n");
    for(i=0;i<10000;i++){    	
    	vetor2[i] = rand();//Cria um vetor com numeros aleatorios
	} 
	printf("Ordenando Vetor: InsertionSort\n");
	t = 0;   
	t = clock(); //armazena tempo
 	insertionSort(vetor2,10000);//Faz a ordenaï¿½ï¿½o do vetor
 	t = clock() - t; //tempo final - tempo inicial 
 	
	
 	printf("Vetor ordenado\n");
 	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
 	fprintf(file, "InsertionSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo
 	
	    
	//Execuï¿½ï¿½o do BubbleSort    
	printf("\nCriando Vetor\n");
    for(i=0;i<10000;i++){    	
    	vetor2[i] = rand();//Cria um vetor com numeros aleatorios
	} 
	printf("Ordenando Vetor: BubbleSort\n");
	t = 0;   
	t = clock(); //armazena tempo
 	BubbleSort(vetor2,10000);//Faz a ordenaï¿½ï¿½o do vetor
 	t = clock() - t; //tempo final - tempo inicial 
 	
 	printf("Vetor ordenado\n");
 	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
 	fprintf(file, "BubbleSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo
	
	
	
	//Ordenando Vetor de Tamanho 100000
	fprintf(file,"\nVetor de Tamanho 100000\n");
	printf("\nVetor de Tamanho 100000\n");
    
    //BinaryinsertionSort
   
    printf("\nCriando Vetor\n");
    for(i=0;i<100000;i++){    	
    	vetor[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: BinaryInsertionSort\n");
	t = 0;
	t = clock(); //armazena tempo
    BinaryinsertionSort(vetor, 100000);
   	t = clock() - t; //tempo final - tempo inicial
   	printf("Vetor ordenado\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Milisegundos
	fprintf(file, "BinaryInsertionSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo
    
    
    //MergeSort
    printf("\nCriando Vetor\n");
    for(i=0;i<100000;i++){    	
    	vetor[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: MergeSort\n");
	t = 0;
	t = clock(); //armazena tempo
   	mergesort(0, 100000-1, vetor);
   	t = clock() - t; //tempo final - tempo inicial
   	printf("Vetor ordenado\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Milisegundos
	fprintf(file, "MergeSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo

    
    //QuickSort  
   	printf("\nCriando Vetor\n");
    for(i=0;i<100000;i++){    	
    	vetor[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: QuickSort\n");
	t = 0;
	t = clock(); //armazena tempo
   	Quick(vetor, 0, 100000-1);
   	t = clock() - t; //tempo final - tempo inicial	
   	printf("Vetor ordenado:\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Milisegundos
	fprintf(file, "QuickSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo


	//Execuï¿½ï¿½o HeapSort

	printf("\nCriando Vetor\n");
    for(i=0;i<100000;i++){    	
    	vetor[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: HeapSort\n");
	t = 0;    
	t = clock(); //armazena tempo    
	heapsort(vetor,100000);
	t = clock() - t; //tempo final - tempo inicial	
	printf("Ordenado\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	fprintf(file, "HeapSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo

	
	//Execuï¿½ï¿½o do BucketSort
	printf("\nCriando Vetor\n");
    for(i=0;i<100000;i++){    	
    	vetor[i] = rand();//Cria um vetor com numeros aleatorios
	}
	printf("Ordenando Vetor: BucketSort\n");
	t = 0;    
	t = clock(); //armazena tempo    
	bucketSort(vetor,100000);
	t = clock() - t; //tempo final - tempo inicial
	printf("Ordenado\n");
	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	fprintf(file, "BucketSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo

	
	//Execuï¿½ï¿½o do selection_sort    
	printf("\nCriando Vetor\n");
    for(i=0;i<100000;i++){    	
    	vetor[i] = rand();//Cria um vetor com numeros aleatorios
	} 
	printf("Ordenando Vetor: SelectionSort\n");
	t = 0;   
	t = clock(); //armazena tempo
 	selection_sort(vetor,100000);//Faz a ordenaï¿½ï¿½o do vetor
 	t = clock() - t; //tempo final - tempo inicial
	
 	printf("Vetor ordenado\n");
 	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
 	fprintf(file, "SelectionSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo


	
	
	//Execuï¿½ï¿½o do insertionSort    

	printf("\nCriando Vetor\n");
    for(i=0;i<100000;i++){    	
    	vetor[i] = rand();//Cria um vetor com numeros aleatorios
	} 
	printf("Ordenando Vetor: InsertionSort\n");
	t = 0;   
	t = clock(); //armazena tempo
 	insertionSort(vetor,100000);//Faz a ordenaï¿½ï¿½o do vetor
 	t = clock() - t; //tempo final - tempo inicial 
 	
	
 	printf("Vetor ordenado\n");
 	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
 	fprintf(file, "InsertionSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo
 	
	    
	//Execuï¿½ï¿½o do BubbleSort    
	printf("\nCriando Vetor\n");
    for(i=0;i<100000;i++){    	
    	vetor[i] = rand();//Cria um vetor com numeros aleatorios
	} 
	printf("Ordenando Vetor: BubbleSort\n");  
	t = 0; 
	t = clock(); //armazena tempo
 	BubbleSort(vetor,100000);//Faz a ordenaï¿½ï¿½o do vetor
 	t = clock() - t; //tempo final - tempo inicial 
 	
 	printf("Vetor ordenado\n");
 	printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
 	fprintf(file, "BubbleSort: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));//Escreve no arquivo
	fclose(file); //Fecha o arquivo
 						

 	
	system("pause");
	return 0;
	
	
}