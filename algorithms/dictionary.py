def main():
    locations = {'North America': {'USA': ['Mountain View']}}
    #Cities to add:
    #Bangalore (India, Asia)
    #Atlanta (USA, North America)
    #Cairo (Egypt, Africa)
    #Shanghai (China, Asia)"""
    locations['Asia']={'India':['Bangalore'],'China':['Shangai']}
    locations['Asia']['India'].append('Hyderabad')
    locations['North America']['USA'].append('Atlanta')
    locations['Africa']={'Egypt':['Cairo']}
   
    
   
    print('1')
    locations['North America']['USA'].sort()
    print(*locations['North America']['USA'],sep='\n')
    print('2')
    for i in locations['Asia']:
        print('Asia-',i)

if __name__ == '__main__':
    main()