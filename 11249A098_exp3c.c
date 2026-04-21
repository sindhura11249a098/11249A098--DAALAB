#include <stdio.h>
#define MAX 100
int main()
{
    int n, cap;
    int w[MAX], bin[MAX], bins = 0;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter bin capacity: ");
    scanf("%d", &cap);
    printf("Enter item weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);
    for (int i = 0; i < n; i++) {
        int best = -1;
        int minSpace = cap + 1;
        for (int j = 0; j < bins; j++) {
            if (bin[j] >= w[i] && (bin[j] - w[i]) < minSpace) {
                best = j;
                minSpace = bin[j] - w[i];
            }
        }
        if (best != -1) {
            bin[best] -= w[i];
        } else {
            bin[bins] = cap - w[i];
            bins++;
        }
    }
    printf("Best Fit: Total bins used = %d\n", bins);
    return 0;
}

