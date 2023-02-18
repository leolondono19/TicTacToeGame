#include <iostream>
#include <conio.h>
using namespace std;
string name1; string name2; char symbol1; char symbol2;
int position1;
int position2;
char matrix_positions[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char matrix_symbols[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };
void player_names(void) {
    cout << "Player 1 introduce your name: "; cin >> name1;
    cout << "Player 2 introduce your name: "; cin >> name2;
    cout << endl;
    cout << name1 << " introduce your symbol: "; cin >> symbol1;
    cout << name2 << " introduce your symbol: "; cin >> symbol2;
}
void show_matrix(char matrix[3][3]) {
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
void position_converter(int position, int &x, int &y) {
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
void ask_position(string name, int player_number) {
    int position;
    int row, column;
    bool is_there_space;
    do {
        cout << name << " What position do you want to choose?:";
        cin >> position;
        position_converter(position, row, column);
        is_there_space = matrix_symbols[row][column] == ' ';
        if (!is_there_space) {
            cout << "Sorry this position is occupied, plese select another one: \n";
        }
    } while (is_there_space==false);
    if (player_number == 1) {
        position1 = position;
    }
    else {
        position2 = position;
    }
}
void save_position(int position, char symbol) {
    int c1, c2;
    position_converter(position, c1, c2);
    matrix_symbols[c1][c2] = symbol;
}
bool winner() {
    bool condition1 = matrix_symbols[0][0] == symbol1 && matrix_symbols[0][1] == symbol1 && matrix_symbols[0][2] == symbol1 || matrix_symbols[0][0] == symbol2 && matrix_symbols[0][1] == symbol2 && matrix_symbols[0][2] == symbol2;
    bool condition2 = matrix_symbols[1][0] == symbol1 && matrix_symbols[1][1] == symbol1 && matrix_symbols[1][2] == symbol1 || matrix_symbols[1][0] == symbol2 && matrix_symbols[1][1] == symbol2 && matrix_symbols[1][2] == symbol2;
    bool condition3 = matrix_symbols[2][0] == symbol1 && matrix_symbols[2][1] == symbol1 && matrix_symbols[2][2] == symbol1 || matrix_symbols[2][0] == symbol2 && matrix_symbols[2][1] == symbol2 && matrix_symbols[2][2] == symbol2;
    bool condition4 = matrix_symbols[0][0] == symbol1 && matrix_symbols[1][0] == symbol1 && matrix_symbols[2][0] == symbol1 || matrix_symbols[0][0] == symbol2 && matrix_symbols[1][0] == symbol2 && matrix_symbols[2][0] == symbol2;
    bool condition5 = matrix_symbols[0][1] == symbol1 && matrix_symbols[1][1] == symbol1 && matrix_symbols[2][1] == symbol1 || matrix_symbols[0][1] == symbol2 && matrix_symbols[1][1] == symbol2 && matrix_symbols[2][1] == symbol2;
    bool condition6 = matrix_symbols[0][2] == symbol1 && matrix_symbols[1][2] == symbol1 && matrix_symbols[2][2] == symbol1 || matrix_symbols[0][2] == symbol2 && matrix_symbols[1][2] == symbol2 && matrix_symbols[2][2] == symbol2;
    bool condition7 = matrix_symbols[0][0] == symbol1 && matrix_symbols[1][1] == symbol1 && matrix_symbols[2][2] == symbol1 || matrix_symbols[0][0] == symbol2 && matrix_symbols[1][1] == symbol2 && matrix_symbols[2][2] == symbol2;
    bool condition8 = matrix_symbols[0][2] == symbol1 && matrix_symbols[1][1] == symbol1 && matrix_symbols[2][0] == symbol1 || matrix_symbols[0][2] == symbol2 && matrix_symbols[1][1] == symbol2 && matrix_symbols[2][0] == symbol2;
    if (condition1 || condition2 || condition3 || condition4 || condition5 || condition6 || condition7 || condition8) {
        return true;
    }
    return false;
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
void pausa() {
    system("pause");
}
int main() {
    /*
    matrix1[0][0] = 'X';
    mostrar_matrix1();
    cout << matrix1[0][0]<<endl;
    matrix1[0][0] = 'O';
    mostrar_matrix1();
    cout << matrix1[0][0];
    pausa();
    */
    int n = 0; //string name1;  string name2; char s1 = ' '; char s2 = ' ';
    int i = 0;

    while (i != 6)
    {
        system("cls"); // borrar la pantalla (clear screen)
        cout << "\n\Welcome to tic tac toe, please select an option\n";
        cout << "\n1.- Register the name players and the symbol";
        cout << "\n2.- PLAY GAME";
        cout << "\n3.- Exit";
        cout << "\nChoose an option: \n";
        cin >> i;
        switch (i)
        {
            case 1:
                player_names();
                pausa();
                break;
            case 2:
                while (is_there_space() && winner() != true) {
                    show_matrix(matrix_positions);
                    ask_position(name1, 1);
                    cout << endl;
                    save_position(position1,symbol1);
                    show_matrix(matrix_symbols);
                    if (winner()) {
                        cout << endl << name1 << " YOU ARE THE WINNER ;D\n";
                        break;
                    }
                    else if (is_there_space() != true) {
                        cout << endl << "UPS NO ONE WINS :( IT'S A TIE\n";
                        break;
                    }
                    show_matrix(matrix_positions);
                    ask_position(name2, 2);
                    cout << endl;
                    save_position(position2, symbol2);
                    show_matrix(matrix_symbols);
                    if (winner()) {
                        cout << endl << name2 << " YOU ARE THE WINNER ;D\n";
                        break;
                    }
                    else if (is_there_space() != true) {
                        cout << endl << "UPS NO ONE WINS :( IT'S A TIE\n";
                        break;
                    }
                }
                pausa();
                break;
                case 3: exit(1);
        }
    }
    system("pause");
    return 0;
}