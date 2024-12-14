#include <iostream> 
#include <cmath> 
using namespace std;

enum enChoices { stone = 1, paper = 2, scusser = 3 };
enum Russlet { lose = 0, win = 1, draw = 2 };
int HowManyRound() {
    cout << "Please enter how many Round you nead to play\n";
    int num;
    cin >> num;

    return num;
}
int randomNum(int from, int to) {
    int number = rand() % (to - from + 1) + from;
    return number;
}

enChoices UserChoice() {
    cout << "Your choice stone=1  paper=2  scusser=3\n";
    int ChoisesUser;
    cin >> ChoisesUser;
    return enChoices(ChoisesUser);


}
Russlet theGame(enChoices Choices) {
    enChoices number = enChoices(randomNum(1, 3));

    switch (number) {
    case stone:
    {
        cout << "Computer choice is stone\n";
        if (Choices == paper) {

            system("color 2F");
            cout << "Player one choice is paper\nRound Win\n";
            return win;
        }
        else if (Choices == scusser)
        {
            system("color 4F");
            cout << "\a";
            cout << "Player one choice is scusser\nRound Lose\n";
            return lose;
        }
        else if (Choices == stone)
        {
            system("color 6F");
            cout << "Player one choice is stone\nRound Draw\n";
            return draw;
        }
    }
    break;
    case paper: {
        cout << "Computer choice is paper\n";
        if (Choices == paper) {

            system("color 6F");
            cout << "Player one choice is paper\nRound Draw\n";
            return draw;
        }
        else if (Choices == scusser)
        {
            system("color 2F");
            cout << "\a";
            cout << "Player one choice is scusser\nRound win\n";
            return win;
        }
        else if (Choices == stone)
        {
            system("color 6F");
            cout << "\a";
            cout << "Player one choice is stone\nRound Lose\n";
            return lose;
        }
    }
              break;



    case scusser: {
        cout << "Computer choice is scusser\n";
        if (Choices == paper) {

            system("color 4F");
            cout << "\a";
            cout << "Player one choice is paper\nRound Lose\n";
            return lose;
        }
        else if (Choices == scusser)
        {
            system("color 6F");
            cout << "Player one choice is scusser\nRound Draw\n";
            return draw;
        }
        else if (Choices == stone)
        {
            system("color 2F");
            cout << "Player one choice is stone\nRound Win\n";
            return win;
        }
    }
                break;




    }
}
void RoundOfTheGamee(int num) {
    int WINcount = 0;
    int LOSEcount = 0;
    int DRAWcount = 0;
    int i = 0;
    for (; i < num; i++) {
        cout << "            ROUND [" << i + 1 << "] START\n";
        cout << "----------------------------------\n";
        int Result = theGame(UserChoice());
        cout << "----------------------------------\n";
        if (Result == 0) {
            LOSEcount++;

        }
        else if (Result == 1) {
            WINcount++;
        }
        else if (Result == 2) {
            DRAWcount++;
        }



    }
    if (DRAWcount >= LOSEcount && DRAWcount >= WINcount) {
        system("color6F");
        cout << "\n--------------------------------------\n";
        cout << "                NO WINNER               \n";
        cout << "\n--------------------------------------\n";
        cout << "Game rounds :" << num << "\nPLAYER 1 WON TIMES :" << WINcount << "\nComputer won time\n" << LOSEcount << "\nDraw times :" << DRAWcount;


    }
    else if (LOSEcount > WINcount) {
        system("color4F");
        cout << "\n--------------------------------------\n";
        cout << "                YOU ARE LOSER              \n";
        cout << "\n--------------------------------------\n";
        cout << "Game rounds :" << num << "\nPLAYER 1 WON TIMES :" << WINcount << "\nComputer won time\n" << LOSEcount << "\nDraw times :" << DRAWcount;


    }
    else if (WINcount > LOSEcount) {
        system("color2F");
        cout << "\n--------------------------------------\n";
        cout << "                YOU ARE WINNER             \n";
        cout << "\n--------------------------------------\n";
        cout << "Game rounds :" << num << "\nPLAYER 1 WON TIMES :" << WINcount << "\nComputer won time\n" << LOSEcount << "\nDraw times :" << DRAWcount;


    }

}
int main() {
    bool PlayAgain = 1;
    if (PlayAgain) {
        RoundOfTheGamee(HowManyRound());
        cout << "Do you need to play again YES:1   NO:0\n";
        cin >> PlayAgain;
    }

    return 0;
}