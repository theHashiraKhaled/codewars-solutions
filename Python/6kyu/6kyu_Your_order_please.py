def order(sentence):
  # code here
  result = []
  sentence = sentence.split()
  x = len(sentence)
  while x != 0:
      for i in sentence:
          if str(x) in i:
              result.append(i)
      x -= 1
  result.reverse()
  return " ".join(result)
