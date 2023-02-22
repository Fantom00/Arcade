/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-tom.bartoccioni
** File description:
** Core
*/

#include <string>
#include "../games/IGame.hpp"
#include "../graphique/IDisplay.hpp"
// #include "../graphique/ncurse/GraphiqueNCurse.hpp"
// #include "../graphique/sfml/GraphiqueSfml.hpp"
// #include "../games/pacman/GamePacman.hpp"
// #include "../games/snake/GameSnake.hpp"
#include "../DLLoader.hpp"
#include <ncurses.h>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#ifndef CORE_HPP_
#define CORE_HPP_

namespace arcade {
    class Core {
        public:
            // CTor where "gameName" is the game and "libName" is the lib
            Core(std::string plibPath);
            // DTor
            ~Core();

            /* ----- Methods ----- */
            // Start and run the arcade with the game "_game" and the lib "_graphique"
            int Start();
            // Run the game
            int Run();
            // True for the next lib & False for the previous lib
            void SwitchLib(bool direction);
            // Init next lib
            void initGraphicLib();

        protected:
        private:
            DLLoader <IGame> _dlGame;
            std::vector<DLLoader <IDisplay>> _graphicLoader;
            std::vector<IDisplay*>::const_iterator _iterator;
            IGame *_game;                            // The game currently running
            std::vector<IDisplay*> _graphique;       // The lib currently running
            std::string _gameName;
            std::string _libName;
            int _event;                 // Last event get
    };
}

#endif /* !CORE_HPP_ */
