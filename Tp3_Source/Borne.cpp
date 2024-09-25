/**
* \file Borne.cpp
* \brief Implantation de la classe Borne
* \author Mohamed Amine Youssef  
* \version 1.0
* \date 13 mars 2024

*/
#include <algorithm>

#include <limits>
#include <iomanip>
#include "Borne.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace bornesQuebec;
/**
* \brief Constructeur de la Borne . Il reçoit en entréeint p_identifiant,const std::string p_identifiantVoiePublique,const std::string p_nomTopographique,double p_longitude,double p_latitude,const std::string& p_ville
 * p_arrondissement

* \param[in] int p_identifiant,const std::string p_identifiantVoiePublique,const std::string p_nomTopographique,double p_longitude,double p_latitude,const std::string& p_ville
 * p_arrondissement  
* \pre m_identifiant L’identifiant de la borne. C'est un entier strictement positif.
 * 
 * l’identifiant de la voie publique sur laquelle la borne est située, C’est un objet string qui peut contenir un numéro ou être vide.
 * Un objet string. Le nom topographique (générique, liaison, spécifique, direction) du centre de chaussée. Il doit être non vide. 
 * Deux nombres réels. La longitude et la latitude. 
* \post m_identifiant est égale à p_identifiant m_nomTopographique est égale à p_nomTopographique m_longitude est égale à p_longitude m_latitude est égale à  p_latitude
*/ 
        

Borne::Borne (int p_identifiant,const std::string p_identifiantVoiePublique,const std::string p_nomTopographique,double p_longitude,double p_latitude):
m_identifiant(p_identifiant),m_identifiantVoiePublique(p_identifiantVoiePublique),m_nomTopographique(p_nomTopographique),
m_longitude(p_longitude),m_latitude(p_latitude){
    PRECONDITION(p_identifiant > 0);
    PRECONDITION(!p_nomTopographique.empty());
    PRECONDITION(p_identifiantVoiePublique.empty() || estNombre(p_identifiantVoiePublique));

    PRECONDITION(!std::isnan(p_longitude) && !std::isinf(p_longitude));
    PRECONDITION(!std::isnan(p_latitude) && !std::isinf(p_latitude));
    POSTCONDITION(m_identifiant == p_identifiant);
    POSTCONDITION(m_nomTopographique == p_nomTopographique);
    POSTCONDITION(m_longitude == p_longitude);
    POSTCONDITION(m_latitude == p_latitude);
    INVARIANTS();
    

    }
/**
* \brief retourne l'identifiant
* \return un entier  qui représente l'identifiant
*/
int Borne:: reqIdentifiant() const{

return m_identifiant;
}
/**
* \brief retourne l'identifiantVoiePublique
* \return un string  qui représente l'identifiantVoiePublique
*/
const std::string & Borne::reqidentifiantVoiePublique() const{
return m_identifiantVoiePublique;

}
/**
* \brief retourne le nomTopographique
* \return un string  qui représente le nomTopographique
*/
const std::string & Borne::reqnomTopographique() const{
return m_nomTopographique;

}
/**
* \brief retourne la longitude
* \return un réel  qui représente la longitude
*/
double Borne:: reqlongitude() const{
return m_longitude;
}
/**
* \brief retourne la latitude
* \return un réel  qui représente la latitude
*/
double Borne:: reqlatitude() const{
return m_latitude;
}
/**
* \brief Assigne le NomTopographique date à l'objet courant
* \param[in] p_nomTopographique est un string l qui représente le nomTopographique 
* \pre p_jour, p_mois, p_annee doivent correspondre à une date valide
* \post l'objet a été assigné à partir des entiers passés en paramètres
*/
void Borne:: asgNomTopographique(const std::string& p_nomTopographique){
    PRECONDITION(!p_nomTopographique.empty());
    m_nomTopographique = p_nomTopographique;
    POSTCONDITION(m_nomTopographique == p_nomTopographique);
    INVARIANTS();

}
/**
* \brief surcharge de l'opérateur ==
* \param[in] p_borne à comparer à la borne courante
* \return un booléen indiquant si les borne sont égales
*/
bool Borne::operator==(const Borne& p_borne)  {
  return m_identifiant == p_borne.m_identifiant &&
         m_identifiantVoiePublique == p_borne.m_identifiantVoiePublique &&
         m_nomTopographique == p_borne.m_nomTopographique &&
         m_longitude == p_borne.m_longitude &&
         m_latitude == p_borne.m_latitude;
}
/**
* \brief Destructeur virtuel de la classe Borne.
* 
* Libère les ressources allouées pour un objet Borne lorsqu'il est détruit.
*/
Borne::~Borne() {}

/**
* \brief retourne les informations d'une  borne formatée 
* \return la Borne formatée en retournant à la ligne 
*/
std::string Borne::reqBorneFormate() const {
    std::ostringstream os;
    os << std::fixed << std::setprecision(6); 
    os << "Identifiant de la borne: " << m_identifiant << "\n"
       << "Voie publique: " << m_identifiantVoiePublique << "\n"
       << "Nom topographique: " << m_nomTopographique << "\n"
       << "Latitude: " << m_latitude << "\n"
       << "Longitude: " << m_longitude << "\n";
    return os.str();
}
/**
* \brief retourne si p_identifiantVoiePublique est un nombre onon
* \return un bool  vrai si c'est un nombre sinon false
*/
bool Borne::estNombre(const std::string& p_identifiantVoiePublique) {
  for (char c : p_identifiantVoiePublique) {
    if (!std::isdigit(c)) {
      return false;
    }
  }
  return true;
}
void Borne::verifieInvariant() const {
    INVARIANT(m_identifiant > 0);
    INVARIANT(!m_nomTopographique.empty());
    INVARIANT(!std::isnan(m_longitude) && !std::isinf(m_longitude));
    INVARIANT(!std::isnan(m_latitude) && !std::isinf(m_latitude));
}