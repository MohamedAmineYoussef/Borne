/********************************************************************************
** Form generated from reading UI file 'SupprimerBorne.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERBORNE_H
#define UI_SUPPRIMERBORNE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SupprimerBorne
{
public:
    QPushButton *ok;
    QLabel *label;
    QSpinBox *identifiant;

    void setupUi(QDialog *SupprimerBorne)
    {
        if (SupprimerBorne->objectName().isEmpty())
            SupprimerBorne->setObjectName(QString::fromUtf8("SupprimerBorne"));
        SupprimerBorne->resize(400, 300);
        ok = new QPushButton(SupprimerBorne);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(150, 240, 90, 28));
        label = new QLabel(SupprimerBorne);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 120, 161, 21));
        identifiant = new QSpinBox(SupprimerBorne);
        identifiant->setObjectName(QString::fromUtf8("identifiant"));
        identifiant->setGeometry(QRect(110, 120, 42, 26));
        identifiant->setMinimum(1);
        identifiant->setMaximum(9999999);

        retranslateUi(SupprimerBorne);
        QObject::connect(ok, SIGNAL(clicked()), SupprimerBorne, SLOT(valider()));

        QMetaObject::connectSlotsByName(SupprimerBorne);
    } // setupUi

    void retranslateUi(QDialog *SupprimerBorne)
    {
        SupprimerBorne->setWindowTitle(QCoreApplication::translate("SupprimerBorne", "SupprimerBorne", nullptr));
        ok->setText(QCoreApplication::translate("SupprimerBorne", "OK", nullptr));
        label->setText(QCoreApplication::translate("SupprimerBorne", "Identifiant:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupprimerBorne: public Ui_SupprimerBorne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERBORNE_H
