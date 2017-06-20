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
    
    Kunde k("A", "31011978", a, "0815", "@@@", "master", "pw");
    m_kundenListe.push_back(k);
    
    m_loggedin = false;
    m_flugPlan = new Flugplan();
    
    m_buchung = new Buchung();
    m_ticket = new Ticket(m_buchung);
    
}

CUI::~CUI(){
    delete m_aktBenutzer;
    delete m_flugPlan;
    delete m_ticket;
    delete m_buchung;
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
    cout << "2. Alle Flüge anzeigen" << endl;
    cout << "3. Suchliste anzeigen" << endl;
    cout << "4. Flüge buchen" << endl;
    cout << "5. Gebuchte Flüge anzeigen" << endl;
    cout << "6. Ticket bezahlen" << endl;
    cout << "0. ausloggen" << endl << endl; 
    int i;
    cin >> i;
    
    
    switch(i){
    case 1:     cout << "Ihre Auswahl: Flug suchen" << endl;
    flugSuchen();
    break;
    break;
    case 6:     cout << "Ihre Auswahl: Ticket bezahlen" << endl;
    bezahlen();
    break;
    case 2:     cout << "Ihre Auswahl: Alle Flüge anzeigen" << endl;
    flugListeAnzeigen();
    break;
    case 3:     cout << "Ihre Auswahl: Suchliste anzeigen" << endl;
    print(m_gesuchtefluege);
    break;
    case 4:     cout << "Ihre Auswahl: Flüge buchen" << endl;
    buchen();
    break;
    case 5:     cout << "Ihre Auswahl: Gebuchte Flüge anzeigen" << endl;
    print(getBuchung());
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
    cout << "Passwort eingeben: ";
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
    string benutzername, pw, name, telefonnr, email, strasse, plz, wohnort, geburtsdatum;

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
        if(m_kundenListe.at(i).getBenutzer() == benutzername){
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
    vector<Flug> fluege = m_flugPlan->getFlugplan();
    for(int i=0;i<fluege.size();i++){
        fluege.at(i).print();
    }
}

vector<Flug> CUI::flugSuchen()
{
    string start;
    string ziel;
    cout << "Start: ";
    cin >> start;
    cout << "Ziel: ";
    cin >> ziel;

    m_gesuchtefluege = m_flugPlan->flugSuchen(start, ziel);
    return m_gesuchtefluege;
}

void CUI::buchen(){

    string xy;
    vector<Flug> v = m_flugPlan->getFlugplan();
    cout << "Welchen Flug möchten Sie buchen? (Flugnr eingeben!):";
    cin >> xy;
    
    for(int i=0;i<v.size();i++){
        if(v.at(i).getFlugnr() == xy){
            m_buchung->buchen(v.at(i));
            cout << "Flug erfolgreich gebucht!!" << endl;
            return;
        }
    }
    
    cout << "Fehler! Flug nicht gefunden!" << endl;

}

void CUI::ausloggen(){
    m_aktBenutzer = nullptr;
    m_loggedin = false;
    cout << "Ausloggen erfolgreich!" << endl;
}

void CUI::bezahlen(){
if (!m_buchung->getStatus())
    {
        string s;
        cout << "Der Geamtpreis beträgt: " << m_buchung->getPreis() << "€" << endl;
        cout << "Möchten sie jetzt bezahlen? (Y/N)" << endl;
        cin >> s;
        if (s == "Y" || s == "y")
        {
            m_ticket->bezahlen();
        }
        else cout << "Nicht bezahlt !" << endl;

    }
    else cout<< "Bereits bezahlt"<< endl;
}




void CUI::print(vector<Flug> v){
    for(int i=0;i<v.size();i++){
        v.at(i).print();
    }
}

vector<Flug> CUI::getBuchung(){
    return m_buchung->getGebuchte();
}



