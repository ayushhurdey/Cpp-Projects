#include <vector>
#include "players.h"   // <string>

class Team{
    public:
        Team();
        std::string name;
        int totalRunsScored;
        int wicketsLost;
        int totalBallsBowled;
        std::vector<Player> players;

};
