import random

def genGifts(t = int(random.random()*100) % 100 + 1):
    print(t)
    for j in range(t):
        n = int(random.random()*1000) % 10 + 1
        print(n)
        L = [[x,y] for x in range(1,1001) for y in range(1,1001)]
        for i in range(int(random.random()*10)%10+1):
            random.shuffle(L)
        for i in range(n):
            t = L.pop()
            print(f'{t[0]} {t[1]}')

if __name__ == '__main__':
	genGifts(100)