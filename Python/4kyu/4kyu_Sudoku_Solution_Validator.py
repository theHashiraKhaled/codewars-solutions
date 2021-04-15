def validSolution(board): #board[i][j]
  # Rows checking
  for i in range(9):
      row_no_dp = list(set(board[i]))
      if len(row_no_dp) != 9:
          return False
  
  # Columns checking
  column = []
  for k in range(9):
      for i in range(9):
          column.append(board[i][k])
      column_no_dp = list(set(column))
      column = []
      if len(column_no_dp) != 9:
          return False
  
  # Regions checking
  region = []
  move_right = 0
  move_down = 0
  for r in range(9): # it will do 9 regions
      if r == 3:
          move_down += 3
          move_right = 0
      elif r == 6:
          move_down += 3
          move_right = 0
      for y in range(3): # Needed to change row
          for x in range(3): # Relative to the 3 int on a row
              region.append(board[y + move_down][x + move_right])
      region_no_dp = list(set(region))
      region = []
      move_right += 3
      if len(region_no_dp) != 9:
          return False

  return True
