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
}

void Flugplan::fluegeEinlesen(Flug flug){
    for(int i=0;i<m_flugListe.size();i++){
        if(m_flugListe.at(i).getFlugnr() != flug.getFlugnr()){
                m_flugListe.push_back(flug);
        }
    }

}

vector<Flug> Flugplan::flugSuchen(string start, string ziel){
    for(int i=0;i<m_flugListe.size();i++){
        if(m_flugListe.at(i).getStart() == start && m_flugListe.at(i).getZiel() == ziel){
            m_suchListe.push_back(m_flugListe.at(i));
        }
    }
    
    return m_suchListe;
}

