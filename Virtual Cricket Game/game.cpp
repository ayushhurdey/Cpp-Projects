#include "game.h"
using namespace std;    // to use cout and other std related functions

Game :: Game(){

    playersPerTeam = 4;
    maxBalls = 6;
    totalPlayers = 11;

    players[0] = "Virat K";
    players[1] = "Rohit S";
    players[2] = "Dhawan";
    players[3] = "R Pant";
    players[4] = "Karthik";
    players[5] = "KL Rahul";
    players[6] = "Jadeja";
    players[7] = "Hardik";
    players[8] = "Bumrah";
    players[9] = "B Kumar";
    players[10] = "Ishant";

    isFirstInnings = false;
    teamA.name = "Team-A";
    teamB.name = "Team-B";
}

void Game :: welcome(){
    cout  << "-----------------------------------------------------" << endl;
    cout  << "|====================== CRIC-IN ====================|" << endl;
    cout  << "|                                                   |" << endl;
    cout  << "|          Welcome to virtual Cricket Game          |" << endl;
    cout  << "-----------------------------------------------------" << endl;

    cout << endl << endl;

    cout  << "---------------------------------------------------- " << endl;
    cout  << "|==================== Instructions =================|" << endl;
    cout  << "|---------------------------------------------------|" << endl;
    cout  << "|                                                   |" << endl;
    cout  << "| 1. Create two teams (Team-A and Team-B with 4     |" << endl;
    cout  << "|    players each) from a given pool of 11 players. |" << endl;
    cout  << "| 2. Lead the toss and decide the choice of play.   |" << endl;
    cout  << "| 3. Each innings will be of 6 balls.               |" << endl;
    cout  << "-----------------------------------------------------" << endl;

}

void Game :: showAllPlayers(){
    
    cout << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "|=================== Pool of Players ================|" << endl;
    cout << "------------------------------------------------------" << endl;   
    cout << endl;

    for(int i=0; i < totalPlayers; i++)
        cout << "\t\t["<< i << "]" << players[i] <<  endl;   
}

int Game :: takeIntegerInput(){
    int n;
    
    while(!(cin >> n)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears the i/p buffer memory including '\n' at the end.   used from  <limits>
        cout << "Invalid input !! Please try again with valid input: ";
    }
    return n;
}


bool Game :: validateSelectedPlayer(int index){
     int n;
     vector<Player> players;

     players = teamA.players;   // objects of team-A players 
     n = players.size();
     for(int i = 0; i < n; i++){
        if(players[i].unique_id == index){
          return false;
        }
     }

    players = teamB.players;
    n = players.size();
    for(int i = 0; i < n ;i++){
        if(players[i].unique_id == index){
            return false;
        }
    }

    return true;
}


void Game :: selectPlayers(){
    cout << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "|=============== Create Team-A and Team-B ============|" << endl;
    cout << "-------------------------------------------------------" << endl;

    for (int i=0; i< playersPerTeam; i++){

        // Add Player to Team-A
        teamASelection:
            cout << endl << "Select Player " << i+1 << " of Team A - ";

            int playerIndexTeamA =takeIntegerInput(); 
            
            // to prevent from invalid out of pool players selection.
            if(playerIndexTeamA < 0 || playerIndexTeamA > 10){
                cout << endl << "!! Please select for the given pool of players only." << endl;
                goto teamASelection;
            } else if(!validateSelectedPlayer(playerIndexTeamA)){
                  cout << endl << "Player has already been selected. Please select another player." << endl;
                  goto teamASelection;
            } else{
                Player teamAPlayer;
                teamAPlayer.unique_id = playerIndexTeamA;
                teamAPlayer.name = players[playerIndexTeamA];
                teamA.players.push_back(teamAPlayer);    // players is a vector in class Team
            }


        // Add Player to Team-B
        teamBSelection:
            cout << endl << "Select Player " << i+1 << " of Team B - ";

            int playerIndexTeamB = takeIntegerInput(); 
            
            // to prevent from invalid out of pool players selection.
            if(playerIndexTeamB < 0 || playerIndexTeamB > 10){
                cout << endl << "!! Please select for the given pool of players only." << endl;
                goto teamBSelection;
            } else if(!validateSelectedPlayer(playerIndexTeamB)){
                  cout << endl << "Player has already been selected. Please select another player." << endl;
                  goto teamBSelection;
            } else{
                Player teamBPlayer;
                teamBPlayer.unique_id = playerIndexTeamB;
                teamBPlayer.name = players[playerIndexTeamB];
                teamB.players.push_back(teamBPlayer);
            }
    }

}

void Game :: showTeamPlayers(){
      vector<Player> teamAPlayers = teamA.players;
      vector<Player> teamBPlayers = teamB.players;

      cout << endl << endl;
      cout << "----------------------\t\t----------------------" <<endl;
      cout << "|====== Team A ======|\t\t|====== Team B ======|" <<endl;
      cout << "----------------------\t\t----------------------" <<endl;
      
      for(int i = 0; i < playersPerTeam; i++){
            cout << "|\t" <<"[" << i << "]" << teamAPlayers[i].name << "\t\t |"
                << "\t\t"
                << "|\t" <<"[" << i << "]" << teamBPlayers[i].name << "\t\t |" << endl;
      }
      cout << "----------------------\t\t----------------------" <<endl << endl;
}

void Game :: toss(){
      cout << endl;
      cout << "------------------------------------------------" << endl;
      cout << "|================= Let's TOSS =================|" << endl;
      cout << "------------------------------------------------" << endl << endl;

      cout << "Tossing the coin..." << endl << endl;
      
      srand(time(NULL));     // to set the seed changing continuously with time as time is keep on changing so we do not get the same random sequence each time.
      int randomValue = rand() % 2;    // to choose randomly either 1 or 0 only.
      switch(randomValue){
            case 0: 
                  cout << "Team-A won the toss." << endl << endl;
                  tossChoice(teamA);
                  break;
            case 1:
                  cout << "Team-B won the toss." << endl << endl;
                  tossChoice(teamB);
                  break;                        
      }
}


void Game :: tossChoice(Team tossWinnerTeam){
        cout << "Enter 1 to bat or 2 to bowl first." << endl
             << "1. Bat" << endl
             << "2. Bowl " << endl; 
        int tossInput = takeIntegerInput();  

        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        switch(tossInput){
              case 1:
                    cout << endl << tossWinnerTeam.name << " won the toss and elected to bat first." << endl << endl;
                    
                    // if Team-A is the toss Winner and wants to bat...
                    if(tossWinnerTeam.name.compare("Team-A") == 0){     // .compare is the string function.
                          battingTeam = &teamA;                        
                          bowlingTeam = &teamB;
                    }else{                // else Team-B is the toss winner and wants to bat...
                          battingTeam = &teamB;
                          battingTeam = &teamA;
                    }
                    break;
              case 2:
                    cout << endl << tossWinnerTeam.name << " won the toss and elected to bowl first. " << endl << endl;

                    // if Team-A is the toss Winner and wants to bowl...
                    if(tossWinnerTeam.name.compare("Team-A") == 0){     // .compare is the string function.
                          bowlingTeam = &teamA;                        
                          battingTeam = &teamB;
                    }else{              // else Team-B is the toss winner and wants to bowl...
                          bowlingTeam = &teamB;
                          battingTeam = &teamA;
                    }
                    break; 
              default:
                    cout << "Invalid input!! Please try again." << endl << endl;
                    tossChoice(tossWinnerTeam);     // recursively calling function until the right choice is provided..
                    break;
        }   
}

void Game :: startFirstInnings(){
      cout << "\t\t ||| FIRST INNINGS STARTS |||" <<  endl << endl;
      isFirstInnings = true;

      initializePlayers();
      playInnings();
}

void Game :: initializePlayers(){
      // Choose batsman and bowler: Initialize *batsman and *bowler 

      batsman =  &battingTeam->players[0];  //accessing batting team first player from the vector of players of batting team object.
      bowler  =  &bowlingTeam->players[0];  //accessing bowling team first player from the vector of players of bowling team object.

      cout << battingTeam->name << " - " << batsman->name << " is batting" << endl;
      cout << bowlingTeam->name << " - " << bowler->name << " is bowling" << endl << endl;
}

void Game :: playInnings(){
    for(int i = 0; i < maxBalls;i++){   // maxBalls = 6
         
         cout << "Press Enter to bowl...";
         getchar();
         cout << "Bowling..." << endl;
         bat();
         
         // if either all out or all balls bowled(6).current Inning finished.
         if(!validateInningsScore()){
             break;
         }
    }
}


void Game :: bat(){
       srand(time(NULL));
       int runsScored =  rand() % 7;  // getting runs between 0-6 and declared OUT for 0.

       // update batting team and batsman score with each ball bowled.
       batsman->runsScored = batsman->runsScored + runsScored;
       battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
       batsman->ballsPlayed = batsman->ballsPlayed + 1;

       // update bowling team and bowler score with each ball bowled.
       bowler->ballsBowled = bowler->ballsBowled + 1;
       bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
       bowler->runsGiven = bowler->runsGiven + runsScored;

       if(runsScored != 0){   // if runsScored = 1,2,3,4,5 or 6
             cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
             showGameScoreCard();
       } else{                 // if runsScored = 0 and the batsman is "OUT".
             cout << endl << bowler->name << " to " << batsman->name  << " OUT!" << endl << endl;
             battingTeam->wicketsLost = battingTeam->wicketsLost +1;
             bowler->wicketsTaken = bowler->wicketsTaken + 1;
             
             showGameScoreCard();

             // to get the next batsman 
             int nextPlayerIndex =  battingTeam->wicketsLost;
             batsman = &battingTeam->players[nextPlayerIndex];
       }
}


bool Game :: validateInningsScore(){
      
      if (isFirstInnings) {
         
            if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {
                  cout << "\t\t ||| FIRST INNING ENDS |||" << endl << endl;
                  cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - " 
                        << battingTeam->wicketsLost << "(" << bowlingTeam->totalBallsBowled
                        << ")" << endl;
                  cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1
                        << " runs to win the match." << endl << endl;        
                  return false;
            }
      } else {      // else 2nd innings
            //................................................//
            //cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

            //cout << "Total runs of Ist Inning - " <<  bowlingTeam->totalRunsScored << endl;
            if (battingTeam->totalRunsScored > bowlingTeam->totalRunsScored){

                   cout << "\t\t ||| SECOND INNING ENDS |||" << endl << endl;
                   cout << battingTeam->name << " WON THE MATCH by " 
                          << battingTeam->totalRunsScored - bowlingTeam->totalRunsScored 
                          << " runs." << endl << endl;
                   cout << "||| MATCH ENDS |||" << endl << endl;
                   return false; 
            } else if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls){
                   
                   cout << "\t\t ||| SECOND INNING ENDS |||" << endl << endl;
                   if (battingTeam->totalRunsScored == bowlingTeam->totalRunsScored){
                        
                        cout << "MATCH IS TIED between "<< battingTeam->name << " and " 
                        << bowlingTeam->name << endl << endl; 
                        return false;
                   } else {
                        
                        cout << bowlingTeam->name << " WON THE MATCH by " 
                               << bowlingTeam->totalRunsScored - battingTeam->totalRunsScored 
                               << " runs." << endl << endl;
                        cout << "||| MATCH ENDS |||" << endl << endl;         
                        return false;         
                   }  
            }
      }

      return true;
}


void Game :: showGameScoreCard(){

    cout << "------------------------------------------------------------------" << endl;
    cout << "\t" << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
        << battingTeam->wicketsLost << "(" << bowlingTeam->totalBallsBowled << ") | " 
        << batsman->name << " " << batsman->runsScored << "(" << batsman->ballsPlayed 
        << ") \t" << bowler->name << " " <<  bowler->ballsBowled << " - " 
        << bowler->runsGiven << " - " << bowler->wicketsTaken << "\t" << endl;
    cout << "------------------------------------------------------------------" << endl << endl;    
}


void Game :: startSecondInnings(){
    cout << endl << endl << "\t\t ||| SECOND INNINGS STARTS |||" <<  endl << endl;
    isFirstInnings = false;

    std::swap(battingTeam,bowlingTeam);
    initializePlayers();
    playInnings();
}

void Game :: displayScoreBoard(){
        cout << endl;
        cout << battingTeam->name << " " << battingTeam->totalRunsScored << "-" << battingTeam->wicketsLost
               << " (" << bowlingTeam->totalBallsBowled << ")" << endl;
        cout << "=========================================" << endl;
        cout << "| PLAYER          BATTING     BOWLING\t|" << endl;
      
        for(int i = 0; i < playersPerTeam; i++){
              cout << "|---------------------------------------|" << endl;
              cout << "| [" << i << "] " << battingTeam->players[i].name << "\t\t" << battingTeam->players[i].runsScored 
                     << "(" << battingTeam->players[i].ballsPlayed << ")\t\t" << battingTeam->players[i].ballsBowled 
                     << "-" << battingTeam->players[i].runsGiven << "-" << battingTeam->players[i].wicketsTaken 
                     << "\t|" << endl;
        }
        cout << "=========================================" << endl;
        

     
        cout << endl << endl;
        cout << bowlingTeam->name << " " << bowlingTeam->totalRunsScored << "-" << bowlingTeam->wicketsLost
               << " (" << battingTeam->totalBallsBowled << ")" << endl;
        cout << "=========================================" << endl;
        cout << "| PLAYER          BATTING     BOWLING\t|" << endl;
      
        for(int i = 0; i < playersPerTeam; i++){
              cout << "|---------------------------------------|" << endl;
              cout << "| [" << i << "] " << bowlingTeam->players[i].name << "\t\t" << bowlingTeam->players[i].runsScored
                     << "(" << bowlingTeam->players[i].ballsPlayed << ")\t\t" << bowlingTeam->players[i].ballsBowled 
                     << "-" << bowlingTeam->players[i].runsGiven << "-" << bowlingTeam->players[i].wicketsTaken 
                     << "\t|" << endl;
        }
        cout << "=========================================" << endl;        
        
}



