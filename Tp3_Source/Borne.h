#include <iostream>
#include <sstream>
#include <string>
#include <memory>


/**
 * \class Borne
 * \brief Cette classe sert au maintien et à la manipulation des Borne.
 *
 *             La classe maintient dans un état cohérent ces renseignements.
 *             Elle valide ce qu'on veut lui assigner.
 *              <p>
 *              Cette classe peut aussi servir à prendre la Borne courante du
 *              système et à faire des calculs avec des Bornes.
 *              <p>
 *              La classe n'accepte que des Borne valides, c'est la
 *              responsabilité de l'utilisateur de la classe de s'en assurer.
 *              <p>
 *  Attributs:  int p_identifiant,const std::string p_identifiantVoiePublique,const std::string p_nomTopographique,double p_longitude,double p_latitude
 
  */
#ifndef BORNE_H
#define BORNE_H
#include "ContratException.h"
namespace bornesQuebec{
class Borne
{
public:
  Borne (int p_identifiant,const std::string p_identifiantVoiePublique,const std::string p_nomTopographique,double p_longitude,double p_latitude);
  int reqIdentifiant() const;
  const std::string & reqidentifiantVoiePublique() const;
  const std::string & reqnomTopographique() const;
  double reqlongitude() const;
  double reqlatitude() const;
  void asgNomTopographique(const std::string& p_nomTopographique);
  bool operator==(const Borne& p_borne);
  virtual ~Borne() ;
  virtual std::unique_ptr<Borne> clone() const=0;
  virtual std::string reqBorneFormate() const;
  
private:
  int m_identifiant;
  std::string m_identifiantVoiePublique;
  std::string m_nomTopographique;
  double m_longitude;
  double m_latitude;
  void verifieInvariant() const;
  bool estNombre(const std::string& p_identifiantVoiePublique);

  

};
}

#endif /* BORNE_H */