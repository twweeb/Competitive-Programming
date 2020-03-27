import random
def Gen(n):
    print(n)
    for i in range(n):
        m = int(100*random.random()%98)+2
        n = int(100*random.random()) % (m-1) + 1
        print(f'{m} {n}')
        for j in range(m):
            print(int(100*random.random())%99+1, end=' ')
        print('')
        tmp = list(range(m-1))
        for j in range(n):
            p = int(100*random.random())%(m-1)
            while p not in tmp:
                p = int(100*random.random())%(m-1)
            print(p+1, end=' ')
            tmp.remove(p)
        print('')

if __name__ == '__main__':
    Gen(1000)
