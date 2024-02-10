#include<iostream>
using namespace std;
#define N 6

// functions declaration //
void shiftLeftRow(int arr[], int d, int n);
void FirstStepShifLeft(int** arr, int n);
void FirstStepshiftUp(int** arr, int n);
void shifLeftAllRow(int** arr, int n);
void shiftUpAllCol(int** arr, int n);
void PrintTheArray(int arr[], int n);
void PrintThe2DArray(int** arr, int n);
int** multiplyMatrix(int** arr1, int** arr2, int n);
void canonsAlgorithm(int** A, int** B, int n);
// Driver code //
int main(int argc, char* argv[])
{
    clock_t tStart = clock();
    //creating A and B matrix
    int** A = new int* [N];
    int** B = new int* [N];
    for (int i = 0; i < N; i++)
    {
        A[i] = new int[N];
        B[i] = new int[N];
    }
    //Generating random elements for A and B matrix  
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }
    //Printing Matrix A
    cout << "Printing generated Matrix A: " << endl;
    PrintThe2DArray(A, N);
    cout << endl;
    //Printing Matrix B
    cout << "Printing generated Matrix B: " << endl;
    PrintThe2DArray(B, N);
    cout << endl;
    cout << "Print final result: " << endl;
    // calling canon's function for matrix multiplication
    canonsAlgorithm(A, B, N);
    printf("Code execution time: %.5fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}

// functions implementation //

// Function to shift left an array with d displacement
void shiftLeftRow(int arr[], int d, int n)
{
    // new version of the array, will store the new shifted array
    int* temp = new int[n];
    // Keep track of the current index of the temp[] array
    int k = 0;
    // Storing the n - d elements of array arr[] to the front of temp[] array
    for (int i = d; i < n; i++) {
        temp[k] = arr[i];
        k++;
    }
    // Storing the first d elements of array arr[] into temp[] array
    for (int i = 0; i < d; i++) {
        temp[k] = arr[i];
        k++;
    }
    // Copying the elements of temp[] in arr[] to get the final shifted array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

// Function to print elements of an Array
void PrintTheArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
// Function to print elements of a Matrix
void PrintThe2DArray(int** arr, int n) {
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            cout << arr[a][b] << " ";
        }
        cout << endl;
    }
}
// Function that shift left all raws for a matrix by 1 shift
void shifLeftAllRow(int** arr, int n) {

    for (int i = 0; i < n; i++) {
        // Creating an array for each raw 
        int* row = arr[i];
        for (int j = 0; j < n; j++) {
            // Copying the matrix raws in the array 
            row[j] = arr[i][j];
        }
        // Shift raws by one.
        shiftLeftRow(row, 1, n);
        
    }
}
// Function that shift left raws of the matrix according to his order 
void FirstStepShifLeft(int** arr, int n) {

    for (int i = 0; i < n; i++) {
        // Creating an array for each raw 
        int* row = arr[i];
        for (int j = 0; j < n; j++) {
            // Copying the matrix raws in the array 
            row[j] = arr[i][j];
        }
        // Shift rows by according to the order of the raw.
        shiftLeftRow(row, i, n);
       
    }
}
// Function that shift up all column of the matrix by 1 shift 
void shiftUpAllCol(int** arr, int n)
{
    for (int i = 0; i < n; i++) {
        // Creating an array for each column 
        int* col = new int(n);
        for (int j = 0; j < n; j++) {
            // Copying the matrix columns in the array (col)
            col[j] = arr[j][i];
        }
        // Shifting the array (col) by 1.
        shiftLeftRow(col, 1, n);
        for (int j = 0; j < n; j++) {
            // Saving back the shifted array into the matrix column
            // to get the matrix column shifted up by 1.
            arr[j][i] = col[j];
        }
       
    }
}
// Function that shift left colomn of the matrix according to his order
void FirstStepshiftUp(int** arr, int n)
{
    for (int i = 0; i < n; i++) {
        // Creating an array for each column 
        int* col = new int(n);
        for (int j = 0; j < n; j++) {
            // Copying the matrix columns in the array (col)
            col[j] = arr[j][i];
        }
        // Shifting the array (col) by his column order
        shiftLeftRow(col, i, n);
        for (int j = 0; j < n; j++) {
            // Saving back the shifted array into the matrix column
            // to get the matrix column shifted up by the order of column
            arr[j][i] = col[j];
        }
        
    }
}
// Function that multiply each element in first Matrix with his corresponding element in the second matrix 
int** multiplyMatrix(int** arr1, int** arr2, int n) {
    // Creating a Matrix to save the final result
    int** result = new int* [n];
    int res;
    for (int i = 0; i < n; i++)
    {
        result[i] = new int[n];
    }
    // Multiplying each element in first Matrix with his corresponding element in the second matrix.
    // Then saving the result in the Matrix result.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = arr1[i][j] * arr2[i][j];
            result[i][j] = res;
        }
    }
    return result;
    
}

// Canon's Algorithm function.
void canonsAlgorithm(int** A, int** B, int n) {
    //////////////////// canon's Algorithm steps //////////////////////
    // Shifting left all matrix A raws by the number of the order of the matrix raw. 
    FirstStepShifLeft(A, N);
    // Shifting up all matrix B column by the number of the order of the matrix column. 
    FirstStepshiftUp(B, N);
    // Multiplying the 2 matrices after doing the shifts, storing the result in c1.
    int** C1;
    C1 = multiplyMatrix(A, B, N);
    for (int i = 0; i < n - 1; i++) {
        // Shifting left all matrix A raws by 1. 
        shifLeftAllRow(A, N);
        // Shifting up all matrix B column by 1. 
        shiftUpAllCol(B, N);
        // Multiplying the 2 matrices after doing the shifts, storing the result in c2.
        int** C2;
        C2 = multiplyMatrix(A, B, N);
        // Adding the corresponding elements in the matrices together in C1,
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                C1[i][j] += C2[i][j];
            }
        }
    }
    // printing the result C1 Matrix which represent the Matrix multiplication with Canon's Algorithm.
    PrintThe2DArray(C1, N);
}
