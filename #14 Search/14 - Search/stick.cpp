#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

inline bool cmpr(int a, int b, int c)
{
    if (a + b > c) {
        return true;
    }
    else 
        return false;
}

int main()
{
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int result = 0;
    for (int i = 0; i < (n - 2); i++) {
        int a = arr[i];
        for (int j = i + 1; j < (n - 1); j++) {
            int b = arr[j];
            for (int k = j + 1; k < n; k++) {
                int c = arr[k];
                if (cmpr(a, b, c))
                    result++;
            }//for k
        }//for j
    }//for i
    
    cout << result << endl;
    delete[] arr;
    system("pause");
    return 0;    
}