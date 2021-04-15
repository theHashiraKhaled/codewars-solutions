def determinant(matrix):
    return sum((-1)**(i)*j*determinant([k[:i]+k[i+1:] for k in matrix[1:]]) for i,j in enumerate(matrix[0])) if len(matrix) !=1 else matrix[0][0]
