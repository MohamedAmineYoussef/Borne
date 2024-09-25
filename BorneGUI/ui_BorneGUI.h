/********************************************************************************
** Form generated from reading UI file 'BorneGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORNEGUI_H
#define UI_BORNEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BorneGUI
{
public:
    QAction *actionBorne_Fontaine;
    QAction *actionBorne_Stationnement;
    QAction *actionQuitter;
    QAction *actionSupprimer_une_borne;
    QAction *actionQuitter_2;
    QWidget *centralwidget;
    QTextEdit *affichage;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjouter_une_borne;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BorneGUI)
    {
        if (BorneGUI->objectName().isEmpty())
            BorneGUI->setObjectName(QString::fromUtf8("BorneGUI"));
        BorneGUI->resize(800, 600);
        actionBorne_Fontaine = new QAction(BorneGUI);
        actionBorne_Fontaine->setObjectName(QString::fromUtf8("actionBorne_Fontaine"));
        actionBorne_Stationnement = new QAction(BorneGUI);
        actionBorne_Stationnement->setObjectName(QString::fromUtf8("actionBorne_Stationnement"));
        actionQuitter = new QAction(BorneGUI);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionSupprimer_une_borne = new QAction(BorneGUI);
        actionSupprimer_une_borne->setObjectName(QString::fromUtf8("actionSupprimer_une_borne"));
        actionQuitter_2 = new QAction(BorneGUI);
        actionQuitter_2->setObjectName(QString::fromUtf8("actionQuitter_2"));
        centralwidget = new QWidget(BorneGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        affichage = new QTextEdit(centralwidget);
        affichage->setObjectName(QString::fromUtf8("affichage"));
        affichage->setGeometry(QRect(110, 20, 571, 481));
        BorneGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BorneGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjouter_une_borne = new QMenu(menuMenu);
        menuAjouter_une_borne->setObjectName(QString::fromUtf8("menuAjouter_une_borne"));
        BorneGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(BorneGUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BorneGUI->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuAjouter_une_borne->menuAction());
        menuMenu->addAction(actionSupprimer_une_borne);
        menuMenu->addAction(actionQuitter_2);
        menuAjouter_une_borne->addAction(actionBorne_Fontaine);
        menuAjouter_une_borne->addAction(actionBorne_Stationnement);

        retranslateUi(BorneGUI);
        QObject::connect(actionQuitter_2, SIGNAL(triggered()), BorneGUI, SLOT(close()));
        QObject::connect(actionBorne_Fontaine, SIGNAL(triggered()), BorneGUI, SLOT(dialogFontaine()));
        QObject::connect(actionBorne_Stationnement, SIGNAL(triggered()), BorneGUI, SLOT(dialogStationnement()));
        QObject::connect(actionSupprimer_une_borne, SIGNAL(triggered()), BorneGUI, SLOT(dialogSupprimerBorne()));

        QMetaObject::connectSlotsByName(BorneGUI);
    } // setupUi

    void retranslateUi(QMainWindow *BorneGUI)
    {
        BorneGUI->setWindowTitle(QCoreApplication::translate("BorneGUI", "BorneGUI", nullptr));
        actionBorne_Fontaine->setText(QCoreApplication::translate("BorneGUI", "Borne Fontaine", nullptr));
        actionBorne_Stationnement->setText(QCoreApplication::translate("BorneGUI", "Borne Stationnement", nullptr));
        actionQuitter->setText(QCoreApplication::translate("BorneGUI", "Quitter", nullptr));
        actionSupprimer_une_borne->setText(QCoreApplication::translate("BorneGUI", "Supprimer une borne", nullptr));
        actionQuitter_2->setText(QCoreApplication::translate("BorneGUI", "Quitter", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("BorneGUI", "Menu", nullptr));
        menuAjouter_une_borne->setTitle(QCoreApplication::translate("BorneGUI", "Ajouter une borne", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BorneGUI: public Ui_BorneGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORNEGUI_H
