#include <iostream>
#include <ncursesw/ncurses.h>
#include <unistd.h>
#include <vector>
#include "snake.h"
#include "growth.h"
#include "poison.h"

extern int map1[30][60];
bool gameOver;
const int width = 30;
const int height = 60;
int x, y, fruitX, fruitY, score;
Direction dir;

void Draw(WINDOW* win, Snake snake, int map[30][60])
{
    werase(win);
    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            if (map[i][j] == 0)
                mvwprintw(win, i, j, " ");
            else if (map[i][j] == 1)
                mvwprintw(win, i, j, "&");
            else if (map[i][j] == 2)
                mvwprintw(win, i, j, "#");
            else if (map[i][j] == 3)
                mvwprintw(win, i, j, "O");
            else if (map[i][j] == 4)
                mvwprintw(win, i, j, "o");
            else if (map[i][j] == 5)
                mvwprintw(win, i, j, "*");
            else if (map[i][j] == 6)
                mvwprintw(win, i, j, "x");
            else
                mvwprintw(win, i, j, "$");
        }
    }
    wrefresh(win);
}

void Input(WINDOW* win, Snake snake)
{
    int c = getch();
    Direction d = snake.getDirection();
    usleep(100000);
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
    srand(time(NULL));
    curs_set(0);
    gameOver = false;
    x = width / 2;
    y = height / 2;
    Growth g = Growth();
    Poison p = Poison();
    score = 0;
    dir = Direction::UP;

    Snake snake(3, x, y, dir, map1);
    WINDOW *win1 = newwin(30, 60, 0, 0);
    g.spawnGrowth(map1);
    p.spawnPoison(map1);
    wrefresh(win1);
    int gcnt = 0;
    int pcnt = 0;
    while (!gameOver){
        Draw(win1, snake, map1);
        Input(win1, snake);
        if (map1[g.getPX()][g.getPY()] == 3){
            snake.plusbody(map1);
        }
        else if (map1[p.getPX()][p.getPY()] == 3){
            snake.minusbody(map1);
        }
        if (gcnt >= 50){
            g.despawnGrowth(map1);
            g.spawnGrowth(map1);
            gcnt = 0;
        }
        if (pcnt >= 50){
            p.despawnPoison(map1);
            p.spawnPoison(map1);
            pcnt = 0;
        }
        if (snake.getLength() < 3){
            gameOver = true;
        }
        snake.setDirection(dir);
        snake.move(map1);
        wrefresh(win1);
        gcnt++;
        pcnt++;
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
