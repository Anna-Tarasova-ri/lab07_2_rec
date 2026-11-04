// Lab_7_2.cpp
// Тарасова А.Д.
// Лабораторна робота 7.2
// Опрацювання багатовимірних масивів рекурсивними способами.
// Варіант 27

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Рекурсивне заповнення поточного рядка випадковими числами
void CreateRow(int** a, const int rowno, const int n, const int Low,
    const int High, int colno)
{
    a[rowno][colno] = Low + rand() % (High - Low + 1);
    if (colno < n - 1)
        CreateRow(a, rowno, n, Low, High, colno + 1);
}

// Рекурсивне заповнення всіх рядків матриці
void CreateRows(int** a, const int n, const int Low, const int High, int rowno)
{
    CreateRow(a, rowno, n, Low, High, 0);
    if (rowno < n - 1)
        CreateRows(a, n, Low, High, rowno + 1);
}

// Рекурсивне виведення поточного рядка
void PrintRow(int** a, const int rowno, const int n, int colno)
{
    cout << setw(4) << a[rowno][colno];
    if (colno < n - 1)
        PrintRow(a, rowno, n, colno + 1);
    else
        cout << endl;
}

// Рекурсивне виведення всіх рядків матриці
void PrintRows(int** a, const int n, int rowno)
{
    PrintRow(a, rowno, n, 0);
    if (rowno < n - 1)
        PrintRows(a, n, rowno + 1);
    else
        cout << endl;
}

// Рекурсивний пошук мінімального елемента головної діагоналі.
// i – номер поточного елемента діагоналі (a[i][i]); початковий виклик: i = 0.
// Повертає мінімум серед елементів a[i][i], ..., a[n-1][n-1].
int SearchMinMainDiag(int** a, const int n, int i)
{
    if (i == n - 1)
        return a[i][i];

    int min = SearchMinMainDiag(a, n, i + 1);   // мінімум решти діагоналі
    return a[i][i] < min ? a[i][i] : min;
}

int main()
{
    srand((unsigned)time(NULL));

    int Low = -20;   // нижня межа діапазону значень елементів
    int High = 50;   // верхня межа діапазону значень елементів

    int n;           // розмірність квадратної матриці (n x n)
    do
    {
        cout << "n = "; cin >> n;
    } while (n <= 0);
    cout << endl;

    int** a = new int* [n];   // динамічна матриця
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    CreateRows(a, n, Low, High, 0);
    PrintRows(a, n, 0);

    cout << "min main diagonal = " << SearchMinMainDiag(a, n, 0) << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}