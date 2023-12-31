#include "snake.h"

using namespace std;

Snake::Snake(int initSize, int initX, int initY, Direction initDirection, int map[30][60]) {
        // Snake의 초기 위치와 방향을 설정하고, 몸통 초기화
        direction = initDirection;
        for (int i = 0; i < initSize; ++i) {
            body.push_back(make_pair(initX - i, initY));
            if (i == 0){
              map[initX- i][initY] = 3; 
            }
            else{
              map[initX- i][initY] = 4; 
          }
      }
}

Direction Snake::move(int map[30][60], Gate gt){
        pair<int, int> head = body[0];
        map[head.first][head.second] = 4;
        switch (direction) {
            case Direction::LEFT:
                body.insert(body.begin(), make_pair(head.first, head.second - 1));
                break;
            case Direction::RIGHT:
                body.insert(body.begin(), make_pair(head.first, head.second + 1));
                break;
            case Direction::UP:
                body.insert(body.begin(), make_pair(head.first - 1, head.second));
                break;
            case Direction::DOWN:
                body.insert(body.begin(), make_pair(head.first + 1, head.second));
                break;
        }

        head = body[0];
        if (map[head.first][head.second] == 2 or map[head.first][head.second] == 1){
          dead = true;
          return direction;
        }
        if (map[head.first][head.second] == 7){
          if (gt.getX1() == head.first && gt.getY1() == head.second){
            head.first = gt.getX2();
            head.second = gt.getY2();
          }
          else{
            head.first = gt.getX1();
            head.second = gt.getY1();
          }
          isgating = true;
           switch (direction) {
            case Direction::LEFT:
                if (map[head.first][head.second-1] == 1 || map[head.first][head.second-1] == 2){
                  direction = Direction::UP;
                  if (map[head.first-1][head.second] ==  1 || map[head.first-1][head.second] ==  2){
                    direction = Direction::DOWN;
                    if (map[head.first+1][head.second] == 1 || map[head.first+1][head.second] == 2){
                      direction = Direction::RIGHT;
                      break;
                      }
                    break;
                    }
                  break;
                }
                break;
            case Direction::UP:
                if (map[head.first-1][head.second] == 1 || map[head.first-1][head.second] == 2){
                  direction = Direction::RIGHT;
                  if (map[head.first][head.second+1] == 1 || map[head.first][head.second+1] == 2){
                    direction = Direction::LEFT;
                    if (map[head.first][head.second-1] == 1 || map[head.first][head.second-1] == 2){
                      direction = Direction::DOWN;
                       break;
                    }
                  break;
                }
                break;
                }
                break;
            case Direction::DOWN:
                if (map[head.first+1][head.second] == 1 || map[head.first+1][head.second] == 2){
                  direction = Direction::LEFT;
                  if (map[head.first][head.second-1] == 1 || map[head.first][head.second-1] == 2){
                      direction = Direction::RIGHT;
                      if (map[head.first][head.second+1] == 1 || map[head.first][head.second+1] == 2){
                        direction = Direction::UP;
                        break;
                      }
                     break;
                  }
                  break;
                }
                break;
            case Direction::RIGHT:
                if (map[head.first][head.second+1] == 1 || map[head.first][head.second+1] == 2){
                  direction = Direction::DOWN;
                  if (map[head.first+1][head.second] == 1 || map[head.first+1][head.second] == 2){
                    direction = Direction::UP;
                    if (map[head.first-1][head.second] == 1 || map[head.first-1][head.second] == 2){
                       direction = Direction::LEFT;
                       break;
                    }
                  break;
                  }
                  break;
                }
                break;
          }
          switch (direction) {
            case Direction::LEFT:
                head.second -= 1;
                setDirection(Direction::LEFT);
                break;
            case Direction::RIGHT:
                head.second += 1;
                setDirection(Direction::RIGHT);
                break;
            case Direction::UP:
                head.first -= 1;
                setDirection(Direction::UP);
                break;
            case Direction::DOWN:
                setDirection(Direction::DOWN);
                head.first += 1;
                break;
        }
        }

        body[0] = make_pair(head.first, head.second);
        map[head.first][head.second] = 3;

        // 꼬리 부분 제거

        pair<int, int> tail = body.back();
        map[tail.first][tail.second] = 0;
        body.pop_back();
        return direction; 
      }


void Snake::plusbody(int map[30][60]){
  pair<int, int> tail = body.back();
  switch (direction) {
            case Direction::LEFT:
                body.insert(body.end(), make_pair(tail.first, tail.second + 1));
                break;
            case Direction::RIGHT:
                body.insert(body.end(), make_pair(tail.first, tail.second - 1));
                break;
            case Direction::UP:
                body.insert(body.end(), make_pair(tail.first + 1, tail.second));
                break;
            case Direction::DOWN:
                body.insert(body.end(), make_pair(tail.first - 1, tail.second));
                break;
        }
  
  tail = body.back();
  map[tail.first][tail.second] = 3;
}

void Snake::minusbody(int map[30][60]){
  pair<int, int> tail = body.back();
  map[tail.first][tail.second] = 0;
  body.pop_back(); 
  if (body.size() < 3){
    dead = true;
  } 
}

void Snake::setDirection(Direction newDirection){
  direction = newDirection;
}

bool Snake::isdead(){
  return dead;
}

bool Snake::isgate(){
  return isgating;
}
vector<pair<int, int>> Snake::getBody() const {
        return body;
    }

Direction Snake::getDirection() const{
    return direction;
}

int Snake::getLength() const{
  return body.size();
}