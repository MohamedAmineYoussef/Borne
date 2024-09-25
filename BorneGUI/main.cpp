/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/main.cc to edit this template
 */

/*
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 14 avril 2024, 17 h 24
 */

#include <QApplication>
#include "BorneGUI.h"

/**
 * \brief Fonction principale du programme.
 * 
 * Elle crée une application Qt, instancie la fenêtre principale de l'application BorneGUI, l'affiche et exécute l'application.
 * 
 * \param argc Le nombre d'arguments de la ligne de commande.
 * \param argv Les arguments de la ligne de commande.
 * \return Le code de sortie de l'application.
 */
int
main (int argc, char *argv[])
{

  QApplication app (argc, argv);

  BorneGUI fenetrePrincipale;
  fenetrePrincipale.show();
  return app.exec ();
}
