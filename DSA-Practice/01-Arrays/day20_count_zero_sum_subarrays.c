#include <stdio.h>

int countZeroSumSubarrays(int arr[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == 0)
                count++;
        }
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", countZeroSumSubarrays(arr, n));

    return 0;
}