from turtle import Screen
import time
from snake import Snake
from food import Food
from scoreboard import Score_board

def main():
    #screen setup and settings
    screen=Screen()
    screen.setup(width=600,height=600)
    screen.bgcolor('black')
    screen.title('Snake Game')
    screen.tracer(0)
    #calling snake class 
    snake=Snake()
    #calling food class
    food=Food()
    #calling scoreboard
    score=Score_board()
    #calling listen function so that we can listen what user 
    #is saying through keyboard
    screen.listen()
    screen.onkey(snake.up,'w')
    screen.onkey(snake.down,'s')
    screen.onkey(snake.right,'d')
    screen.onkey(snake.left,'a')

    #game starts
    game_is_on=True
    while game_is_on:
        screen.update()
        time.sleep(0.2)
        snake.move()

        #detect collision with food
        if snake.head.distance(food)<15:
            snake.extent()
            score.increase()
            food.refresh()

        
        #detect collision with wall
        if snake.head.xcor()>280 or snake.head.xcor()<-280 or snake.head.ycor()>280 or snake.head.ycor()<-280:
            score.reset()
            snake.reset()
            
        
        #detect collision with tail
        #if head collid with any segment in the tail
        for seg in snake.segment[1:]:
            if snake.head.distance(seg)<10:
                score.reset()
                snake.reset()
                
        

    screen.exitonclick()

if __name__=='__main__':
    main()