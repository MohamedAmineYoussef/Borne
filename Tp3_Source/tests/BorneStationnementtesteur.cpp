/**
 * \file BorneStationnementTest.cpp
 * \brief Fichier de tests unitaires pour la classe BorneStationnement
 * \author Mohamed Amine Youssef
 * \version 0.1
 * \date 2024-03-25
 
 */
#include <gtest/gtest.h>
#include "BorneStationnement.h"
#include "ContratException.h"
using namespace bornesQuebec;

/**
 * \brief Test du constructeur avec paramètres de BorneStationnement(int p_identifiant,const std::string p_identifiantVoiePublique,const std::string p_nomTopographique,
                   double p_longitude,double p_latitude,int p_numBorne, const std::string& p_coteRue)
 *
 *        cas valide :
 *          Création d'une BorneStationnement valide 
 *
 *        cas invalides :
 *        	 NumBorne invalide -> ConstructeurNumBorneInvalide
 *        	CoteRur Invalide : ConstructeurCoteRueInvalide
 *        	
 */
class BorneStationnementFixture : public ::testing::Test {
public:
    BorneStationnement borneStationnement{1, "10000", "Boulevard Laurier", -71.123456, 46.123456, 4005, "N"};


};

// Test du constructeur avec paramètres valides
TEST_F(BorneStationnementFixture, ConstructeurParametreValide) {
    EXPECT_EQ(borneStationnement.reqNumBorne(), 4005);
    EXPECT_EQ(borneStationnement.reqCoteRue(), "N");
}

// Test du constructeur avec un numéro de borne invalide
TEST(BorneStationnementTest, ConstructeurNumBorneInvalide) {
    EXPECT_THROW(BorneStationnement(1, "10000", "Boulevard Laurier", -71.123456, 46.123456, 0, "N"), PreconditionException);
}

// Test du constructeur avec un côté de rue invalide
TEST(BorneStationnementTest, ConstructeurCoteRueInvalide) {
    EXPECT_THROW(BorneStationnement(1, "10000", "Boulevard Laurier", -71.123456, 46.123456, 4005, "Faux"), PreconditionException);
}
/**
 * \brief Test de la méthode clone pour BorneStationnement
 *        Cas valide :
 *          MethodeClone : L'objet cloné doit être une copie exacte de l'original.
 */
TEST_F(BorneStationnementFixture, MethodeClone) {
    auto borneClonee = borneStationnement.clone();

    auto borneStationnementClonee = dynamic_cast<BorneStationnement*>(borneClonee.get());

    ASSERT_NE(borneStationnementClonee, nullptr);  
    EXPECT_EQ(borneStationnementClonee->reqNumBorne(), borneStationnement.reqNumBorne());
    EXPECT_EQ(borneStationnementClonee->reqCoteRue(), borneStationnement.reqCoteRue());
    EXPECT_EQ(borneStationnementClonee->reqIdentifiant(), borneStationnement.reqIdentifiant());
    EXPECT_EQ(borneStationnementClonee->reqidentifiantVoiePublique(), borneStationnement.reqidentifiantVoiePublique());
    EXPECT_EQ(borneStationnementClonee->reqnomTopographique(), borneStationnement.reqnomTopographique());
    EXPECT_DOUBLE_EQ(borneStationnementClonee->reqlongitude(), borneStationnement.reqlongitude());
    EXPECT_DOUBLE_EQ(borneStationnementClonee->reqlatitude(), borneStationnement.reqlatitude());
}


/**
 * \brief  Test de la méthode BorneStationnement::reqBorneFormate() 
 *        cas valide BorneStationnementFormat: BorneStationnement connue dont on connaît le format.
 *        cas invalide Aucun d'identifié
 */
TEST_F(BorneStationnementFixture, ReqBorneFormate) {
    std::string formatAttendu =
        "Borne de stationnement\n"
        "----------------------------------------------\n"
        "Identifiant de la borne: 1\n"
        "Voie publique: 10000\n"
        "Nom topographique: Boulevard Laurier\n"
        "Latitude: 46.123456\n"
        "Longitude: -71.123456\n"
        "Numero de la borne: 4005\n"
        "Cote de la rue: N\n";

    EXPECT_EQ(borneStationnement.reqBorneFormate(), formatAttendu);
}

