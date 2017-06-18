/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Buchung.h
 * Author: stud
 *
 * Created on 19. Juni 2017, 00:45
 */
#include "Kunde.h"
#include "Flug.h"
#include <vector>
#ifndef BUCHUNG_H
#define BUCHUNG_H
using namespace std;
        
class Buchung
{
public:
    Buchung();
    bool istBezahlt();
    bool buchen(Flug flug);
private:
    bool m_status;
    double m_preis;
    Kunde m_kunde;
    string m_buchungsnr;
    vector<Flug> m_fluege;
    
};

#endif /* BUCHUNG_H */

