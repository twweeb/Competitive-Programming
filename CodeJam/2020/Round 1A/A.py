##
##  A.py
##  Code Jam Round 1 2020 A. Pattern Matching
##
##  Created by Lei Hsiung on 2020/04/11.
##  Copyright © 2020 Lei Hsiung. All rights reserved.
##

t = int(input())
for x in range(t):
    n = int(input())
    pattern = []

    for i in range(n):
        s = input().split("*")
        pattern.append(s)

    longest_st = 0
    longest_ed = 0
    st = ''
    ed = ''
    for i in pattern:
        if len(i[0]) > longest_st:
            longest_st = len(i[0])
            st = i[0]
        if len(i[-1]) > longest_ed:
            longest_ed = len(i[-1])
            ed = i[-1]
    solved = True
    for i in pattern:
        if not st.startswith(i[0]):
            solved = False
            break
        if not ed.endswith(i[-1]):
            solved = False
            break
    if solved:
        ans = st
        for i in pattern:
            ans += "".join(i[1:-1])
        ans += ed
        print("Case #{}: {}".format(x+1, ans))

    else:
        print ("Case #{}: *".format(x+1))
