#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    srand(time(nullptr));
    int16_t from, to, N = 3, M = 5;
    int16_t a[N][M];
    int sum0 = 0, sum1 = 0;
    bool sorted = false;

    cout << "Generate random numbers in range\nfrom: ";
    cin >> from;
    cout << "to: ";
    cin >> to;

    cout << "\nRandom-generated matrix:" << "\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            a[i][j] = from + rand() % (to - from + 1);
            cout << setw(3) << a[i][j];
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
            cout << setw(3) << a[i][j];
        }
        cout << "\n";
    }

    return 0;
}