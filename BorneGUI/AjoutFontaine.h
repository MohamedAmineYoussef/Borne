/**
 * \file AjoutFontaine.h
 * \brief Définit la classe AjoutFontaine qui fournit une interface utilisateur pour ajouter un objet de type "Fontaine".
 *
 * Ce fichier contient la déclaration de la classe AjoutFontaine, qui est utilisée
 * pour interagir avec l'utilisateur afin de recueillir des données pour l'ajout d'une nouvelle Fontaine dans le système.
 * Elle repose sur l'interface utilisateur définie dans ui_AjoutFontaine.h.
 *
 * \author Étudiant
 * \date 19 avril 2024
 */


#ifndef _AJOUTFONTAINE_H
#define _AJOUTFONTAINE_H

#include "ui_AjoutFontaine.h"

class AjoutFontaine : public QDialog
{
  Q_OBJECT
public:
  AjoutFontaine ();
  virtual ~AjoutFontaine ();
  
  int reqIdentifiant()const;
  QString reqVoiePublique()const;
  QString reqNomTopographique()const;
  double reqLongitude()const;
  double reqLatitude()const;
  QString reqVille()const;
  QString reqArrondissement()const;
  
  private slots:
    void valider();
private:
  Ui::AjoutFontaine widget;
};

#endif /* _AJOUTFONTAINE_H */
