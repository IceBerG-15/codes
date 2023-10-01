
#using loop
def fibo(position):
    a=0
    b=1
    if position==0:
        print(a)
    else:
        print(a)
        print(b)
        for i in range(position-1):
            c=a+b 
            a=b
            b=c 
            print(c) 

#using recursion
def Fibonacci(n):
    if n < 0:
        print("Incorrect input")
    elif n == 0:
        return 0
    elif n == 1 or n == 2:
        return 1
    else:
        return Fibonacci(n-1) + Fibonacci(n-2)

#driver code
def main():
    fibo(9)
    fibo(1)
    print(Fibonacci(9))

if __name__ == "__main__":
    main()