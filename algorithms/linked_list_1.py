class element:
    def __init__(self,value):
        self.value=value
        self.next=None

class LinkedList(element):
    def __init__(self,head=None):
        self.head=head

    def append(self,new_element):
        current=self.head
        if self.head:
            while current.next:
                current=current.next 
            current.next=new_element
        else:
            self.head=new_element

    def get_position(self,pos):
        current=self.head
        if self.head:
            i=0
            while i<pos-1:
                current=current.next 
                i+=1
            return current
        else:
            return None

    def insert(self,new_element,pos):
        current=self.get_position(pos)
        previous=self.get_position(pos-1)
        previous.next=new_element 
        new_element.next=current

    def delete(self,value):
        temp=element(value)
        temp=None
        self.head=self.head.next


def main():
    e1=element(1)
    e2=element(2)
    e3=element(3)
    e4=element(4)
    # Start setting up a LinkedList
    ll = LinkedList(e1)
    ll.append(e2)
    ll.append(e3)

    # Test get_position
    # Should print 3
    print(ll.head.next.next.value)
    # Should also print 3
    print(ll.get_position(3).value)

    # Test insert
    ll.insert(e4,3)
    # Should print 4 now
    print(ll.get_position(3).value)

    # Test delete
    ll.delete(1)
    # Should print 2 now
    print(ll.get_position(1).value)
    # Should print 4 now
    print(ll.get_position(2).value)
    # Should print 3 now
    print(ll.get_position(3).value)



if __name__=='__main__':
    main()