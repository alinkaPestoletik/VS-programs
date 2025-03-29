import numpy as np

def read_vectors():
    num_vectors = int(input("Enter the number of vectors: "))
    vector_length = int(input("Enter the length of vectors: "))
    
    vectors = []
    print("Enter the vectors:")
    for i in range(num_vectors):
        vector = list(map(float, input().split()))
        if len(vector) != vector_length:
            raise ValueError(f"Length of the vector {i+1} does not match the specified length.")
        vectors.append(vector)
    
    return np.array(vectors)

def gram_schmidt(vectors):
    n = len(vectors)

    orthogonal_vectors = []
    
    for i in range(n):
        v = vectors[i].astype(float)
        for j in range(i):
            v -= np.dot(vectors[i], orthogonal_vectors[j]) * orthogonal_vectors[j]
        v /= np.linalg.norm(v)
        orthogonal_vectors.append(v)
    return orthogonal_vectors

vectors = read_vectors()
orthogonal_vectors = gram_schmidt(vectors)

for i, vec in enumerate(orthogonal_vectors):
    print(vec)