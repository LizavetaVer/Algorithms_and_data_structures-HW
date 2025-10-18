#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

/* ЗАДАЧА:
Twosum
Развернуть массив
Развернуть часть массива

Слияние 2х сортированных массива
Сортировка массива нулей и единиц
Задача флага Нидерландов

Передвинуть чётные числа вперёд
Передвинуть нули в конец
*/

// TwoSum
pair<int, int> TwoSum(const int* arr, int n, int target) {
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target)
            return {left, right};
        else if (sum < target)
            ++left;
        else
            --right;
    }
}

// Разворот всего массива
void ReverseArray(int* arr, int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        ++i; --j;
    }
}

// Разворот части массива
void ReverseSubArray(int* arr, int start, int end) {
    while (start < end) {
        int temp = arr[start]; arr[start] = arr[end]; arr[end] = temp;
        ++start; --end;
    }
}

// Слияние массивов
void MergeSortedArrays(const int* a, int na, const int* b, int nb, int* result) {
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb) {
        if (a[i] < b[j]) result[k++] = a[i++];
        else result[k++] = b[j++];
    }
    while (i < na) result[k++] = a[i++];
    while (j < nb) result[k++] = b[j++];
}

// Сортировка массива из нулей и единиц
void SortBinaryArray(int* arr, int n) {
    int zeroPos = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 0) {
            int temp = arr[i]; arr[i] = arr[zeroPos]; arr[zeroPos] = temp;
            ++zeroPos;
        }
    }
}

// Флаг Нидерландов (0, 1, 2)
void DutchFlag(int* arr, int n) {
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            int tmp = arr[low]; arr[low] = arr[mid]; arr[mid] = tmp;
            ++low; ++mid;
        } else if (arr[mid] == 1) {
            ++mid;
        } else { // 2
            int tmp = arr[mid]; arr[mid] = arr[high]; arr[high] = tmp;
            --high;
        }
    }
}

// Передвинуть чётные числа вперёд
void MoveEvenFront(int* arr, int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        while (left < right && arr[left] % 2 == 0) ++left;
        while (left < right && arr[right] % 2 != 0) --right;
        if (left < right) {
            int tmp = arr[left]; arr[left] = arr[right]; arr[right] = tmp;
            ++left; --right;
        }
    }
}

// Передвинуть нули в конец
void MoveZerosToEnd(int* arr, int n) {
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0) {
            arr[pos++] = arr[i];
        }
    }
    for (int i = pos; i < n; ++i) {
        arr[i] = 0;
    }
}

//---------------------------ТЕСТ
void PrintArray(const int* arr, int n) {
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Введите количество элементов массива:" << endl;
    cin >> n;
    int Massiv[n];

    int x;
    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> Massiv[i];
    }
    cout << "Ваш массив:" << endl;
    for (int i = 0; i < n; i++) {
        cout << Massiv[i] << " " << endl;}

    //Сортируем массив
    sort(Massiv, Massiv + n);
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; ++i)
        cout << Massiv[i] << " ";
    cout << endl;

    int target_sum;
    cout << "Введите нужную сумму для TwoSum:" << endl;
    cin >> target_sum;

    auto res = TwoSum(Massiv, n, target_sum);
    cout << "TwoSum: " << res.first << ", " << res.second << endl;

    cout << "Разворот массива:" << endl;
    ReverseArray(Massiv, n);
    PrintArray(Massiv, n);

    int ind1;
    int ind2;
    cout << "Введите индексы элементов для разворота части массива:" << endl;
    cin >> ind1 >> ind2;
    cout << "Ваш разворот части массива:" << endl;
    ReverseSubArray(Massiv, ind1, ind2);
    PrintArray(Massiv, n);

    cout << "Чётные числа вперёд:" << endl;
    MoveEvenFront(Massiv, n);
    PrintArray(Massiv, n);

    int y;
    cout << "Введите количество элементов массива с нулями:" << endl;
    cin >> y;
    int nulARR[y];
    cout << "Введите массив с нулями:" << endl;
    for ( int i = 0; i < 0; i++) {cin >> nulARR[i];}
    cout << "Ваш массив:" << endl;
    for ( int i = 0; i < 0; i++) {cout << nulARR[i] << " " << endl;}
    DutchFlag(nulARR, y);
    PrintArray(nulARR, y);

    cout << "Нули в конец:" << endl;
    MoveZerosToEnd(nulARR, y);
    PrintArray(nulARR, y);

    int e;
    cout << "Введите количество элементов массива из нулей и единиц:" << endl;
    cin >> e;
    int binARR[e];
    cout << "Введите массив из нулей и единиц:" << endl;
    for ( int i = 0; i < 0; i++) {
        cin >> binARR[i];
    }
    cout << "Ваш массив:" << endl;
    for ( int i = 0; i < 0; i++) {cout << binARR[i] << " " << endl;}
    DutchFlag(binARR, e);
    PrintArray(binARR, e);

    SortBinaryArray(binARR, e);
    PrintArray(binARR, e);

    return 0;
}


