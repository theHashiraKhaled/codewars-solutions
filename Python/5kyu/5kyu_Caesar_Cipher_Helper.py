class CaesarCipher(object):
    
    def __init__(self, shift):
        self.shift  = shift
        self.ALPHABET = list("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z".split())

    def encode(self, str):
        res = ""
        
        for char in str:
            if char.upper() in self.ALPHABET:
                if self.ALPHABET.index(char.upper()) + self.shift >= 26:
                    res += self.ALPHABET[self.ALPHABET.index(char.upper()) + self.shift - 26]
                else:
                    res += self.ALPHABET[self.ALPHABET.index(char.upper()) + self.shift]
            else:
                res += char
        return res

        
    def decode(self, str):
        res = ""
        for char in str:
            if char.upper() in self.ALPHABET:
                if self.ALPHABET.index(char.upper()) - self.shift < 0:
                    res += self.ALPHABET[26 + self.ALPHABET.index(char.upper()) - self.shift]
                else:
                    res += self.ALPHABET[self.ALPHABET.index(char.upper()) - self.shift]
            else:
                res += char
        return res
