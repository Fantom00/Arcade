/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-tom.bartoccioni
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <vector>

class IGame {
    public:
    class IObject
    {
        // public:
        //     ~IObject() = default;
        //     virtual const int getX() const = 0;
        //     virtual const int getY() const = 0;
        //     virtual void setX(const int x) = 0;
        //     virtual void setY(const int y) = 0;
        //     virtual const int getId() const = 0;
        //     virtual const std::vector<int> getColor() const = 0;

        //     virtual void setColor(const std::vector<int> color) = 0;

        // private:
        //     int _x, _y;
        //     int _id;
        //     std::vector<int> _color;
    };

    virtual const std::vector<std::string>getMap() const = 0;
    virtual const std::string &getName() const = 0;
    virtual const int getX() const = 0;
    virtual const int getY() const = 0;
    virtual const int getGameOver() const = 0;
    virtual void setMap(const std::vector<std::string>) = 0;
    virtual void run() = 0;
    virtual void useEvent(const int) = 0;
    virtual std::vector<IGame::IObject> getObj() = 0;
    virtual int const getScore() const = 0;

    protected:
    private:
        std::vector<IGame::IObject> _object;
};

#endif /* !IGAME_HPP_ */
