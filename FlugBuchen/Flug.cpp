/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flug.cpp
 * Author: stud
 * 
 * Created on 19. Juni 2017, 00:49
 */

#include "Flug.h"

Flug::Flug()
{
}

Flug::Flug(string start, string ziel, string flugnr, time_t datumS, time_t datumZ){
    m_start = start;
    m_ziel = ziel;
    m_flugnr = flugnr;
    m_datumS = datumS;
    m_datumZ = datumZ;
}

string Flug::getFlugnr(){
    return m_flugnr;
}

string Flug::getStart(){
    return m_start;
}

string Flug::getZiel(){
    return m_ziel;
}

void Flug::print()
{
    cout<< "Flugnummer:" << m_flugnr << endl;
    cout<< "Start: "<< m_start<< ", Datum: "<< m_datumS << endl;
    cout<< "Ziel: "<< m_ziel<< ", Datum: "<< m_datumZ << endl;
}

