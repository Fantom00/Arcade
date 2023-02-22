/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-tom.bartoccioni
** File description:
** main
*/

#include "core/Core.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Your program must take 1 arguments : the link to your graphical lib" << std::endl;
        return 84;
    }

    // DLLoader<IDisplay> dlLoader;
    // dlLoader.open(argv[1]);
    // std::unique_ptr<IDisplay> disp(dlLoader.getInstance("create"));

    // DLLoader<IDisplay> dlLib;
    // dlLib.open("./lib/arcade_sfml.so");
    // std::unique_ptr<IDisplay> grap(dlLib.getInstance("create"));

    // DLLoader<IGame> dlGame;
    // dlGame.open("./lib/arcade_nibbler.so");
    // std::unique_ptr<IGame> game(dlGame.getInstance("create"));

    // if (strcmp(disp->getName().c_str(), "ncurses") != 0 && strcmp(disp->getName().c_str(), "sfml") != 0
    //     && strcmp(grap->getName().c_str(), "sfml") != 0 || strcmp(game->getName().c_str(), "snake") != 0) {
    //     std::cerr << "Lib must be 'ncurses' or 'sfml'" << std::endl;
    //     return 84;
    // }

    // arcade::Core Core(game.release(), disp.release(), grap.release());
    // dlLoader.close();
    // dlLib.close();
    // dlGame.close();
    arcade::Core Core(argv[1]);
    return Core.Start();
}