/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CUI.h
 * Author: stud
 *
 * Created on 19. Juni 2017, 01:24
 */

#include "Kunde.h"
#include "Flugplan.h"
#include <ctime>
#include <vector>
#include <iostream>
#include "Ticket.h"
#ifndef CUI_H
#define CUI_H

using namespace std;

class CUI
{
public:
    CUI();
    void zeigeMenue();
    bool registrieren();
    bool anmelden();
    vector<Flug> flugSuchen();
    void bezahlen();
    void buchen();
    void flugListeAnzeigen();
    void ausloggen();
    void ticketAnzeigen();
private:
    int m_auswahl;
    vector<Kunde> m_kundenListe;
    vector<Ticket> m_tickets;
    Kunde* m_aktBenutzer;
    Flugplan* m_flugPlan;
    bool m_loggedin;
    
};

#endif /* CUI_H */

