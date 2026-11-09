#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QPlainTextEdit>

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *p_parent = nullptr);

private slots:
    void incrementer();
    void lireTrame();
    void arreter();

private:
    QLabel *m_labelCompteur;
    int m_compteur = 0;
    QTimer *m_minuterie;

    QLabel *m_labelTrame;
    QPlainTextEdit *m_journal;
    QTimer *m_minuterieTrame;
};

#endif
