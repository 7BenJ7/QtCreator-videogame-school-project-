<h4 align="center">Projet scolaire de Langage Objet Avancé (ENSIIE) :</h4>
<h1 align="center">Application sur QtCreator : jeu vidéo</h1>
<h4 align="center">Benjamin FARIGOUL, Mars 2022</h4>

# Lancer l'application
Pour lancer l'application, il suffit d'executer le code dans QtCreator. Vous avez alors 3 choix de difficultés, leur différence se fait sur le temps d'apparition des ennemis (5 secondes en mode facile, 3 secondes en mode normal et 1 seconde en mode difficile). Le but est ensuite de faire le meilleur score (visible en haut de l'écran).
Lors de la première execution du code, il devrait vous manquer les flèches sur le panneau de commandes :

<figure>
    <p align="center">
        <img src="/Images/IllustrationFleches.png" alt="Panneau de commande avec les flèches">
        Figure 1 : Vue de l'application en jeu avec les flèches sur le panneau de commande.
    </p>
</figure>

Il vous suffit juste de copier le dossier **Images** dans votre dossier de build.


# Contrôles et vue de l'application
Les contrôles sont les suivants :
- **Barre d'espace :** tirer
- **Flèches droite/gauche :** se déplacer à droite/gauche

Informations visuelles :

<figure>
    <p align="center">
        <img src="/Images/Jeu.png" alt="Image de jeu">
        Figure 2 : Vue générale de la fenêtre de jeu.
    </p>
</figure>

De haut en bas :
- **Score du joueur**
- Scène de jeu :
    - **Carrés rouges et roses :** ennemis
    - **Rectangles jaunes :** munitions
    - **Carré vert :** vie
    - **Carré bleu :** joueur
- De gauche à droite :
    - **Barre de vie**
    - **Nombre de munitions restantes**
- **Panneau de commande**

