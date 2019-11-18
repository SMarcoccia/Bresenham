# Bresenham
Algorithme pour le traçage de lignes et de cercles.

- Pour compiler : 
  - S'assurer que mingw32 soit installer.
  - Que le chemin d'accée des exécutables de mingw soit mit dans la variable d'environnement PATH de windows.
  - Ouvrir la console de windows CMD et :
    - Taper cd puis le chemin ou se trouve le dossier du projet.
      Ex. : cd C:\_Programmation\C\C_Bresenham
    - Puis taper make pour compiler le projet.
    - Puis taper line pour exécuter le programme.
  
 ## Utilisation :
  
  - Ligne :
    - Pour activer la fonction : 
      - Activée par défaut. Juste à compiler.
    - Pour afficher dans la console : 
      - Dans la fenêtre d'affichage fait un clic gauche laissé appuyé et fait glisser la souris puis relâcher.

  - Cercle :
      - Pour activer la fonction :
        - Aller dans le fichier tools.c 
        - Dans la fonction click ligne 103 désactiver la fonction line_bresenham et activer circle_bresenham.
      - Pour afficher dans la console : 
        - Idem que pour la ligne.

  - Ellipse :
      - Pour activer : 
        - Idem que pour le cercle.
      - Pour afficher dans la console :
        - Dans la fenêtre d'affichage il y a juste a faire un clic gauche.

  ## Note :  
    - si vous afficher la fonction ellipse elle se trouvera dans le coin supérieur gauche de la fenêtre, on ne peut afficher qu'une fois l'ellipse. 
    - Pour changer de tracé obliger de retourner dans le code et de choisir la fonction voulue.
    - Ce projet à été fait il y a plusieurs années.
    
  

