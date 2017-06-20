/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Kunde.h
 * Author: stud
 *
 * Created on 19. Juni 2017, 00:27
 */

#include <string>
#include <iostream>
#ifndef KUNDE_H
#define KUNDE_H

using namespace std;

struct Anschrift{
    string strasse;
    string plz;
    string wohnort;
};
class Kunde
{
public:
    Kunde();
    Kunde(string name, int geburtsdatum, Anschrift anschrift, string telefon, string email, string benutzer, string password);
    void passwortAendern(string s);
    void emailAendern(string s);
    void anschriftAendern(Anschrift a);
    bool anmelden(string pw);
    string getBenutzer();
    string getPW();
    
private:
    string m_name;
    int m_geburtsdatum;
    string m_telefon;
    string m_email;
    string m_benutzername;
    string m_pw;
    Anschrift m_anschrift;
};

#endif /* KUNDE_H */

