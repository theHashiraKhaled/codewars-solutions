def get_pins(observed):
  '''TODO: This is your job, detective!'''
  import itertools
  digit = []
  variations = []
  pins = []
  
  digit = [x for x in observed if x != " "]
      
  for elem in digit:
      if elem == "1":
          variations.append(["1", "2", "4"])
      elif elem == "2":
          variations.append(["2", "1", "3", "5"])
      elif elem == "3":
          variations.append(["3", "2", "6"])
      elif elem == "4":
          variations.append(["4", "1", "5", "7"])
      elif elem == "5":
          variations.append(["5", "2", "4", "6", "8"])
      elif elem == "6":
          variations.append(["6", "3", "5", "9"])
      elif elem == "7":
          variations.append(["7", "4", "8"])
      elif elem == "8":
          variations.append(["8", "5", "7", "9", "0"])
      elif elem == "9":
          variations.append(["9", "6", "8"])
      elif elem == "0":
          variations.append(["0", "8"])
    
  # FAIRE DEUX BOUCLE FOR QUI VONT TOURNER DANS UNE LISTE A ET B, ET APPARIER AU FUR ET A MESURE
  if len(variations) == 1:
      return variations[0]
  
  temp = list(itertools.product(*variations))
  for item in temp:
      pins.append("".join(str(e) for e in item))
  return pins
