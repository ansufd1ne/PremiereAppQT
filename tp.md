# Réponses au TP Qt + Git (Ansufdine)

**Question 1.** Si je supprimais `.git`, je perdrais tout l'historique : tous les commits, donc toutes les versions enregistrées du projet. Le dossier redeviendrait un dossier ordinaire, plus un dépôt Git. Mon code resterait, car il est à côté de `.git`, mais sans aucune version précédente.

**Question 2.** C'est la ligne `return a.exec();`. Elle lance la boucle d'événements, qui attend les clics, touches et délais, et ne s'arrête que quand on ferme la fenêtre.

**Question 3.** Non, les fichiers compilés (`.o`, `.exe`) n'apparaissent pas dans Changes, car `build/` et `build-*/` sont dans le `.gitignore`. Il ne serait pas utile de les archiver : on peut les régénérer en recompilant, ils sont lourds, et ils dépendent du poste et du kit utilisés.

**Question 4.** L'objet qui émet le signal est `boutonAjouter` (signal `clicked`). Quand on clique, la méthode `Widget::incrementer` est appelée.

**Question 5.** Le compteur augmente tout seul de 1 chaque seconde. Oui, le bouton fonctionne encore : le timer ne bloque rien, la boucle d'événements continue de traiter les clics.

**Question 6.** Les lignes en vert sont les lignes ajoutées depuis le dernier commit (les lignes en rouge seraient celles supprimées).

**Question 7.** Pendant 5 secondes, la fenêtre est gelée : le bouton « Ajouter 1 » ne réagit pas et le compteur ne bouge plus, car `QThread::sleep(5)` bloque la boucle d'événements. Les événements sont traités seulement après les 5 secondes.

**Question 8.** Le bouton d'arrêt d'urgence ne réagirait pas pendant la pause, puisque l'interface est gelée. L'arrêt serait pris en compte seulement après la fin de la pause. Pour un bras robotisé, c'est dangereux : un arrêt d'urgence doit réagir immédiatement. D'où la règle « jamais de boucle bloquante ni de sleep ».

**Question 9.** Non. Le bouton « Bloquer 5 s » n'est plus là sur `main` : il a été ajouté sur la branche `essai-blocage`, qui n'a jamais été fusionnée dans `main` puis a été supprimée. Une branche isole les modifications.

**Question 10.** La trame au hasard sera remplacée par les vraies trames envoyées par le contrôleur (les données reçues du Leap Motion / du matériel, lues à la place du tirage aléatoire). Le bouton « ARRET » servira d'arrêt d'urgence : il stoppe tout (les timers, donc l'envoi et la lecture des trames) sans bloquer l'interface.

**Question 11.** Oui, sur github.com je retrouve tous mes commits (Création du projet, Bouton et compteur, Ajout du timer, Simulation d'un controleur et bouton d'arret, et le commit de fusion).

**Question 12.** Après le pull, le dépôt de l'équipe sur mon poste contient le travail de tous les membres : un dossier par membre (`ansufdine`, `hugo`, ...) avec son projet MiniTP, ainsi que `README.md` et `.gitignore`. Mon dépôt local est à jour avec `main` sur GitHub.

**Question 13.** Chacun travaille uniquement dans son propre dossier et sur sa propre branche, sans modifier les fichiers des autres. On fait aussi un Pull origin avant de commencer à travailler, et on passe par une pull request relue par un camarade avant de fusionner dans `main`.
