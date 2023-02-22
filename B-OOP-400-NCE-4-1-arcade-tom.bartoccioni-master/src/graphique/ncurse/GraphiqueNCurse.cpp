/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-tom.bartoccioni
** File description:
** GraphiqueNCurse
*/

#include "GraphiqueNCurse.hpp"

namespace arcade {

    // CTor
    GraphiqueNCurse::GraphiqueNCurse() : _name("ncurses"),
        _lines(LINES),
        _cols(COLS)
    {
    }

    // DTor
    GraphiqueNCurse::~GraphiqueNCurse()
    {
        if (_open == true)
            stop();
    }

    void GraphiqueNCurse::init()
    {
        initscr();
        noecho();
        keypad(stdscr, TRUE);
        nodelay(stdscr, TRUE);
        curs_set(FALSE);
        _winGame = newwin(50, 100, (LINES / 2) - 25, (COLS / 2) - 50);
        wborder(_winGame, '|', '|', '-', '-', '+', '+', '+', '+');
        start_color();
        _open = true;
    }

    void GraphiqueNCurse::stop()
    {
        delwin(_winGame);
        endwin();
        _open = false;
    }

    /* ----- Getter ----- */
    // Get the last event
    int GraphiqueNCurse::getEvent()
    {
        return (int)getch();
    }

    /* ----- Methods ----- */
    // Start the graphique
    void GraphiqueNCurse::run()
    {
        if (LINES != _lines || COLS != _cols) {
            if (LINES < 50 || COLS < 100) {
                wclear(stdscr);
                wclear(_winGame);
                mvprintw(LINES / 2, (COLS / 2) - 10, "Window is to small");
            }
            else {
                delwin(_winGame);
                wclear(stdscr);
                _winGame = newwin(50, 100, (LINES / 2) - 25, (COLS / 2) - 50);
            }
            _lines == LINES;
            _cols == COLS;
        }
        this->refresh();
        this->clear();
    }
    // Print a map based on a std::string "map"
    void GraphiqueNCurse::displayMap(const std::vector<std::string> map)
    {
        // mvwprintw(_winGame, 1, 1, "11111");
        // mvwprintw(_winGame, 2, 1, "10001");
        // mvwprintw(_winGame, 3, 1, "11111");
        mvwprintw(_winGame, 1, 1, map[0].c_str());
        mvwprintw(_winGame, 2, 1, map[1].c_str());
        mvwprintw(_winGame, 3, 1, map[2].c_str()); 
    }
    // Print txt at "x" and "y" pos
    void GraphiqueNCurse::displayText(const int posx, const int posy, const std::string &text)
    {
        if (COLS < 100 || LINES < 50) return;
        mvwprintw(_winGame, (_lines * posy) / 100, (_cols * posx) / 100, text.c_str());
    }

    // Print a square at "x" and "y" pos, size of "xLong" and "yLong"
    void GraphiqueNCurse::displayRect(const int x, const int y, const int w, const int h, const std::vector<int> color)
    {
        if (COLS < 100 || LINES < 50) return;
        init_pair(1, COLOR_BLACK, COLOR_RED);
        wattron(_winGame, COLOR_PAIR(1));
        for (int i = 0; i < (h * _lines) / 100; i++) {
            for (int ii = 0; ii < (w * _cols) / 100; ii++) {
                mvwprintw(_winGame, ((y * _lines) / 100) + i, ((x * _cols) / 100) + ii, " ");        
            }
        }
        wattroff(_winGame, COLOR_PAIR(1));
    }
    // Print the asset "assetName" at "x" and "y" pos, otherwise print the "otherwise" char
    void GraphiqueNCurse::printAsset(const std::string assetName, const int x, const int y, const char otherwise)
    {}

    // Clear the window
    void GraphiqueNCurse::clear()
    {
        wclear(_winGame);
    }
    // Refresh the window
    void GraphiqueNCurse::refresh()
    {
        wborder(_winGame, '|', '|', '-', '-', '+', '+', '+', '+');
        wrefresh(_winGame);
    }

    extern "C" GraphiqueNCurse *create() {
        return new GraphiqueNCurse();
    }
}
