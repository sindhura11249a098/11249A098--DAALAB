#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int compare(const void *a, const void *b)
{
    return (*(int*)b - *(int*)a);  // Descending order
}
int main()
{
    int n, cap,i,j;
    int w[MAX], bin[MAX], bins = 0;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter bin capacity: ");
    scanf("%d", &cap);
    printf("Enter item weights:\n");
    for ( i = 0; i < n; i++)
        scanf("%d", &w[i]);
    qsort(w, n, sizeof(int), compare);
    for ( i = 0; i < n; i++) {
        int placed = 0;
        for ( j = 0; j < bins; j++) {
            if (bin[j] >= w[i]) {
                bin[j] -= w[i];
                placed = 1;
                break;
            }
        }
        if (!placed) {
            bin[bins] = cap - w[i];
            bins++;
        }
    }
    printf("First Fit Decreasing: Total bins used = %d\n", bins);
    return 0;
}

