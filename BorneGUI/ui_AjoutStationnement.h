/********************************************************************************
** Form generated from reading UI file 'AjoutStationnement.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTSTATIONNEMENT_H
#define UI_AJOUTSTATIONNEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AjoutStationnement
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *voie;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *cote;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *ok;
    QLabel *label_8;
    QLineEdit *topographique;
    QDoubleSpinBox *latitude;
    QDoubleSpinBox *longitude;
    QSpinBox *numeroborne;
    QSpinBox *identifiant;

    void setupUi(QDialog *AjoutStationnement)
    {
        if (AjoutStationnement->objectName().isEmpty())
            AjoutStationnement->setObjectName(QString::fromUtf8("AjoutStationnement"));
        AjoutStationnement->resize(450, 300);
        label = new QLabel(AjoutStationnement);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 191, 16));
        label_2 = new QLabel(AjoutStationnement);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 141, 16));
        voie = new QLineEdit(AjoutStationnement);
        voie->setObjectName(QString::fromUtf8("voie"));
        voie->setGeometry(QRect(150, 40, 113, 28));
        label_3 = new QLabel(AjoutStationnement);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 50, 91, 16));
        label_4 = new QLabel(AjoutStationnement);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 110, 58, 16));
        cote = new QLineEdit(AjoutStationnement);
        cote->setObjectName(QString::fromUtf8("cote"));
        cote->setGeometry(QRect(150, 190, 113, 28));
        label_5 = new QLabel(AjoutStationnement);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 140, 71, 16));
        label_6 = new QLabel(AjoutStationnement);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 170, 131, 16));
        label_7 = new QLabel(AjoutStationnement);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 200, 141, 16));
        ok = new QPushButton(AjoutStationnement);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(160, 240, 90, 28));
        label_8 = new QLabel(AjoutStationnement);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 80, 131, 16));
        topographique = new QLineEdit(AjoutStationnement);
        topographique->setObjectName(QString::fromUtf8("topographique"));
        topographique->setGeometry(QRect(150, 70, 113, 28));
        latitude = new QDoubleSpinBox(AjoutStationnement);
        latitude->setObjectName(QString::fromUtf8("latitude"));
        latitude->setGeometry(QRect(150, 100, 111, 26));
        latitude->setDecimals(5);
        latitude->setMinimum(-1001.999990000000025);
        latitude->setMaximum(1001.999990000000025);
        longitude = new QDoubleSpinBox(AjoutStationnement);
        longitude->setObjectName(QString::fromUtf8("longitude"));
        longitude->setGeometry(QRect(150, 130, 111, 26));
        longitude->setDecimals(5);
        longitude->setMinimum(-1001.999990000000025);
        longitude->setMaximum(1000.999990000000025);
        numeroborne = new QSpinBox(AjoutStationnement);
        numeroborne->setObjectName(QString::fromUtf8("numeroborne"));
        numeroborne->setGeometry(QRect(150, 160, 111, 26));
        numeroborne->setMaximum(9999);
        identifiant = new QSpinBox(AjoutStationnement);
        identifiant->setObjectName(QString::fromUtf8("identifiant"));
        identifiant->setGeometry(QRect(150, 10, 111, 26));
        identifiant->setMinimum(0);
        identifiant->setMaximum(10000000);

        retranslateUi(AjoutStationnement);
        QObject::connect(ok, SIGNAL(clicked()), AjoutStationnement, SLOT(enregistrer()));

        QMetaObject::connectSlotsByName(AjoutStationnement);
    } // setupUi

    void retranslateUi(QDialog *AjoutStationnement)
    {
        AjoutStationnement->setWindowTitle(QCoreApplication::translate("AjoutStationnement", "AjoutStationnement", nullptr));
        label->setText(QCoreApplication::translate("AjoutStationnement", "Identifiant de la borne:", nullptr));
        label_2->setText(QString());
        voie->setText(QString());
        label_3->setText(QCoreApplication::translate("AjoutStationnement", "Voie publique:", nullptr));
        label_4->setText(QCoreApplication::translate("AjoutStationnement", "Latitude:", nullptr));
        label_5->setText(QCoreApplication::translate("AjoutStationnement", "Longitude:", nullptr));
        label_6->setText(QCoreApplication::translate("AjoutStationnement", "Numero de la borne:", nullptr));
        label_7->setText(QCoreApplication::translate("AjoutStationnement", "Cote de la rue:", nullptr));
        ok->setText(QCoreApplication::translate("AjoutStationnement", "OK", nullptr));
        label_8->setText(QCoreApplication::translate("AjoutStationnement", "Nom topographique: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutStationnement: public Ui_AjoutStationnement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTSTATIONNEMENT_H
