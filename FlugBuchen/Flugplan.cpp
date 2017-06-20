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
    for(int i=0;i<5;i++){
        Flug f("Hannover", "Berlin", "123", i, i+10, i*10, economy);
        fluegeEinlesen(f);
    }
}

void Flugplan::fluegeEinlesen(Flug flug){
    m_flugListe.push_back(flug);


}

vector<Flug> Flugplan::flugSuchen(string start, string ziel){
    for(int i=0;i<m_flugListe.size();i++){
        if(m_flugListe.at(i).getStart() == start && m_flugListe.at(i).getZiel() == ziel){
            m_suchListe.push_back(m_flugListe.at(i));
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