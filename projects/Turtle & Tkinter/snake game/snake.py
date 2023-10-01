from turtle import Turtle

X_AXIS=[(0,0),(0,-20),(0,-40)]
MOVE_DISTANCE=20
UP=90
DOWN=270
LEFT=180
RIGHT=0

class Snake:

    def __init__(self):
        self.segment=[]
        self.create_segment()
        self.head=self.segment[0]

    def create_segment(self):
        for i in X_AXIS:
            self.add_segment(i)
            

    def add_segment(self,position):
        new_segment=Turtle(shape='square')
        new_segment.color('white')
        new_segment.penup()
        new_segment.goto(position)
        self.segment.append(new_segment)

    def extent(self):
        self.add_segment(self.segment[-1].position())

    def move(self):
        for seg in range(len(self.segment)-1,0,-1):
            x=self.segment[seg-1].xcor()
            y=self.segment[seg-1].ycor()
            self.segment[seg].goto(x,y)
        self.head.forward(MOVE_DISTANCE)

    def up(self):
        if self.head.heading()!=DOWN:
            self.head.setheading(UP)

    def down(self):
        if self.head.heading()!=UP:
            self.head.setheading(DOWN)

    def left(self):
        if self.head.heading()!=RIGHT:
            self.head.setheading(LEFT)

    def right(self):
        if self.head.heading()!=LEFT:
            self.head.setheading(RIGHT)
        
    def reset(self):
        for seg in self.segment:
            seg.goto(1000,1000)
        self.segment.clear()
        self.create_segment()
        self.head=self.segment[0]
        