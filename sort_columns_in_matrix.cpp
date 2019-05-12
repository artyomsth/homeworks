#include <iostream>
#include <iomanip>
using namespace std;

uint16_t max_number_of_digits(int a, int b);

int main()
{
    srand(time(nullptr));
    int16_t from = 0, to = 0, N = 3, M = 5;
    int16_t a[N][M];
    int sum0 = 0, sum1 = 0;
    bool sorted;
    uint16_t maxwidth = 0;

    cout << "Generate random numbers in range\n";
    do
    {
        cout << "from: ";
        cin >> from;
        cout << "to: ";
        cin >> to;
    } while (from > to);

    maxwidth = max_number_of_digits(from, to);

    cout << "\nRandom-generated matrix:" << "\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            a[i][j] = from + rand() % (to - from + 1);
            cout << setw(maxwidth) << a[i][j];
        }
        cout << "\n";
    }

    do // bubble sort, XD
    {
        sorted = true;
        for (int j = 1; j < M; j++)
        {
            if (a[0][j] < a[0][j - 1])
            {
                sorted = false;
                for (int i = 0; i < N; i++) // swapping elements
                {
                    a[i][j] ^= a[i][j - 1] ^= a[i][j] ^= a[i][j - 1];
                }
            }
            else if (a[0][j] == a[0][j - 1])
            {
                sum0 = 0;
                sum1 = 0;
                for (int i = 0; i < N; i++)
                {
                    sum0 += a[i][j - 1];
                    sum1 += a[i][j];
                }
                if (sum0 > sum1)
                {
                    sorted = false;
                    for (int i = 0; i < N; i++) // swapping elements
                    {
                        a[i][j] ^= a[i][j - 1] ^= a[i][j] ^= a[i][j - 1];
                    }
                }
            }
        }
    } while (!sorted);

    cout << "\nColumns-sorted matrix:" << "\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << setw(maxwidth) << a[i][j];
        }
        cout << "\n";
    }

    return 0;
}

uint16_t max_number_of_digits(int a, int b)
{
    uint16_t k = 2;
    while ((a != 0) | (b != 0))
    {
        k += 1;
        a /= 10;
        b /= 10;
    }
    return k;
}