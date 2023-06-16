#include <iostream>
#include <ncursesw/ncurses.h>
#include <unistd.h>
#include <vector>
#include "snake.h"
#include "growth.h"
#include "poison.h"
#include "score.h"

extern int map[4][30][60];
bool gameOver, cleared;
const int width = 30;
const int height = 60;
int x, y, level;
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
    level = 1;
    // for (int i = 0; i < 30; i++){
    //     for (int j = 0; j < 60; j++){
    //         std::cout << map1[i][j] << std::endl;
    //     }
    // }
        initscr();
        clear();
        noecho();
        cbreak();
        keypad(stdscr, TRUE);
        nodelay(stdscr, TRUE);
        srand(time(NULL));
        curs_set(0);

        start_color();
        init_pair(1, COLOR_MAGENTA, COLOR_CYAN);
        init_pair(2, COLOR_BLUE, COLOR_BLACK);
        init_pair(3, COLOR_GREEN, COLOR_WHITE);
        init_pair(4, COLOR_YELLOW, COLOR_RED);
        gameOver = false;
        x = width / 2;
        y = height / 2;
        Growth g = Growth();
        g.makevector(map[0]);
        Poison p = Poison();
        p.makevector(map[0]);
        dir = Direction::UP;

        Snake snake(3, x, y, dir, map[0]);
        WINDOW *win1 = newwin(30, 60, 0, 0);
        Score score(6, 2, 2, 1, level);
        g.spawnGrowth(map[0]);
        p.spawnPoison(map[0]);
        //mvwprintw(win1, 0, 0, "loading");
        wrefresh(win1);
        int gcnt = 0;
        int pcnt = 0;
        while (!gameOver){
            Draw(win1, snake, map[0]);
            score.printScoreBoard();
            score.printMission();
            Input(win1, snake);
            if (map[0][g.getPX()][g.getPY()] == 3){
                snake.plusbody(map[0]);
                score.plusGrow();
            }
            else if (map[0][p.getPX()][p.getPY()] == 3){
                snake.minusbody(map[0]);
                score.plusPoison();
            }
            if (gcnt >= 50){
                g.despawnGrowth(map[0]);
                g.spawnGrowth(map[0]);
                gcnt = 0;
            }
            if (pcnt >= 50){
                p.despawnPoison(map[0]);
                p.spawnPoison(map[0]);
                pcnt = 0;
            }
            if (snake.isdead()){
                gameOver = true;
            }
            snake.setDirection(dir);
            snake.move(map[0]);
            wrefresh(win1);
            gcnt++;
            pcnt++;
        
    }
}

int main()
{
    std::cout << "game start" << std::endl;
    game();

    endwin();
    std::cout << "Game Over" << std::endl;
    return 0;
}
