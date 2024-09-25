/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   BorneGUI.h
 * Author: etudiant
 *
 * Created on 18 avril 2024, 17 h 24
 */

#ifndef _BORNEGUI_H
#define _BORNEGUI_H

#include "ui_BorneGUI.h"
#include "RegistreBorne.h"

using namespace bornesQuebec;

 /**
 * \class BorneGUI
 * \brief Interface principale de l'application de gestion des bornes.
 * 
 * Cette classe représente l'interface principale de l'application de gestion des bornes. Elle permet à l'utilisateur
 * d'interagir avec le système pour ajouter de nouvelles bornes, supprimer des bornes existantes et afficher les
 * informations sur les bornes enregistrées.
 */
class BorneGUI : public QMainWindow
{
  Q_OBJECT
public:
  /**
  * \brief Constructeur par défaut de la classe BorneGUI.
  */
  BorneGUI ();
  /**
  * \brief Destructeur de la classe BorneGUI.
  */
  virtual ~BorneGUI ();
private slots:
  /**
  * \brief Ouvre un dialogue pour ajouter une nouvelle borne de stationnement.
  */
  void dialogStationnement();
  /**
  * \brief Ouvre un dialogue pour ajouter une nouvelle borne-fontaine.
  */
  void dialogFontaine();
  /**
  * \brief Ouvre un dialogue pour supprimer une borne.
  */
  void dialogSupprimerBorne();


  
private:
  Ui::BorneGUI widget;
  RegistreBorne *registreBorne;
  
};

#endif /* _BORNEGUI_H */
