#include <iostream>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <stdexcept>
#include <string.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

#include <windows.h>

string optionSDif = "Choose difficulty";
string optionStGa = "Start Game";
string optionQuit = "Quit";
string difficultyOptions[] = {"Easy","Hard","Challenger"};
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
int difficulty = 0;

const string Symbols[] =
{
    "         ",
    "    O    ",
    "    X    "
};

void setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
    if(size == 0)
    {
        size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
    }
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console,&lpCursor);
}

void gotoxy(int x, int y)
{
    static HANDLE hStdout = NULL;
    COORD coord;

    coord.X = x + 10;
    coord.Y = y + 10;

    if (!hStdout)
    {
        hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    }

    SetConsoleCursorPosition(hStdout,coord);
}

void clrscr(int x,int y)
{
    static HANDLE hStdout = NULL;
    static CONSOLE_SCREEN_BUFFER_INFO csbi;
    const COORD startCoords = {x,y};
    DWORD dummy;

    if (!hStdout)
    {
        hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        GetConsoleScreenBufferInfo(hStdout,&csbi);
    }

    FillConsoleOutputCharacter(hStdout,
                               ' ',
                               csbi.dwSize.X * csbi.dwSize.Y,
                               startCoords,
                               &dummy);
    gotoxy(0,0);
}

void color(int n)
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, n);
}

void SelectOption(int option)
{
    if(option == 0)
    {
        clrscr(0,0);
        color(2);
        cout<<optionSDif;
        color(7);
        gotoxy(optionSDif.size()+5,0);
        cout<<optionStGa;
        gotoxy(optionSDif.size()+5+optionStGa.size()+5,0);
        cout<<optionQuit;
    }
    if(option == 1)
    {
        clrscr(0,0);
        color(7);
        cout<<optionSDif;
        color(2);
        gotoxy(optionSDif.size()+5,0);
        cout<<optionStGa;
        color(7);
        gotoxy(optionSDif.size()+5+optionStGa.size()+5,0);
        cout<<optionQuit;
    }
    if(option == 2)
    {
        clrscr(0,0);
        color(7);
        cout<<optionSDif;
        gotoxy(optionSDif.size()+5,0);
        cout<<optionStGa;
        color(2);
        gotoxy(optionSDif.size()+5+optionStGa.size()+5,0);
        cout<<optionQuit;
    }
}

void SelectDifficulty(int option)
{
    if(option == 0)
    {
        clrscr(0,1);
        gotoxy(2,1);
        color(2);
        cout<<difficultyOptions[0];
        color(7);
        gotoxy(2,2);
        cout<<difficultyOptions[1];
        gotoxy(2,3);
        cout<<difficultyOptions[2];
    }
    if(option == 1)
    {
        clrscr(0,1);
        gotoxy(2,1);
        color(7);
        cout<<difficultyOptions[0];
        color(2);
        gotoxy(2,2);
        cout<<difficultyOptions[1];
        color(7);
        gotoxy(2,3);
        cout<<difficultyOptions[2];
    }
    if(option == 2)
    {
        clrscr(0,1);
        gotoxy(2,1);
        color(7);
        cout<<difficultyOptions[0];
        color(7);
        gotoxy(2,2);
        cout<<difficultyOptions[1];
        color(2);
        gotoxy(2,3);
        cout<<difficultyOptions[2];
    }
}

void printField()
{
    cout<<"   "<<char(186)<<"   "<<char(186)<<"   "<<endl;
    cout<<"   "<<char(186)<<"   "<<char(186)<<"   "<<endl;
    cout<<"   "<<char(186)<<"   "<<char(186)<<"   "<<endl;
    cout<<char(205)<<char(205)<<char(205)<<char(206)<<char(205)<<char(205)<<char(205)<<char(206)<<char(205)<<char(205)<<char(205)<<endl;
    cout<<"   "<<char(186)<<"   "<<char(186)<<"   "<<endl;
    cout<<"   "<<char(186)<<"   "<<char(186)<<"   "<<endl;
    cout<<"   "<<char(186)<<"   "<<char(186)<<"   "<<endl;
    cout<<char(205)<<char(205)<<char(205)<<char(206)<<char(205)<<char(205)<<char(205)<<char(206)<<char(205)<<char(205)<<char(205)<<endl;
    cout<<"   "<<char(186)<<"   "<<char(186)<<"   "<<endl;
    cout<<"   "<<char(186)<<"   "<<char(186)<<"   "<<endl;
    cout<<"   "<<char(186)<<"   "<<char(186)<<"   "<<endl;
}

void printSymbol(int boxIndex, string Symbol)
{
    if(boxIndex >= 0 && boxIndex <= 2)
    {
        int sInd = 0;
        for(int j = 0; j < 3; j++)
        {
            for(int i = 0; i < 3; i++)
            {
                gotoxy(4*boxIndex + i,j);
                cout<<Symbol[sInd];
                sInd++;
            }
        }
    }

    if(boxIndex >= 3 && boxIndex <= 5)
    {
        int sInd = 0;
        for(int j = 0; j < 3; j++)
        {
            for(int i = 0; i < 3; i++)
            {
                gotoxy(4*(boxIndex - 3) + i,j + 4);
                cout<<Symbol[sInd];
                sInd++;
            }
        }
    }

    if(boxIndex >= 6 && boxIndex <= 8)
    {
        int sInd = 0;
        for(int j = 0; j < 3; j++)
        {
            for(int i = 0; i < 3; i++)
            {
                gotoxy(4*(boxIndex - 6) + i,j + 8);
                cout<<Symbol[sInd];
                sInd++;
            }
        }
    }
}

int figureCellIndex(int row,int cell)
{
    if(row == 0)return cell;
    if(row == 1)return cell + 3;
    if(row == 2)return cell + 6;
}

int checkForWin(string GameCombo)
{
    ifstream winnings("winningCombos.txt");
    string line;
    bool searching = true;
    while(searching)
    {
        getline(winnings,line);
        if(winnings.eof())
        {
            searching = false;
            break;
        }
        int index1 = line.find('x',0);
        int index2 = line.find('x',index1 + 1);
        int index3 = line.find('x',index2 + 1);
        int index[] = {index1,index2,index3};

        int indexes = 0;
        for(int i = 0; i < 3; i++)
        {
            if(GameCombo[index[i]] == '1')indexes++;
        }

        if(indexes == 2)
        {
            for(int i = 0; i < 3; i++)
            {
                if(GameCombo[index[i]] == '0')
                {
                    winnings.close();
                    return index[i];
                }
            }
        }
    }
    winnings.close();
    return -1;
}

int evaluateTurn(string GameCombo)
{
    int winIndex = checkForWin(GameCombo);
    if(winIndex != -1)return winIndex;
    int index = GameCombo.find('0',0);
    string GameComboCopy = GameCombo;
    bool searching = true;
    while(searching)
    {
        GameComboCopy[index] = '1';
        ifstream check("wrongCombos.txt");
        string line;
        bool b = true;
        while(b)
        {
            getline(check,line);
            if(line == "")
            {
                searching = false;
                b = false;
                break;
            }
            if(line == GameComboCopy)
            {
                GameComboCopy = GameCombo;
                b = false;
                break;
            }
        }
        check.close();
        if(searching)index = GameCombo.find('0',index + 1);
        if(index == -1)
        {
            searching = false;
            index = GameCombo.find('0',0);
        }
    }
    return index;
}
void computerTurn(string &GameCombo)
{
    int cCellIndex = evaluateTurn(GameCombo);
    GameCombo[cCellIndex] = '1';
    printSymbol(cCellIndex, Symbols[1]);
}

int checkForWinner(string GameCombo)
{
    ifstream winnings("winningCombos.txt");
    bool winner = false;
    bool null = false;

    do
    {
        string readLine;
        getline(winnings,readLine);

        if(readLine.find("x",0) == -1)
        {
            null == true;
            break;
        }

        bool b = true;
        int index = readLine.find('x',0);
        while(b && index != -1)
        {
            if(index == -1)break;
            if(GameCombo[index] != '1')
            {
                b = false;
                break;
            }
            index = readLine.find('x',index + 1);
        }
        if(b)
        {
            winnings.close();
            return 1;
        }

        b = true;
        index = readLine.find('x',0);
        while(b || index != -1)
        {
            if(index == -1)break;
            if(GameCombo[index] != '2')
            {
                b = false;
                break;
            }
            index = readLine.find('x',index + 1);
        }
        if(b)
        {
            winnings.close();
            return 2;
        }
    }
    while(!winner && !null);
    winnings.close();
    if(GameCombo.find('0') == -1)return 3;
    else return 0;
}
void startGame()
{
    clrscr(0,0);
    printField();
    string gameCombo = "000000000";

    int selectRow = 0;
    int selectCell = 0;
    int cellIndex = 0;

    color(175);
    printSymbol(cellIndex,Symbols[0]);

    char pressedButton;
    bool win = false;
    while(!win)
    {
        do
        {
            pressedButton = getch();
            if(pressedButton == 'w' && selectRow != 0)selectRow--;
            if(pressedButton == 's' && selectRow != 2)selectRow++;
            if(pressedButton == 'a' && selectCell != 0)selectCell--;
            if(pressedButton == 'd' && selectCell != 2)selectCell++;
            color(7);
            printSymbol(cellIndex,Symbols[gameCombo[cellIndex] - '0']);
            cellIndex = figureCellIndex(selectRow,selectCell);
            if(gameCombo[cellIndex] == '0')color(175);
            else color(207);
            printSymbol(cellIndex,Symbols[gameCombo[cellIndex] - '0']);
        }
        while(pressedButton != 'k');
        if(gameCombo[cellIndex] == '0')
        {
            color(207);
            printSymbol(cellIndex,Symbols[2]);
            gameCombo[cellIndex] = '2';
            if(checkForWinner(gameCombo) != 0)
                if(checkForWinner(gameCombo) == 2)
                {
                    color(7);
                    printSymbol(cellIndex,Symbols[2]);
                    fstream wrongs("wrongCombos.txt",ios::out | ios::app);
                    gameCombo[cellIndex] = '0';
                    wrongs<<gameCombo<<endl;
                    wrongs.close();

                    gotoxy(0,12);
                    color(7);
                    cout<<"Player WINS";
                    getch();

                    win = true;
                    break;

                }
                else
                {
                    color(7);
                    printSymbol(cellIndex,Symbols[2]);
                    gotoxy(0,12);
                    color(7);
                    cout<<"DRAW";
                    getch();

                    win = true;
                    break;
                }
            color(7);
            computerTurn(gameCombo);
            if(checkForWinner(gameCombo) != 0)
                if(checkForWinner(gameCombo) == 1)
                {
                    color(7);
                    printSymbol(cellIndex,Symbols[1]);
                    gotoxy(0,12);
                    color(7);
                    cout<<"Computer WINS";
                    getch();

                    win = true;
                    break;
                }
                else
                {
                    color(7);
                    printSymbol(cellIndex,Symbols[1]);
                    gotoxy(0,12);
                    color(7);
                    cout<<"DRAW";
                    getch();

                    win = true;
                    break;
                }
        }
    }
}

void ExecuteOption(int option)
{
    if(option == 0)
    {
        gotoxy(2,1);
        color(2);
        cout<<difficultyOptions[0];
        color(7);
        gotoxy(2,2);
        cout<<difficultyOptions[1];
        gotoxy(2,3);
        cout<<difficultyOptions[2];

        char pressedButton;
        int selectedDifficulty = 0;

        do
        {
            pressedButton = getch();
            if(pressedButton == 'w' && selectedDifficulty > 0)selectedDifficulty--;
            if(pressedButton == 's' && selectedDifficulty < 2)selectedDifficulty++;
            SelectDifficulty(selectedDifficulty);
        }
        while(pressedButton != 'k');
        difficulty = selectedDifficulty;
        clrscr(0,1);
    }
    if(option == 2)exit(0);
    if(option == 1)startGame();
}

int main()
{

    //cout<<checkForWin("002000000");
    setcursor(false,0);

    color(2);
    cout<<optionSDif;
    color(7);
    gotoxy(optionSDif.size()+5,0);
    cout<<optionStGa;
    gotoxy(optionSDif.size()+5+optionStGa.size()+5,0);
    cout<<optionQuit;

    int selectedOption = 0;
    char pressedButton;

    do
    {
        pressedButton = getch();
        if(pressedButton == 'a' && selectedOption > 0)selectedOption--;
        if(pressedButton == 'd' && selectedOption < 2)selectedOption++;
        SelectOption(selectedOption);
        if(pressedButton == 'k')
        {
            ExecuteOption(selectedOption);

            clrscr(0,0);

            color(2);
            cout<<optionSDif;
            color(7);
            gotoxy(optionSDif.size()+5,0);
            cout<<optionStGa;
            gotoxy(optionSDif.size()+5+optionStGa.size()+5,0);
            cout<<optionQuit;
        }
    }
    while(true);

    return 0;
}
