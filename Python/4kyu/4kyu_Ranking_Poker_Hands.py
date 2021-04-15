class PokerHand(object): 

    def __init__(self, hand):
        self.h = hand
        self.cards = list()
        self.values = list()
        self.suits = list()
        self.populate(hand)
        self.ranking()

    def populate(self, hand):
        for i in hand.split():
            added = False
            c = Card(i[:1], i[1:])
            if self.cards:
                for card in self.cards:
                    if c.value <= card.value:
                        self.cards.insert(self.cards.index(card), c)
                        added = True
                        break
                if added == False:
                    self.cards.append(c)
            else:
                self.cards.append(c)

        for card in self.cards:
            self.values.append(card.value)
            self.suits.append(card.suit)

    def ranking(self):
        #CHECK FOR FOUR OF A KIND
        self.fk = False
        for i in range(2):
            if self.fk != True:
                count = self.values.count(self.values[i])
                if count == 4:
                    self.fk = True
                    self.fk_card = self.values[i]

            
        if self.fk != True:
            #CHECK FOR FLUSH
            self.flush = None
            s = self.suits.count(self.suits[0])
            if s == 5:
                self.flush = True
            else:
                self.flush = False

            # CHECK FOR STRAIGHT
            self.straight = None
            for i in range(1, 5):
                if self.straight != False:
                    if self.values[i] - 1 == self.values[i-1]:
                        self.straight = True
                    else:
                        self.straight = False
                else:
                    break

            if self.flush == False and self.straight == False:
                # CHECK FOR A FULL HOUSE
                self.full = False
                v1 = self.values[0]
                v2 = self.values[1]
                v3 = self.values[2]
                v4 = self.values[3]
                v5 = self.values[4]
                if v1 == v2 == v3 and v4 == v5:
                    self.full = True
                    self.card1 = v1
                    self.card2 = v4
                if v1 == v2 and v3 == v4 == v5 and self.full == False:
                    self.full = True
                    self.card1 = v3
                    self.card2 = v1
                
                if self.full == False:
                    # CHECK FOR THREE OF A KIND
                    self.tk = False
                    for i in range(3):
                        if self.tk != True:
                            count = self.values.count(self.values[i])
                            if count == 3:
                                self.tk = True
                                self.tk_card = self.values[i]
                    
                    if self.tk == False:
                        # CHECK FOR ONE OR TWO PAIR(S)
                        self.pairs = list()
                        self.not_paired = None
                        self.tp = False
                        self.p = False
                        c1 = self.values.count(v1)
                        c3 = self.values.count(v3)
                        c5 = self.values.count(v5)
                        if c1 == 2:
                            self.pairs.append(v1)
                            if c3 == 2:
                                self.tp = True
                                self.pairs.append(v3)
                                self.pairs.sort(reverse=True)
                                self.not_paired = v5
                            elif c5 == 2:
                                self.tp = True
                                self.pairs.append(v5)
                                self.pairs.sort(reverse=True)
                                self.not_paired = v3
                            else:
                                self.tp = False
                                self.p = True
                        elif c3 == 2:
                            self.pairs.append(v3)
                            if c5 == 2:
                                self.tp = True
                                self.pairs.append(v5)
                                self.pairs.sort(reverse=True)
                                self.not_paired = v1
                            else:
                                self.tp = False
                                self.p = True
                        elif c5 == 2:
                            self.p = True
                            self.tp = False
                            self.pairs.append(v5)
                    
                    else:
                        self.tp = False
                        self.p = False
                else:
                    self.tk = False
                    self.tp = False
                    self.p = False
            else:
                self.full = False
                self.tk = False
                self.tp = False
                self.p = False
        else:
            self.flush = False
            self.straight = False
            self.full = False
            self.tk = False
            self.tp = False
            self.p = False

    def compare_with(self, other):
        # if both players have the same hand, it's a tie (what shouldn't have happen but whatever...)
        if self.h.split() == other.h.split():
            return "Tie"

        # If i have a straight flush and he doesnt, i win
        if self.flush and self.straight:
            if other.flush == False or other.straight == False:
                return "Win"
            #Else, if we both have a straight flush, the highest win, else its a tie
            else: #elif other.flush and other.straight:
                if self.values[4] > other.values[4]:
                    return "Win"
                elif self.values[4] < other.values[4]:
                    return "Loss"
                else:
                    return "Tie"
        # Else, If he has a straight flush, i lost
        elif other.straight and other.flush:
            return "Loss"

        # If i have four of a kind and he doesnt have neither a straight flush nor a four of a kind, i win
        if self.fk:
            if other.fk == False:
                return "Win"
            else: # Else, if he also has a fk, the highest wins
                if self.fk_card < other.fk_card:
                    return "Loss"
                elif self.fk_card == other.fk_card:
                    for card in self.values:
                        if card != self.fk_card:
                            c = card
                    for card in other.values:
                        if card != other.fk_card:
                            c_bis = card
                    if c > c_bis:
                        return "Win"
                    elif c < c_bis:
                        return "Loss"
                    else:
                        return "Tie"
                else:
                    return "Win"
        elif other.fk:
            return "Loss"
        
        # if i have a full ...
        if self.full:
            if other.full == False:
                return "Win"
            else:
                if self.card1 < other.card1:
                    return "Loss"
                elif self.card1 == other.card1:
                    if self.card2 < other.card2:
                        return "Loss"
                    elif self.card2 > other.card2:
                        return "Win"
                    else:
                        return "Tie"
                else:
                    return "Win"
        elif other.full:
            return "Loss"

        # If i have a flush and he doesnt, i win
        if self.flush:
            if other.flush == False:
                return "Win"
            else: #elif other.flush
                if self.values[4] > other.values[4]:
                    return "Win"
                elif self.values[4] < other.values[4]:
                    return "Loss"
                else:
                    if self.values[3] > other.values[3]:
                        return "Win"
                    elif self.values[3] < other.values[3]:
                        return "Loss"
                    elif self.values[3] == other.values[3]:
                        if self.values[2] > other.values[2]:
                            return "Win"
                        elif self.values[2] < other.values[2]:
                            return "Loss"
                        elif self.values[2] == other.values[2]:
                            if self.values[1] > other.values[1]:
                                return "Win"
                            elif self.values[1] < other.values[1]:
                                return "Loss"
                            elif self.values[1] == other.values[1]:
                                if self.values[0] > other.values[0]:
                                    return "Win"
                                elif self.values[0] < other.values[0]:
                                    return "Loss"
                                elif self.values[0] == other.values[0]:
                                    return "Tie"
        elif other.flush:
            return "Loss"
        
        # if i have a straight and he doesnt, i win
        if self.straight:
            if other.straight == False:
                return "Win"
            else: #elif other.flush
                if self.values[4] > other.values[4]:
                    return "Win"
                elif self.values[4] < other.values[4]:
                    return "Loss"
                else:
                    return "Tie"
        elif other.straight:
            return "Loss"
        
        # If i have a three of a kind and he doesnt i win
        if self.tk:
            if other.tk == False:
                return "Win"
            else:
                if self.tk_card > other.tk_card:
                    return "Win"
                elif self.tk_card == other.tk_card:
                    if self.values[4] > other.values[4]:
                        return "Win"
                    elif self.values[4] < other.values[4]:
                        return "Loss"
                    elif self.values[4] == other.values[4]:
                        if self.values[3] > other.values[3]:
                            return "Win"
                        elif self.values[3] < other.values[3]:
                            return "Loss"
                        elif self.values[3] == other.values[3]:
                            if self.values[2] > other.values[2]:
                                return "Win"
                            elif self.values[2] < other.values[2]:
                                return "Loss"
                            elif self.values[2] == other.values[2]:
                                if self.values[1] > other.values[1]:
                                    return "Win"
                                elif self.values[1] < other.values[1]:
                                    return "Loss"
                                elif self.values[1] == other.values[1]:
                                    if self.values[0] > other.values[0]:
                                        return "Win"
                                    elif self.values[0] < other.values[0]:
                                        return "Loss"
                                    elif self.values[0] == other.values[0]:
                                        return "Tie"
                else:
                    return "Loss"
        elif other.tk:
            return "Loss"
        
        # if i have two pairs...
        if self.tp:
            if other.tp == False:
                return "Win"
            else:
                if self.pairs[0] > other.pairs[0]:
                    return "Win"
                elif self.pairs[0] < other.pairs[0]:
                    return "Loss"
                elif self.pairs[0] == other.pairs[0]:
                    if self.pairs[1] > other.pairs[1]:
                        return "Win"
                    elif self.pairs[1] < other.pairs[1]:
                        return "Loss"
                    elif self.pairs[1] == other.pairs[1]:
                        if self.not_paired > other.not_paired:
                            return "Win"
                        elif self.not_paired < other.not_paired:
                            return "Loss"
                        else:
                            return "Tie"
                    else:
                        return "Tie"
        elif other.tp:
            return "Loss"
        
        # If i have a pair
        if self.p:
            if other.p == False:
                return "Win"
            else:
                if self.pairs[0] > other.pairs[0]:
                    return "Win"
                elif self.pairs[0] < other.pairs[0]:
                    return "Loss"
                else:
                    if self.values[4] > other.values[4]:
                        return "Win"
                    elif self.values[4] < other.values[4]:
                        return "Loss"
                    elif self.values[4] == other.values[4]:
                        if self.values[3] > other.values[3]:
                            return "Win"
                        elif self.values[3] < other.values[3]:
                            return "Loss"
                        elif self.values[3] == other.values[3]:
                            if self.values[2] > other.values[2]:
                                return "Win"
                            elif self.values[2] < other.values[2]:
                                return "Loss"
                            elif self.values[2] == other.values[2]:
                                if self.values[1] > other.values[1]:
                                    return "Win"
                                elif self.values[1] < other.values[1]:
                                    return "Loss"
                                elif self.values[1] == other.values[1]:
                                    if self.values[0] > other.values[0]:
                                        return "Win"
                                    elif self.values[0] < other.values[0]:
                                        return "Loss"
                                    elif self.values[0] == other.values[0]:
                                        return "Tie"
        elif other.p:
            return "Loss"
        
        # If both have nothing, the highest card win
        if self.values[4] > other.values[4]:
            return "Win"
        elif self.values[4] < other.values[4]:
            return "Loss"
        elif self.values[4] == other.values[4]:
            if self.values[3] > other.values[3]:
                return "Win"
            elif self.values[3] < other.values[3]:
                return "Loss"
            elif self.values[3] == other.values[3]:
                if self.values[2] > other.values[2]:
                    return "Win"
                elif self.values[2] < other.values[2]:
                    return "Loss"
                elif self.values[2] == other.values[2]:
                    if self.values[1] > other.values[1]:
                        return "Win"
                    elif self.values[1] < other.values[1]:
                        return "Loss"
                    elif self.values[1] == other.values[1]:
                        if self.values[0] > other.values[0]:
                            return "Win"
                        elif self.values[0] < other.values[0]:
                            return "Loss"
                        elif self.values[0] == other.values[0]:
                            return "Tie"

        



class Card(object):
    """ A playing card. """
    RANKS = ["2", "3", "4", "5", "6", "7",
             "8", "9", "T", "J", "Q", "K", "A"]
    SUITS = ["C", "D", "H", "S"]

    def __init__(self, rank, suit):
        self.rank = rank
        self.suit = suit
    
    @property
    def value(self):
        return Card.RANKS.index(self.rank)
