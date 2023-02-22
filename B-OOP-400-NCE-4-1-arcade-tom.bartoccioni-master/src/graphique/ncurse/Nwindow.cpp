/*
** EPITECH PROJECT, 2021
** Cpool
** File description:
** Nwindow
*/

#include "Nwindow.hpp"

Nwindow::Nwindow(Information Info) :
    _Info(Info),
    winInfos(true),
    winProc(true),
    winInternet(true),
    winRam(true),
    winOs(true)
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    start_color();
    if (this->_Info.getColor() == "Red") {
        init_pair(1, COLOR_RED, COLOR_BLACK);
        attron(COLOR_PAIR(1));
    }
    if (this->_Info.getColor() == "Green") {
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        attron(COLOR_PAIR(1));
    }
    if (this->_Info.getColor() == "Blue") {
        init_pair(1, COLOR_BLUE, COLOR_BLACK);
        attron(COLOR_PAIR(1));
    }
    this->infos = subwin(stdscr, 6, 50, 0, 0);
    this->proc = subwin(stdscr, 6, 50, 6, 0);
    this->ram = subwin(stdscr, 5, 50, 15, 0);
    this->internet = subwin(stdscr, 3, 50 , 12, 0);
    this->os = subwin(stdscr, 4, 50 , 20, 0);
    this->commandes = subwin(stdscr, 5, 50 , 25, 0);
}

Nwindow::~Nwindow()
{
    delwin(this->infos);
    delwin(this->proc);
    delwin(this->ram);
    delwin(this->internet);
    delwin(this->os);
    attroff(COLOR_PAIR(1));
    endwin();
}

void Nwindow::clearAll()
{
    wclear(this->infos);
    wclear(this->ram);
    wclear(this->proc);
    wclear(this->internet);
    wclear(this->os);
    wclear(this->commandes);
}

void Nwindow::refreshAll()
{
    wrefresh(this->infos);
    wrefresh(this->ram);
    wrefresh(this->proc);
    wrefresh(this->internet);
    wrefresh(this->os);
    wrefresh(this->commandes);
}

void Nwindow::printAll()
{
    if (this->winInfos == true) printInfos();
    if (this->winProc == true) printProc();
    if (this->winRam == true) printRam();
    if (this->winInternet == true) printInternet();
    if (this->winOs == true) printOs();
    printCommandes();
}

void Nwindow::printInfos()
{
    mvwprintw(this->infos, 1, 1, this->_Info.getHostname().c_str());
    mvwprintw(this->infos, 2, 1, this->_Info.getLogname().c_str());
    mvwprintw(this->infos, 3, 1, this->_Info.getDate().c_str());
    mvwprintw(this->infos, 4, 1, this->_Info.getTime().c_str());
    box(this->infos, ACS_VLINE, ACS_HLINE);
    wattron(this->infos, A_BOLD);
    mvwprintw(this->infos, 0, 1 , "Infos");
    wattroff(this->infos, A_BOLD);
    wattron(this->infos, A_NORMAL);
}

void Nwindow::printProc()
{
    wclear(this->proc);
    mvwprintw(this->proc, 1, 1, this->_Info.getModelName().c_str());
    mvwprintw(this->proc, 2, 1, "Core Number : ");
    mvwprintw(this->proc, 2, 15, std::to_string(this->_Info.getNbCore()).c_str());
    mvwprintw(this->proc, 3, 1, "Activity : ");
    mvwprintw(this->proc, 3, 12, (this->_Info.getCpuUse() + " %").c_str());
    mvwprintw(this->proc, 4, 1, "Total Frequency : ");
    mvwprintw(this->proc, 4, 19, myGetFrequency().c_str());
    box(this->proc, ACS_VLINE, ACS_HLINE);
    wattron(this->proc, A_BOLD);
    mvwprintw(this->proc, 0, 1 , "Processeur");
    wattroff(this->proc, A_BOLD);
    wattron(this->proc, A_NORMAL);
}

void Nwindow::printRam()
{
    mvwprintw(this->ram, 1, 1, "Total Ram : ");
    mvwprintw(this->ram, 1, 13, this->_Info.getRam().c_str());
    mvwprintw(this->ram, 2, 1, "Free Ram : ");
    mvwprintw(this->ram, 2, 12, (std::to_string(std::stoi(this->_Info.getRam()) - std::stoi(this->_Info.getActiveRam())) + " kB").c_str());
    mvwprintw(this->ram, 3, 1, "Used Ram : ");
    mvwprintw(this->ram, 3, 12, this->_Info.getActiveRam().c_str());
    box(this->ram, ACS_VLINE, ACS_HLINE);
    wattron(this->ram, A_BOLD);
    mvwprintw(this->ram, 0, 1 , "Ram");
    wattroff(this->ram, A_BOLD);
    wattron(this->ram, A_NORMAL);
}

void Nwindow::printInternet()
{
    mvwprintw(this->internet, 1, 1, ("Internet : " + this->_Info.getInternet()).c_str());
    box(this->internet, ACS_VLINE, ACS_HLINE);
    wattron(this->internet, A_BOLD);
    mvwprintw(this->internet, 0, 1 , "Internet");
    wattroff(this->internet, A_BOLD);
    wattron(this->internet, A_NORMAL);
}

void Nwindow::printOs()
{
    mvwprintw(this->os, 1, 1, this->_Info.getOsName().c_str());
    mvwprintw(this->os, 2, 1, this->_Info.getKernelversion().c_str());
    box(this->os, ACS_VLINE, ACS_HLINE);
    wattron(this->os, A_BOLD);
    mvwprintw(this->os, 0, 1 , "OS");
    wattroff(this->os, A_BOLD);
    wattron(this->os, A_NORMAL);
}

void Nwindow::printCommandes()
{
    mvwprintw(this->commandes, 1, 1, "Press q to exit.");
    mvwprintw(this->commandes, 2, 1, "Press c to empty the trash.");
    mvwprintw(this->commandes, 3, 1, "Use a,z,e,r,t to show or hide modules.");
    box(this->commandes, ACS_VLINE, ACS_HLINE);
    wattron(this->commandes, A_BOLD);
    mvwprintw(this->commandes, 0, 1 , "Commandes");
    wattroff(this->commandes, A_BOLD);
    wattron(this->commandes, A_NORMAL);
}