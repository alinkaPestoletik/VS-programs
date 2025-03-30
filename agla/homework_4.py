import numpy as np

def orthogonal_complement(matrix):
    if not isinstance(matrix, np.ndarray) or matrix.ndim != 2:
        return None

    # Transpose the matrix to make rows into columns
    matrix_transpose = matrix.T

    # Use QR decomposition to get an orthonormal basis of the columns
    q, r = np.linalg.qr(matrix_transpose)

    # If the rank of the matrix is less than the number of columns, the orthogonal complement exists
    if matrix.shape[1] > np.linalg.matrix_rank(matrix):
        # The columns of Q that are orthogonal to the columns of the original matrix
        # form the orthogonal complement
        complement = q[:, np.linalg.matrix_rank(matrix):]
        return complement
    else:
        return np.array([]) # Return an empty array if the orthogonal complement is zero

# Example 
matrix1 = np.array([[1, 2, 3],
                    [4, 5, 6]])

complement1 = orthogonal_complement(matrix1)

if complement1 is not None:
    print("Orthogonal complement of matrix1:")
    print(complement1)
else:
    print("Invalid input for matrix1")