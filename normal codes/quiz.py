class quiz:
    def __init__(self,ques,ans):
        self.score=0
        self.ques=ques
        self.ans=ans

    def question(self):
        ques=input('enter question--')
        ans=input('enter answer of the question--')
        op=quiz(ques,ans)
        ls.append(op)

    def game(self):
        for i in range(len(ls)):
            print(ls[i].ques)
            a=input('enter answer of the above question')
            if a==ls[i].ans:
                self.score+=1
            else:
                break
        print('your score--',self.score,'/',len(ls))

ls=[]
obj=quiz('','')
obj.question()
obj.question()


obj.game()
                

