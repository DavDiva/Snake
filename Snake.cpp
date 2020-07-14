#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
using namespace std;

bool GameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;



void SetUp()
{
    GameOver = false;
    x = width / 2-1;
    y = height / 2-1;
    srand(time(NULL));
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    dir = STOP;
}
void Draw()
{
    system("cls");
    for (int i = 0; i < width+1; i++)
    {
        cout << "*";
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1)
            {
                cout << "*";
            }
            if (i == y && j == x)
            {
                cout << "S";
            }
            else if (i == fruitY && j == fruitX)
            {
                cout << "F";
            }
            
            else
            {
                cout << " ";
            }
        }
        cout << endl;
        
    }



    for (int i = 0; i < width+1; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << "Score: " << score << endl;
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a': dir = LEFT;
            break;
        case 'd': dir = RIGHT;
            break;
        case 'w': dir = UP;
            break;
        case 's': dir = DOWN;
            break;
        case 'x': GameOver=true;
            break;
        }

    }
}
void Logic()
{
    switch (dir)
    {
    case LEFT: x--;
        break;
    case RIGHT: x++;
        break;
    case UP: y--;
        break;
    case DOWN:y++;
        break;
 
    }
    if (x<0 || x>width || y<0 || y>height)
    {
        GameOver = true;
    }
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        srand(time(NULL));
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}

int main()
{
    SetUp();
    while (!GameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(300);
    }
    return 0;
}

