/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Kunde.cpp
 * Author: stud
 * 
 * Created on 19. Juni 2017, 00:27
 */

#include "Kunde.h"

Kunde::Kunde()
{
}

Kunde::Kunde(string name, int geburtsdatum, Anschrift anschrift, string telefon, string email, string benutzer, string password){
    m_name = name;
    m_email = email;
    m_geburtsdatum = geburtsdatum;
    m_anschrift = anschrift;
    m_telefon = telefon;
    m_benutzername = benutzer;
    m_pw = password;
}

void Kunde::anschriftAendern(Anschrift a){
    m_anschrift = a;
}

void Kunde::emailAendern(string s){
    m_email = s;
}

void Kunde::passwortAendern(string s){
    m_pw = s;
}

bool Kunde::anmelden(string pw){
    if(pw == m_pw){
        cout << "Login erfolgreich" << endl;
        return true;
    }
    else{
        cout << "Falsches Passwort!" << endl;
        return false;
    }
}

string Kunde::getBenutzer(){
    return m_benutzername;
}

string Kunde::getPW(){
    return m_pw;
}

string Kunde::getName(){
    return m_name;
}
