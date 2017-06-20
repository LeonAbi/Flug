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
#include "Buchung.h"
#ifndef CUI_H
#define CUI_H

using namespace std;

class CUI
{
public:
    CUI();
    virtual ~CUI();
    void zeigeMenue();
    bool registrieren();
    void anmelden();
    vector<Flug> flugSuchen();
    void bezahlen();
    void buchen();
    void flugListeAnzeigen();
    void suchListeAnzeigen();
    void ausloggen();
    void ticketAnzeigen();
    void print(vector<Flug> v);
private:
    int m_auswahl;
    vector<Kunde> m_kundenListe;
    Ticket* m_ticket;
    Kunde* m_aktBenutzer;
    Flugplan* m_flugPlan;
    bool m_loggedin;
    Buchung* m_buchung;
    vector<Flug> m_gesuchtefluege;
    
};

#endif /* CUI_H */

