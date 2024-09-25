/**
* \file BorneFontaine.cpp
* \brief Implantation de la classe BorneFontaine.cpp
* \author Mohamed Amine Youssef  
* \version 1.0
* \date 18 mars 2024

*/
#include "BorneFontaine.h"
#include <sstream>
#include <iomanip>

#include <cassert>
using namespace bornesQuebec;
/**
* \brief Constructeur de la BorneFontaine . Il reçoit en entrée la capacité de la BorneFontaine.
* 
* \param[in] int p_identifiant, const std::string& p_identifiantVoiePublique, const std::string& p_nomTopographique,
                  double p_longitude, double p_latitude, const std::string& p_ville, const std::string& p_arrondissement):
* \pre p_ville doit être non vide di la ville est Quebec l'arrondissment doit etre non vide
* \post lm_ville est égale à p_ville m_arrondissement est égale à p_arrondissement
*/
BorneFontaine::BorneFontaine(int p_identifiant, const std::string& p_identifiantVoiePublique, const std::string& p_nomTopographique,
                  double p_longitude, double p_latitude, const std::string& p_ville, const std::string& p_arrondissement):
Borne(p_identifiant,p_identifiantVoiePublique,p_nomTopographique,p_longitude,p_latitude),m_ville(p_ville),m_arrondissement(p_arrondissement){
  PRECONDITION(!p_ville.empty());
  PRECONDITION(p_ville != "Québec" || (p_ville == "Québec" && !p_arrondissement.empty()));
  POSTCONDITION(m_ville == p_ville);
  POSTCONDITION(m_arrondissement == p_arrondissement);
  INVARIANTS();

  

}
/**
* \brief retourne la ville
* \return un string  qui représente la ville
*/
const std::string& BorneFontaine::reqVille() const{
  return m_ville;
}
/**
* \brief retourne la arrondissement
* \return un string   qui représente la arrondissement 
*/
const std::string& BorneFontaine::reqArrondissement() const{
  return m_arrondissement;
}
/**
*\brief Clone l'objet Borne.
* 
* \return Un pointeur unique vers une copie de l'objet Borne.
*/

std::unique_ptr<Borne> BorneFontaine::clone() const {
    return std::make_unique<BorneFontaine>(*this);

}
 /**
* \brief retourne les informations d'une  borne Fontaine formatée 
* \return la BorneFontaine formatée en retournant à la ligne 
*/
std::string BorneFontaine::reqBorneFormate() const {
    std::ostringstream os;
    os << std::fixed << std::setprecision(8);

    os << "Borne-fontaine\n";
    os << "----------------------------------------------\n";
    os << Borne::reqBorneFormate();
    os << "Ville: " << reqVille() << "\n"
       << "Arrondissement: " << reqArrondissement() << "\n"; 

    return os.str();
}
void BorneFontaine::verifieInvariant() const {
INVARIANT(!m_ville.empty());
INVARIANT(m_ville != "Québec" || (m_ville == "Québec" && !m_arrondissement.empty()));
}