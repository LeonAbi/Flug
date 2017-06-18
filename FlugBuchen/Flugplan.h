/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flugplan.h
 * Author: stud
 *
 * Created on 19. Juni 2017, 01:08
 */

#include "Flug.h"
#include <string>
#include <ctime>
#include <vector>
#ifndef FLUGPLAN_H
#define FLUGPLAN_H

using namespace std;

class Flugplan
{
public:
    Flugplan();
    void fluegeEinlesen(Flug flug);
    vector<Flug> flugSuchen(string start, string ziel);
private:
    string m_flughafen;
    time_t m_gueltigab;
    vector<Flug> m_flugListe;
    vector<Flug> m_suchListe;
};

#endif /* FLUGPLAN_H */

