/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ticket.h
 * Author: stud
 *
 * Created on 19. Juni 2017, 01:04
 */

#ifndef TICKET_H
#define TICKET_H
#include <string>
////#include <iostream>
#include "Buchung.h"

using namespace std;


class Ticket
{
public:
    Ticket();
    void bezahlen();
    void print();
    
private:
    Reiseklasse m_reiseklasse;
    string m_ticketnr;
    Buchung* m_buchung;
    Kunde* m_kunde;
    bool m_istBezahlt;

};

#endif /* TICKET_H */

