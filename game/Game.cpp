#include "Game.h"

#include <algorithm>
#include <limits.h>

void SnakeGame::addPlayer(const std::string& name){
    players_.emplace_back(Player{name});
}

uint32_t SnakeGame::getHighScore() const {
    return high_score_;
}

const std::string& SnakeGame::getBestPlayer() const {
    return best_player_;
}

void SnakeGame::play(const std::string& name){
    auto find = std::find_if(players_.begin(), players_.end(), [&name](const Player& p){ return p.getName() == name; });

    if (find == players_.end()) {
        players_.emplace_back(Player(name));
        find = std::prev(players_.end());
    }

    Graphics::get().init(game_name_);

    find->play();

    Graphics::get().finalize();


    if (find->getHighScore() > high_score_){
        high_score_ = find->getHighScore();
        best_player_ = find->getName();
    }

    std::cout << "Highscore: " << high_score_ << " by " << best_player_ << std::endl;
}

void SnakeGame::play(){
    while(1) {
        std::string name;
        std::cout << "Who's playing: ";
        std::cin >> name;
        std::cout << std::endl;


        play(name);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Do you or someone else want to play again? (yes or no): ";
        std::string ans;
        
        std::cin >> ans;
        
        if (ans != "yes") {
            std::cout << "Exiting ..." << std::endl;
            break;
        }

        std::cout << "Perfect..." << std::endl;
    }
}