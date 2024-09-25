/**
 * \file BorneFontaine Test.cpp
 * \brief Fichier de tests unitaires pour la classe Fontaine
 * \author Mohamed Amine Youssef
 * \version 0.1
 * \date 2024-03-22
 
 */
#include <gtest/gtest.h>
#include "BorneFontaine.h"
using namespace bornesQuebec;

/**
 * \brief Test du constructeur avec paramètres de BorneFontaine(int p_identifiant, const std::string& p_identifiantVoiePublique, const std::string& p_nomTopographique,
                  double p_longitude, double p_latitude, const std::string& p_ville, const std::string& p_arrondissement)
 *
 *        cas valide :
 *          Création d'une BorneFontaine valide 
 *
 *        cas invalides :
 *        	ville invalide -> Constructeur_VilleEmptyInvalide,
 *        	arrondissement Invalide : Constructeur_ArrondissementEmptyInvalide,
 *        	
 */
class BorneFixture : public ::testing::Test {
public:
    BorneFontaine borne2{1, "12345", "Boulevard Laurier", -71.123456, 46.123456, "Québec", "Sainte-Foy"};
};

// Use TEST_F instead of TEST to utilize the BorneFixture
TEST_F(BorneFixture, Constructeur_ParametreValide) {
    EXPECT_EQ(borne2.reqVille(), "Québec");
    EXPECT_EQ(borne2.reqArrondissement(), "Sainte-Foy");
}

TEST_F(BorneFixture, Constructeur_VilleEmptyInvalide) {
    EXPECT_THROW(BorneFontaine(100, "12345", "Boulevard Laurier", -71.123456, 46.123456, "", "Sainte-Foy"), PreconditionException);
}

TEST_F(BorneFixture, Constructeur_ArrondissementEmptyInvalide) {
    EXPECT_THROW(BorneFontaine(100, "12345", "Boulevard Laurier", -71.123456, 46.123456, "Québec", ""), PreconditionException);
}
/**
 * \brief Test de la méthode clone pour BorneFontaine
 *        Cas valide :
 *          CloneMethod : L'objet cloné doit être une copie exacte de l'original.
 */


TEST_F(BorneFixture, MethodeClone) {
    auto Borne1 = borne2.clone();

    auto BorneFontaine1 = dynamic_cast<BorneFontaine*>(Borne1.get());

    ASSERT_NE(BorneFontaine1, nullptr);  
    EXPECT_EQ(BorneFontaine1->reqVille(), borne2.reqVille());
    EXPECT_EQ(BorneFontaine1->reqArrondissement(), borne2.reqArrondissement());
    EXPECT_EQ(BorneFontaine1->reqIdentifiant(), borne2.reqIdentifiant());
    EXPECT_EQ(BorneFontaine1->reqidentifiantVoiePublique(), borne2.reqidentifiantVoiePublique());
    EXPECT_EQ(BorneFontaine1->reqnomTopographique(), borne2.reqnomTopographique());
    EXPECT_DOUBLE_EQ(BorneFontaine1->reqlongitude(), borne2.reqlongitude());
    EXPECT_DOUBLE_EQ(BorneFontaine1->reqlatitude(), borne2.reqlatitude());
}
TEST_F(BorneFixture, reqVille) {
    EXPECT_EQ(borne2.reqVille(), "Québec");
}

TEST_F(BorneFixture, reqArrondissement) {
    EXPECT_EQ(borne2.reqArrondissement(), "Sainte-Foy");
}
/**
 * \brief  Test de la méthode std::string reqBorneFontaineFormate() 
 *        cas valide BorneFOntaineFormat: BorneFontaine connue dont on connaît le format.
 *        cas invalide Aucun d'identifié
 */
TEST_F(BorneFixture, reqBorneFormate) {
    std::string FormatAttendu =
        "Borne-fontaine\n"
        "----------------------------------------------\n"
        "Identifiant de la borne: 1\n"
        "Voie publique: 12345\n"
        "Nom topographique: Boulevard Laurier\n"
        "Latitude: 46.123456\n"
        "Longitude: -71.123456\n"
        "Ville: Québec\n"
        "Arrondissement: Sainte-Foy\n"; 

    EXPECT_EQ(borne2.reqBorneFormate(), FormatAttendu);
}


