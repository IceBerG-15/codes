from turtle import Turtle

class Paddle(Turtle):

    def __init__(self,x,y):
        super().__init__()
        self.shape('square')
        self.shapesize(stretch_wid=5,stretch_len=1)
        self.color('white')
        self.penup()
        self.goto(x,y)

    def go_up(self):
        y=self.ycor()+20
        self.goto(self.xcor(),y)

    def go_down(self):
        y=self.ycor()-20
        self.goto(self.xcor(),y)
