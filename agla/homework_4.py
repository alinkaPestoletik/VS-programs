def transpose(matrix):
    return list(map(list, zip(*matrix)))

def gaussian_elimination(matrix):
    n = len(matrix)
    m = len(matrix[0])
    
    for i in range(min(n, m)):
        max_row = max(range(i, n), key=lambda r: abs(matrix[r][i]))
        matrix[i], matrix[max_row] = matrix[max_row], matrix[i]

        pivot = matrix[i][i]
        if pivot != 0:
            matrix[i] = [x / pivot for x in matrix[i]]
        for j in range(i + 1, n):
            factor = matrix[j][i]
            matrix[j] = [x - factor * y for x, y in zip(matrix[j], matrix[i])]
    
    return matrix

def back_substitution(matrix):
    n = len(matrix)
    m = len(matrix[0])
    solution = [0] * m
    
    for i in range(n - 1, -1, -1):
        if matrix[i][i] != 0:
            solution[i] = matrix[i][-1] - sum(matrix[i][j] * solution[j] for j in range(i + 1, m))
    
    return solution

def find_orthogonal_complement(matrix):
    n = len(matrix)
    m = len(matrix[0])

    augmented_matrix = [row + [0] * n for row in matrix]
    for i in range(n):
        augmented_matrix[i][m + i] = 1
    reduced_matrix = gaussian_elimination(augmented_matrix)
    orthogonal_complement = []
    for i in range(m, m + n):
        orthogonal_complement.append([row[i] for row in reduced_matrix])
    
    return orthogonal_complement

matrix = [
    [1, 2, 1],
    [2, 4, 3],
    [3, 6, 4]
]

orthogonal_complement = find_orthogonal_complement(matrix)
for i, vec in enumerate(orthogonal_complement):
    print(f"Orthogonal complement vector {i+1}: {vec}")