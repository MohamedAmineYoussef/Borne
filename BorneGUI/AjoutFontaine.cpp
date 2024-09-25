/**
 * \file AjoutFontaine.cpp
 * \brief Implémentation des méthodes de la classe AjoutFontaine, destinée à la création de nouvelles bornes fontaine.
 *
 * Cette classe fournit une interface pour saisir les données relatives aux nouvelles bornes fontaine. Elle interagit directement 
 * avec l'utilisateur via des champs de formulaire pour capturer les informations nécessaires à l'enregistrement d'une borne.
 *
 * \author Étudiant
 * \date 18 avril 2024
 */

#include "AjoutFontaine.h"
#include <QMessageBox>

 /**
 * \brief Constructeur de la classe.
 * 
 * Initialise l'interface utilisateur.
 */
AjoutFontaine::AjoutFontaine ()
{
  widget.setupUi (this);
}

 /**
 * \brief Destructeur de la classe.
 */
AjoutFontaine::~AjoutFontaine () { }

 /**
 * \brief Récupère l'identifiant de la borne entré par l'utilisateur.
 * \return L'identifiant de la borne comme un entier.
 */
int AjoutFontaine::reqIdentifiant()const{
  return widget.identifiant->value ();
}
 /**
 * \brief Récupère l'identifiant de la voie publique de la borne entré par l'utilisateur.
 * \return L'identifiant de la voie publique comme une chaîne de caractères.
 */
  QString AjoutFontaine::reqVoiePublique()const{
    return widget.voiePublique->text ();
  }
  
 /**
 * \brief Récupère le nom topographique du site de la borne entré par l'utilisateur.
 * \return Le nom topographique comme une chaîne de caractères.
 */
  QString AjoutFontaine::reqNomTopographique()const{
    return widget.nomTopographique->text ();
  }
  
 /**
 * \brief Récupère la longitude de la borne entrée par l'utilisateur.
 * \return La longitude comme un double.
 */
  double AjoutFontaine::reqLongitude()const{
    return widget.longitude->value ();
  }
   
 /**
 * \brief Récupère la latitude de la borne entrée par l'utilisateur.
 * \return La latitude comme un double.
 */
  double AjoutFontaine::reqLatitude()const{
    return widget.latitude->value ();
  }
  
 /**
 * \brief Récupère le nom de la ville où se trouve la borne entré par l'utilisateur.
 * \return Le nom de la ville comme une chaîne de caractères.
 */
  QString AjoutFontaine::reqVille()const{
    return widget.ville->text ();
  }
  
 /**
 * \brief Récupère le nom de l'arrondissement où se trouve la borne entré par l'utilisateur.
 * \return Le nom de l'arrondissement comme une chaîne de caractères.
 */
  QString AjoutFontaine::reqArrondissement()const{
    return widget.arrondissement->text ();
  }
  
 /**
 * \brief Valide et enregistre les informations saisies pour une nouvelle borne fontaine.
 * 
 * Cette méthode valide les données entrées par l'utilisateur dans le formulaire. Elle vérifie que l'identifiant
 * est strictement positif, que le nom topographique n'est pas vide, et que si la ville est "Québec", 
 * l'arrondissement n'est pas vide. Si ces conditions ne sont pas remplies, un message d'erreur est affiché 
 * et le processus d'enregistrement est interrompu. 
 *
 * \exception QMessageBox::information Affiche une boîte de dialogue d'erreur si les conditions de validation ne sont pas respectées.
 */
  
  void AjoutFontaine::valider(){
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
    
     if(reqVille() == "Québec" and reqArrondissement().isEmpty()){
        QString message("L’arrondissement ne doit pas être vide si la ville est Québec");
        QMessageBox::information(this,"ERREUR", message);
        return;
      }
    accept();
  }
