/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-tom.bartoccioni
** File description:
** GameSnake
*/

#include "GameSnake.hpp"

GameSnake::GameSnake() : _dir(RIGHT), _posx(32), _posy(32), _GameOver(0), _name("snake")
{
    IObject Obj;
    _object.push_back(Obj);
}

GameSnake::~GameSnake()
{
}

const std::vector<std::string> GameSnake::getMap() const
{
    return _map;
}

const int GameSnake::getX() const
{
    return _posx;
}

const int GameSnake::getY() const
{
    return _posy;
}

const int GameSnake::getGameOver() const
{
    return _GameOver;
}

void GameSnake::setMap(const std::vector<std::string> map)
{
    _map = map;
}

void GameSnake::run()
{
    int x = rand() % 24 + 1;
    int y = rand() % 50 + 1;
    if (_dir == UP) {
        if (_map[(_posy - 32)/32][_posx/32] == '#')
            _GameOver = 1;
        else if (_GameOver == 0)
            _posy -= 32;
    }
    if (_dir == DOWN) {
        if (_map[(_posy + 32)/32][_posx/32] == '#')
            _GameOver = 1;
        else if (_GameOver == 0)
            _posy += 32;
    }
    if (_dir == RIGHT) {
        if (_map[_posy/32][(_posx + 32)/32] == '#')
            _GameOver = 1;
        else if (_GameOver == 0)
            _posx += 32;
    }
    if (_dir == LEFT) {
        if (_map[_posy/32][(_posx - 32)/32] == '#')
            _GameOver = 1;
        else if (_GameOver == 0)
            _posx -= 32;
    }
}

void GameSnake::useEvent(const int dir)
{
    if (dir == KEY_UP)
        _dir = UP;
    if (dir == KEY_DOWN)
        _dir = DOWN;
    if (dir == KEY_LEFT)
        _dir = LEFT;
    if (dir == KEY_RIGHT)
        _dir = RIGHT;
}

std::vector<IGame::IObject> GameSnake::getObj()
{
    return _object;
}

int const GameSnake::getScore() const
{
    return _score;
}

extern "C" GameSnake *create() {
    return new GameSnake();
}