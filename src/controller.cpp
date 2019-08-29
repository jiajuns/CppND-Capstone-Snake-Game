#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake, SDL_Point &food) const
{
  if (food.x > snake.head_x & snake.direction != Snake::Direction::kLeft)
      ChangeDirection(snake, Snake::Direction::kRight, Snake::Direction::kLeft);

  else if (food.x < snake.head_x & snake.direction != Snake::Direction::kRight)
      ChangeDirection(snake, Snake::Direction::kLeft, Snake::Direction::kRight);

  else if (food.y > snake.head_y & snake.direction != Snake::Direction::kUp)
      ChangeDirection(snake, Snake::Direction::kDown, Snake::Direction::kUp);

  else if (food.y < snake.head_y & snake.direction != Snake::Direction::kDown)
    ChangeDirection(snake, Snake::Direction::kUp, Snake::Direction::kDown);
}