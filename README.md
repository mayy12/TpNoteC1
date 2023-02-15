# TpNoteC1 réalisé par Maysa BAKHTI et Sanâa AÏT-BELLA - ING1 GM01

Sujet 1:
Notre programme en C consiste à prédire le prix d'une habitation que nous voulons mettre en location dans la plateforme Airbnb.
Pour cela, nous avons parcouru toutes les lignes du fichier csv, cellule par cellule, en affichant chaque caractérisitque du logement correspondant.
Ensuite, nous avons créé un logement x où l'on a donné une valeur à chacunes de ses caractéristiques puis stockées ces dernières dans un tabeau.
Cela nous a permis de calculer la distance de similarité, que l'on stock dans un tableau trié par ordre croissant. Nous affichons par la suite la moyenne des prix qui sera le prix prédit pour le logement x.

Sujet 2:
Notre programme en C consiste à utiliser l'ordonnancement de processus, pour cela, nous utilisons les files. Nous avons donc tout d'abord affiché la file par l'ajout d'un processus x (avec son nom, sa durée d'execution et sa priorité). Ensuite, nous effectuons un “tour” d’ordonnancement : si la file est vide, on l'indique et on ne fait rien. S’il y a au moins une activité dans la file,on exécute et on défile l’activité en affichant son nom et sa durée et en attendant le temps correspondant à la durée de l’activité (avec sleep()). Nous obtenons à la fin une file de processus vide, et on l'indique.

Pour excécuter, taper "make" sur le terminal.
