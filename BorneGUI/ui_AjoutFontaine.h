/********************************************************************************
** Form generated from reading UI file 'AjoutFontaine.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTFONTAINE_H
#define UI_AJOUTFONTAINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AjoutFontaine
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *identifiant;
    QPushButton *ok;
    QLineEdit *voiePublique;
    QLineEdit *nomTopographique;
    QDoubleSpinBox *longitude;
    QDoubleSpinBox *latitude;
    QLineEdit *ville;
    QLineEdit *arrondissement;

    void setupUi(QDialog *AjoutFontaine)
    {
        if (AjoutFontaine->objectName().isEmpty())
            AjoutFontaine->setObjectName(QString::fromUtf8("AjoutFontaine"));
        AjoutFontaine->resize(401, 429);
        label = new QLabel(AjoutFontaine);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 40, 141, 16));
        label_2 = new QLabel(AjoutFontaine);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 80, 121, 16));
        label_3 = new QLabel(AjoutFontaine);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 120, 131, 16));
        label_4 = new QLabel(AjoutFontaine);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 160, 91, 16));
        label_5 = new QLabel(AjoutFontaine);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 200, 58, 16));
        label_6 = new QLabel(AjoutFontaine);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 240, 121, 16));
        label_7 = new QLabel(AjoutFontaine);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 280, 171, 16));
        identifiant = new QSpinBox(AjoutFontaine);
        identifiant->setObjectName(QString::fromUtf8("identifiant"));
        identifiant->setGeometry(QRect(230, 30, 111, 26));
        identifiant->setMaximum(99999);
        ok = new QPushButton(AjoutFontaine);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(150, 350, 90, 28));
        voiePublique = new QLineEdit(AjoutFontaine);
        voiePublique->setObjectName(QString::fromUtf8("voiePublique"));
        voiePublique->setGeometry(QRect(230, 70, 113, 28));
        nomTopographique = new QLineEdit(AjoutFontaine);
        nomTopographique->setObjectName(QString::fromUtf8("nomTopographique"));
        nomTopographique->setGeometry(QRect(230, 110, 113, 28));
        longitude = new QDoubleSpinBox(AjoutFontaine);
        longitude->setObjectName(QString::fromUtf8("longitude"));
        longitude->setGeometry(QRect(230, 150, 111, 26));
        longitude->setDecimals(5);
        longitude->setMinimum(-1000.999990000000025);
        longitude->setMaximum(1001.999990000000025);
        latitude = new QDoubleSpinBox(AjoutFontaine);
        latitude->setObjectName(QString::fromUtf8("latitude"));
        latitude->setGeometry(QRect(230, 190, 111, 26));
        latitude->setDecimals(5);
        latitude->setMinimum(-1001.999990000000025);
        latitude->setMaximum(1001.999990000000025);
        ville = new QLineEdit(AjoutFontaine);
        ville->setObjectName(QString::fromUtf8("ville"));
        ville->setGeometry(QRect(230, 230, 113, 28));
        arrondissement = new QLineEdit(AjoutFontaine);
        arrondissement->setObjectName(QString::fromUtf8("arrondissement"));
        arrondissement->setGeometry(QRect(230, 270, 113, 28));

        retranslateUi(AjoutFontaine);
        QObject::connect(ok, SIGNAL(clicked()), AjoutFontaine, SLOT(valider()));

        QMetaObject::connectSlotsByName(AjoutFontaine);
    } // setupUi

    void retranslateUi(QDialog *AjoutFontaine)
    {
        AjoutFontaine->setWindowTitle(QCoreApplication::translate("AjoutFontaine", "AjoutFontaine", nullptr));
        label->setText(QCoreApplication::translate("AjoutFontaine", "Identifiant de la borne:", nullptr));
        label_2->setText(QCoreApplication::translate("AjoutFontaine", "Voie publique:", nullptr));
        label_3->setText(QCoreApplication::translate("AjoutFontaine", "Nom topographique:", nullptr));
        label_4->setText(QCoreApplication::translate("AjoutFontaine", "Longitude:", nullptr));
        label_5->setText(QCoreApplication::translate("AjoutFontaine", "Latitude:", nullptr));
        label_6->setText(QCoreApplication::translate("AjoutFontaine", "Nom de la ville:", nullptr));
        label_7->setText(QCoreApplication::translate("AjoutFontaine", "Nom de l'arrondissement:", nullptr));
        ok->setText(QCoreApplication::translate("AjoutFontaine", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutFontaine: public Ui_AjoutFontaine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTFONTAINE_H
