#include "snake.h"

using namespace std;

Snake::Snake(int initSize=3, int initX = 15, int initY=30, Direction initDirection = Direction::RIGHT) {
        // Snake의 초기 위치와 방향을 설정하고, 몸통 초기화
        direction = initDirection;
        for (int i = 0; i < initSize; ++i) {
            body.push_back(make_pair(initX - i, initY));
          }
      }

void Snake::move(){
        pair<int, int> head = body[0];
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

        // 꼬리 부분 제거
        body.pop_back();  
      }


void Snake::setDirection(Direction newDirection){
  direction = newDirection;
}

vector<pair<int, int>> Snake::getBody() const {
        return body;
    }

Direction Snake::getDirection() const{
    return direction;
}