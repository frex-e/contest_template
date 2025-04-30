points = sorted(tuple(int(x) for x in input().split()) for _ in range(3))
(x1,y1), (x2,y2),(x3,y3) = points

def createQuadratic(m,c,x0):
    aa = m/2
    bb = c

    cc = -(aa * (x0 * x0) + bb * x0)

    return (aa, bb, cc)

def sub_quad(quad,x):
    (a,b,c) = quad
    return a * x * x + b * x + c

def find_zeroes(quad):
    a,b,c = quad
    sq = (b*b - 4 * a * c)**0.5
    return ((-b - sq)/(2 * a),(-b + sq)/(2 * a))

if (x1 == x2):
    mr =  abs(((y2 - y3)/(x2 - x3)) - ((y3-y1)/(x3-x1)))
    cr = -(mr * x3)
    right = createQuadratic(mr,cr,x3)
    right_a = sub_quad(right,x2)

    ans = find_zeroes((right[0],right[1],right[2] - right_a/2))
    print(ans[0])
elif (x2 == x3):
    ml = abs(((y2 - y1)/(x2 - x1)) - ((y3-y1)/(x3-x1)))
    cl = -(ml * x1)
    left = createQuadratic(ml,cl,x1)

    left_a = sub_quad(left,x2)
    ans = find_zeroes((left[0],left[1],left[2] - (left_a)/2))
    print(ans[1])

else:
    ml = abs(((y2 - y1)/(x2 - x1)) - ((y3-y1)/(x3-x1)))
    cl = -(ml * x1)
    mr =  abs(((y2 - y3)/(x2 - x3)) - ((y3-y1)/(x3-x1)))
    cr = -(mr * x3)

    left = createQuadratic(ml,cl,x1)
    right = createQuadratic(mr,cr,x3)

    left_a = sub_quad(left,x2)
    right_a = sub_quad(right,x2)

    if left_a > right_a:
        # Line is on left
        ans = find_zeroes((left[0],left[1],left[2] - (left_a + right_a)/2))
        print(ans[1])
    else:
        ans = find_zeroes((right[0],right[1],right[2] - (left_a + right_a)/2))
        print(ans[0])

    