/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flugplan.cpp
 * Author: stud
 * 
 * Created on 19. Juni 2017, 01:08
 */

#include "Flugplan.h"

Flugplan::Flugplan()
{
        Flug a("Hannover", "Berlin", "1111", 10101, 20101, 265, economy);
    fluegeEinlesen(a);
        Flug b("München", "Berlin", "2222", 10101, 20101, 265, economy);
    fluegeEinlesen(b);
        Flug c("Stuttgart", "Berlin", "3333", 10101, 20101, 265, economy);
    fluegeEinlesen(c);
        Flug d("Zürich", "Berlin", "4444", 10101, 20101, 265, economy);
    fluegeEinlesen(d);
        Flug e("Paris", "Berlin", "5555", 10101, 20101, 265, economy);
    fluegeEinlesen(e);
}

void Flugplan::fluegeEinlesen(Flug flug){
    m_flugListe.push_back(flug);


}

vector<Flug> Flugplan::flugSuchen(string start, string ziel){
    for(int i=0;i<m_flugListe.size();i++){
        if(m_flugListe.at(i).getStart() == start && m_flugListe.at(i).getZiel() == ziel){
            m_suchListe.push_back(m_flugListe.at(i));
            cout << "Flug wurde gefunden!! Siehe Suchliste" << endl;
        }
    }
    
    if(m_suchListe.empty()){
        cout << "Keine Flüge gefunden" << endl;
    }
    
    return m_suchListe;
}

vector<Flug> Flugplan::getFlugplan(){
    return m_flugListe;
}