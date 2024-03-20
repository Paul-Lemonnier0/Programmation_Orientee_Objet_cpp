#pragma once

#include <QtWidgets>
#include <QString>

class calcul: public QWidget
{
private:
    QLineEdit * _operande1, * _operande2;
    QComboBox * _operateur;
    QLabel * _resultat;
    QPushButton * _calculer, * _quitter;

public:
    calcul();;

    void oncliccalculer();
};
