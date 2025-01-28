# heliarch_v1
Creation de systeme solaire 3D avec cpp et opengl/glew. Projet perso d'apprentissage. Parcourt de creation fait par ChatGPT.

**1. Mise en place du projet**
Étapes :

    Configurer ton environnement :
        Installe les outils nécessaires :
            Un IDE (comme Visual Studio, CLion, ou VSCode).
            OpenGL + GLEW (ou GLAD pour les extensions modernes).
            GLFW pour la gestion de fenêtre et des entrées.
        Configure un projet C++ de base pour afficher une fenêtre OpenGL.

    Créer un "Hello Triangle" avec OpenGL :
        Écris un shader simple pour dessiner un triangle à l'écran.
        Comprends comment fonctionne le pipeline graphique de base.

Résultat attendu :

    Une fenêtre avec un triangle affiché.

**2. Affichage des corps célestes**
Étapes :

    Créer des sphères pour représenter les planètes et le soleil :
        Utilise une bibliothèque comme GLM pour les mathématiques 3D.
        Implémente un générateur de sphères à l’aide de maillages triangulaires.
        Applique des textures pour représenter la surface des planètes (terre, mars, etc.).

    Organiser les planètes dans l'espace :
        Utilise des matrices de transformation (translation, rotation, échelle) pour positionner les planètes autour du soleil.
        Ajoute un effet de rotation sur elles-mêmes.

    Gérer l'éclairage :
        Implémente un shader de lumière diffuse pour simuler l'effet du soleil.
        Ajoute une lumière ponctuelle (point light) au centre du système solaire.

Résultat attendu :

    Un système solaire statique avec des planètes texturées et éclairées.

**3. Animation des orbites**
Étapes :

    Faire orbiter les planètes autour du soleil :
        Implémente des transformations basées sur le temps pour simuler des orbites circulaires ou elliptiques.
        Ajuste les vitesses orbitales pour chaque planète (basées sur des approximations des lois de Kepler).

    Ajout de lunes :
        Simule des orbites secondaires pour certaines planètes (comme la Lune pour la Terre ou Titan pour Saturne).

Résultat attendu :

    Les planètes et leurs lunes se déplacent en orbite autour de leurs corps respectifs.

**4. Interaction utilisateur**
Étapes :

    Caméra libre :
        Implémente une caméra contrôlée par l'utilisateur pour se déplacer autour du système solaire.
        Ajoute des contrôles de rotation (souris) et de zoom (molette ou touches clavier).

    Clic sur une planète pour zoomer :
        Implémente un système de picking (détection d'objets sous le curseur).
        Lorsqu’une planète est cliquée, ajuste la caméra pour effectuer un zoom progressif sur celle-ci.

    Interface utilisateur (UI) :
        Ajoute des informations dynamiques à l’écran (nom de la planète, distance au soleil, etc.).
        Utilise une bibliothèque comme ImGui pour créer des menus simples.

Résultat attendu :

    Une caméra libre et des interactions intuitives avec les planètes.

**5. Effets visuels avancés**
Étapes :

    Ajouter des anneaux autour de certaines planètes :
        Modélise des anneaux pour des planètes comme Saturne.
        Implémente des shaders pour des effets transparents et lumineux.

    Ajouter des étoiles en arrière-plan :
        Crée une skybox pour simuler l’espace (un cube avec une texture d’étoiles).
        Ajoute des points lumineux pour représenter des étoiles lointaines.

    Simuler des effets atmosphériques :
        Implémente des shaders pour simuler des atmosphères (lueur autour des planètes).

Résultat attendu :

    Un rendu visuel immersif avec des anneaux, une skybox et des effets atmosphériques.

**6. Optimisation et finalisation**
Étapes :

    Optimisation des performances :
        Implémente le frustum culling pour ne dessiner que les objets visibles par la caméra.
        Réduis la charge des calculs en utilisant des approximations pour les corps éloignés.

    Ajout de fonctionnalités supplémentaires :
        Temps accéléré : Permets à l'utilisateur de modifier la vitesse du temps pour observer les orbites rapides.
        Simulation de collisions : Ajoute des fonctionnalités pour voir ce qui se passe si deux corps célestes entrent en collision.

    Exporter une démo :
        Prépare un exécutable facile à exécuter pour montrer ton projet.

Résultat attendu :

    Un simulateur interactif fluide et bien optimisé.
