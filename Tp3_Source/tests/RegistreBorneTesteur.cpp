/**
 * \file RegistreBorneTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe RegistreBorne
 * \author Mohamed Amine Youssef
 * \version 0.1
 * \date 2024-04-7
 
 */
#include <gtest/gtest.h>
#include "RegistreBorne.h"
#include "BorneFontaine.h"
#include "BorneStationnement.h"
#include "BorneException.h"
#include "ContratException.h"
using namespace bornesQuebec;



class RegistreBorneFixture : public ::testing::Test {
public:
    RegistreBorne registre{"bornes de la ville de Québec 2024"};
    BorneStationnement borneStationnement{100001, "115066", "1re Avenue", -71.236271, 46.828998, 4005, "E"};
    BorneFontaine borneFontaine{103270, "115066", "Rue Arthur-Dion", -71.369426, 46.848633, "Québec", "La Haute-Saint-Charles"};

    void SetUp() override {
        registre.ajouteBorne(borneFontaine);
        registre.ajouteBorne(borneStationnement);
    }
};
/**
 * \brief Test du constructeur 
 *
 *        cas valide :
 *          Création d'une RegistreBorne valide 
 *
 *        cas invalides :NOnregistreBorne est vide
 *        	
 */

TEST_F(RegistreBorneFixture, Constructeur_NomValide) {
    EXPECT_EQ(registre.reqNomRegistreBorne(), "bornes de la ville de Québec 2024");
}
TEST_F(RegistreBorneFixture, NomRegistreInvalide) {
    EXPECT_THROW(RegistreBorne registreInvalide{""}, ContratException) << "Une ContratException aurait dû être lancée car le nom du registre est vide";
}

/**
 * \brief Test du constructeur de copie 
 */

TEST_F(RegistreBorneFixture, Constructeurdecopie) {
    RegistreBorne registreCopie = registre; 
    EXPECT_EQ(registreCopie.reqNomRegistreBorne(), registre.reqNomRegistreBorne());
    EXPECT_EQ(registreCopie.nbBornes(), registre.nbBornes());
}
/**
 * \brief Test  de une une forme canonique de coplien, il faut faire une copie en profondeur
 */

TEST_F(RegistreBorneFixture, Operateur) {
    RegistreBorne registreAssign{"Registre Assign"};
    registreAssign = registre; 
    EXPECT_EQ(registreAssign.reqNomRegistreBorne(), registre.reqNomRegistreBorne());
    EXPECT_EQ(registreAssign.nbBornes(), registre.nbBornes());
}
/**
 * \brief Test  pour ajout borne 
 * \brief vrai si le nbborne estégales aux nombres de borneavant+1
 */
/**
 * \brief  Test de la méthode std::string reRegistreFormate() 
 *        cas valide RegistreFormate: Registre connue dont on connaît le format.
 *        cas invalide Aucun d'identifié
 */
TEST_F(RegistreBorneFixture, ReqRegistreBorneFormate) {
    RegistreBorne registre("bornes de la ville de Québec 2024");
    BorneFontaine borneFontaine{103270, "115066", "Rue Arthur-Dion", -71.123456, 46.123456, "Québec", "La Haute-Saint-Charles"};
    BorneStationnement borneStationnement{100001, "115066", "1re Avenue", -71.123456, 46.123456, 4005, "E"};

    registre.ajouteBorne(borneFontaine);
    registre.ajouteBorne(borneStationnement);

    std::string formatAttendu =
      "Registre : bornes de la ville de Québec 2024\n"
      "----------------------------------------------\n"
      "Borne-fontaine\n"
      "----------------------------------------------\n"
      "Identifiant de la borne: 103270\n"
      "Voie publique: 115066\n"
      "Nom topographique: Rue Arthur-Dion\n"
      "Latitude: 46.123456\n"
      "Longitude: -71.123456\n"
      "Ville: Québec\n"
      "Arrondissement: La Haute-Saint-Charles\n\n"
      "----------------------------------------------\n"
      "Borne de stationnement\n"
      "----------------------------------------------\n"
      "Identifiant de la borne: 100001\n"
      "Voie publique: 115066\n"
      "Nom topographique: 1re Avenue\n"
      "Latitude: 46.123456\n"
      "Longitude: -71.123456\n"
      "Numero de la borne: 4005\n"
      "Cote de la rue: E\n\n"
      "----------------------------------------------\n";  

  auto actual = registre.reqRegistreBorneFormate();
  EXPECT_EQ(actual, formatAttendu);
}
TEST_F(RegistreBorneFixture, NbBornes) {
    EXPECT_EQ(registre.nbBornes(), 2);
}

/**
 * \brief Test de la méthode ajouteBorne de la classe RegistreBorne.
 * 
 * Ce test vérifie le comportement de la méthode ajouteBorne dans différentes situations :
 *  - Cas valide : Ajout d'une nouvelle borne qui n'existe pas déjà dans le registre.
 *  - Cas invalide : Tentative d'ajout d'une borne qui existe déjà dans le registre.
 */
TEST_F(RegistreBorneFixture, AjouteBorne) {
    // Cas valide : Ajout d'une borne qui n'existe pas déjà dans le registre
    int nbBornesAvant = registre.nbBornes();
    BorneFontaine nouvelleBorne{1, "12345", "Boulevard Laurier", -71.123456, 46.123456, "Québec", "Sainte-Foy"};
    EXPECT_NO_THROW(registre.ajouteBorne(nouvelleBorne));
    EXPECT_EQ(registre.nbBornes(), nbBornesAvant + 1);

    // Cas invalide : Tentative d'ajout d'une borne qui existe déjà dans le registre
    EXPECT_THROW(registre.ajouteBorne(borneFontaine), BorneDejaPresenteException);
    // Assurez-vous que le nombre de bornes reste inchangé après une tentative d'ajout invalide
    EXPECT_EQ(registre.nbBornes(), nbBornesAvant + 1); // Le nombre de bornes ne devrait pas avoir changé
}


/**
 * \brief Test de la méthode SupprimeBorne.
 * 
 *        cas valide: Supprimer une borne existante.
 *        cas invalide: Supprimer une borne inexistante.
 */
TEST_F(RegistreBorneFixture, SupprimeBorne) {
    // Test pour supprimer une borne existante
    int idBorneASupprimer = 103270; // Identifiant de la borne existante
    int nbBornesAvantSuppression = registre.nbBornes();
    EXPECT_NO_THROW(registre.SupprimeBorne(idBorneASupprimer));
    EXPECT_EQ(registre.nbBornes(), nbBornesAvantSuppression - 1);

    // Test pour supprimer une borne inexistante
    int idBorneInexistante = 999999; // Identifiant d'une borne inexistante
    EXPECT_THROW(registre.SupprimeBorne(idBorneInexistante), BorneAbsenteException);
}


