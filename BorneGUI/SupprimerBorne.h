/**
 * \file SupprimerBorne.h
 * \brief Définit la classe SupprimerBorne qui fournit une interface utilisateur pour ajouter un objet de type "Borne".
 *
 * Ce fichier contient la déclaration de la classe SupprimerBorne, qui est utilisée
 * pour interagir avec l'utilisateur afin de recueillir des données pour supprimer d'une nouvelle Borne dans le système.
 * 
 *
 * \author Étudiant
 * \date 19 avril 2024
 */
#ifndef _SUPPRIMERBORNE_H
#define _SUPPRIMERBORNE_H

#include "ui_SupprimerBorne.h"

class SupprimerBorne : public QDialog
{
  Q_OBJECT
public:
  SupprimerBorne ();
  virtual ~SupprimerBorne ();
  int reqIdentifiant()const;
  private slots:
    void valider();
private:
  Ui::SupprimerBorne widget;
};

#endif /* _SUPPRIMERBORNE_H */
