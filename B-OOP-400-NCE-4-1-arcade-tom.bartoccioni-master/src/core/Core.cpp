/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-tom.bartoccioni
** File description:
** Core
*/

#include "Core.hpp"

std::vector<std::string> read_map(std::string filename)
{
    std::ifstream file("src/games/snake/maps/map1.txt");
    std::vector<std::string> vect;
    std::string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            vect.push_back(line);
        }
    } else {
        std::cerr << "File does not exist" << std::endl;
        exit (84);
    }
    return vect;
}

namespace arcade {
    // CTor
    // Core::Core(IGame *game, IDisplay *lib, IDisplay *lib2) :
        // _gameName(game->getName()),
        // _libName(lib->getName()),
        // _game(game),
        // _graph(0)
    // {
        // _graphique.push_back(lib);
        // _graphique.push_back(lib2);
    // }
    Core::Core(std::string libPath)
    {
        _graphicLoader.emplace_back();
        _graphicLoader[0].open(libPath);
        _graphique.push_back(_graphicLoader[0].getInstance("create"));

        _graphicLoader.emplace_back();
        _graphicLoader[1].open("./lib/arcade_sfml.so");
        _graphique.push_back(_graphicLoader[1].getInstance("create"));

        _dlGame.open("./lib/arcade_nibbler.so");
        std::unique_ptr<IGame> game(_dlGame.getInstance("create"));
        _game = game.release();

        _iterator = _graphique.cbegin();
        initGraphicLib();
    }

    Core::~Core()
    {
        for (auto it : _graphique) {
            delete it;
        }
        for (auto it : _graphicLoader) {
            it.close();
        }
        delete _game;
        _dlGame.close();
    }

    void Core::SwitchLib(bool direction)
    {
        (*_iterator)->stop();
        if (direction == true) {
            std::cout << "tu es passé a la lib suivante" << std::endl;
            _iterator ++;
            if (_iterator == _graphique.cend())
                _iterator = _graphique.cbegin();
        }
        if (direction == false) {
            std::cout << "tu es passé a la lib précédente" << std::endl;
            if (_iterator == _graphique.cbegin())
                _iterator = _graphique.cend();
            _iterator --;
        }
        initGraphicLib();
    }

    void Core::initGraphicLib()
    {
        (*_iterator)->init();
    }

    int Core::Run()
    {
        // std::unique_ptr<IGame> New = std::make_unique<GamePacman>();
        while ((*_iterator))
        {
            _event = (*_iterator)->getEvent();
            if (_event == 'y') this->SwitchLib(true);
            _game->useEvent(_event);
            _game->run();
            //(*_iterator)->displayMap(_game->getMap());
            (*_iterator)->run();
        }
        return 0;
    }

    int Core::Start()
    {
        clock_t t1, t2;
        t1 = clock();
        const std::vector<std::string> mmap = read_map("src/games/snake/maps/map1.txt");
        _game->setMap(mmap);
        while ((char)_event != 'q') {
            t2 = clock();
            if ((double)(t2-t1)/((double)CLOCKS_PER_SEC / 100) > 30) {
                (*_iterator)->clear();
                (*_iterator)->displayMap(mmap);
                (*_iterator)->displayRect(_game->getX(), _game->getY(), 32, 32);
                _event = (*_iterator)->getEvent();
                _game->useEvent(_event);
                _game->run();
                if (_game->getGameOver() == 1)
                    (*_iterator)->displayText(45,40, "GAME OVER\nPress Q to quit");
                if ((char)_event == 'y') this->SwitchLib(true);
                if ((char)_event == 'u') this->SwitchLib(false);
                (*_iterator)->refresh();
                (*_iterator)->run();
                t1 = clock();
            }
        }
        return 0;
    }
}