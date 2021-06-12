def palindrome(st):
    return st == st[::-1]

def solve(lst):
    for i in range(len(lst)):
        if(not palindrome(lst[i]+'a')):
            print(f"YES\n{lst[i]+'a'}")
        elif(not palindrome('a'+lst[i])):
            print(f"YES\n{'a'+lst[i]}")
        else:
            print("NO")
            
def main():
        t = int(input())
        lst = []
        for i in range(t):
            lst.append(input())
        solve(lst)

if __name__ == '__main__':
    main()