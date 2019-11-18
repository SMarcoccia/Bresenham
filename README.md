# Bresenham
Algorithme pour le traçage de lignes et de cercles.

Pour compiler : 
  - S'assurer que mingw32 soit installer.
  - Que le chemin d'accée des exécutables de mingw soit mit dans la variable d'environnement PATH de windows.
  - Ouvrir la console de windows CMD et :
    - Taper cd puis le chemin ou se trouve le dossier du projet.
      Ex. : cd C:\_Programmation\C\C_Bresenham
    - Puis taper make pour compiler le projet.
    - Puis taper line pour exécuter le programme.
    
Pour afficher une droite : 
  - Activée par défaut. Juste à compiler.
 
Pour afficher un cercle :
  - Aller dans le fichier tools.c 
  - Dans la fonction click ligne 103 désactiver la fonction line_bresenham et activer circle_bresenham.
  
Pour afficher ellipse_bresenham :
  - Idem que pour le cercle.

Note :  si vous afficher la fonction ellipse elle se trouvera dans le coin supérieur gauche de la fenêtre. 
        Ce projet à été fait il y a plusieurs années.
    
  

