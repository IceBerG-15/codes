from turtle import Turtle

FONT = ("Courier", 24, "normal")


class Scoreboard(Turtle):
    def __init__(self):
        super().__init__()
        self.hideturtle()
        self.level=1
        self.penup()
        self.goto(-290,270)
        self.show()

    def show(self):
        self.clear()
        self.write(f'LEVEL--{self.level}',align='left',font=FONT)

    def level_up(self):
        self.level+=1
        self.show()


    def gameover(self):
        self.goto(0,0)
        self.write('GAME OVER',align='center',font=FONT)
