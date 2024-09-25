
/**
 * \class BorneFontaine
 * \brief Cette classe sert au maintien et à la manipulation des BorneFontaine.
 *
 *             La classe maintient dans un état cohérent ces renseignements.
 *             Elle valide ce qu'on veut lui assigner.
 *              <p>
 *              Cette classe peut aussi servir à prendre la BorneFontaine courante du
 *              système et à faire des calculs avec des BorneFontaine.
 *              <p>
 *              La classe n'accepte que des BorneFontaine valides, c'est la
 *              responsabilité de l'utilisateur de la classe de s'en assurer.
 *              <p>
 *  Attributs:  int p_identifiant,const std::string p_identifiantVoiePublique,const std::string p_nomTopographique,double p_longitude,double p_latitude,const std::string& p_ville
 * p_arrondissement
 
  */
#ifndef BORNEFONTAINE_H
#define BORNEFONTAINE_H


#include "Borne.h"
#include <string>
#include <memory>
using namespace bornesQuebec;


class BorneFontaine : public Borne {
public:
    BorneFontaine(int p_identifiant, const std::string& p_identifiantVoiePublique, const std::string& p_nomTopographique,
                  double p_longitude, double p_latitude, const std::string& p_ville, const std::string& p_arrondissement);

    const std::string& reqVille() const;
    const std::string& reqArrondissement() const;
    virtual std::unique_ptr<Borne> clone() const ;
    virtual std::string reqBorneFormate() const override;  

private:
    std::string m_ville;
    std::string m_arrondissement;

    void verifieInvariant() const;
};


#endif // BORNEFONTAINE_H
