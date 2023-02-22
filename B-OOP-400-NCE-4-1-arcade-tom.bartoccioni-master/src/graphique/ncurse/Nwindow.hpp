/*
** EPITECH PROJECT, 2021
** Cpool
** File description:
** Nwindow
*/

#ifndef NWINDOW_HPP_
#define NWINDOW_HPP_

class Nwindow {
    public:
        Nwindow(Information Info);
        ~Nwindow();
        void clearAll();
        void refreshAll();
        void printAll();
        void printInfos();
        void printRam();
        void printProc();
        void printInternet();
        void printOs();
        void printCommandes();

        bool winInfos;
        bool winProc;
        bool winRam;
        bool winInternet;
        bool winOs;

        WINDOW *infos, *proc, *ram, *internet, *os, *commandes;

    protected:
    private:
        Information _Info;        
};

#endif /* !NWINDOW_HPP_ */
