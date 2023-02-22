/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-tom.bartoccioni
** File description:
** GameSnake
*/

// VOIR POUR AJOUTER D'UNE MANIERE OU D'UNE AUTRE UN FRUIT
#include "IncludeSnake.hpp"

#ifndef GAMESNAKE_HPP_
#define GAMESNAKE_HPP_

class GameSnake : public IGame{
public:
    GameSnake();
    ~GameSnake();

    const std::vector<std::string> getMap() const;
    const std::string &getName() const {return _name;}
    const int getX() const;
    const int getY() const;
    const int getGameOver() const;
    void setMap(const std::vector<std::string> map);
    void run();
    void useEvent(const int);
    std::vector<IGame::IObject> getObj();
    int const getScore() const;
    enum Direction { UP, DOWN, LEFT, RIGHT };

    protected:
    private:
        std::string _name;
        int _score;
        int _status;
        std::vector<IGame::IObject> _object;
        std::vector<std::string> _map;
        Direction _dir;
        int _posx;
        int _posy;
        int _GameOver;
};

#endif /* !GAMESNAKE_HPP_ */
