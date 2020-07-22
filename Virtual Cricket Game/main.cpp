#include "game.h"
using namespace std;

int main(){
    Game game;
    game.welcome();

    cout << "\nPress Enter to continue:";
    getchar();

    game.showAllPlayers();
    
    cout << "\nPress Enter to continue:";
    getchar();

    game.selectPlayers();    
    game.showTeamPlayers();

    cin.ignore(numeric_limits<streamsize>::max(),'\n');  // clearing input buffer memory..

    cout << "\nPress Enter to toss.";
    getchar();

    game.toss();

    game.startFirstInnings();
    game.startSecondInnings();

    game.displayScoreBoard();

    return 0;
}
