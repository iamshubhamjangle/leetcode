#include <iostream>
using namespace std;

void print(int **arr, int m, int n ) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}


int main()
{
	int n, m;
	cin >> n >> m;

	int **arr = NULL;
	arr = new int *[m];

    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                arr[i][j] = 2*(i+j);
            } else {
                arr[i][j] = 3*(i+j);
            }
        }
    }

    print(arr, n, m);  
    return 0;
}