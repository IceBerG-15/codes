def add(*args):
    print(args[1])
    '''type of args is tuple, so we can access index at given position'''
    s=0
    for n in args:
        s+=n
    return s

def calculate(n,**kwargs):
    print(kwargs)
    n+=kwargs['add']
    n*=kwargs['multiple']
    print(n)

def main():
    #print(add(2,4,5,6,8,9,6))
    calculate(2,add=3,multiple=5)

if __name__ == '__main__':
    main()