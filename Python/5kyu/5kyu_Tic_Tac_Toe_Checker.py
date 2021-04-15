import itertools
def isSolved(board):
    # TODO: Check if the board is solved!
    board = list(itertools.chain(*board))
    
    WAYS_TO_WIN = ((0, 1, 2),
                   (3, 4, 5),
                   (6, 7, 8),
                   (0, 3, 6),
                   (1, 4, 7),
                   (2, 5, 8),
                   (0, 4, 8),
                   (2, 4, 6))
    
    for row in WAYS_TO_WIN:
        if board[row[0]] == board[row[1]] == board[row[2]] != 0:
            winner = board[row[0]]
            return winner

    if 0 not in board:
        return 0

    return -1
