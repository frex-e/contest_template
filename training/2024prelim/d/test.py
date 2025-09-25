#!/usr/bin/env python3
import sys
from itertools import permutations

# ---------- crash checking ----------
def valid_order(T, order, L, G):
    """
    T: list of lap times for the chosen K cars (ints)
    order: permutation of indices (0..K-1), order[p] = car put at time p*G
    L: laps
    G: gap
    """
    K = len(T)
    # start times for each car i
    start = [None]*K
    # order[p] is car index at slot p -> that car starts at p*G
    for p, car in enumerate(order):
        start[car] = p * G

    # First car is the one at slot 0. Must finish first lap after last placement.
    first_car = order[0]
    if (K-1)*G >= T[first_car]:
        return False

    # For each pair of cars (i, j), check all lap pairs for crash condition.
    # A crash happens if some lap of i starts AFTER some lap of j, but finishes
    # before or at the same time as j's corresponding lap finishes.
    for i in range(K):
        si, Ti = start[i], T[i]
        # precompute lap start/end times for i
        i_lap_start = [si + m*Ti for m in range(L)]           # m = 0..L-1
        i_lap_end   = [si + (m+1)*Ti for m in range(L)]       # m = 0..L-1
        for j in range(K):
            if i == j: 
                continue
            sj, Tj = start[j], T[j]
            j_lap_start = [sj + n*Tj for n in range(L)]
            j_lap_end   = [sj + (n+1)*Tj for n in range(L)]
            # brute-force all lap pairs
            for m in range(L):
                si_m = i_lap_start[m]
                ei_m = i_lap_end[m]
                # Only those j-laps that started before si_m could be "ahead"
                # but we brute-force anyway for clarity.
                for n in range(L):
                    sj_n = j_lap_start[n]
                    ej_n = j_lap_end[n]
                    # "started a lap after Q did" => strict >
                    # "finish before or at the same time" => <=
                    if si_m > sj_n and ei_m <= ej_n:
                        return False
    return True

# ---------- search K with brute force ----------
def max_cars_bruteforce(L, G, T_all):
    """
    Returns the maximum K satisfying constraints using brute force over permutations
    of the K fastest cars. Exponential in K.
    """
    R = len(T_all)
    # Sort cars by lap time ascending (fastest first)
    T_sorted = sorted(T_all)

    # Try K from R down to 1; stop at first feasible
    for K in range(R, 0, -1):
        T = T_sorted[:K]
        # Quick necessary condition: there exists some car that can be first
        # i.e., max(T) > (K-1)*G. If not, skip without permuting.
        if max(T) <= (K-1)*G:
            continue

        # Permute assignment of cars to slots 0..K-1
        # Small pruning: only try cars with T > (K-1)*G in slot 0.
        candidates_first = [i for i in range(K) if T[i] > (K-1)*G]
        if not candidates_first:
            continue

        idxs = list(range(K))
        # Place a valid first car, then permute the rest
        for i0 in candidates_first:
            rest = [i for i in idxs if i != i0]
            for tail in permutations(rest):
                order = (i0,) + tail
                if valid_order(T, order, L, G):
                    return K
    return 0

def main():
    import sys
    input = sys.stdin.readline
    L, G, R = map(int, input().split())
    T_all = [int(input()) for _ in range(R)]
    ans = max_cars_bruteforce(L, G, T_all)
    print(ans)


if __name__ == "__main__":
    main()
