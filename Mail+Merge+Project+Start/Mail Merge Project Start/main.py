#TODO: Create a letter using starting_letter.txt 
#for each name in invited_names.txt
#Replace the [name] placeholder with the actual name.
#Save the letters in the folder "ReadyToSend".
    
#Hint1: This method will help you: https://www.w3schools.com/python/ref_file_readlines.asp
    #Hint2: This method will also help you: https://www.w3schools.com/python/ref_string_replace.asp
        #Hint3: THis method will help you: https://www.w3schools.com/python/ref_string_strip.asp


replaces=lambda x: x.replace('\n','')
with open(r'C:\Python310\codes\Mail+Merge+Project+Start\Mail Merge Project Start\Input\Names\invited_names.txt','r') as file:
    names=list(map(replaces,file.readlines()))
    #print(names)


with open('C:\Python310\codes\Mail+Merge+Project+Start\Mail Merge Project Start\Input\Letters\starting_letter.txt') as file:
    letter_contents=file.read()
    #print(letter_contents)

for i in names:
    new_letter=letter_contents.replace('[name]',i)
    with open(f'C:\Python310\codes\Mail+Merge+Project+Start\Mail Merge Project Start\Output\ReadyToSend\letter_for_{i}',mode='w') as file:
        file.write(new_letter)