class HashTable(object):
    def __init__(self):
        self.table = [None]*10000

    def store(self, string):
        """Input a string that's stored in 
        the table."""
        
        a=int(self.calculate_hash_value(string))
        self.table[a]=string
        

    def lookup(self, string):
        """Return the hash value if the
        string is already in the table.
        Return -1 otherwise."""
        
        if string in self.table:
            return self.calculate_hash_value(string)
        else:
            return -1

    def calculate_hash_value(self, string):
        """Helper function to calulate a
        hash value from a string."""
        '''calculation= ascii of first two characters of string concatenated in one string'''
        a=''
        a+=str(ord(string[0]))+str(ord(string[1]))
        return a
        


# Setup
def main():
    
    hash_table = HashTable()

    # Test calculate_hash_value
    # Should be 8568
    print(hash_table.calculate_hash_value('UDACITY'))

    # Test lookup edge case
    # Should be -1
    print(hash_table.lookup('UDACITY'))

    # Test store
    hash_table.store('UDACITY')
    # Should be 8568
    print(hash_table.lookup('UDACITY'))

    # Test store edge case
    hash_table.store('UDACIOUS')
    # Should be 8568
    print(hash_table.lookup('UDACIOUS'))


if __name__=='__main__':
    main()