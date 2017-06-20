/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flug.h
 * Author: stud
 *
 * Created on 19. Juni 2017, 00:49
 */
#include <string>
#include <ctime>
#include <iostream>
#ifndef FLUG_H
#define FLUG_H

using namespace std;
class Flug
{
public:
    Flug();
    Flug(string start, string ziel, string flugnr, time_t datumS, time_t datumZ);
    string getFlugnr();
    string getStart();
    string getZiel();
    void print();

private:
    string m_start;
    string m_ziel;
    string m_flugnr;
    time_t m_datumS;
    time_t m_datumZ;
};

#endif /* FLUG_H */

