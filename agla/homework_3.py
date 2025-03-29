def find_matrix_spaces(matrix):
    def transpose(matrix):
        rows = len(matrix)
        cols = len(matrix[0])
        return [[matrix[j][i] for j in range(rows)] for i in range(cols)]

    def row_reduce(matrix):
        rows = len(matrix)
        cols = len(matrix[0])
        reduced_matrix = [row[:] for row in matrix] 

        lead = 0
        for r in range(rows):
            if lead >= cols:
                break
            i = r
            while reduced_matrix[i][lead] == 0:
                i += 1
                if i == rows:
                    i = r
                    lead += 1
                    if lead == cols:
                        return reduced_matrix
                    continue

            reduced_matrix[i], reduced_matrix[r] = reduced_matrix[r], reduced_matrix[i]
            lv = reduced_matrix[r][lead]
            reduced_matrix[r] = [mrx / float(lv) for mrx in reduced_matrix[r]]
            for i in range(rows):
                if i != r:
                    lv = reduced_matrix[i][lead]
                    reduced_matrix[i] = [iv - lv * rv for iv, rv in zip(reduced_matrix[i], reduced_matrix[r])]
            lead += 1
        return reduced_matrix

    def get_basis(reduced_matrix):
        rows = len(reduced_matrix)
        cols = len(reduced_matrix[0])
        basis = []
        lead = 0
        for r in range(rows):
            if lead >= cols:
                break
            if reduced_matrix[r][lead] != 0:
                basis.append(reduced_matrix[r])
                lead += 1
            else:
                lead = cols

        return basis

    def approximate_null_space(matrix, reduced_matrix):
        rows = len(matrix)
        cols = len(matrix[0])
        basis = []
        lead = 0
        pivots = []
        for r in range(rows):
            if lead >= cols:
                break
            if reduced_matrix[r][lead] != 0:
                pivots.append(lead)
                lead += 1
            else:
                lead = cols

        free_vars = [i for i in range(cols) if i not in pivots]

        if not free_vars:
            return []

        for free_var in free_vars:
            vec = [0] * cols
            vec[free_var] = 1
            for pivot_index, pivot_col in enumerate(pivots):
                if pivot_col < free_var:
                    vec[pivot_col] = -reduced_matrix[pivot_index][free_var]

            basis.append(vec)

        return transpose(basis) 

    transposed_matrix = transpose(matrix)
    reduced_matrix = row_reduce(matrix)
    reduced_transposed = row_reduce(transposed_matrix)

    column_space = transpose(get_basis(reduced_transposed))
    row_space = get_basis(reduced_matrix)
    column_null_space = approximate_null_space(matrix, reduced_matrix)
    row_null_space = approximate_null_space(transposed_matrix, reduced_transposed)

    return {
        "column_space": column_space,
        "row_space": row_space,
        "column_null_space": column_null_space,
        "row_null_space": row_null_space,
    }

matrix = [[1, 2, 3], 
          [4, 5, 6], 
          [7, 8, 9]]
result = find_matrix_spaces(matrix)

print("Column Space:\n", result["column_space"])
print("\nRow Space:\n", result["row_space"])
print("\nColumn Null Space:\n", result["column_null_space"])
print("\nRow Null Space:\n", result["row_null_space"])
