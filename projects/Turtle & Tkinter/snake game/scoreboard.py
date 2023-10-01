from turtle import Turtle

ALIGN='center'
FONT=('Aerial',20,'normal')

class Score_board(Turtle):
    def __init__(self):
        super().__init__()
        self.score=0
        with open('projects\Turtle & Tkinter\snake game\highscore.txt') as file:
            self.high_score = int(file.read())
        self.hideturtle()
        self.penup()
        self.goto(0,270)
        self.color('white')
        self.update_board()
    def increase(self):
        self.score+=1
        self.update_board()

    def update_board(self):
        self.clear()
        self.write(f'Score--{self.score} High score--{self.high_score}',align=ALIGN,font=FONT)

    def reset(self):
        if self.score>self.high_score:
            self.high_score=self.score
            with open('C:\Python310\codes\projects\snake game\highscore.txt', 'w') as file:
                file.write(str(self.high_score))
        self.score=0
        self.update_board()
