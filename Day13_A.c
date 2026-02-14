#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> matrix(r, vector<int>(c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while (top <= bottom && left <= right) {

        // Traverse Top Row
        for (int j = left; j <= right; j++)
            cout << matrix[top][j] << " ";
        top++;

        // Traverse Right Column
        for (int i = top; i <= bottom; i++)
            cout << matrix[i][right] << " ";
        right--;

        // Traverse Bottom Row (if exists)
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                cout << matrix[bottom][j] << " ";
            bottom--;
        }

        // Traverse Left Column (if exists)
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                cout << matrix[i][left] << " ";
            left++;
        }
    }

    return 0;
}
