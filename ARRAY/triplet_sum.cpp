#include <iostream>
using namespace std;

// 1 3 -1 5 -3 8 9 -5 7 4
// sum=4 ex (1,-1,4)

int main()
{
    int arr[10] = {1, 3, -1, 5, -3, 8, 9, -5, 7, 4};
    int sum = 4;
    for (int i = 0; i < 10 - 2; i++)
    {
        for (int j = 0 + i + 1; j < 10-1; j++)
        {
            for (int k = j + 1; k < 10; k++)
            {
                if (arr[i] + arr[j]+arr[k] == sum)
                {
                    cout << "(" << arr[i] << "," << arr[j] <<","<<arr[k] <<")"
                         << ",";
                }
            }
        }
    }

    return 0;
}