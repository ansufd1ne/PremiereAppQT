#include "widget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QRandomGenerator>
#include <QTime>

Widget::Widget(QWidget *p_parent) : QWidget(p_parent)
{
    // --- Partie 3 : un bouton et un compteur ---
    m_labelCompteur = new QLabel("Compteur : 0");
    QPushButton *boutonAjouter = new QPushButton("Ajouter 1");

    QVBoxLayout *disposition = new QVBoxLayout(this);   // range les widgets verticalement
    disposition->addWidget(m_labelCompteur);
    disposition->addWidget(boutonAjouter);

    connect(boutonAjouter, &QPushButton::clicked, this, &Widget::incrementer);

    // --- Partie 4 : un timer qui ne bloque rien ---
    m_minuterie = new QTimer(this);
    connect(m_minuterie, &QTimer::timeout, this, &Widget::incrementer);
    m_minuterie->start(1000);   // en millisecondes

    // --- Partie 6 : un contrôleur simulé (trame X:Y) et un bouton d'arrêt ---
    m_labelTrame = new QLabel("Trame : aucune");
    m_journal = new QPlainTextEdit;
    m_journal->setReadOnly(true);   // journal en lecture seule
    QPushButton *boutonArret = new QPushButton("ARRET");

    disposition->addWidget(m_labelTrame);
    disposition->addWidget(m_journal);
    disposition->addWidget(boutonArret);

    m_minuterieTrame = new QTimer(this);
    connect(m_minuterieTrame, &QTimer::timeout, this, &Widget::lireTrame);
    m_minuterieTrame->start(200);   // une trame toutes les 200 ms

    connect(boutonArret, &QPushButton::clicked, this, &Widget::arreter);
}

void Widget::incrementer()
{
    m_compteur++;   // augmenter le compteur de 1
    m_labelCompteur->setText("Compteur : " + QString::number(m_compteur));
}

void Widget::lireTrame()
{
    const int x = QRandomGenerator::global()->bounded(256);   // valeur au hasard de 0 à 255
    const int y = QRandomGenerator::global()->bounded(256);
    const QString trame = QString::number(x) + ":" + QString::number(y);
    m_labelTrame->setText("Trame : " + trame);
    m_journal->appendPlainText(QTime::currentTime().toString("HH:mm:ss.zzz ") + trame);
}

void Widget::arreter()
{
    m_minuterie->stop();
    m_minuterieTrame->stop();
    m_journal->appendPlainText("ARRET demande");
}
