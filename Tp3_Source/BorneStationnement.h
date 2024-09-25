/**
 * \class BorneStationnement
 * \brief Cette classe sert au maintien et à la manipulation des BorneStationnement.
 *
 *             La classe maintient dans un état cohérent ces renseignements.
 *             Elle valide ce qu'on veut lui assigner.
 *              <p>
 *              Cette classe peut aussi servir à prendre la BorneStationnement courante du
 *              système et à faire des calculs avec des Bornes.
 *              <p>
 *              La classe n'accepte que des BorneStationnement invalides, c'est la
 *              responsabilité de l'utilisateur de la classe de s'en assurer.
 *              <p>
 *  Attributs:  int p_identifiant,const std::string p_identifiantVoiePublique,const std::string p_nomTopographique,
                   double p_longitude,double p_latitude,int p_numBorne, const std::string& p_coteRue
 
  */
#ifndef BORNESTATIONNEMENT_H
#define BORNESTATIONNEMENT_H
#include "ContratException.h"


#include "Borne.h"
#include <string>
#include <memory>
using namespace bornesQuebec;

class BorneStationnement : public Borne {
public:
  BorneStationnement(int p_identifiant,const std::string p_identifiantVoiePublique,const std::string p_nomTopographique,
                   double p_longitude,double p_latitude,int p_numBorne, const std::string& p_coteRue);
  int reqNumBorne() const;
  std::string reqCoteRue() const;
  virtual std::unique_ptr<Borne> clone() const;
  virtual std::string reqBorneFormate() const override;  

private:
  int m_numBorne;
  std::string m_coteRue;
  void verifieInvariant() const;
    
        
  };    
    
  

#endif /* BORNESTATIONNEMENT_H */