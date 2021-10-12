n = int (input())
lst = []
it = 0
i = 1
while (it<1000):
    if (i%3 >0) and (str(i)[-1] != "3"):
        lst.append(i)
        it+=1
    i+=1

for i in range(n):
    ip = int (input()) -1
    print(lst[ip])