/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-tom.bartoccioni
** File description:
** GraphiqueSfml
*/

#include "GraphiqueSfml.hpp"

namespace arcade {

    // CTor
    GraphiqueSfml::GraphiqueSfml() : _lines(1600), _cols(800), _name("sfml")
    {
    }

    // DTor
    GraphiqueSfml::~GraphiqueSfml()
    {
        if (_winGame.isOpen())
            stop();
    }

    void GraphiqueSfml::init()
    {
        _open = true,
        _winGame.create(sf::VideoMode(1600, 800), "SFML window");
    }

    void GraphiqueSfml::stop() 
    {
        _open = false;
        _winGame.close();
    }

    /* ----- Getter ----- */
    // Get the last event
    int GraphiqueSfml::getEvent()
    {
        sf::Event event;
        while (_winGame.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _winGame.close();
                exit (0);
            }
            if (event.type == sf::Event::TextEntered && (event.text.unicode > 32 && event.text.unicode < 127)) {
                return event.text.unicode;
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up)) {
                return 0403;
            } else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down)) {
                return 0402;
            } else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right)) {
                return 0405;
            } else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left)) {
                return 0404;
            }
        } return 0;
    }

    /* ----- Methods ----- */
    // Start the graphique
    void GraphiqueSfml::run()
    {
        // if (!_open) {
        //     _winGame.create(sf::VideoMode(1600, 800), "SFML window");
        //     _open = !_open;
        // }
        // _winGame.clear();
        // _winGame.display();
    }
    // Print a map based on a std::string "map"
    void GraphiqueSfml::displayMap(const std::vector<std::string> map)
    {
        for (int i = 0; i != map.size(); i++) {
            for (int j = 0; map[i][j] != '\0'; j++) {
                if (map[i][j] == '0' || map[i][j] == ' ') {
                    printAsset("src/graphique/sfml/assets/sol.png", j * 32, i * 32, '0');
                } else if (map[i][j] == '1' || map[i][j] == '#') {
                    printAsset("src/graphique/sfml/assets/mur.png", j * 32, i * 32, '0');
                }
            }
        }
    }
    // Print txt at "x" and "y" pos
    void GraphiqueSfml::displayText(const int posx, const int posy, const std::string &text)
    {
        sf::Font font;
        font.loadFromFile("src/graphique/sfml/assets/arial.ttf");
        sf::Text sfText;
        sf::Vector2f vec = {(float)(posx * 1600 / 100), (float)(posy * 800 / 100)};
        sfText.setFillColor({0, 0, 0});
        sfText.setString(text);
        sfText.setFont(font);
        sfText.setCharacterSize(25);
        sfText.setPosition(vec);
        _winGame.draw(sfText);
    }
    // Print a square at "x" and "y" pos, size of "xLong" and "yLong"
    void GraphiqueSfml::displayRect(const int x, const int y, const int w, const int h, const std::vector<int> color)
    {
        sf::RectangleShape rectangle(sf::Vector2f(w, h));
        rectangle.setPosition(x, y);
        rectangle.setFillColor((sf::Color)(color[0], color[1], color[2]));
        // rectangle.setPosition((int)(x * 1600 / 100), (int)(y * 800 / 100));
        _winGame.draw(rectangle);
    }
    // Print the asset "assetName" at "x" and "y" pos, otherwise print the "otherwise" char
    void GraphiqueSfml::printAsset(const std::string assetName, const int x, const int y, const char otherwise)
    {
        sf::Sprite img_s;
        sf::Texture img_t;
        img_t.loadFromFile(assetName);
        img_s.setTexture(img_t);
        img_s.setPosition(x, y);
        // img_s.setPosition((int)(x * 800 / 100), (int)(y * 800 / 100));
        _winGame.draw(img_s);
    }
    // Clear the window
    void GraphiqueSfml::clear()
    {
        _winGame.clear();
    }
    // Refresh the window
    void GraphiqueSfml::refresh()
    {
        _winGame.display();
    }

    extern "C" GraphiqueSfml *create() {
        return new GraphiqueSfml();
    }
}