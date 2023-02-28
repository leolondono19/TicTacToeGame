#include <iostream>
#include <conio.h>
                    
using namespace std;

class Player {
public:
    string Name;
    char Symbol;
    void ask_player_name() {
        cout << "Introduce your name: "; cin >> Name;
        cout << endl;
    }
    void ask_player_symbol() {
        cout << Name << " Introduce your symbol: "; cin >> Symbol;
        cout << endl;
    }
};

int position1, position2;
char matrix_positions[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char matrix_symbols[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };

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

void ask_table_position(string name, int player_number) {
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

bool Is_there_a_winner(Player p1, Player p2) {
    bool condition1 = matrix_symbols[0][0] == p1.Symbol && matrix_symbols[0][1] == p1.Symbol && matrix_symbols[0][2] == p1.Symbol || matrix_symbols[0][0] == p2.Symbol && matrix_symbols[0][1] == p2.Symbol && matrix_symbols[0][2] == p2.Symbol;
    bool condition2 = matrix_symbols[1][0] == p1.Symbol && matrix_symbols[1][1] == p1.Symbol && matrix_symbols[1][2] == p1.Symbol || matrix_symbols[1][0] == p2.Symbol && matrix_symbols[1][1] == p2.Symbol && matrix_symbols[1][2] == p2.Symbol;
    bool condition3 = matrix_symbols[2][0] == p1.Symbol && matrix_symbols[2][1] == p1.Symbol && matrix_symbols[2][2] == p1.Symbol || matrix_symbols[2][0] == p2.Symbol && matrix_symbols[2][1] == p2.Symbol && matrix_symbols[2][2] == p2.Symbol;
    bool condition4 = matrix_symbols[0][0] == p1.Symbol && matrix_symbols[1][0] == p1.Symbol && matrix_symbols[2][0] == p1.Symbol || matrix_symbols[0][0] == p2.Symbol && matrix_symbols[1][0] == p2.Symbol && matrix_symbols[2][0] == p2.Symbol;
    bool condition5 = matrix_symbols[0][1] == p1.Symbol && matrix_symbols[1][1] == p1.Symbol && matrix_symbols[2][1] == p1.Symbol || matrix_symbols[0][1] == p2.Symbol && matrix_symbols[1][1] == p2.Symbol && matrix_symbols[2][1] == p2.Symbol;
    bool condition6 = matrix_symbols[0][2] == p1.Symbol && matrix_symbols[1][2] == p1.Symbol && matrix_symbols[2][2] == p1.Symbol || matrix_symbols[0][2] == p2.Symbol && matrix_symbols[1][2] == p2.Symbol && matrix_symbols[2][2] == p2.Symbol;
    bool condition7 = matrix_symbols[0][0] == p1.Symbol && matrix_symbols[1][1] == p1.Symbol && matrix_symbols[2][2] == p1.Symbol || matrix_symbols[0][0] == p2.Symbol && matrix_symbols[1][1] == p2.Symbol && matrix_symbols[2][2] == p2.Symbol;
    bool condition8 = matrix_symbols[0][2] == p1.Symbol && matrix_symbols[1][1] == p1.Symbol && matrix_symbols[2][0] == p1.Symbol || matrix_symbols[0][2] == p2.Symbol && matrix_symbols[1][1] == p2.Symbol && matrix_symbols[2][0] == p2.Symbol;
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
void initialize_matrix_symbols() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix_symbols[i][j] = ' ';
        }
    }
}
void pausa() {
    system("pause");
}
int main() {
    Player p1;
    Player p2;
    char again;
    int n = 0; //string name1;  string name2; char s1 = ' '; char s2 = ' ';
    int i = 0;

    do 
    {
        initialize_matrix_symbols();
        system("cls"); // borrar la pantalla (clear screen)
        cout << "\n\Welcome to tic tac toe, please select an option\n";
        cout << "\n1.- PLAY GAME";
        cout << "\n2.- Exit";
        cout << "\nChoose an option: \n";
        cin >> i;
        switch (i)
        {
            case 1:
                p1.ask_player_name();
                p2.ask_player_name();
                p1.ask_player_symbol();
                p2.ask_player_symbol();
                pausa();
                system("cls");
                while (is_there_space() && Is_there_a_winner(p1, p2) != true) {
                    show_matrix(matrix_positions);
                    ask_table_position(p1.Name, 1);
                    cout << endl;
                    save_position(position1,p1.Symbol);
                    show_matrix(matrix_symbols);
                    if (Is_there_a_winner(p1, p2)) {
                        cout << endl << p1.Name << " YOU ARE THE WINNER ;D\n";
                        break;
                    }
                    else if (is_there_space() != true) {
                        cout << endl << "UPS NO ONE WINS :( IT'S A TIE\n";
                        break;
                    }
                    show_matrix(matrix_positions);
                    ask_table_position(p2.Name, 2);
                    cout << endl;
                    save_position(position2, p2.Symbol);
                    show_matrix(matrix_symbols);
                    if (Is_there_a_winner(p1, p2)) {
                        cout << endl << p2.Name << " YOU ARE THE WINNER ;D\n";
                        break;
                    }
                    else if (is_there_space() != true) {
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