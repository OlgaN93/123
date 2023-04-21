#include <iostream>
#include <vector>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    int max_num;

    vector <int> primes = {2, 3};

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

    cout << "Простые числа" << endl;

    int i = 1;

    for (int prime : primes)
    {
        cout << i << ": " << prime << endl;
        i++;
    }

    return 0;
}


