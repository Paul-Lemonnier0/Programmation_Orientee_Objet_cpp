#pragma once
#include <QWidget>
#include <QtWidgets>
#include <QString>
#include <iostream>
#include <string>

class calcul: public QWidget{
private:
    QLineEdit* _operande1;
    QLineEdit* _operande2;
    QComboBox* _operateur;
    QLabel* _resultat;
    QPushButton* _calculer;
    QPushButton* _quitter;

public:
    calcul(): QWidget(){
        int comboWidth = 50;
        int textWidth = 80;
        int height = 30;
        int heightPosition = 10;
        QRect textDimensions(0, 0, textWidth, height);
        QRect comboDimensions(0, 0, comboWidth, height);

        this->resize(475,50);

        _operande1 = new QLineEdit(this);
        _operande1->setGeometry(textDimensions);
        _operande1->move(10, heightPosition);
        connect(_operande1, &QLineEdit::textChanged, this, &calcul::onPressCalculer);


        _operateur = new QComboBox(this);
        _operateur->addItem("+");
        _operateur->addItem("-");
        _operateur->addItem("*");
        _operateur->addItem("/");
        _operateur->setGeometry(comboDimensions);
        _operateur->move(textWidth + 15, heightPosition);
        connect(_operateur, &QComboBox::currentTextChanged, this, &calcul::onPressCalculer);

        _operande2 = new QLineEdit(this);
        _operande2->setGeometry(textDimensions);
        _operande2->move(textWidth + comboWidth + 20, heightPosition);
        connect(_operande2, &QLineEdit::textChanged, this, &calcul::onPressCalculer);

        _calculer = new QPushButton("=", this);
        _calculer->setGeometry(comboDimensions);
        _calculer->move(textWidth + comboWidth + textWidth + 25, heightPosition);
        connect(_calculer, &QPushButton::clicked, this, &calcul::onPressCalculer);

        _resultat = new QLabel("", this);
        _resultat->setGeometry(textDimensions);
        _resultat->move(textWidth + comboWidth + textWidth + comboWidth + 30, heightPosition);


        _quitter = new QPushButton("Quitter", this);
        _quitter->setGeometry(textDimensions);
        _quitter->move(textWidth + comboWidth + textWidth + comboWidth + textWidth + 35, heightPosition);
        connect(_quitter, &QPushButton::clicked, this, &calcul::close);

        this->show();
   }

    public slots:
        void onPressCalculer(){

            std::string op1_string = _operande1->text().toStdString();
            std::string op2_string = _operande2->text().toStdString();
            std::string ope = _operateur->currentText().toStdString();

            float op1 = 0, op2 = 0;
            float resultat;

            if(op1_string != ""){
                op1 = std::stof(op1_string);
            }

            if(op2_string != ""){
                op2 = std::stof(op2_string);
            }

            if(ope == "+"){
                resultat = op1 + op2;
            }

            else if(ope == "-"){
                resultat = op1 - op2;
            }

            else if(ope == "*"){
                resultat = op1 * op2;
            }

            else {
                resultat = op1 / op2;
            }

            std::string resultat_string = std::to_string(resultat);
            QString resultat_Qstring = QString::fromStdString(resultat_string);
            _resultat->setText(resultat_Qstring);
        }

};
