from math import log10

def main():
    t = int(input())
    for i in range(t):
        m = int(input())
        print(m - 10**(int(log10(m))))

if __name__ == "__main__":
    main()
