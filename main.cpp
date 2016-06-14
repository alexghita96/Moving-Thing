#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <time.h>

/*
0 = Empty Space;
1 = Player;
2 = Exterior Wall;
3 = Vertical Wall;
4 = Horizontal Wall;
5 = Special Floor;
6 = Closed Vertical Door;
7 = Closed Horizontal Door;
8 = Heart;
9 = Dot;
10 = Boots;
11 = Exit Level 3
12 = Exit Level 2
13 = Exit Level 1
14 = ); -14 = (;
15 = (; -15 = );
16 = U; -16 = n;
17 = n; -17 = U;
18 = Vertical Enemy;
19 = Horizontal Enemy;
20 = New Line;
21 = SE Wall;
22 = SW Wall;
23 = NE Wall;
24 = NW Wall;
25 = N Triple Wall;
26 = S Triple Wall;
27 = E Triple Wall;
28 = W Triple Wall;
*/

int board[21][81]=
{
    {
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
    },
    {
        2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,0,0,0,0,9,3,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2
    },
    {
        2,0,0,0,21,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,26,4,4,4,4,4,22,0,21,4,4,4,4,4,4,28,0,21,
        4,4,4,4,4,4,4,4,26,4,4,4,4,7,4,4,4,4,4,4,4,4,4,26,4,4,4,4,22,0,0,2,2
    },
    {
        2,0,0,0,3,0,0,0,9,0,0,0,0,5,5,5,5,0,0,0,0,0,0,5,5,5,0,0,0,3,0,0,8,0,0,3,0,0,18,0,0,0,0,8,3,0,3,0,0,0,0,
        16,0,0,0,3,0,0,0,0,0,0,0,18,0,0,0,18,0,0,3,0,0,0,0,3,0,0,2,2
    },
    {
        2,0,0,0,3,5,5,5,5,5,5,5,5,5,18,0,5,5,5,5,5,5,5,5,18,5,5,5,5,23,4,5,5,5,5,3,0,0,0,18,0,0,0,0,3,0,3,0,0,0,0,0,0,0,0,
        3,14,0,0,0,0,0,0,0,18,0,18,0,0,0,0,0,0,0,15,3,0,0,2,2
    },
    {
        2,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,3,0,0,0,0,18,0,0,0,3,0,27,4,7,4,4,26,4,4,4,
        24,0,0,0,0,0,0,0,0,0,18,0,0,0,0,3,0,0,0,0,3,0,0,2,2
    },
    {
        2,0,0,0,3,5,5,5,5,5,5,5,5,5,0,18,5,5,5,5,5,5,5,5,0,5,5,5,5,21,4,5,5,5,5,3,0,0,0,0,0,18,0,0,3,0,3,0,0,0,0,3,0,0,0,0,
        0,0,0,0,0,0,0,23,4,4,4,4,4,4,28,0,0,0,0,3,19,0,2,2
    },
    {
        2,0,0,0,3,0,0,0,9,0,0,0,0,5,5,5,5,0,0,0,0,0,0,5,5,5,0,0,0,3,0,0,17,0,0,3,9,0,0,0,0,0,0,0,3,0,3,0,0,0,0,3,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,3,0,0,2,2
    },
    {
        2,0,0,0,23,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,26,4,4,4,4,4,4,4,4,25,4,4,4,4,4,25,4,4,4,4,4,4,4,4,24,0,27,4,7,4,4,24,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,3,0,19,2,2
    },
    {
        2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,14,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,3,0,0,2,2
    },
    {
        2,0,0,0,21,4,4,4,4,4,4,4,4,4,4,4,22,0,0,0,3,0,21,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,25,4,4,4,4,4,4,4,4,4,4,4,4,
        4,4,4,7,4,4,4,4,4,4,4,4,4,4,4,4,28,19,0,2,2
    },
    {
        2,0,0,0,3,9,0,18,0,5,5,5,0,0,0,9,3,19,0,0,3,0,3,0,0,0,0,0,0,5,5,0,18,0,0,0,0,0,18,0,0,0,0,0,0,18,0,0,0,0,0,0,0,0,0,0,0,0,0,
        18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,2,2
    },
    {
        2,0,0,0,3,0,0,0,0,5,5,5,0,18,0,0,3,0,0,19,3,0,3,0,21,4,4,22,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,15,2,2
    },
    {
        2,0,0,0,23,4,4,4,4,4,7,26,4,4,4,4,24,19,0,0,3,0,3,0,0,0,15,3,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,0,0,0,0,18,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,2,2
    },
    {
        2,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0,27,4,4,4,4,24,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,21,4,4,4,4,4,4,4,4,4,4,4,22,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,11,11
    },
    {
        2,0,0,0,21,4,4,4,4,4,4,24,0,21,4,4,4,4,4,4,24,0,3,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,18,16,0,0,0,0,0,3,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,2,2
    },
    {
        2,19,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,18,0,0,0,0,0,18,0,0,3,19,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,
        0,0,0,0,0,0,5,5,5,5,5,5,5,5,3,0,0,2,2
    },
    {
        2,0,0,19,3,0,0,26,4,4,4,4,4,25,4,4,26,4,4,4,4,4,25,4,0,0,0,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,19,3,0,0,0,0,
        0,0,0,0,0,0,0,5,5,0,9,0,9,0,0,3,0,0,2,2
    },
    {
        2,5,5,5,3,19,0,3,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,4,4,4,4,4,4,4,4,4,4,4,28,0,0,0,0,0,0,0,0,0,0,0,23,4,4,4,4,4,4,
        4,4,4,4,4,4,4,4,4,4,4,4,4,24,0,0,2,2
    },
    {
        2,0,8,0,3,14,9,3,0,0,17,0,0,21,4,4,24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,14,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,18,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2
    },
    {
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
    }
};

int i, j, lives = 15, x = 1, y = 1, special_floor = 0, boots = 0, moves = 800, victory = 0,
    moved = 0, xi, yi, board_x = 1, board_y = 1, special_floor2 = 0, prev_lives = 3, go;
char play = 0;

int t01 = 0, t02 = 0;

double dif;

int mx[] =
{
    16, 17, 18, 11, 12,  4,  6, 11, 13, 12,  4, 17, 11, 16,  3, 11,  4,  5, 16,  6, 16, 11, 15, 19, 13,
    17, 13, 11,  3,  4,  5,  4,  3,  6, 10,  8
},
my[] =
{
    1,  3,  5,  7, 13, 14, 15, 17, 17, 19, 24, 27, 32, 34, 38, 38, 39, 40, 40, 41, 44, 45, 48, 50, 51,
    54, 56, 59, 63, 64, 65, 66, 67, 76, 76, 77
},
s[] =
{
    1,  1,  1,  2,  2,  2,  2,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  2,  2,  2,  2,
    1,  2,  2,  2,  2,  2,  2,  2,  1,  1,  1
};

void print_board(int x, int y);
void move();
void button();
void output_correction(int x, int y);
void which_button(int x, int y);
void move_monster();
void set_cursor(int i);

int main (void)
{
    t01 = clock();
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord_end = {0, 31};
    system("title The Escape");
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 800, 500, TRUE);
    for(i = 0; i < 21; i++)
        for(j = 0; j < 80; j++)
        {
            if(board[i][j] == 0 || board[i][j] == -6 || board[i][j] == -7)
            {
                SetConsoleTextAttribute(hConsole, 119);
                printf(" ");
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 1)
            {
                SetConsoleTextAttribute(hConsole, 114);
                printf("%c", 2);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 2)
            {
                SetConsoleTextAttribute(hConsole, 112);
                printf("%c", 178);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 3)
            {
                SetConsoleTextAttribute(hConsole, 112);
                printf("%c", 179);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 4)
            {
                SetConsoleTextAttribute(hConsole, 112);
                printf("%c", 196);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 5)
            {
                SetConsoleTextAttribute(hConsole, 115);
                printf("%c", 176);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 6)
            {
                SetConsoleTextAttribute(hConsole, 112);
                printf("%c", 219);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 7)
            {
                SetConsoleTextAttribute(hConsole, 112);
                printf("%c", 254);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 8)
            {
                SetConsoleTextAttribute(hConsole, 124);
                printf("%c", 3);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 9)
            {
                SetConsoleTextAttribute(hConsole, 121);
                printf("%c", 15);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 10)
            {
                SetConsoleTextAttribute(hConsole, 126);
                printf("%c", 6);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 11)
            {
                SetConsoleTextAttribute(hConsole, 125);
                printf("%c", 177);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 12)
            {
                SetConsoleTextAttribute(hConsole, 125);
                printf("%c", 215);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 13)
            {
                SetConsoleTextAttribute(hConsole, 125);
                printf("%c", 186);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 14 || board[i][j] == -15)
            {
                SetConsoleTextAttribute(hConsole, 125);
                printf(")");
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 15 || board[i][j] == -14)
            {
                SetConsoleTextAttribute(hConsole, 125);
                printf("(");
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 16 || board[i][j] == -17)
            {
                SetConsoleTextAttribute(hConsole, 125);
                printf("U");
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 17 || board[i][j] == -16)
            {
                SetConsoleTextAttribute(hConsole, 125);
                printf("%c", 234);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 18 || board[i][j] == 19)
            {
                SetConsoleTextAttribute(hConsole, 116);
                printf("%c", 1);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 20)
            {
                printf("\n");
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 21)
            {
                SetConsoleTextAttribute(hConsole, 112);
                printf("%c", 218);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 22)
            {
                SetConsoleTextAttribute(hConsole, 112);
                printf("%c", 191);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 23)
            {
                SetConsoleTextAttribute(hConsole, 112);
                printf("%c", 192);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 24)
            {
                SetConsoleTextAttribute(hConsole, 112);
                printf("%c", 217);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 25)
            {
                SetConsoleTextAttribute(hConsole, 112);
                printf("%c", 193);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 26)
            {
                SetConsoleTextAttribute(hConsole, 112);
                printf("%c", 194);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 27)
            {
                SetConsoleTextAttribute(hConsole, 112);
                printf("%c", 195);
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(board[i][j] == 28)
            {
                SetConsoleTextAttribute(hConsole, 112);
                printf("%c", 180);
                SetConsoleTextAttribute(hConsole, 7);
            }
        }
    {
        printf("\nYou are: ");
        SetConsoleTextAttribute(hConsole, 2);
        printf("%c", 2);
        SetConsoleTextAttribute(hConsole, 7);
        printf("\nMovement Controls: W%c S%c A%c D%c \nLives:", 24, 25, 27, 26);
        SetConsoleTextAttribute(hConsole, 12);
        for(i = 1; i <= lives; i++)
            printf("%c", 3);
        printf("\n");
        SetConsoleTextAttribute(hConsole, 7);
        printf("Moves: %d\n", moves);
        SetConsoleTextAttribute(hConsole, 9);
        printf("%c", 15);
        SetConsoleTextAttribute(hConsole, 7);
        printf(" = 50 Moves\n");
        SetConsoleTextAttribute(hConsole, 14);
        printf("%c", 6);
        SetConsoleTextAttribute(hConsole, 7);
        printf(" %c  Allows you to walk over these: ", 26);
        SetConsoleTextAttribute(hConsole, 3);
        printf("%c", 176);
        SetConsoleTextAttribute(hConsole, 7);
        printf("\nTo open gates, press E near buttons: ");
        SetConsoleTextAttribute(hConsole, 13);
        printf("( ) U %c", 234);
        SetConsoleTextAttribute(hConsole, 7);
        printf("\nAvoid these: ");
        SetConsoleTextAttribute(hConsole, 4);
        printf("%c", 1);
        SetConsoleTextAttribute(hConsole, 7);
        printf("\nPress X to exit.\n");
    }
    Sleep(1000);
    while(play != 'x' && play != 'X' && moves > 0 && lives > 0)
    {
        if(moved) print_board(x, y);
        xi = x;
        yi = y;
        special_floor2 = special_floor;
        move();
        if(x == 79 && y == 14)
        {
            victory = 1;
            break;
        }
    }
    print_board(x, y);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord_end);
    if(victory) printf("\nCongratulations! You have won the game!\n");
    else printf("\nGame Over!\n");
    system("pause");
}

void print_board(int x, int y)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {x, y};
    COORD coord1 = {xi, yi};
    COORD reset = {16, 30};
    COORD vieti = {6, 24};
    COORD mutari = {7, 25};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    SetConsoleTextAttribute(hConsole, 114);
    printf("%c", 2);
    SetConsoleTextAttribute(hConsole, 7);
    if(special_floor2 && (xi != x || yi != y))
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord1);
        SetConsoleTextAttribute(hConsole, 115);
        printf("%c", 176);
        SetConsoleTextAttribute(hConsole, 7);
    }
    else if(xi != x || yi != y)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord1);
        SetConsoleTextAttribute(hConsole, 119);
        printf(" ");
        SetConsoleTextAttribute(hConsole, 7);
    }
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), vieti);
    SetConsoleTextAttribute(hConsole, 12);
    for(i = 1; i <= lives; i++)
        printf("%c", 3);
    for(i = lives+1; i <= prev_lives; i++)
        printf(" ");
    if(!lives)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        SetConsoleTextAttribute(hConsole, 119);
        printf(" ");
    }
    SetConsoleTextAttribute(hConsole, 7);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mutari);
    printf("%d", moves);
    if(moves < 100) printf(" ");
    if(moves < 10) printf(" ");
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), reset);
    prev_lives = lives;
}

void move()
{
    HANDLE hConsole;
    COORD vieti = {6, 24};
    moved = 0;
    while(kbhit() == 0)
    {
        t02 = clock();
        dif = (double)(t02 - t01) / CLOCKS_PER_SEC;
        if(dif + .75 >= 1 )
        {
            move_monster();
            t01 = t02;
        }
    }
    play = getch();

    if(play == 'A' || play == 'a')
    {
        if(board[board_x][board_y-1] == 0 || board[board_x][board_y-1] == 8 ||
                board[board_x][board_y-1] == 9 || board[board_x][board_y-1] == 10)
        {
            moved = 1;
            if(special_floor == 1)
                board[board_x][board_y--] = 5;
            else board[board_x][board_y--] = 0;
            if(board[board_x][board_y] == 8)
            {
                lives+=5;
                printf("\a");
            }
            else if(board[board_x][board_y] == 9)
            {
                moves+=50;
                printf("\a");
            }
            else if(board[board_x][board_y] == 10)
            {
                boots = 1;
                printf("\a");
            }
            board[board_x][board_y] = 1;
            special_floor = 0;
            moves--;
            x--;
        }
        else if(board[board_x][board_y-1] == 5 && boots)
        {
            moved = 1;
            if(special_floor == 1)
                board[board_x][board_y--] = 5;
            else board[board_x][board_y--] = 0;
            if(board[board_x][board_y] == 8)
            {
                lives+=5;
                printf("\a");
            }
            else if(board[board_x][board_y] == 9)
            {
                moves+=20;
                printf("\a");
            }
            else if(board[board_x][board_y] == 10)
            {
                boots = 1;
                printf("\a");
            }
            board[board_x][board_y] = 1;
            special_floor = 1;
            moves--;
            x--;
        }
        else if(board[board_x][board_y-1] == 18 || board[board_x][board_y-1] == 19)
        {
            lives--;
            moves--;
            moved = 1;
            printf("\a");
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), vieti);
            SetConsoleTextAttribute(hConsole, 12);
            for(i = 1; i <= lives; i++)
                printf("%c", 3);
            for(i = lives+1; i <= prev_lives; i++)
                printf(" ");
            SetConsoleTextAttribute(hConsole, 7);
        }
        if(!moved) printf("\a");
    }
    else if(play == 'D' || play == 'd')
    {
        if(board[board_x][board_y+1] == 0 || board[board_x][board_y+1] == 8 ||
                board[board_x][board_y+1] == 9 || board[board_x][board_y+1] == 10)
        {
            moved = 1;
            if(special_floor == 1)
                board[board_x][board_y++] = 5;
            else board[board_x][board_y++] = 0;
            if(board[board_x][board_y] == 8)
            {
                lives+=5;
                printf("\a");
            }
            else if(board[board_x][board_y] == 9)
            {
                moves+=50;
                printf("\a");
            }
            else if(board[board_x][board_y] == 10)
            {
                boots = 1;
                printf("\a");
            }
            board[board_x][board_y] = 1;
            special_floor = 0;
            moves--;
            x++;
        }
        else if(board[board_x][board_y+1] == 5 && boots)
        {
            moved = 1;
            if(special_floor == 1)
                board[board_x][board_y++] = 5;
            else board[board_x][board_y++] = 0;
            if(board[board_x][board_y] == 8)
            {
                lives+=5;
                printf("\a");
            }
            else if(board[board_x][board_y] == 9)
            {
                moves+=20;
                printf("\a");
            }
            else if(board[board_x][board_y] == 10)
            {
                boots = 1;
                printf("\a");
            }
            board[board_x][board_y] = 1;
            special_floor = 1;
            moves--;
            x++;
        }
        else if(board[board_x][board_y+1] == 18 || board[board_x][board_y+1] == 19)
        {
            lives--;
            moves--;
            moved = 1;
            printf("\a");
        }
        if(!moved) printf("\a");
    }
    else if(play == 'S' || play == 's')
    {
        if(board[board_x+1][board_y] == 0 || board[board_x+1][board_y] == 8 ||
                board[board_x+1][board_y] == 9 || board[board_x+1][board_y] == 10)
        {
            moved = 1;
            if(special_floor == 1)
                board[board_x++][board_y] = 5;
            else board[board_x++][board_y] = 0;
            if(board[board_x][board_y] == 8)
            {
                lives+=5;
                printf("\a");
            }
            else if(board[board_x][board_y] == 9)
            {
                moves+=50;
                printf("\a");
            }
            else if(board[board_x][board_y] == 10)
            {
                boots = 1;
                printf("\a");
            }
            board[board_x][board_y] = 1;
            special_floor = 0;
            moves--;
            y++;
        }
        else if(board[board_x+1][board_y] == 5 && boots)
        {
            moved = 1;
            if(special_floor == 1)
                board[board_x++][board_y] = 5;
            else board[board_x++][board_y] = 0;
            if(board[board_x][board_y] == 8)
            {
                lives+=5;
                printf("\a");
            }
            else if(board[board_x][board_y] == 9)
            {
                moves+=20;
                printf("\a");
            }
            else if(board[board_x][board_y] == 10)
            {
                boots = 1;
                printf("\a");
            }
            board[board_x][board_y] = 1;
            special_floor = 1;
            moves--;
            y++;
        }
        else if(board[board_x+1][board_y] == 18 || board[board_x+1][board_y] == 19)
        {
            lives--;
            moves--;
            moved = 1;
            printf("\a");
        }
        if(!moved) printf("\a");
    }
    else if(play == 'W' || play == 'w')
    {
        if(board[board_x-1][board_y] == 0 || board[board_x-1][board_y] == 8 ||
                board[board_x-1][board_y] == 9 || board[board_x-1][board_y] == 10)
        {
            moved = 1;
            if(special_floor == 1)
                board[board_x--][board_y] = 5;
            else board[board_x--][board_y] = 0;
            if(board[board_x][board_y] == 8)
            {
                lives+=5;
                printf("\a");
            }
            else if(board[board_x][board_y] == 9)
            {
                moves+=50;
                printf("\a");
            }
            else if(board[board_x][board_y] == 10)
            {
                boots = 1;
                printf("\a");
            }
            board[board_x][board_y] = 1;
            special_floor = 0;
            moves--;
            y--;
        }
        else if(board[board_x-1][board_y] == 5 && boots)
        {
            moved = 1;
            if(special_floor == 1)
                board[board_x--][board_y] = 5;
            else board[board_x--][board_y] = 0;
            if(board[board_x][board_y] == 8)
            {
                lives+=5;
                printf("\a");
            }
            else if(board[board_x][board_y] == 9)
            {
                moves+=20;
                printf("\a");
            }
            else if(board[board_x][board_y] == 10)
            {
                boots = 1;
                printf("\a");
            }
            board[board_x][board_y] = 1;
            special_floor = 1;
            moves--;
            y--;
        }
        else if(board[board_x-1][board_y] == 18 || board[board_x-1][board_y] == 19)
        {
            lives--;
            moves--;
            moved = 1;
            printf("\a");
        }
        if(!moved) printf("\a");
    }
    else if(play == 'E' || play == 'e')
        button();
}

void button()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD up = {x, y-1};
    COORD down = {x, y+1};
    COORD left = {x-1, y};
    COORD right = {x+1, y};

    if(board[board_x-1][board_y] == 16)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), up);
        SetConsoleTextAttribute(hConsole, 125);
        printf("%c", 234);
        SetConsoleTextAttribute(hConsole, 7);
        board[board_x-1][board_y] = -16;
        which_button(board_x-1, board_y);
    }
    else if(board[board_x-1][board_y] == -16)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), up);
        SetConsoleTextAttribute(hConsole, 125);
        printf("U");
        SetConsoleTextAttribute(hConsole, 7);
        board[board_x-1][board_y] = 16;
        which_button(board_x-1, board_y);
    }

    if(board[board_x+1][board_y] == 17)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), down);
        SetConsoleTextAttribute(hConsole, 125);
        printf("U");
        SetConsoleTextAttribute(hConsole, 7);
        board[board_x+1][board_y] = -17;
        which_button(board_x+1, board_y);
    }
    else if(board[board_x+1][board_y] == -17)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), down);
        SetConsoleTextAttribute(hConsole, 125);
        printf("%c", 234);
        SetConsoleTextAttribute(hConsole, 7);
        board[board_x+1][board_y] = 17;
        which_button(board_x+1, board_y);
    }

    if(board[board_x][board_y-1] == 14)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), left);
        SetConsoleTextAttribute(hConsole, 125);
        printf("(");
        SetConsoleTextAttribute(hConsole, 7);
        board[board_x][board_y-1] = -14;
        which_button(board_x, board_y-1);
    }
    else if(board[board_x][board_y-1] == -14)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), left);
        SetConsoleTextAttribute(hConsole, 125);
        printf(")");
        SetConsoleTextAttribute(hConsole, 7);
        board[board_x][board_y-1] = 14;
        which_button(board_x, board_y-1);
    }

    if(board[board_x][board_y+1] == 15)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), right);
        SetConsoleTextAttribute(hConsole, 125);
        printf(")");
        SetConsoleTextAttribute(hConsole, 7);
        board[board_x][board_y+1] = -15;
        which_button(board_x, board_y+1);
    }
    else if(board[board_x][board_y+1] == -15)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), right);
        SetConsoleTextAttribute(hConsole, 125);
        printf("(");
        SetConsoleTextAttribute(hConsole, 7);
        board[board_x][board_y+1] = 15;
        which_button(board_x, board_y+1);
    }
}

void which_button(int x, int y)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("\a");
    if(x == 15 && y == 49)
    {
        COORD gate1 = {43, 19};
        if(board[19][43] == 6)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate1);
            SetConsoleTextAttribute(hConsole, 119);
            printf(" ");
            board[19][43] = 0;
            SetConsoleTextAttribute(hConsole, 7);
        }
        else if(board[19][43] == 0)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate1);
            SetConsoleTextAttribute(hConsole, 112);
            printf("%c", 219);
            board[19][43] = 6;
            SetConsoleTextAttribute(hConsole, 7);
        }
    }
    else if(x == 19 && y == 32)
    {
        COORD gate2 = {16, 18};
        if(board[18][16] == 6)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate2);
            SetConsoleTextAttribute(hConsole, 119);
            printf(" ");
            board[18][16] = 0;
            SetConsoleTextAttribute(hConsole, 7);
        }
        else if(board[18][16] == 0)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate2);
            SetConsoleTextAttribute(hConsole, 112);
            printf("%c", 219);
            board[18][16] = 6;
            SetConsoleTextAttribute(hConsole, 7);
        }
    }
    else if(x == 12 && y == 77)
    {
        COORD gate3 = {60, 2};
        if(board[2][60] == 7)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate3);
            SetConsoleTextAttribute(hConsole, 119);
            printf(" ");
            board[2][60] = 0;
            SetConsoleTextAttribute(hConsole, 7);
        }
        else if(board[2][60] == 0)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate3);
            SetConsoleTextAttribute(hConsole, 112);
            printf("%c", 254);
            board[2][60] = 7;
            SetConsoleTextAttribute(hConsole, 7);
        }
    }
    else if(x == 4 && y == 56)
    {
        COORD gate4 = {48, 5};
        if(board[5][48] == 7)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate4);
            SetConsoleTextAttribute(hConsole, 119);
            printf(" ");
            board[5][48] = 0;
            SetConsoleTextAttribute(hConsole, 7);
        }
        else if(board[5][48] == 0)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate4);
            SetConsoleTextAttribute(hConsole, 112);
            printf("%c", 254);
            board[5][48] = 7;
            SetConsoleTextAttribute(hConsole, 7);
        }
    }
    else if(x == 9 && y == 47)
    {
        COORD gate5 = {62, 10};
        if(board[10][62] == 7)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate5);
            SetConsoleTextAttribute(hConsole, 119);
            printf(" ");
            board[10][62] = 0;
            SetConsoleTextAttribute(hConsole, 7);
        }
        else if(board[10][62] == 0)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate5);
            SetConsoleTextAttribute(hConsole, 112);
            printf("%c", 254);
            board[10][62] = 7;
            SetConsoleTextAttribute(hConsole, 7);
        }
    }
    else if(x == 19 && y == 10)
    {
        COORD gate6 = {4, 5};
        if(board[5][4] == 6)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate6);
            SetConsoleTextAttribute(hConsole, 119);
            printf(" ");
            board[5][4] = 0;
            SetConsoleTextAttribute(hConsole, 7);
        }
        else if(board[5][4] == 0)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate6);
            SetConsoleTextAttribute(hConsole, 112);
            printf("%c", 219);
            board[5][4] = 6;
            SetConsoleTextAttribute(hConsole, 7);
        }
    }
    else if(x == 19 && y == 5)
    {
        COORD gate6 = {10, 13};
        if(board[13][10] == 7)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate6);
            SetConsoleTextAttribute(hConsole, 119);
            printf(" ");
            board[13][10] = 0;
            SetConsoleTextAttribute(hConsole, 7);
        }
        else if(board[13][10] == 0)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate6);
            SetConsoleTextAttribute(hConsole, 112);
            printf("%c", 254);
            board[13][10] = 7;
            SetConsoleTextAttribute(hConsole, 7);
        }
    }
    else if((x == 7 && y == 32) || (x == 13 && y == 26) || (x == 3 && y == 51))//
    {
        COORD gate7a = {79, 14};
        COORD gate7b = {78, 14};
        COORD erase_button = {y, x};
        if(board[14][79] == 11)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate7a);
            SetConsoleTextAttribute(hConsole, 125);
            printf("%c", 215);
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate7b);
            printf("%c", 215);
            board[14][79] = board[14][78] = 12;
            SetConsoleTextAttribute(hConsole, 7);
        }
        else if(board[14][79] == 12)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate7a);
            SetConsoleTextAttribute(hConsole, 125);
            printf("%c", 186);
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate7b);
            printf("%c", 186);
            board[14][79] = board[14][78] = 13;
            SetConsoleTextAttribute(hConsole, 7);
        }
        else if(board[14][79] == 13)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate7a);
            SetConsoleTextAttribute(hConsole, 119);
            printf(" ");
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate7b);
            printf(" ");
            board[14][79] = board[14][78] = 0;
            SetConsoleTextAttribute(hConsole, 7);
        }
        SetConsoleTextAttribute(hConsole, 119);
        board[x][y] = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), erase_button);
        printf(" ");
        SetConsoleTextAttribute(hConsole, 7);
    }
    else if(x == 4 && y == 74)//
    {
        COORD gate8 = {48, 8};
        if(board[8][48] == 7)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate8);
            SetConsoleTextAttribute(hConsole, 119);
            printf(" ");
            board[8][48] = 0;
            SetConsoleTextAttribute(hConsole, 7);
        }
        else if(board[8][48] == 0)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gate8);
            SetConsoleTextAttribute(hConsole, 112);
            printf("%c", 254);
            board[8][48] = 7;
            SetConsoleTextAttribute(hConsole, 7);
        }
    }
    COORD reset = {16, 30};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), reset);
}

void move_monster()
{
    //mx[] = {16, 17, 18, 11, 12, 4, 6, 11, 13, 12, 4, 17, 11, 16, 3, 11, 4, 5, 16, 6, 16, 11, 15, 19, 13,
    //17, 13, 11, 3, 4, 5, 4, 3, 6, 10, 8}
    //my[] = {1, 3, 5, 7, 13, 14, 15, 17, 17, 9, 24, 27, 32, 34, 38, 39, 40, 40, 41, 43, 44, 47, 49, 49, 53,
    //58, 61, 64, 65, 66, 67, 68, 76, 76, 77}
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD reset = {16, 30};
    int dep;

    for(int i = 0; i < 36; i++)
    {
        go = 0;
        if(s[i] == 1 || s[i] == -1)
            if(board[mx[i]][my[i]+s[i]] == 0)
            {
                set_cursor(i);
                SetConsoleTextAttribute(hConsole, 119);
                printf(" ");
                board[mx[i]][my[i]] = 0;
                my[i]+=s[i];
                go = 1;
                set_cursor(i);
                go = 0;
                set_cursor(i);
                SetConsoleTextAttribute(hConsole, 116);
                printf("%c", 1);
                board[mx[i]][my[i]] = 19;
                SetConsoleTextAttribute(hConsole, 7);
            }
            else
            {
                s[i] = -s[i];
                if(board[mx[i]][my[i]+1] == 1 || board[mx[i]][my[i]-1] == 1)
                {
                    lives--;
                    printf("\a");
                }
            }
        else if(s[i] == 2 || s[i] == -2)
        {
            if(s[i] == 2) dep = 1;
            else dep = -1;
            if(board[mx[i]+dep][my[i]] == 0)
            {
                set_cursor(i);
                SetConsoleTextAttribute(hConsole, 119);
                printf(" ");
                board[mx[i]][my[i]] = 0;
                mx[i]+=dep;
                go = 1;
                set_cursor(i);
                go = 0;
                set_cursor(i);
                SetConsoleTextAttribute(hConsole, 116);
                printf("%c", 1);
                board[mx[i]][my[i]] = 19;
                SetConsoleTextAttribute(hConsole, 7);
            }
            else
            {
                s[i] = -s[i];
                if(board[mx[i] + 1][my[i]] == 1 || board[mx[i] - 1][my[i]] == 1)
                {
                    lives--;
                    printf("\a");
                }
            }
        }
    }
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), reset);
}

void set_cursor(int i)
{
    COORD m1 = {my[0], mx[0]};
    COORD m19 = {my[18], mx[18]};
    COORD m2 = {my[1], mx[1]};
    COORD m20 = {my[19], mx[19]};
    COORD m3 = {my[2], mx[2]};
    COORD m21 = {my[20], mx[20]};
    COORD m4 = {my[3], mx[3]};
    COORD m22 = {my[21], mx[21]};
    COORD m5 = {my[4], mx[4]};
    COORD m23 = {my[22], mx[22]};
    COORD m6 = {my[5], mx[5]};
    COORD m24 = {my[23], mx[23]};
    COORD m7 = {my[6], mx[6]};
    COORD m25 = {my[24], mx[24]};
    COORD m8 = {my[7], mx[7]};
    COORD m26 = {my[25], mx[25]};
    COORD m9 = {my[8], mx[8]};
    COORD m27 = {my[26], mx[26]};
    COORD m10 = {my[9], mx[9]};
    COORD m28 = {my[27], mx[27]};
    COORD m11 = {my[10], mx[10]};
    COORD m29 = {my[28], mx[28]};
    COORD m12 = {my[11], mx[11]};
    COORD m30 = {my[29], mx[29]};
    COORD m13 = {my[12], mx[12]};
    COORD m31 = {my[30], mx[30]};
    COORD m14 = {my[13], mx[13]};
    COORD m32 = {my[31], mx[31]};
    COORD m15 = {my[14], mx[14]};
    COORD m33 = {my[32], mx[32]};
    COORD m16 = {my[15], mx[15]};
    COORD m34 = {my[33], mx[33]};
    COORD m17 = {my[16], mx[16]};
    COORD m35 = {my[34], mx[34]};
    COORD m18 = {my[17], mx[17]};
    COORD m36 = {my[35], mx[35]};
    if(!go)
    {
        if(i == 0) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m1);
        else if(i == 1) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m2);
        else if(i == 2) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m3);
        else if(i == 3) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m4);
        else if(i == 4) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m5);
        else if(i == 5) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m6);
        else if(i == 6) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m7);
        else if(i == 7) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m8);
        else if(i == 8) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m9);
        else if(i == 9) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m10);
        else if(i == 10) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m11);
        else if(i == 11) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m12);
        else if(i == 12) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m13);
        else if(i == 13) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m14);
        else if(i == 14) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m15);
        else if(i == 15) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m16);
        else if(i == 16) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m17);
        else if(i == 17) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m18);
        else if(i == 18) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m19);
        else if(i == 19) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m20);
        else if(i == 20) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m21);
        else if(i == 21) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m22);
        else if(i == 22) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m23);
        else if(i == 23) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m24);
        else if(i == 24) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m25);
        else if(i == 25) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m26);
        else if(i == 26) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m27);
        else if(i == 27) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m28);
        else if(i == 28) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m29);
        else if(i == 29) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m30);
        else if(i == 30) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m31);
        else if(i == 31) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m32);
        else if(i == 32) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m33);
        else if(i == 33) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m34);
        else if(i == 34) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m35);
        else if(i == 35) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m36);
    }
    else
    {
        if(i == 0) m1 = {my[i], mx[i]};
        else if(i == 1) m2 = {my[i], mx[i]};
        else if(i == 2) m3 = {my[i], mx[i]};
        else if(i == 3) m4 = {my[i], mx[i]};
        else if(i == 4) m5 = {my[i], mx[i]};
        else if(i == 5) m6 = {my[i], mx[i]};
        else if(i == 6) m7 = {my[i], mx[i]};
        else if(i == 7) m8 = {my[i], mx[i]};
        else if(i == 8) m9 = {my[i], mx[i]};
        else if(i == 9) m10 = {my[i], mx[i]};
        else if(i == 10) m11 = {my[i], mx[i]};
        else if(i == 11) m12 = {my[i], mx[i]};
        else if(i == 12) m13 = {my[i], mx[i]};
        else if(i == 13) m14 = {my[i], mx[i]};
        else if(i == 14) m15 = {my[i], mx[i]};
        else if(i == 15) m16 = {my[i], mx[i]};
        else if(i == 16) m17 = {my[i], mx[i]};
        else if(i == 17) m18 = {my[i], mx[i]};
        else if(i == 18) m19 = {my[i], mx[i]};
        else if(i == 19) m20 = {my[i], mx[i]};
        else if(i == 20) m21 = {my[i], mx[i]};
        else if(i == 21) m22 = {my[i], mx[i]};
        else if(i == 22) m23 = {my[i], mx[i]};
        else if(i == 23) m24 = {my[i], mx[i]};
        else if(i == 24) m25 = {my[i], mx[i]};
        else if(i == 25) m26 = {my[i], mx[i]};
        else if(i == 26) m27 = {my[i], mx[i]};
        else if(i == 27) m28 = {my[i], mx[i]};
        else if(i == 28) m29 = {my[i], mx[i]};
        else if(i == 29) m30 = {my[i], mx[i]};
        else if(i == 30) m31 = {my[i], mx[i]};
        else if(i == 31) m32 = {my[i], mx[i]};
        else if(i == 32) m33 = {my[i], mx[i]};
        else if(i == 33) m34 = {my[i], mx[i]};
        else if(i == 34) m35 = {my[i], mx[i]};
        else if(i == 35) m36 = {my[i], mx[i]};
    }
}
