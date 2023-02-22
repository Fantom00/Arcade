/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-tom.bartoccioni
** File description:
** GamePacman
*/

#include "IncludePacman.hpp"

#ifndef GAMEPACMAN_HPP_
#define GAMEPACMAN_HPP_

class GamePacman : public IGame{
public:

    const std::vector<std::string> getMap() const;
    const std::string &getName() const;
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
        int _score;
        int _status;
        std::vector<IGame::IObject> _object;
        std::vector<std::string> _map;
        Direction _dir;
        int _posx;
        int _posy;
};

#endif /* !GAMEPACMAN_HPP_ */
