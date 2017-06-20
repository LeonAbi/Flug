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
    Anschrift a;
    a.plz = "878787";
    a.strasse = "abc";
    a.wohnort = "bcbcbc";
    
    Kunde k("Bob", 31030000, a, "181818181", "@@@", "Master", "password");
    m_kundenListe.push_back(k);
    
    m_loggedin = false;
    m_flugPlan = new Flugplan();
    m_ticket = new Ticket();
    
}

CUI::~CUI(){
    delete m_aktBenutzer;
    delete m_flugPlan;
    delete m_ticket;
}

void CUI::zeigeMenue(){
    char sein;
    bool b;
    
    
    do{
    cout << "Anmelden (A) / Registrieren (R)" << endl;
    cin >> sein;
      
    switch(sein){
    case 'A':   
    case 'a':       anmelden();
    if(m_loggedin == true) b=true;
    break;
    case 'R':
    case 'r':     
    registrieren();
    b=true;
    break;
    default:    cout << "Falsche Eingabe" << endl;
    }
    }
    
    while(!b);   
   
    b=false;
    
    
    do{
    
    cout << endl << "    MENÜ   " << endl << endl;
    cout << "1. Flug suchen" << endl;
    cout << "5. Alle Flüge anzeigen" << endl;
    cout << "6. Suchliste anzeigen" << endl;
    cout << "2. Ticket anzeigen" << endl;
    cout << "3. Ticket bezahlen" << endl;
    cout << "0. ausloggen" << endl; 
    int i;
    cin >> i;
    
    
    switch(i){
    case 1:     cout << "Ihre Auswahl: Flug suchen" << endl;
    flugSuchen();
    //b=true;
    break;
    case 2:     cout << "Ihre Auswahl: Ticket anzeigen" << endl;
    ticketAnzeigen();
    b=true;
    break;
    case 3:     cout << "Ihre Auswahl: Ticket bezahlen" << endl;
    bezahlen();
    b=true;
    break;
    case 5:     cout << "Ihre Auswahl: Alle Flüge anzeigen" << endl;
    flugListeAnzeigen();
    break;
    case 6:     cout << "Ihre Auswahl: Suchliste anzeigen" << endl;
    print(m_gesuchtefluege);
    break;
    case 0:     cout << "Ihre Auswahl: Ausloggen" << endl;
    ausloggen();
    b=true;
    break;
    default:    cout << "Falsche Eingabe!" << endl << endl;
    break;
    }
    }
    while(!b);

    
    
    
}
void CUI::anmelden(){
    string benutzername, pw;
    cout  << "Benutzername eingeben: ";
    cin >> benutzername;
    cout << endl << "Passwort eingeben: ";
    cin >> pw;
    
    for(int i=0;i<m_kundenListe.size();i++){
        if(m_kundenListe.at(i).getBenutzer() == benutzername && m_kundenListe.at(i).getPW() == pw ){
            m_loggedin = true;
            m_aktBenutzer = &m_kundenListe.at(i);
            cout << "Anmelden erfolgreich!!" << endl;
        }
    }

         
}

bool CUI::registrieren(){
    string benutzername, pw, name, telefonnr, email, strasse, plz, wohnort;
    int geburtsdatum;
    cout << "Benutzername eingeben: ";
    cin >> benutzername;
    cout << "Passwort eingeben: ";
    cin >> pw;
    cout << "Name eingeben: ";
    cin >> name;
    cout << "Telefonnummer eingeben: ";
    cin >> telefonnr;
    cout << "E-Mail Adresse eingeben: ";
    cin >> email;
    cout << "Straße eingeben: ";
    cin >> strasse;
    cout << "Postleitzahl eingeben: ";
    cin >> plz;
    cout << "Wohnort eingeben: ";
    cin >> wohnort;
    cout << "Geburtsdatum eingeben: ";
    cin >> geburtsdatum;
    cout << endl;
    
    
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
    
    m_aktBenutzer = &k;
    m_kundenListe.push_back(k);
    cout << "Neuer Benutzer wurde angelegt" << endl;
    return true;
    
}

void CUI::ticketAnzeigen(){
    m_ticket->print();
}

void CUI::flugListeAnzeigen()
{
//    vector<Flug> fluege = flugSuchen();
//
//    for (int i; i < fluege.size(); i++)
//    {
//        cout << i+1 << ". ";
//        fluege.at(i).print();
//        cout << endl;
//    }
//
//    return fluege;
    vector<Flug> fluege = m_flugPlan->getFlugplan();
    for(int i=0;i<fluege.size();i++){
        fluege.at(i).print();
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

    m_gesuchtefluege = m_flugPlan->flugSuchen(start, ziel);
    return m_gesuchtefluege;
}

void CUI::buchen(){
//    vector <Flug> v = flugListeAnzeigen();
//    cout << "Welchen Flug möchten Sie buchen?" << endl;
//    cin >> m_auswahl;
//    
//    if(m_auswahl <= v.size()){
//    m_buchung->buchen(v.at(m_auswahl-1));
//    }
//    else cout << "Flug nicht gefunden!" << endl;
}

void CUI::ausloggen(){
    m_aktBenutzer = nullptr;
    m_loggedin = false;
    cout << "Ausloggen erfolgreich!" << endl;
}

void CUI::bezahlen(){
    m_ticket->bezahlen();

}

void CUI::print(vector<Flug> v){
    for(int i=0;i<v.size();i++){
        v.at(i).print();
    }
}



