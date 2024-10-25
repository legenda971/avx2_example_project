#include <immintrin.h>
#include <stdio.h>

int main() {
    // Initialize two arrays with 8 integers each
    int a[8] __attribute__ ((aligned (32))) = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[8] __attribute__ ((aligned (32))) = {8, 7, 6, 5, 4, 3, 2, 1};
    int c[8] __attribute__ ((aligned (32)));

    // Load data into AVX2 registers
    __m256i vec_a = _mm256_load_si256((__m256i*)a);
    __m256i vec_b = _mm256_load_si256((__m256i*)b);

    // Perform vector addition
    __m256i vec_c = _mm256_add_epi32(vec_a, vec_b);

    // Store the result back to memory
    _mm256_store_si256((__m256i*)c, vec_c);

    // Print the result
    for (int i = 0; i < 8; i++) {
        printf("%d + %d = %d\n", a[i], b[i], c[i]);
    }

    return 0;
}
