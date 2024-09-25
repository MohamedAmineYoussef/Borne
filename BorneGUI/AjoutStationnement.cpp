/**
 * \file AjoutStationnement.cpp
 * \brief Implémentation des méthodes de la classe AjoutStationnement, destinée à la création de nouvelles bornes de stationnement.
 *
 * Cette classe fournit une interface pour saisir les données relatives aux nouvelles bornes de stationnement. Elle interagit directement 
 * avec l'utilisateur via des champs de formulaire pour capturer les informations nécessaires à l'enregistrement d'une borne.
 *
 * \author Étudiant
 * \date 18 avril 2024
 */
#include "AjoutStationnement.h"
#include "BorneStationnement.h"

#include <QMessageBox>
/**
 * \brief Constructeur de la classe, initialise l'interface utilisateur.
 * \param parent Le widget parent.
 */
AjoutStationnement::AjoutStationnement(QWidget *parent) : QDialog(parent) {
    ui.setupUi(this); 
}
/**
 * \brief Destructeur de la classe.
 */
AjoutStationnement::~AjoutStationnement() {}
/**
 * \brief Récupère l'identifiant de la borne entré par l'utilisateur.
 * \return L'identifiant de la borne comme un entier.
 */
int AjoutStationnement::reqIdentifiant() const {
    return ui.identifiant->value();
}
/**
 * \brief Récupère l'identifiant de la voie publique de la borne entré par l'utilisateur.
 * \return L'identifiant de la voie publique comme une chaîne de caractères.
 */
QString AjoutStationnement::reqIdentifiantVoiePublique() const {
    return ui.voie->text();
}
/**
 * \brief Récupère le nom topographique du site de la borne entré par l'utilisateur.
 * \return Le nom topographique comme une chaîne de caractères.
 */
QString AjoutStationnement::reqNomTopographique() const {
    return ui.topographique->text();
}
/**
 * \brief Récupère la longitude de la borne entrée par l'utilisateur.
 * \return La longitude comme un double.
 */

double AjoutStationnement::reqLongitude() const {
    return ui.longitude->value();
}
/**
 * \brief Récupère la latitude de la borne entrée par l'utilisateur.
 * \return La latitude comme un double.
 */
double AjoutStationnement::reqLatitude() const {
    return ui.latitude->value();
}
/**
 * \brief Récupère le numéro de borne entré par l'utilisateur.
 * \return Le numéro de la borne comme un entier.
 */
int AjoutStationnement::reqNumBorne() const {
    return ui.numeroborne->value();
}
/**
 * \brief Récupère le côté de la rue  entré par l'utilisateur.
 * \return Le côté de la rue comme une chaîne de caractères.
 */
QString AjoutStationnement::reqCoteRue() const {
    return ui.cote->text();
}
/**
 * \brief Valide et enregistre les informations saisies pour une nouvelle borne de stationnement.
 * 
 * Cette méthode valide les données entrées par l'utilisateur dans le formulaire. Elle vérifie que l'identifiant
 * est strictement positif et que le nom topographique n'est pas vide. Si ces conditions ne sont pas remplies,
 * un message d'erreur est affiché et le processus d'enregistrement est interrompu. 
 *
 * \exception QMessageBox::information Affiche une boîte de dialogue d'erreur si les conditions de validation ne sont pas respectées.
 */

  void AjoutStationnement::enregistrer(){
    if(reqIdentifiant() <= 0){
        QString message("L'identifiant doit être strictement positif");
        QMessageBox::information(this,"ERREUR", message);
        return;
      } 
    
    if(reqNomTopographique().isEmpty()){
        QString message("Le nom topographique ne doit pas être vide");
        QMessageBox::information(this,"ERREUR", message);
        return;
      }
      accept();
  }

