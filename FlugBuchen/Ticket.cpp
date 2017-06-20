/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ticket.cpp
 * Author: stud
 * 
 * Created on 19. Juni 2017, 01:04
 */

#include "Ticket.h"

Ticket::Ticket()
{
}

void Ticket::bezahlen(){
    m_buchung->setStatus(true);
    m_istBezahlt = true;
    cout << "Ticket bezahlt!" << endl;
}

void Ticket::print(){
    cout << "Buchungsnr: " << m_buchung->getBuchungsnr() << endl;
    cout << "Ticketnr: " << m_ticketnr << endl;
    cout << m_kunde->getName() << endl;
    cout << m_reiseklasse << endl;
    cout << m_buchung->getPreis() << endl;       
}

