def main():
    s = input()
    maxD = 0
    count = 0
    for i in range(len(s)):
        if s[i] == 'E':
            count+=1
        elif s[i] == 'L':
            count-=1
        maxD = max(maxD,count)
    print(maxD)

if __name__ == "__main__":
    main()
