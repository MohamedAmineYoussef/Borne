/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/*
 * File:   SupprimerBorne.cpp
 * Author: etudiant
 *
 * Created on 19 avril 2024, 12 h 25
 */

/**
 * \brief Boîte de dialogue pour supprimer une borne.
 *
 * Cette classe représente une boîte de dialogue permettant à l'utilisateur de saisir
 * l'identifiant d'une borne à supprimer. L'utilisateur peut valider la suppression ou annuler
 * l'opération.
 */
#include "SupprimerBorne.h"
#include "RegistreBorne.h"
#include <QMessageBox>



/**
 * \brief Constructeur par défaut de la classe SupprimerBorne.
 * 
 * Initialise la boîte de dialogue avec les éléments d'interface utilisateur.
 */
SupprimerBorne::SupprimerBorne ()
{
  widget.setupUi (this);
}

/**
 * \brief Renvoie l'identifiant de la borne à supprimer.
 * 
 * \return L'identifiant de la borne à supprimer.
 */
int SupprimerBorne::reqIdentifiant()const{
  return widget.identifiant->value ();
}

/**
 * \brief Valide la saisie de l'utilisateur.
 * 
 * Cette méthode est appelée lorsque l'utilisateur appuie sur le bouton "Valider".
 * Elle vérifie que l'identifiant saisi est strictement positif. Si ce n'est pas le cas,
 * elle affiche un message d'erreur. Sinon, elle accepte la saisie et ferme la boîte de dialogue.
 */

void SupprimerBorne::valider()
{

    if(reqIdentifiant() <= 0){
        QString message("L'identifiant doit être strictement positif");
        QMessageBox::information(this,"ERREUR", message);
        return;
      } 
      accept();

    }

 /**
 * \brief Destructeur par défaut de la classe SupprimerBorne.
 * 
 * Ce destructeur ne fait rien de particulier car la classe ne nécessite pas de nettoyage spécifique
 * lors de sa destruction.
 */

SupprimerBorne::~SupprimerBorne () { }
