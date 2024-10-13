#include <iostream>
#include <vector>

using namespace std;

int search(const vector<vector<int>>& mat, int x) {
    int n = mat.size(); // Get the number of rows
    if (n == 0 || mat[0].size() == 0)
        return -1; // Handle empty matrix case

    int smallest = mat[0][0], largest = mat[n - 1][mat[0].size() - 1];
    if (x < smallest || x > largest)
        return -1; // If x is out of bounds

    int i = 0, j = mat[0].size() - 1; // Start from top-right corner
    while (i < n && j >= 0) {
        if (mat[i][j] == x) {
            cout << "Element found at " << i << ", " << j << endl;
            return 1; // Element found
        }
        if (mat[i][j] > x) {
            j--; // Move left
        } else {
            i++; // Move down
        }
    }

    cout << "Element not found" << endl;
    return 0; // Element not found
}

int main() {
    int rows, cols, x;
    
    // Input matrix dimensions
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> mat(rows, vector<int>(cols));

    // Input matrix elements
    cout << "Enter the elements of the matrix (sorted row-wise and column-wise):" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> mat[i][j];
        }
    }

    // Input element to search for
    cout << "Enter the element to search: ";
    cin >> x;

    // Search for the element in the matrix
    search(mat, x);

    return 0;
}
