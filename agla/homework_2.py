def inverse_matrix_gauss_jordan(matrix):
    n = len(matrix)
    if n != len(matrix[0]):
        return None  

    # Create an augmented matrix [matrix | identity]
    augmented_matrix = [row + [1 if i == j else 0 for j in range(n)] for i, row in enumerate(matrix)]

    # Perform Gauss-Jordan elimination
    for i in range(n):
        # Find pivot row
        pivot_row = i
        for j in range(i + 1, n):
            if abs(augmented_matrix[j][i]) > abs(augmented_matrix[pivot_row][i]):
                pivot_row = j

        # Swap rows
        augmented_matrix[i], augmented_matrix[pivot_row] = augmented_matrix[pivot_row], augmented_matrix[i]

        # Check for singular matrix 
        if augmented_matrix[i][i] == 0:
            return None  

        # Normalize pivot row
        pivot_element = augmented_matrix[i][i]
        for j in range(2 * n):
            augmented_matrix[i][j] /= pivot_element

        # Eliminate other rows
        for j in range(n):
            if i != j:
                factor = augmented_matrix[j][i]
                for k in range(2 * n):
                    augmented_matrix[j][k] -= factor * augmented_matrix[i][k]

    # Extract inverse matrix
    inverse = [row[n:] for row in augmented_matrix]
    return inverse

# Example 
matrix = [[1, 2, 3], [0, 1, 4], [5, 6, 0]]
inverse = inverse_matrix_gauss_jordan(matrix)

if inverse:
    print("Inverse matrix:")
    for row in inverse:
        print(row)
else:
    print("Matrix is singular (no inverse exists).")
