# PremiereAppQt

Première application Qt versionnée avec Git (TP guidé, BTS CIEL option IR).

## Fonctionnalités

- Un bouton « Ajouter 1 » et un label qui affiche le compteur.
- Un `QTimer` de 1000 ms qui incrémente le compteur chaque seconde, sans bloquer l'interface.
- Un contrôleur simulé : une trame `X:Y` (valeurs au hasard de 0 à 255) est générée toutes les 200 ms, affichée dans un label et horodatée dans un journal (`QPlainTextEdit`).
- Un bouton ARRET qui stoppe les deux timers et écrit « ARRET demande » dans le journal.

## Principe

Aucun `sleep` ni boucle bloquante : tout passe par des signaux et des slots, traités par la boucle d'événements Qt.

| Signal | Slot |
|---|---|
| `boutonAjouter::clicked` | `Widget::incrementer` |
| `m_minuterie::timeout` | `Widget::incrementer` |
| `m_minuterieTrame::timeout` | `Widget::lireTrame` |
| `boutonArret::clicked` | `Widget::arreter` |

## Fichiers

- `MiniTP.pro` : fichier de projet qmake
- `main.cpp` : point d'entrée, boucle d'événements
- `widget.h` / `widget.cpp` : classe `Widget` (interface et logique)

## Compilation

Environnement : Qt 5.14.2, kit Desktop MinGW 64-bit.

Ouvrir `MiniTP.pro` dans Qt Creator, choisir le kit, puis compiler et lancer (Ctrl+R).

En ligne de commande :

```
qmake MiniTP.pro
mingw32-make
```

## Auteur

Ansufdine, BTS CIEL option IR, lycée Élisabeth et Robert Badinter.
