/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-tom.bartoccioni
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_

#include <iostream>
#include <string>
#include <vector>

class IDisplay {

    public:
        // Initialize library
        virtual void init() = 0;
        // Destroy library
        virtual void stop() = 0;
        // Just run your librarie
        virtual void run() = 0;
        // Get the name of the window
        virtual const std::string &getName() const = 0;
        // Function to display text in screen with x & y pos and the string we want
        virtual void displayText(const int posx, const int posy, const std::string &text) = 0;
        // Function to display rectangle on screen with x, y, width, height
        virtual void displayRect(const int x, const int y, const int w, const int h, const std::vector<int> color = {6, 139, 196}) = 0;
        // Display a map by string
        virtual void displayMap(const std::vector<std::string> map) = 0;

        // Clear the window
        virtual void clear() = 0;
        // Refresh the window
        virtual void refresh() = 0;

        // Get last event
        virtual int getEvent() = 0;
};

#endif /* !IDISPLAY_HPP_ */
