#include <iostream>

class SparseMatrix {
private:
    int numRows, numCols;
    int* values;      // Stores non-zero values
    int* rowIndices;  // Stores row indices of non-zero values
    int* colIndices;  // Stores column indices of non-zero values
    int numElements;  // Number of non-zero elements

public:
    SparseMatrix(int m, int n) : numRows(m), numCols(n), numElements(0) {
        values = new int[100];      // You can use an initial size or dynamic resizing
        rowIndices = new int[100];
        colIndices = new int[100];
    }

    // Add a non-zero element at a specified row and column
    void insertElement(int row, int col, int value) {
        if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
            std::cerr << "Invalid row or column index" << std::endl;
            return;
        }

        values[numElements] = value;
        rowIndices[numElements] = row;
        colIndices[numElements] = col;
        numElements++;
    }

    // Retrieve the value at a specified row and column
    int getElement(int row, int col) {
        for (int i = 0; i < numElements; i++) {
            if (rowIndices[i] == row && colIndices[i] == col) {
                return values[i];
            }
        }
        return 0;  // Default value for non-existent elements
    }

    // Display the sparse matrix
    void printMatrix() {
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                std::cout << getElement(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }

    // Destructor to free dynamically allocated memory
    ~SparseMatrix() {
        delete[] values;
        delete[] rowIndices;
        delete[] colIndices;
    }
};

int main() {
    SparseMatrix sparse(3, 3);

    sparse.insertElement(0, 0, 1);
    sparse.insertElement(1, 1, 2);
    sparse.insertElement(2, 2, 3);

    std::cout << "Sparse Matrix:" << std::endl;
    sparse.printMatrix();

    return 0;
}
