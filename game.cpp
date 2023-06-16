#include <iostream>
#include <ncursesw/ncurses.h>
#include <unistd.h>
#include <vector>
#include "snake.h"

extern int map1[30][60];
bool gameOver;
const int width = 30;
const int height = 60;
int x, y, fruitX, fruitY, score;
Direction dir;

void Draw(WINDOW* win, Snake snake)
{
    werase(win);
    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            if (map1[i][j] == 1)
                mvwprintw(win, i, j, "&");
            else if (map1[i][j] == 0)
                mvwprintw(win, i, j, " ");
            else{
                mvwprintw(win, i, j, "#");
            }
        }
    }
    vector<pair<int, int>> sbody = snake.getBody();
        auto it = sbody.begin();
        for (; it != sbody.end(); it++){
            mvwaddch(win, (*it).first, (*it).second, 'O');
        }
    wrefresh(win);
}

void Input(WINDOW* win, Snake snake)
{
    halfdelay(1);
    int c = getch();
    Direction d = snake.getDirection();
    switch (c)
    {
    case KEY_LEFT:
        if (d != Direction::LEFT && d != Direction::RIGHT){
            dir = Direction::LEFT;
        }
        else if (d == Direction::RIGHT){
            gameOver = true;
        }
        break;
    case KEY_RIGHT:
        if (d != Direction::LEFT && d != Direction::RIGHT){
            dir = Direction::RIGHT;
        }
        else if (d == Direction::LEFT){
            gameOver = true;
        }
        break;
    case KEY_UP:
        if (d != Direction::UP && d != Direction::DOWN){
             dir = Direction::UP;
        }
        else if (d == Direction::DOWN){
            gameOver = true;
        }
        break;
    case KEY_DOWN:
        if (d != Direction::UP && d != Direction::DOWN){
            dir = Direction::DOWN;
        }
        else if (d == Direction::UP){
            gameOver = true;
        }
        break;
    case 113: // 'q' key
        gameOver = true;
        break;
    default:
        break;
    }
}


void game(){
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    timeout(100);
    curs_set(0);
    gameOver = false;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    dir = Direction::UP;

    Snake snake(3, x, y, dir);
    WINDOW *win1 = newwin(30, 60, 0, 0);
    wrefresh(win1);
    while (!gameOver){
        Draw(win1, snake);
        Input(win1, snake);
        snake.setDirection(dir);
        snake.move();
        wrefresh(win1);
        usleep(100000);
    }
}

int main()
{
    game();

    endwin();
    std::cout << "Game Over" << std::endl;
    std::cout << "Your Score: " << score << std::endl;
    return 0;
}
