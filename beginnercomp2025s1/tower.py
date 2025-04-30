n = int(input())

stable = True
horizontal = True
planks = []
stable = []
ans = []

for i in range(n):

    if horizontal:
        a,b,c = (input()[0] == "X" for _ in range(3))
    else:
        a,b,c = (x == "X" for x in input())
        input()
        input()

    horizontal = not horizontal

    planks.append((a,b,c))
    stable.append(b or (a and c))

    # match (a,b,c):
    #     case (True,True,True):
    #         ans += [(i + 1, 1), (i + 1, 3)]
    #         stable = True
    #     case (True, True, False):
    #         ans += [(i + 1, 1)]
    #         stable = True
    #     case (True, False,True):
    #         if stable:
    #             ans += [(i + 1,1)]
    #             stable = False
    #         stable = True
    #     case (True,False,False):
    #         stable = False
    #     case (False,True,True):
    #         ans += [(i + 1,3)]
    #         stable = True
    #     case (False,True,False):
    #         stable = True
    #     case (False,False,True):
    #         stable = False
    #     case (False, False,False):
    #         stable = False

for i in range(n):
    can_be_unstable = True and (i == 0 or stable[i - 1]) and (i == n-1 or stable[i + 1])

    match planks[i]:
        case (True,True,True):
            pass
        case (True, True, False):
            ans += [(i + 1, 1)]
        case (True, False,True):
            pass
        case (True,False,False):
            pass
        case (False,True,True):
            ans += [(i + 1,3)]
        case (False,True,False):
            pass
        case (False,False,True):
            pass
        case (False, False,False):
            pass

for i in range(n):
    can_be_unstable = True and (i == 0 or stable[i - 1]) and (i == n-1 or stable[i + 1])

    match planks[i]:
        case (True,True,True):
            if can_be_unstable:
                ans += [(i + 1, 1), (i + 1, 3)]
            else:
                ans += [(i + 1, 2)]
        case (True, True, False):
            pass
        case (True, False,True):
            pass
        case (True,False,False):
            pass
        case (False,True,True):
            pass
        case (False,True,False):
            pass
        case (False,False,True):
            pass
        case (False, False,False):
            pass

for i in range(n):
    can_be_unstable = True and (i == 0 or stable[i - 1]) and (i == n-1 or stable[i + 1])

    match planks[i]:
        case (True,True,True):
            pass
        case (True, True, False):
            pass
        case (True, False,True):
            if can_be_unstable:
                ans += [(i + 1, 1)]
                stable[i] = False
        case (True,False,False):
            pass
        case (False,True,True):
            pass
        case (False,True,False):
            pass
        case (False,False,True):
            pass
        case (False, False,False):
            pass

print(len(ans))

for a,b in ans:
    print(a,b)