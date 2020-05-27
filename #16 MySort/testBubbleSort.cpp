#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

void shuffle(int*, int);
void bubbleSort(int*, int);

int main()
{
    int len = 100;
    int arr[100];
    arr[0] = 0;
	for(int i = 1; i < len; i++)
		arr[i] = arr[i - 1] + rand() % 100;
        
    shuffle(arr, len);
	bubbleSort(arr, len);

    for(int i = 0; i < len; i++)
		// cout << "res[" << i <<"] = " << res[i] << endl;
        cout << "arr[" << i <<"] = " << arr[i] << endl;

    return 0;
}

void shuffle(int* arr, int len) {
	srand(time(0));
	for(int i = 0; i < len; i++){
		int randn = rand() % len;
		std::swap(arr[i], arr[randn]);
	}
}

void bubbleSort(int* arr, int len) {
    int i = 0;
    bool exchange = true;
    while (i < len && exchange) {
        exchange = false;
        for (int j = i + 1; j < len; j++) {
            if (arr[j - 1] > arr[j]) {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                exchange = true;
            }
        }
        i++;
    }
}