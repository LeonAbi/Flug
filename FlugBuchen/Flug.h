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

enum Reiseklasse{
    business,
    economy,
    first
};

class Flug
{
public:
    Flug();
    Flug(string start, string ziel, string flugnr, int datumS, int datumZ, double preis, Reiseklasse klasse);
    string getFlugnr();
    string getStart();
    string getZiel();
    void print();
    double getPreis();

private:
    string m_start;
    string m_ziel;
    string m_flugnr;
    int m_datumS;
    int m_datumZ;
    double m_preis;
};

#endif /* FLUG_H */

