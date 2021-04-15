class RomanNumerals(object):
    @staticmethod
    def reduce(value, res):
        if value >= 1000:
            res += "M"
            value -= 1000
        elif value >= 900:
            res += "CM"
            value -= 900
        elif value >= 500:
            res += "D"
            value -= 500
        elif value >= 400:
            res += "CD"
            value -= 400
        elif value >= 100:
            res += "C"
            value -= 100
        elif value >= 90:
            res += "XC"
            value -= 90
        elif value >= 50:
            res += "L"
            value -= 50
        elif value >= 40:
            res += "XL"
            value -= 40
        elif value >= 10:
            res += "X"
            value -= 10
        elif value >= 9:
            res += "IX"
            value -= 9
        elif value >= 5:
            res += "V"
            value -= 5
        elif value >= 4:
            res += "IV"
            value -= 4
        else:
            res += "I"
            value -= 1
        return value, res

    @staticmethod
    def develop(chain, value):
        if chain[0] == "M":
            chain = chain[1:]
            value += 1000
        elif chain[0] == "C":
            if len(chain) > 1:
                if chain[1] == "M":
                    chain = chain[2:]
                    value += 900
                elif chain[1] == "D":
                    chain = chain[2:]
                    value += 400
                else:
                    chain = chain[1:]
                    value += 100
            else:
                chain = chain[1:]
                value += 100
        elif chain[0] == "D":
            chain = chain[1:]
            value += 500
        elif chain[0] == "X":
            if len(chain) > 1:
                if chain[1] == "C":
                    chain = chain[2:]
                    value += 90
                elif chain[1] == "L":
                    chain = chain[2:]
                    value += 40
                else:
                    chain = chain[1:]
                    value += 10
            else:
                chain = chain[1:]
                value += 10
        elif chain[0] == "L":
            chain = chain[1:]
            value += 50
        elif chain[0] == "I":
            if len(chain) > 1:
                if chain[1] == "X":
                    chain = chain[2:]
                    value += 9
                elif chain[1] == "V":
                    chain = chain[2:]
                    value += 4
                else:
                    chain = chain[1:]
                    value += 1
            else:
                chain = chain[1:]
                value += 1
        else:
            chain = chain[1:]
            value += 5
        return value, chain
        
    @classmethod
    def to_roman(self, value):
        res = str()
        while value != 0:
            value, res = self.reduce(value, res)
        return res

    @classmethod
    def from_roman(self, chain):
        value = int()
        while chain != "":
            value, chain = self.develop(chain, value)
        return value
