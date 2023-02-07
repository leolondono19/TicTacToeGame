#include <iostream>
using namespace std;
string name1; string name2; char s1; char s2;
int n1;
int n2;
char matrix[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char matrix1[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };
void player_names(void) {
    cout << "Player 1 introduce your name: "; cin >> name1;
    cout << "Player 2 introduce your name: "; cin >> name2;
    cout << endl;
    cout << name1 << " introduce your symbol: "; cin >> s1;
    cout << name2 << " introduce your symbol: "; cin >> s2;
}
void ask_position1() {
    cout << name1 << " What position do you want to choose?: "; cout << endl;
    cin >> n1;
}
void ask_position2() {
    cout << name2 << " What posistion do you want to choose: "; cout << endl;
    cin >> n2;
}
void mostrar_matrix() {
    /*
     x | x | x
    ---|---|---
     x | x | x
    ---|---|---
     x | x | x
    */
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

        // Newline for new row
        cout << endl;
    }
    cout << endl;
}
void positions_player1() {
    if (n1 == 9) {
        matrix1[2][2] = s1;
    }
    else if (n1 == 8) {
        matrix1[2][1] = s1;
    }
    else if (n1 == 7) {
        matrix1[2][0] = s1;
    }
    else if (n1 == 6) {
        matrix1[1][2] = s1;
    }
    else if (n1 == 5) {
        matrix1[1][1] = s1;
    }
    else if (n1 == 4) {
        matrix1[1][0] = s1;
    }
    else if (n1 == 3) {
        matrix1[0][2] = s1;
    }
    else if (n1 == 2) {
        matrix1[0][1] = s1;
    }
    else if (n1 == 1) {
        matrix1[0][0] = s1;
    }

}
void positions_player2() {
    if (n2 == 9) {
        matrix1[2][2] = s2;
    }
    else if (n2 == 8) {
        matrix1[2][1] = s2;
    }
    else if (n2 == 7) {
        matrix1[2][0] = s2;
    }
    else if (n2 == 6) {
        matrix1[1][2] = s2;
    }
    else if (n2 == 5) {
        matrix1[1][1] = s2;
    }
    else if (n2 == 4) {
        matrix1[1][0] = s2;
    }
    else if (n2 == 3) {
        matrix1[0][2] = s2;
    }
    else if (n2 == 2) {
        matrix1[0][1] = s2;
    }
    else if (n2 == 1) {
        matrix1[0][0] = s2;
    }

}
void mostrar_matrix1() {
    for (int i = 0; i < 3; i++)
    {
        if (i != 0) {
            cout << "--|---|--";
        }

        cout << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << matrix1[i][j] << " ";
            if (j != 2) {
                cout << "| ";
            }
        }

        // Newline for new row
        cout << endl;
    }
}
bool winner() {
    bool condition1 = matrix1[0][0] == s1 && matrix1[0][1] == s1 && matrix1[0][2] == s1 || matrix1[0][0] == s2 && matrix1[0][1] == s2 && matrix1[0][2] == s2;
    bool condition2 = matrix1[1][0] == s1 && matrix1[1][1] == s1 && matrix1[1][2] == s1 || matrix1[1][0] == s2 && matrix1[1][1] == s2 && matrix1[1][2] == s2;
    bool condition3 = matrix1[2][0] == s1 && matrix1[2][1] == s1 && matrix1[2][2] == s1 || matrix1[2][0] == s2 && matrix1[2][1] == s2 && matrix1[2][2] == s2;
    bool condition4 = matrix1[0][0] == s1 && matrix1[1][0] == s1 && matrix1[2][0] == s1 || matrix1[0][0] == s2 && matrix1[1][0] == s2 && matrix1[2][0] == s2;
    bool condition5 = matrix1[0][1] == s1 && matrix1[1][1] == s1 && matrix1[2][1] == s1 || matrix1[0][1] == s2 && matrix1[1][1] == s2 && matrix1[2][1] == s2;
    bool condition6 = matrix1[0][2] == s1 && matrix1[1][2] == s1 && matrix1[2][2] == s1 || matrix1[0][2] == s2 && matrix1[1][2] == s2 && matrix1[2][2] == s2;
    bool condition7 = matrix1[0][0] == s1 && matrix1[1][1] == s1 && matrix1[2][2] == s1 || matrix1[0][0] == s2 && matrix1[1][1] == s2 && matrix1[2][2] == s2;
    bool condition8 = matrix1[0][2] == s1 && matrix1[1][1] == s1 && matrix1[2][0] == s1 || matrix1[0][2] == s2 && matrix1[1][1] == s2 && matrix1[2][0] == s2;
    if (condition1 || condition2 || condition3 || condition4 || condition5 || condition6 || condition7 || condition8) {
        return true;
    }
    return false;
}
bool is_there_space() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix1[i][j] == ' ') {
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
    int n = 0; //string name1;  string name2; char s1 = ' '; char s2 = ' ';
    int i = 0;
    while (i != 6)
    {
        system("cls"); // borrar la pantalla (clear screen)
        cout << "\n\Welcome to tic tac toe, please select an option\n";
        cout << "\n1.- Register the name players and the symbol";
        cout << "\n2.- PLAY GAME";
        cout << "\n5.- Exit";
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
                mostrar_matrix();
                ask_position1();
                cout << endl;
                positions_player1();
                mostrar_matrix1();
                if (winner()) {
                    cout << endl << name1 << " YOU ARE THE WINNER ;D\n";
                    break;
                }
                else if (is_there_space() != true) {
                    cout << endl << "UPS NO ONE WINS :( IT'S A TIE\n";
                    break;
                }
                    mostrar_matrix();
                    ask_position2();
                    cout << endl;
                    positions_player2();
                    mostrar_matrix1();
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
        case 4: exit(1);
        }
    }
    system("pause");
}