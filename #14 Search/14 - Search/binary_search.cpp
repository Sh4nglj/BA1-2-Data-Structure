#include <iostream>
using namespace std;

int main()
{
    int n = 0;      //个数
    int times = 0;  //次数
    cin >> n >> times;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    while (times--) {
        int tar = 0;
        cin >> tar;

        int low = 0;
        int high = n;

        int result = 0;
        while (low <= high) {
            int mid = (low + high) / 2; 
            if (tar <= arr[mid] && tar > arr[mid - 1]) {
                cout << arr[mid] << endl;
                break;
            }
            else if (tar < arr[mid - 1]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }//else
        }//while
    }//while
    delete[] arr;
    return 0;
}//main()