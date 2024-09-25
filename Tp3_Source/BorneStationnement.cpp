/**
* \file BorneStationnement.cpp
* \brief Implantation de la classe BorneStationnement.cpp
* \author Mohamed Amine Youssef  
* \version 1.0
* \date 28 mars 2024
  */

#include "BorneStationnement.h"
#include "validationFormat.h"  
#include <sstream>
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace bornesQuebec;

/**
* \brief Constructeur de la BorneStationnement . Il reçoit en entrée la capacité de la BorneStationnement
* 
* \param[in] int p_identifiant,const std::string p_identifiantVoiePublique,const std::string p_nomTopographique,
                   double p_longitude,double p_latitude,int p_numBorne, const std::string& p_coteRue
* \pre LnumBorne Peut être composé de 1 à 4 chiffres. coteRue Un objet string. Le coté par rapport au centre de chaussée où est la borne.
 *  Il doit correspondre à un point cardinal. La validité du point cardinal doit être établie par la fonction util::validerPointCardinal 
* \post m_numBorne est égale à p_numBorne m_coteRue est égale à p_coteRue
*/
  BorneStationnement::BorneStationnement(int p_identifiant,const std::string p_identifiantVoiePublique,const std::string p_nomTopographique,
                   double p_longitude,double p_latitude,int p_numBorne, const std::string& p_coteRue)
          :Borne(p_identifiant,p_identifiantVoiePublique,p_nomTopographique,p_longitude,p_latitude),m_numBorne(p_numBorne),m_coteRue(p_coteRue){
    PRECONDITION(p_numBorne > 0 && p_numBorne <= 9999);
    PRECONDITION(util::validePointCardinal (p_coteRue));
    POSTCONDITION(m_numBorne==p_numBorne);
    POSTCONDITION(m_coteRue==p_coteRue);
    INVARIANTS();
    
  }
  /**
* \brief retourne la NumBorne
* \return un int  qui représente la Numero Borne
*/
  int BorneStationnement::reqNumBorne() const {
    return m_numBorne;
  }
    /**
* \brief retourne la CoteRue
* \return un string  qui représente la Cote Rue
*/
  std::string BorneStationnement::reqCoteRue() const{
    return m_coteRue;
  }
  /**
*\brief Clone l'objet Borne.
* 
* \return Un pointeur unique vers une copie de l'objet Borne.
*/
 std::unique_ptr<Borne> BorneStationnement::clone() const {
    return std::make_unique<BorneStationnement>(*this);
}
  /**
* \brief retourne les informations d'une  borne Stationnement formatée 
* \return la BorneStationnement formatée en retournant à la ligne 
*/
  std::string BorneStationnement::reqBorneFormate() const {
    std::ostringstream os;
    os << std::fixed << std::setprecision(8); 
    os << "Borne de stationnement\n";
    os << "----------------------------------------------\n";

    os<< Borne::reqBorneFormate()  
        << "Numero de la borne: " << m_numBorne << "\n"
        << "Cote de la rue: " << m_coteRue << "\n";
    return os.str();
  }
  void BorneStationnement::verifieInvariant() const {
    INVARIANT(m_numBorne > 0 && m_numBorne <= 9999);
    INVARIANT(util::validePointCardinal (m_coteRue));
  }