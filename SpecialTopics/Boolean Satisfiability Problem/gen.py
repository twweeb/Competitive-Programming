# Generate Satisfied CNF!
import random

def generateCNF(n = int(random.random()*10000)%158 + 1, m = int(random.random()*10000)%1200 + 1):
    var = [1 for x in range(n)]
    var_false_num = int(random.random()*10000)%n + 1
    var[0:var_false_num] = [0 for x in range(var_false_num)]
    random.shuffle(var)
    clauses = []
    for i in range(m):
        clause = []
        z = int(random.random()*10000)%n + 1
        clause_size = int(random.random()*10000)%n
        clause.append(z if var[z-1] == 1 else -z)
        for j in range(clause_size):
            seed = int(random.random()*10000)
            idx = int(random.random()*10000)%n
            if idx+1 in clause or -idx-1 in clause:
                pass
            else:
                clause.append(idx+1 if seed%2 else -idx-1)
        random.shuffle(clause)
        clauses.append(clause)
    random.shuffle(clauses)
    print("p cnf {} {}".format(n,m))
    for i in clauses:
        for j in i:
            print(j, end = " ")
        print('0')
    return var

def print_ans():
    global ans
    for i in ans:
        print(i,end=' ')
    print('')

if __name__ == '__main__':
    ans = generateCNF()

