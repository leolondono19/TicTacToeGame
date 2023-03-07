#include <iostream>
#include <conio.h>
                    
using namespace std;

char matrix_positions[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char matrix_symbols[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };

class Table {

private:    
    void show_matrix(char (&matrix)[3][3]) {
        for (int i = 0; i < 3; i++)
        {
            if (i != 0) {
                cout << "--|---|--";
            }

            cout << endl;
            for (int j = 0; j < 3; j++)
            {
                cout << matrix[i][j] << " ";
                if (j != 2) {
                    cout << "| ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

public:

    void ShowPositions() {
        show_matrix(matrix_positions);
    }

    void ShowSymbols() {
        show_matrix(matrix_symbols);
    }
    
    void position_converter(int position, int& x, int& y) {
        switch (position) {
        case 1:
            x = 0;
            y = 0;
            break;
        case 2:
            x = 0;
            y = 1;
            break;
        case 3:
            x = 0;
            y = 2;
            break;
        case 4:
            x = 1;
            y = 0;
            break;
        case 5:
            x = 1;
            y = 1;
            break;
        case 6:
            x = 1;
            y = 2;
            break;
        case 7:
            x = 2;
            y = 0;
            break;
        case 8:
            x = 2;
            y = 1;
            break;
        case 9:
            x = 2;
            y = 2;
            break;
        }
    }

    bool IsThereSpaceInPosition(int position) {
        int row, column;
        position_converter(position, row, column);
        if (matrix_symbols[row][column] == ' ') {
            return true;
        }
        return false;
    }

    bool IsThereAWinner(char symbol)
    {
        bool condition1 = matrix_symbols[0][0] == symbol && matrix_symbols[0][1] == symbol && matrix_symbols[0][2] == symbol;
        bool condition2 = matrix_symbols[1][0] == symbol && matrix_symbols[1][1] == symbol && matrix_symbols[1][2] == symbol;
        bool condition3 = matrix_symbols[2][0] == symbol && matrix_symbols[2][1] == symbol && matrix_symbols[2][2] == symbol;
        bool condition4 = matrix_symbols[0][0] == symbol && matrix_symbols[1][0] == symbol && matrix_symbols[2][0] == symbol;
        bool condition5 = matrix_symbols[0][1] == symbol && matrix_symbols[1][1] == symbol && matrix_symbols[2][1] == symbol;
        bool condition6 = matrix_symbols[0][2] == symbol && matrix_symbols[1][2] == symbol && matrix_symbols[2][2] == symbol;
        bool condition7 = matrix_symbols[0][0] == symbol && matrix_symbols[1][1] == symbol && matrix_symbols[2][2] == symbol;
        bool condition8 = matrix_symbols[0][2] == symbol && matrix_symbols[1][1] == symbol && matrix_symbols[2][0] == symbol;
            if (condition1 || condition2 || condition3 || condition4 || condition5 || condition6 || condition7 || condition8) {
                return true;
            }
        return false;

    }

    void save_position(int position, char symbol) {
        int c1, c2;
        position_converter(position, c1, c2);
        matrix_symbols[c1][c2] = symbol;
    }

    bool is_there_space() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (matrix_symbols[i][j] == ' ') {
                    return true;
                }
            }
        }
        return false;
    }

    void initialize_matrix_symbols() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrix_symbols[i][j] = ' ';
            }
        }
    }

};

class Player {

public:
    Table _gameTable;
    string Name;
    char Symbol = ' ';
    int Position = -1;

    Player(Table& gameTable) {
        _gameTable = gameTable;
    }

    void AskPlayerName() {
        cout << "Introduce your name: "; cin >> Name;
        cout << endl;
    }
    void AskPlayerSymbol() {
        cout << Name << " Introduce your symbol: "; cin >> Symbol;
        cout << endl;
    }
    void AskTablePosition() {
        int row, column;
        bool is_there_space;
        do {
            cout << Name << " What position do you want to choose?:";
            cin >> Position;
            is_there_space = _gameTable.IsThereSpaceInPosition(Position);
            if (!is_there_space) {
                cout << "Sorry this position is occupied, plese select another one: \n";
            }
        } while (is_there_space == false);
    }
};

//int position1, position2;
//char matrix_positions[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
//char matrix_symbols[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };


void pausa() {
    system("pause");
}
int main() {
    Table _gameTable;
    //_gameTable.save_position(1, 'X');
    Player p1(_gameTable);
    Player p2(_gameTable);
    char again;
    int n = 0; //string name1;  string name2; char s1 = ' '; char s2 = ' ';
    int i = 0;

    do 
    {
        _gameTable.initialize_matrix_symbols();
        system("cls"); // borrar la pantalla (clear screen)
        cout << "\n\Welcome to tic tac toe, please select an option\n";
        cout << "\n1.- PLAY GAME";
        cout << "\n2.- Exit";
        cout << "\nChoose an option: \n";
        cin >> i;
        switch (i)
        {
            case 1:
                system("cls");
                p1.AskPlayerName();
                p2.AskPlayerName();
                p1.AskPlayerSymbol();
                p2.AskPlayerSymbol();
                pausa();
                system("cls");
                while (_gameTable.is_there_space() && _gameTable.IsThereAWinner(p2.Symbol) != true) {
                    _gameTable.ShowPositions();
                    p1.AskTablePosition();
                    cout << endl;
                    _gameTable.save_position(p1.Position,p1.Symbol);
                    _gameTable.ShowSymbols();
                    if (_gameTable.IsThereAWinner(p1.Symbol)) {
                        cout << endl << p1.Name << " YOU ARE THE WINNER ;D\n";
                        break;
                    }
                    else if (_gameTable.is_there_space() != true) {
                        cout << endl << "UPS NO ONE WINS :( IT'S A TIE\n";
                        break;
                    }
                    _gameTable.ShowPositions();
                    p2.AskTablePosition();
                    cout << endl;
                    _gameTable.save_position(p2.Position, p2.Symbol);
                    _gameTable.ShowSymbols();
                    if (_gameTable.IsThereAWinner(p2.Symbol)) {
                        cout << endl << p2.Name << " YOU ARE THE WINNER ;D\n";
                        break;
                    }
                    else if (_gameTable.is_there_space() != true) {
                        cout << endl << "UPS NO ONE WINS :( IT'S A TIE\n";

                        break;
                    }
                }
                pausa();
                break;
                case 2: exit(1);
        }
        cout << "Do you want to play again (y=yes ; n= no): \n";
        cin >> again;
        system("cls");
    }while (again=='y');
    system("pause");
    return 0;
}
//Read about oriented programming
//