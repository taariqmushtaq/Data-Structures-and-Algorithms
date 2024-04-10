#include <iostream>
#include<iostream>
#include <conio.h> // For _getch() function

using namespace std;

const int width = 20;
const int height = 10;

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Point {
    int x, y;
};

class SnakeGame {
private:
    bool gameOver;
    Direction dir;
    Point head;
    Point fruit;
    Point tail[100];
    int tailLength;
    int score;

public:
    SnakeGame() : gameOver(false), dir(RIGHT), tailLength(0), score(0) {
        head = { width / 2, height / 2 };
        fruit = { rand() % width, rand() % height };
    }

    void Draw() {
        system("cls"); // Clear the console screen

        // Draw the game board
        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0)
                    cout << "#"; // left wall
                if (i == head.y && j == head.x)
                    cout << "O"; // snake head
                else if (i == fruit.y && j == fruit.x)
                    cout << "F"; // fruit
                else {
                    bool printTail = false;
                    for (int k = 0; k < tailLength; k++) {
                        if (tail[k].x == j && tail[k].y == i) {
                            cout << "o"; // snake tail
                            printTail = true;
                        }
                    }
                    if (!printTail)
                        cout << " ";
                }

                if (j == width - 1)
                    cout << "#"; // right wall
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;
    }

    void Input() {
        if (_kbhit()) {
            switch (_getch()) {
                case 'w':
                    dir = UP;
                    break;
                case 's':
                    dir = DOWN;
                    break;
                case 'a':
                    dir = LEFT;
                    break;
                case 'd':
                    dir = RIGHT;
                    break;
                case 'x':
                    gameOver = true;
                    break;
            }
        }
    }

    void Move() {
        Point prevTail = tail[0];
        Point prev2Tail;

        tail[0] = head;

        for (int i = 1; i < tailLength; i++) {
            prev2Tail = tail[i];
            tail[i] = prevTail;
            prevTail = prev2Tail;
        }

        switch (dir) {
            case UP:
                head.y--;
                break;
            case DOWN:
                head.y++;
                break;
            case LEFT:
                head.x--;
                break;
            case RIGHT:
                head.x++;
                break;
        }

        // Check for collision with walls
        if (head.x >= width || head.x < 0 || head.y >= height || head.y < 0)
            gameOver = true;

        // Check for collision with tail
        for (int i = 0; i < tailLength; i++) {
            if (tail[i].x == head.x && tail[i].y == head.y)
                gameOver = true;
        }

        // Check for collision with fruit
        if (head.x == fruit.x && head.y == fruit.y) {
            tailLength++;
            fruit = { rand() % width, rand() % height };
        }
    }

    bool IsGameOver() const {
        return gameOver;
    }

    int GetScore() const {
        return score;
    }
};

int main() {
    SnakeGame snakeGame;

    while (!snakeGame.IsGameOver()) {
        snakeGame.Draw();
        snakeGame.Input();
        snakeGame.Move();
    }

    cout << "Game Over! Score: " << snakeGame.GetScore() << endl;

    return 0;
}
