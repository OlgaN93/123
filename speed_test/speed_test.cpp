#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    int max_num; int num_loop;

    vector <int> primes = { 2, 3 };

    cout << "Введите число, до которого следует вывести простые числа:\n" << endl;
    cin >> max_num;
    cout << endl;

    while (max_num < 2)
    {
        cout << "Введите число не меньше двух:\n" << endl;
        cin >> max_num;
        cout << endl;
    }

    if (max_num == 2)
    {
        cout << '1: 2' << endl;
        return 0;
    }

    cout << "Введите количество параллельных измерений:\n";
    cin >> num_loop;
    double sum_sec = 0;

    for (int loop = 0; loop < num_loop; loop++)
    {
        clock_t start = clock();

        for (int num = 5; num <= max_num; num++)
        {
            int sqrt_num = sqrt(num);

            for (int prime : primes)
            {
                if (prime <= sqrt_num)
                {
                    if (num % prime == 0)
                    {
                        break;
                    }
                }
                else
                {
                    primes.push_back(num);
                    break;
                }
            }
        }

        clock_t end = clock();

        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        sum_sec = sum_sec + seconds;
    }

    double avg_time = sum_sec / num_loop;

    printf("The time: %f seconds\n", avg_time); // num == 10000000 - 0.4 сек
                                                // num == 100000000 - 8,5 сек 
                                                // num == 1000000000 - 201 сек 

    return 0;
}
