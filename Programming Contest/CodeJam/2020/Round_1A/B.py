##
##  B.py
##  Code Jam Round 1A 2020 B. Pascal Walk
##
##  Created by Lei Hsiung on 2020/04/11.
##  Copyright © 2020 Lei Hsiung. All rights reserved.
##

t = int(input())
for x in range(t):
    goal = int(input())
    print("Case #{}:".format(x+1))
    extra_goal = 0
    cur_r = 1
    cur_c = 1
    if goal <= 30:
        for i in range(1, goal+1):
            print ("{} {}".format(i, 1))
    else:
        goal -= 30
        isRight = False
        for i in range(1,31):
            if goal & (1 << i-1):
                if isRight:
                    for j in range(i, 0, -1):
                        print ("{} {}".format(i, j))
                else:
                    for j in range(1, i+1):
                        print ("{} {}".format(i, j))
                extra_goal += 1
                isRight = ~isRight
            else:
                if isRight:
                    print ("{} {}".format(i, i))
                else:
                    print ("{} {}".format(i, 1))
        for i in range(extra_goal):
            if isRight:
                print ("{} {}".format(i+31, i+31))
            else:
                print ("{} {}".format(i+31, 1))
