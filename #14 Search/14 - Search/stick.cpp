#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        //输入-1退出程序
        if (n == -1)
            break;
        
        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
            
        int result = 0; 
        for (int i = n - 1; i > 1; i--) {
            int high = arr[i];
            int mid = i - 1;
            int low = 0;
            while (mid > low) {
                if (arr[low] + arr[mid] > high) {
                    result += mid-- - low;
                }
                else {
                    low++;
                }//else
            }//while
        }//for
        
        cout << result << endl;
        delete[] arr;
    }
    
   return 0;
}