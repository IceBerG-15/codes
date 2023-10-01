import time
from turtle import Screen
from player import Player
from car_manager import CarManager
from scoreboard import Scoreboard

screen = Screen()
screen.setup(width=600, height=600)
screen.tracer(0)

#car manager
car_manager= CarManager()

#scoreboard creation
score=Scoreboard()

#turtle creation
tom=Player()

#screen listen
screen.listen()
screen.onkey(tom.go_up,"w")


game_is_on = True
while game_is_on:
    time.sleep(0.1)
    screen.update()

    car_manager.create_car()
    car_manager.move_car()


    #successfully crossing
    if tom.finish_line():
        tom.go_to_start()
        car_manager.level_up()
        score.level_up()

    #collision detection with car
    for car in car_manager.all_cars:
        if car.distance(tom)<20:
            game_is_on=False
            score.gameover()

screen.exitonclick()
