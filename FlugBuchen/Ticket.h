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
#include "Buchung.h"

using namespace std;

enum Reiseklasse{
    business,
    economy,
    first
};
class Ticket
{
public:
    Ticket();
    bool bezahlen(Buchung buchung);
    
private:
    Reiseklasse m_reiseklasse;
    string m_ticketnr;
    Buchung m_buchung;
};

#endif /* TICKET_H */

