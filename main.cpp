#include <iostream>
#include <cstdlib>
#include <conio.h>
#include<ctime>
#include "Snake.h"
#include "Food.h"

#include <windows.h>

#define WIDTH 50
#define HEIGHT 25

using namespace std;

Snake snake({ WIDTH / 2, HEIGHT / 2 }, 1);
Food food;
int score;

void board() {
    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();

       vector<COORD> snake_body = snake.get_body();

    cout << "SCORE : " << score << "\n\n";

    for (int i = 0; i < HEIGHT; i++) {
        cout << "\t\t#";
        for (int j = 0; j < WIDTH - 2; j++) {
            if (i == 0 || i == HEIGHT - 1)
                cout << "#";
            else if (i == snake_pos.Y && j == snake_pos.X)
                cout << "0";
            else if (i == food_pos.Y && j == food_pos.X )
                cout << "*";
            else 
            {
                bool isBodyPart = false;
                for(int k = 0; k < snake_body.size()-1; k++)
                {
                    if(i == snake_body[k].Y && j+1 == snake_body[k].X)
                    {
                        cout << 'o';
                        isBodyPart = true;
                        break;
                    }
                }

                if(!isBodyPart) cout << ' ';
            }
        }
        cout << "#\n";
    }
}

int main()
 {
 score = 0;
    srand(time(NULL));

    food.gen_food();

    char game_over = false;

    while (!game_over) {
        board();
        int ch;

      /*  if (kbhit()) {
            ch = getch();
            if (ch == 119 || ch == 87 || ch == 72) {
                snake.change_dir('u');
            } else if (ch == 80 || ch == 83 || ch == 115) {
                snake.change_dir('d');
            } else if (ch == 65 || ch == 97 || ch == 75) {
                snake.change_dir('l');
            } else if (ch == 77 || ch == 100 || ch == 68) {
                snake.change_dir('r');
            } else {
                cout << "Invalid input" << endl;
            }
        } */

        if(kbhit())
        {
            switch(getch())
            {
                case 'w': snake.direction('u'); break;
                case 'a': snake.direction('l'); break;
                case 's': snake.direction('d'); break;
                case 'd': snake.direction('r'); break;
            }
        }
          if(snake.collided()) game_over = true;

        if(snake.eaten(food.get_pos()))
        {
            food.gen_food();
            snake.grow();
            score = score + 10;
        }

        snake.move_snake();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }
}
