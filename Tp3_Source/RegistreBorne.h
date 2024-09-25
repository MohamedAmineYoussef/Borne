/**
 * \class RegistreBorne
 * \brief Cette classe sert au maintien et à la manipulation des RegistreBorne.
 *
 *             La classe maintient dans un état cohérent ces renseignements.
 *             Elle valide ce qu'on veut lui assigner.
 *              <p>
 *              Cette classe peut aussi servir à prendre la REgistreBorne courante du
 *              système et à faire des calculs avec des REgistreBornes.
 *              <p>
 *              La classe n'accepte que des registreBorne invalides, c'est la
 *              responsabilité de l'utilisateur de la classe de s'en assurer.
 *              <p>
 *  Attributs:  const std::string& p_nomRegistreBorne
 
  */

#ifndef REGISTREBORNE_H
#define REGISTREBORNE_H
#include <vector>
#include <memory>
#include "Borne.h"
using namespace bornesQuebec;

class RegistreBorne{
public:
  RegistreBorne(const std::string& p_nomRegistreBorne);
  RegistreBorne (const RegistreBorne& p_registreborne);
  void ajouteBorne(const Borne& p_borne);
  std::string reqNomRegistreBorne() const;
  std::string reqRegistreBorneFormate() const;
  int nbBornes() const;
  RegistreBorne& operator= (const RegistreBorne& p_registreborne);
  void SupprimeBorne(int p_identifiant);
  
private:
    std::string m_nomRegistreBorne;
    std::vector<std::unique_ptr<Borne>> m_bornes;
    bool borneExisteDeja(const Borne& p_borne) const;
    void verifieInvariant() const;
};

#endif /* REGISTREBORNE_H */