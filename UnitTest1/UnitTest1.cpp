// unittest.cpp
// Unit-тест до Lab_7_2_2.cpp (Тарасова А.Д., варіант 27)
// Функція SearchMinMainDiag – пошук мінімального елемента головної діагоналі

#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7_2_rec/pr7_2_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_7_2_rec
{
    // Допоміжна функція: створює матрицю n x n зі значень, заданих по рядках
    static int** MakeMatrix(const int n, const int* values)
    {
        int** a = new int* [n];
        for (int i = 0; i < n; i++)
        {
            a[i] = new int[n];
            for (int j = 0; j < n; j++)
                a[i][j] = values[i * n + j];
        }
        return a;
    }

    // Допоміжна функція: знищує матрицю n x n
    static void FreeMatrix(int** a, const int n)
    {
        for (int i = 0; i < n; i++)
            delete[] a[i];
        delete[] a;
    }

    TEST_CLASS(UnitTest_7_2_2)
    {
    public:

        // Матриця 1x1: єдиний елемент є мінімумом
        TEST_METHOD(SingleElement)
        {
            const int v[] = { 42 };
            int** a = MakeMatrix(1, v);
            Assert::AreEqual(42, SearchMinMainDiag(a, 1, 0));
            FreeMatrix(a, 1);
        }

        // Мінімум – на початку діагоналі
        TEST_METHOD(MinAtBeginning)
        {
            const int v[] = { -5, 9, 9,
                          9, 3, 9,
                          9, 9, 7 };
            int** a = MakeMatrix(3, v);
            Assert::AreEqual(-5, SearchMinMainDiag(a, 3, 0));
            FreeMatrix(a, 3);
        }

        // Мінімум – всередині діагоналі
        TEST_METHOD(MinInMiddle)
        {
            const int v[] = { 8, 1, 1, 1,
                          1, -6, 1, 1,
                          1, 1, 4, 1,
                          1, 1, 1, 10 };
            int** a = MakeMatrix(4, v);
            Assert::AreEqual(-6, SearchMinMainDiag(a, 4, 0));
            FreeMatrix(a, 4);
        }

        // Мінімум – в кінці діагоналі
        TEST_METHOD(MinAtEnd)
        {
            const int v[] = { 10, 0, 0,
                          0, 7, 0,
                          0, 0, 2 };
            int** a = MakeMatrix(3, v);
            Assert::AreEqual(2, SearchMinMainDiag(a, 3, 0));
            FreeMatrix(a, 3);
        }

        // Елементи поза головною діагоналлю (навіть менші) не впливають на результат
        TEST_METHOD(OffDiagonalIgnored)
        {
            const int v[] = { 5, -100, -100,
                          -100, 6, -100,
                          -100, -100, 7 };
            int** a = MakeMatrix(3, v);
            Assert::AreEqual(5, SearchMinMainDiag(a, 3, 0));
            FreeMatrix(a, 3);
        }

        // Побічна діагональ не враховується
        TEST_METHOD(AntiDiagonalIgnored)
        {
            const int v[] = { 4, 9, -50,
                          9, 5, 9,
                          -50, 9, 6 };
            int** a = MakeMatrix(3, v);
            Assert::AreEqual(4, SearchMinMainDiag(a, 3, 0));
            FreeMatrix(a, 3);
        }

        // Усі елементи діагоналі однакові
        TEST_METHOD(EqualDiagonal)
        {
            const int v[] = { 3, 1,
                          2, 3 };
            int** a = MakeMatrix(2, v);
            Assert::AreEqual(3, SearchMinMainDiag(a, 2, 0));
            FreeMatrix(a, 2);
        }

        // Усі елементи діагоналі від'ємні
        TEST_METHOD(AllNegative)
        {
            const int v[] = { -1, 0, 0,
                          0, -9, 0,
                          0, 0, -4 };
            int** a = MakeMatrix(3, v);
            Assert::AreEqual(-9, SearchMinMainDiag(a, 3, 0));
            FreeMatrix(a, 3);
        }
    };
}