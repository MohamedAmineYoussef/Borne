

/**
 * \file AjoutStationnement.h
 * \brief Définit la classe AjoutStationnement qui permet de saisir les informations relatives à un nouveau stationnement.
 *
 * Ce fichier contient la déclaration de la classe AjoutStationnement, utilisée pour recueillir les informations 
 * nécessaires à l'ajout d'une nouvelle borne de stationnement dans l'application.
 *
 * \author Étudiant
 * \date 19 avril 2024
 */


#ifndef AJOUTSTATIONNEMENT_H
#define AJOUTSTATIONNEMENT_H

#include <QDialog>
#include "ui_AjoutStationnement.h"

class AjoutStationnement : public QDialog {
    Q_OBJECT

public:
    explicit AjoutStationnement(QWidget *parent = nullptr);
    ~AjoutStationnement();

    int reqIdentifiant() const;
    QString reqIdentifiantVoiePublique() const;
    QString reqNomTopographique() const;
    double reqLongitude() const;
    double reqLatitude() const;
    int reqNumBorne() const;
    QString reqCoteRue() const;
private slots:
    void enregistrer();

private:
    Ui::AjoutStationnement ui;
};

#endif // AJOUTSTATIONNEMENT_H