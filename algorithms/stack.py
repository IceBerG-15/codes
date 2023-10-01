class element:
    def __init__(self,value) -> None:
        self.value=value
        self.next=None 

class stacks(element):
    def __init__(self,head=None):
        self.head=head

    def push(self,new_element):
        print('push')
        current=self.head
        if self.head:
            new_element.next=self.head
            self.head=new_element
        else:
            self.head=new_element
        

    def pop(self):
        print('pop')
        if self.head:
            self.head=self.head.next
        else:
            print('NULL')
        

    def display(self):
        print('display')
        current=self.head
        if self.head:
            
            while current:
                print(current.value)    
                current=current.next    
        else:
            print('null')
        

def main():
    e1=element(1)
    e2=element(2)
    e3=element(3)
    e4=element(4)
    ll=stacks(e1)
    ll.display()
    ll.push(e2)
    ll.push(e3)
    ll.display()
    ll.pop()
    ll.display()
    ll.push(e4)
    ll.display()
    ll.pop()
    ll.display()
    ll.pop()
    ll.pop()
    ll.display()
    ll.pop()

if __name__=='__main__':
    main()