def straight(ranks):
    if len(set(ranks))==5 and (max(ranks)-min(ranks)==4):
        return True
    return False

def flush(suits):
    if len(set(suits))==1 :
        return True
    return False

def kind(n, ranks):
    for r in ranks:
        if ranks.count(r) == n:
            return r
    return None

def two_pair(ranks):
    hicard = kind(2, ranks)
    locard = kind(2, tuple(reversed(ranks)))
    
    if hicard!=locard:
        return (hicard, locard)
    return None

'''def pair(n,ranks):
    c=0
    for r in ranks:
        if ranks.count(r) == 2:
            c+=1
            if c==n:
	        return True
    return False'''

def card_ranks(hand): # arrange in descending order, j-11 , q-12, k-13, a-14
    ranks = ['--23456789TJQKA'.index(r) for r,s in hand]
    ranks.sort(reverse=True)
    return ranks

def card_suits(hand):
    return [s for r,s in hand]

def poker(hands):
    return max(hands,key=hand_rank)

def hand_rank(hand):
    ranks=card_ranks(hand)
    suits=card_suits(hand)

    if straight(ranks) and flush(hand):
      return (8, max(ranks))
    if kind(4, ranks):
      return (7, kind(4, ranks), kind(1, ranks))
    if kind(3, ranks) and kind(2, ranks):
      return (6, kind(3, ranks), kind(2, ranks))
    if flush(hand):
      return (5, ranks)
    if straight(ranks):
      return (4, max(ranks))
    if kind(3, ranks):
      return (3, kind(3, ranks), ranks)
    if two_pair(ranks):
      return (2, two_pair(ranks), ranks)
    if kind(2, ranks):
      return (1, kind(2, ranks), ranks)
    else:
      return (0, ranks)

#if __name__ == '__main__':
    #assert(straight([5,4,3,2,1])==True)
    #assert(straight([5,4,3,3,2])==False)
def examp(a,b):
    #a=('6C','7C','8C','9C','TC')
    #b=('4C','4C','4C','4C','8D')
    hands=[a,b]
    return poker(hands)