#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

int main() {
    int t;
    cin >> t;

    char arr[9][9];
    while (t--) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> arr[i][j];
                arr[i][j] -= '0';        
            }
        }
            
        arr[0][0] != 9 ? arr[0][0]++ : arr[0][0]--;
        arr[3][1] != 9 ? arr[3][1]++ : arr[3][1]--;
        arr[6][2] != 9 ? arr[6][2]++ : arr[6][2]--;
        arr[1][3] != 9 ? arr[1][3]++ : arr[1][3]--;
        arr[4][4] != 9 ? arr[4][4]++ : arr[4][4]--;
        arr[7][5] != 9 ? arr[7][5]++ : arr[7][5]--;
        arr[2][6] != 9 ? arr[2][6]++ : arr[2][6]--;
        arr[5][7] != 9 ? arr[5][7]++ : arr[5][7]--;
        arr[8][8] != 9 ? arr[8][8]++ : arr[8][8]--;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << (int) arr[i][j];
            cout << '\n';
        }
        
    }

    return 0;
}