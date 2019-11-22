#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    for (; T > 0; T--) {
        int M, N;
        int i;
        scanf("%d%d", &M, &N);
        int *a, *b;
        a = malloc(N*sizeof(int));
        b = calloc(N, sizeof(int));
        if (a == NULL || b == NULL) {
            puts("Nedostatek paměti!");
        }
        for (; M > 0; M--) {
            for (i = 0; i < N; ++i) {
                scanf("%d", a+i);
                a[i] = a[i]^b[i];
            }
            int *swp = a;
            a = b;
            b = swp;
        }
        for (int i = 0; i < N-1; i++) {
            printf("%d ", b[i]);
        }
        printf("%d\n", b[N-1]);
        free(a);
        free(b);
    }
    return 0;
}
