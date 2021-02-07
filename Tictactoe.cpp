// Tictactoe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdlib.h>
using namespace std;

void check(int *c , char v[3][3] , char w) {

    if ((v[1][0] == v[1][1] && v[1][1]== v[1][2]) || (v[0][0] == v[0][1] && v[0][1] == v[0][2]) || (v[2][0] == v[2][1] && v[2][1] == v[2][1]) || (v[0][0] == v[1][0] && v[1][0] == v[2][0]) || (v[0][1] == v[1][1] && v[1][1] == v[2][1]) || (v[0][2] == v[1][2] && v[1][2] == v[2][2]) || (v[0][0] == v[1][1] && v[1][1] == v[2][2]) || (v[2][0] == v[1][1] && v[1][1] == v[0][2])) {

        cout << "THE WINNER IS " << w << endl;
        *c += 9;
    }
    else {
        cout << "TIC TAK TOE  " << endl;
        *c += 1;
    }
    
}

char Display(char x[3][3]) {

    cout << "   | |    | |    "<<endl;
    cout << " "<<x[0][0]<<" | |  "<<x[0][1]<<" | | "<<x[0][2] << endl;
    cout << "___| |____| |____" << endl;
    cout << "___| |____| |____" << endl;
    cout << "   | |    | |    " << endl;
    cout << " " << x[1][0] << " | |  " << x[1][1] << " | | " << x[1][2] << endl;
    cout << "___| |____| |____" << endl;
    cout << "___| |____| |____" << endl;
    cout << "   | |    | |    " << endl;
    cout << " " << x[2][0] << " | |  " << x[2][1] << " | |" << x[2][2] << endl;
    cout << "   | |    | |    "<<endl;
    return 0;
}
int main()
{
    int i=1,x;
    char play[3][3] = {
    {'9','8','7'},
    {'6','5','4'},
    {'3','2','1'}
    },XO,X='X',O='O';
    bool ocuppied[10] = {0,0,0,0,0,0,0,0,0,0};


    while (i < 10) {

        system("CLS");

        if (i % 2 == 0) {
            XO = 'X'; cout << "PLAYER X TURN" << endl;
            check(&i, play,O);
        }
        else
        {
            XO = 'O'; cout << "PLAYER O TURN" << endl;
            check(&i, play,X);
        }
        Display(play);
        
        cin >> x;
        if (ocuppied[x] == 0)
        {
            switch (x) {
            case 9: play[0][0] = XO;
                break;
            case 8: play[0][1] = XO;
                break;
            case 7: play[0][2] = XO;
                break;
            case 6: play[1][0] = XO;
                break;
            case 5: play[1][1] = XO;
                break;
            case 4: play[1][2] = XO;
                break;
            case 3: play[2][0] = XO;
                break;
            case 2: play[2][1] = XO;
                break;
            case 1: play[2][2] = XO;
                break;
              }
            ocuppied[x] = 1;
        }
        else if(ocuppied[x]==1)
        {
            cout << "invalid input" << '\a';
            i -= 1;
            cin.get();
        }
 
    }
    return 0;
}

