 /**
 * \brief Implémentation de la classe BorneGUI qui fonctionne comme le contrôleur central de l'application de gestion des bornes.
 *
 * Dans ce fichier se trouvent les définitions des méthodes pour la classe BorneGUI, qui joue un rôle crucial en tant que contrôleur
 * de l'application. Elle orchestre les interactions entre l'interface utilisateur et la logique métier sous-jacente. La classe facilite
 * l'ajout, l'affichage et la suppression des bornes de stationnement et des fontaines via des dialogues interactifs. Chaque interaction
 * utilisateur provoque une action correspondante dans l'application, assurant ainsi une gestion cohérente et efficace des bornes urbaines.
 *
 * \author Étudiant
 * \date 18 avril 202

 */
#include "BorneException.h"
#include <QMessageBox>

#include "BorneGUI.h"
#include "AjoutStationnement.h"
#include "BorneStationnement.h"
#include "AjoutFontaine.h"
#include "SupprimerBorne.h"
#include "BorneFontaine.h"
#include "RegistreBorne.h"
#include <sstream>
#include "SupprimerBorne.h"

/**
 * \brief Constructeur de BorneGUI initialisant l'interface utilisateur et le registre des bornes.
 *
 * Ce constructeur crée l'interface utilisateur à partir d'un fichier de configuration Qt Designer et initialise
 * un nouveau registre de bornes avec un nom par défaut.
 * 
 * \post L'interface utilisateur est chargée et le registre de bornes est initialisé.
 */

BorneGUI::BorneGUI ()
{
    widget.setupUi (this);
    registreBorne = new RegistreBorne("bornes de l'agglomération de la ville de Québec");
}
/**
 * \brief Lance un dialogue pour ajouter une nouvelle borne de stationnement.
 *
 * Cette méthode ouvre une boîte de dialogue permettant à l'utilisateur de saisir les informations
 * d'une nouvelle borne de stationnement. Si l'utilisateur confirme l'ajout, la borne est créée et ajoutée
 * au registre. En cas de doublon, une erreur est signalée. L'affichage est mis à jour pour refléter le
 * contenu actuel du registre.
 * 
 * \pre Le dialogue doit être configuré correctement dans Qt Designer.
 * \post Si ajouté avec succès, la borne est incluse dans le registre et l'affichage est mis à jour.
 * \exception BorneDejaPresenteException S'il existe déjà une borne avec la même base .
 */
void BorneGUI::dialogStationnement() {
    AjoutStationnement stationnement;

    if (stationnement.exec()) {
        int identifiant = stationnement.reqIdentifiant();
        std::string voiePublique = stationnement.reqIdentifiantVoiePublique().toStdString();
        std::string nomTopographique = stationnement.reqNomTopographique().toStdString();
        double longitude = stationnement.reqLongitude();
        double latitude = stationnement.reqLatitude();
        int numBorne = stationnement.reqNumBorne();
        std::string coteRue = stationnement.reqCoteRue().toStdString();

        BorneStationnement uneBorne1{identifiant, voiePublique, nomTopographique, longitude, latitude, numBorne, coteRue};

        try {
            registreBorne->ajouteBorne(uneBorne1);
        } catch (BorneDejaPresenteException& e) {
            QString message = e.what();
            QMessageBox::information(this, "ERREUR", message);
        }
        widget.affichage->setText(QString::fromStdString(registreBorne->reqRegistreBorneFormate()));
    }
}

/**
 * \brief Lance un dialogue pour ajouter une nouvelle borne-fontaine.
 *
 * Cette méthode ouvre une boîte de dialogue permettant à l'utilisateur de saisir les informations
 * d'une nouvelle borne-fontaine. Si l'utilisateur confirme l'ajout, la borne est créée et ajoutée
 * au registre. En cas de doublon, une erreur est signalée. L'affichage est mis à jour pour refléter le
 * contenu actuel du registre.
 * 
 * \pre Le dialogue doit être configuré correctement dans Qt Designer.
 * \post Si ajouté avec succès, la borne est incluse dans le registre et l'affichage est mis à jour.
 * \exception BorneDejaPresenteException S'il existe déjà une borne avec la même base.
 */

void BorneGUI::dialogFontaine() {
    AjoutFontaine Fontaine;
    if (Fontaine.exec()) {
        std::string voiePublique = Fontaine.reqVoiePublique().toStdString();
        std::string nomTopographique = Fontaine.reqNomTopographique().toStdString();
        std::string ville = Fontaine.reqVille().toStdString();
        std::string arrondissement = Fontaine.reqArrondissement().toStdString();

        BorneFontaine uneBorne{Fontaine.reqIdentifiant(),
                               voiePublique,
                               nomTopographique,
                               Fontaine.reqLongitude(),
                               Fontaine.reqLatitude(),
                               ville,
                               arrondissement};

        try {
            registreBorne->ajouteBorne(uneBorne);
        } catch (BorneDejaPresenteException& e) {
            QString message = e.what();
            QMessageBox::information(this, "ERREUR", message);
        }
        widget.affichage->setText(QString::fromStdString(registreBorne->reqRegistreBorneFormate()));
    }
}
/**
 * \brief Lance un dialogue pour supprimer une borne par son identifiant.
 *
 * Cette méthode ouvre une boîte de dialogue qui demande à l'utilisateur de saisir l'identifiant d'une borne
 * à supprimer. Si l'utilisateur confirme, la méthode tente de supprimer la borne du registre. Si la borne
 * avec l'identifiant donné n'existe pas, une erreur est affichée. Si la suppression est réussie, l'affichage
 * est mis à jour pour refléter les changements dans le registre.
 * 
 * \pre L'utilisateur doit entrer un identifiant valide.
 * \post Si la borne est trouvée et supprimée avec succès, elle est retirée du registre et l'affichage est mis à jour.
 * \exception BorneAbsenteException S'il n'y a pas de borne avec l'identifiant spécifié.
 */
void BorneGUI::dialogSupprimerBorne() {
    SupprimerBorne dialogSupp;
    if (dialogSupp.exec() == QDialog::Accepted) {
        int identifiant = dialogSupp.reqIdentifiant();
        try {
            registreBorne->SupprimeBorne(identifiant);
            widget.affichage->setText(QString::fromStdString(registreBorne->reqRegistreBorneFormate()));
        } catch (const BorneAbsenteException& e) {
            QMessageBox::warning(this, "Erreur lors de Suppression", e.what());
        }
    }
}
      
    
    
  

/**
 * \brief Destructeur de la classe.
 */
  

BorneGUI::~BorneGUI() {
    delete registreBorne; 
}
