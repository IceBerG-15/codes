from turtle import Turtle,Screen
from paddle import Paddle
from ball import Ball
from scoreboard import Scoreboard
import time

#screen setup
screen=Screen()
screen.bgcolor('black')
screen.setup(width=800,height=600)
screen.title('PONG')
screen.tracer(0)

#paddle creation
r_paddle=Paddle(350,0)
l_paddle=Paddle(-350,0)

#ball creation
ball=Ball()

#scoreboard creation
score=Scoreboard()

#telling screen to listen
screen.listen()
screen.onkey(r_paddle.go_up,'Up')
screen.onkey(r_paddle.go_down,'Down')

screen.onkey(l_paddle.go_up,'w')
screen.onkey(l_paddle.go_down,'s')

game_is_on=True

while game_is_on:
    time.sleep(ball.move_speed)
    screen.update()
    ball.move()


    #detecting collision
    if ball.ycor()>280 or ball.ycor()<-280:
        ball.bounce_y()

    #collision detection with paddle
    if ball.distance(r_paddle)<50 and ball.xcor()>320 or ball.distance(l_paddle)<50 and ball.xcor()<-320:
        ball.bounce_x()

    
    #ball miss by right paddle
    if ball.xcor()>380:
        ball.reset()
        score.l_update()

    #ball miss by left paddle
    if ball.xcor()<-380:
        ball.reset()
        score.r_update()


    #game over
    if score.l_score==5 or score.r_score==5:
        score.gameover()
        game_is_on=False
        
    

screen.exitonclick()



