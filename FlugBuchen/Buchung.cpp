/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Buchung.cpp
 * Author: stud
 * 
 * Created on 19. Juni 2017, 00:45
 */

#include "Buchung.h"

Buchung::Buchung()
{
    m_buchungsnr = "DE0000111100LE";
    
    m_status = false;
}


void Buchung::buchen(Flug flug){
    m_fluege.push_back(flug);
}

double Buchung::getPreis(){
    for(int i=0;i<m_fluege.size();i++){
        m_preis += m_fluege.at(i).getPreis();
    }
    
    return m_preis;
}

string Buchung::getBuchungsnr(){
    return m_buchungsnr;
}

bool Buchung::getStatus(){
    return m_status;
}

void Buchung::setStatus(bool b){
    m_status = b;
}

vector<Flug> Buchung::getGebuchte(){
    return m_fluege;
}
