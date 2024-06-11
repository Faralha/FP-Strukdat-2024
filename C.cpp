#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printEven(int arr[], int size) {
    cout << "Angka Genap:" << "\n";
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void printOdd(int arr[], int size) {
    cout << "Angka Ganjil:" << "\n";
    for (int i = size - 1; i >= 0; i--)
    {
        if (arr[i] % 2 != 0)
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

    int main()
    {
        int N;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        quickSort(arr, 0, N - 1);

        printEven(arr, N);
        printOdd(arr, N);

        return 0;
}