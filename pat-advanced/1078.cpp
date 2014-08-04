#include <iostream>
#include <cmath>
using namespace std;

int isPrime(int n)
{
    if (n < 2){
        return false;
    }
    else if (n == 2){
        return true;
    }
    else{
        for (int i = 2; i <= sqrt(n); ++i){
            if (n % i == 0){
                return false;
            }
        }
    }

    return true;
}

int ceilPrime(int size)
{
    for (int i = size;; ++i){
        if (isPrime(i)){
            return i;
        }
    }
}

int isFull(bool* isOccupied, int n)
{
    for (int i = 0; i < n; ++i){
        if (isOccupied[i] == false){
            return false;
        }
    }
    return true;
}

int quadraticHash(int num, int size, int round)
{
    return (num + round * round) % size;
}

int main()
{
    int tableSize;
    int nums;
    cin >> tableSize >> nums;

    int realSize = ceilPrime(tableSize);

    bool* isOccupied = new bool[realSize];

    for (int i = 0; i < realSize; ++i){
        isOccupied[i] = false;
    }

    int num;
    bool firstnum = true;
    for (int i = 0; i < nums; ++i){
        cin >> num;
        int rounds = 0;
        
        while (true){
            if (rounds >= realSize || isFull(isOccupied, realSize)){
                cout << " -"; // cant be the first number
                break;
            }
            int position = quadraticHash(num, realSize, rounds);
            if (isOccupied[position]){
                ++rounds;
                continue;
            }
            else{
                isOccupied[position] = true;
                if (firstnum){
                    cout << position;
                    firstnum = false;
                }
                else{
                    cout << " " << position;
                }
                break;
            }
        }
    }

    delete[] isOccupied;
    system("pause");

    return 0;
}