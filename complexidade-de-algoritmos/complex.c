// ==============================================================================

// (1)
int soma_numeros(int n) {
  int soma = 0;                  // 1 vez, c1
  for (int i = 1; i <= n; i++) { // n vezes, c2*n
    soma += i;                   // n vezes, c3*n
  }
  return soma; // 1 vez, c4
}

// t(n) = c1 + c2*n + c3*n + c4
// t(n) = (c2+c3)n + c4 + c1
// t(n) = a + bn: linear
// 1. remova os termos constantes
// t(n) = bn
// 2. remova constantes multiplicativas
// t(n) = n
// O(n) - complexidade de tempo linear

// ==============================================================================

// (2)
// algoritmo A
void algoritmo_a(int n) {
  for (int i = 0; i < n; i++) {   // n vezes, c1*n
    for (int j = 0; j < n; j++) { // c2*n*n
      printf("%d, %d\n", i, j);   // c3*n*n
    }
  }
}
// t(n) = c1*n + c2*n*n + c3*n*n
// t(n) = (c2 + c3) * n^2 + c1 * n
// t(n) = n^2 + n
// t(n) = n^2
// O(n^2) - quadratica

// algoritmo B
void algoritmo_b(int n) {
  for (int i = 0; i < n; i++) { // c1*n
    printf("%d\n", i);          // c2*n
  }
  for (int j = 0; j < n; j++) { // c3*n
    printf("%d\n", j);          // c4*n
  }
}
// t(n) = (c1 + c2 + c3 + c4) * n
// t(n) = n
// O(n) - linear

// o B é mais eficiente pois gaste menos tempo

// ==============================================================================

// (3)
int soma(int arr[], int n) {
  int soma = 0;                 // 4 bytes, c1
  for (int i = 0; i < n; i++) { // 4 bytes, c2
    soma += arr[i];             // n * 4 bytes, c3*n
  }
  return soma;
}

// s(n) = S_v + S_c + S_d
// s(n) = c1 + c2 + c3*n
// s(n) = c3*n
// O(n) - linear

// ==============================================================================

// (4)
int busca_linear(int arr[], int n, int x) {
  for (int i = 0; i < n; i++) { // pior caso c1*n, melhor caso c1*1
    if (arr[i] == x) {          // pior caso c2*n, melhor caso c2*1
      return i;                 // c3
    }
  }
  return -1; // c4
}

// t(n) = (c1 + c2) * n + c3 ou c4
// t(n) = (c1 + c2) * n
// t(n) = n
// O(n) - linear

// melhor caso
// t(n) = c1 + c2 + c3
// O(1) - constante

// um binario seira mais rapido por ser de complexidade O(log(n)) que é mais
// rapida que uma linear

// ==============================================================================

// (5)
void selection_sort(int arr[], int n) {
  int i, j, min_idx; // c1
  for (i = 0; i < n - 1; i++) { // c2*n
    min_idx = i; // c3*n
    for (j = i + 1; j < n; j++) { // c3*n^2
      if (arr[j] < arr[min_idx]) { // c4*n^2
        min_idx = j; // c5*n^2
      }
    }
    int temp = arr[min_idx]; // c6
    arr[min_idx] = arr[i]; // c7
    arr[i] = temp; // c8
  }
}

// t(n) = (c2 + c3 + c4) * n^2 (c2 + c3) * n + c1 + c6 + c7 + c8
// t(n) = (c2 + c3 + c4) * n^2 (c2 + c3) * n
// t(n) = n^2 * n
// O(n^2) - quadratica

// sim, um binario O(log(n)) ou linear O(n)
