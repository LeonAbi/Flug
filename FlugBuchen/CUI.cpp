/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CUI.cpp
 * Author: stud
 * 
 * Created on 19. Juni 2017, 01:24
 */

#include "CUI.h"

CUI::CUI()
{
    m_loggedin = false;
}

bool CUI::anmelden(){
    string benutzername, pw;
    cout  << "Benutzername eingeben: ";
    cin >> benutzername;
    cout << endl << "Passwort eingeben: ";
    cin >> pw;
    
    for(int i=0;i<m_kundenListe.size();i++){
        if(m_kundenListe.at(i).getBenutzer() == benutzername && m_kundenListe.at(i).getPW() == pw ){
            m_loggedin = true;
            m_aktBenutzer = &m_kundenListe.at(i);
        }
    }

         
}

bool CUI::registrieren(){
    string benutzername, pw, name, telefonnr, email, strasse, plz, wohnort;
    int geburtsdatum;
    cout << "Benutzername eingeben: ";
    cin >> benutzername;
    cout << endl << "Passwort eingeben: ";
    cin >> pw;
    cout << endl << "Name eingeben: ";
    cin >> name;
    cout << endl << "Telefonnummer eingeben: ";
    cin >> telefonnr;
    cout << endl << "E-Mail Adresse eingeben: ";
    cin >> email;
    cout << endl << "Straße eingeben: ";
    cin >> strasse;
    cout << endl << "Postleitzahl eingeben: ";
    cin >> plz;
    cout << endl << "Wohnort eingeben: ";
    cin >> wohnort;
    cout << "Geburtsdatum eingeben: ";
    cout << endl << geburtsdatum;
    
    
    Anschrift a;
    a.plz = plz;
    a.strasse = strasse;
    a.wohnort = wohnort;
    
    Kunde k(name, geburtsdatum, a, telefonnr, email, benutzername, pw);
    
    for(int i=0;i<m_kundenListe.size();i++){
        if(m_kundenListe.at(i).getBenutzer() == name){
            cout << "Benutzer bereits registriert!!" << endl;
            return false;
        }
        
    }
    
    m_kundenListe.push_back(k);
    cout << "Neuer Benutzer wurde angelegt";
    return true;
    
}

void CUI::ticketAnzeigen(){
    
}

void CUI::flugListeAnzeigen()
{
    vector<Flug> fluege = flugSuchen();

    for (int i; i < fluege.size(); i++)
    {
        fluege.at(i).print();
        cout << endl;
    }

}

vector<Flug> CUI::flugSuchen()
{
    string start;
    string ziel;
    cout << "Start: " << endl;
    cin >> start;
    cout << "Ziel: " << endl;
    cin >> ziel;

    return m_flugPlan->flugSuchen(start, ziel);
}

