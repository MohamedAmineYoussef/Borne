/**
 * \file BorneTest.cpp
 * \brief Fichier de tests unitaires pour la classe Borne
 * \author Mohamed Amine Youssef
 * \version 0.1
 * \date 2024-03-17
 
 */
#include <gtest/gtest.h>
#include "Borne.h"
#include "ContratException.h"
using namespace bornesQuebec;

/**
 * \brief Test du constructeur avec paramètres de Date::Date(int p_identifiant,const std::string p_identifiantVoiePublique,
 * const std::string p_nomTopographique,double p_longitude,double p_latitude)
 *
 *        cas valide :
 *          Création d'une Borne valide 
 *
 *        cas invalides :
 *        	Identifiant invalide -> ConstructeurInvalide,
 *        	nomTopographique Invalide : ConstructeurInvalideNomTopographique,
 *        	
 *        	longitude+latitude invalides : ConstructeurInvalideLongitudeLatitude
 */
class BorneFix : public Borne {
public:
    BorneFix(int p_identifiant, const std::string& p_identifiantVoiePublique, const std::string& p_nomTopographique, double p_longitude, double p_latitude)
    : Borne(p_identifiant, p_identifiantVoiePublique, p_nomTopographique, p_longitude, p_latitude) {
    }

    std::unique_ptr<Borne> clone() const override {
        return std::make_unique<BorneFix>(*this);
    }
};
class BorneFixture : public ::testing::Test {
  
public:
   BorneFix borne2{1, "100000", "Boulevard Laurier", -71.712647, 46.712647};
    };

TEST_F(BorneFixture, Constructeur) {
    EXPECT_EQ(borne2.reqIdentifiant(), 1);
    EXPECT_EQ(borne2.reqnomTopographique(), "Boulevard Laurier");
    EXPECT_EQ(borne2.reqidentifiantVoiePublique(), "100000");
    EXPECT_DOUBLE_EQ(borne2.reqlongitude(), -71.712647);
    EXPECT_DOUBLE_EQ(borne2.reqlatitude(), 46.712647);
}

TEST_F(BorneFixture, ConstructeurInvalideLongitudeLatitude) {
    EXPECT_THROW(BorneFix borne(-1, "111Bd St", "Boulevard Micheal", -71, 46), ContratException);
}
TEST_F(BorneFixture, ConstructeurInvalide) {
    EXPECT_THROW(BorneFix borne(-1, "111Bd St", "Boulevard Micheal", -71.712647, 46.712647), ContratException);
}

TEST_F(BorneFixture, ConstructeurInvalideNomTopographique) {
    EXPECT_THROW(BorneFix borne(-1, "111Bd St", "", -71.712647, 46.712647), ContratException);
}
/**
 * \brief Test de la méthode void Borne:: asgNomTopographique
 *     	cas valide
 *     		AssignNomTopographique: Assigner une Borne avec un NomTopographique valide
 *   	cas invalides
 *        	NomTopographique Invalide : AssignInvalideNomTopographique

 */
TEST_F(BorneFixture, AssignNomTopographique) {
    borne2.asgNomTopographique("New Boulevard");
    EXPECT_EQ(borne2.reqnomTopographique(), "New Boulevard");
}

TEST_F(BorneFixture, AssignInvalideNomTopographique) {
    EXPECT_THROW(borne2.asgNomTopographique(""), ContratException);
}
/**
 * \brief  Test de la méthode bool operator== (const Borne& p_borne)
 *        cas valide:
 *   		OperatorEgalEgalVrai: 	Borne indentique à elle-même.
 *  		OperatorEgalEgalFaux: 	Borne différentes
 *        cas invalide Aucun d'identifié
 */
TEST_F(BorneFixture, Égalité) {
    BorneFix borne1{1, "100000", "Boulevard Laurier", -71.712647, 46.712647};
    EXPECT_TRUE(borne2 == borne1);
    
}

TEST_F(BorneFixture, NonEgale) {
    BorneFix borne3{2, "100000", "Boulevard Laurier", -71.712647, 46.712647};
    EXPECT_FALSE(borne2 == borne3);
}
/**
 * \brief  Test de la méthode std::string reqBorneFormate() 
 *        cas valide BorneFormat: Borne connue dont on connaît le format.
 *        cas invalide Aucun d'identifié
 */
TEST_F(BorneFixture, BorneFormat) {
    std::string Format = "Identifiant de la borne: 1\n"
                                 "Voie publique: 100000\n"
                                 "Nom topographique: Boulevard Laurier\n"
                                 "Latitude: 46.712647\n"
                                 "Longitude: -71.712647\n";  
    EXPECT_EQ(borne2.reqBorneFormate(), Format);
}

