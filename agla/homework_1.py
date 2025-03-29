import numpy as np

def gaussian_elimination(matrix, vector):
    # Convert the matrix and vector to NumPy arrays
    A = np.array(matrix, dtype=float)
    b = np.array(vector, dtype=float)
    
    n = len(b)

    for i in range(n):
        # Find the pivot row
        max_row = np.argmax(np.abs(A[i:n, i])) + i
        A[[i, max_row]] = A[[max_row, i]]
        b[[i, max_row]] = b[[max_row, i]]

        pivot = A[i, i]
        if pivot == 0:
            raise ValueError("Matrix cannot be solved")
        A[i] = A[i] / pivot
        b[i] = b[i] / pivot
        
        # Eliminate the column below the pivot
        for j in range(i + 1, n):
            factor = A[j, i]
            A[j] = A[j] - factor * A[i]
            b[j] = b[j] - factor * b[i]
    
    # Perform back substitution
    x = np.zeros(n)
    for i in range(n - 1, -1, -1):
        x[i] = b[i] - np.sum(A[i, i + 1:] * x[i + 1:])
    
    return x

# Define the matrix and vector
matrix = [
    [2, 1, -1],
    [-3, -1, 2],
    [-2, 1, 2]
]
vector = [8, -11, -3]

# Solve the system of linear equations using Gaussian elimination
solution = gaussian_elimination(matrix, vector)
print("Solution:", solution)