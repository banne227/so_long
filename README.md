# so_long

![Aperçu du jeu](img.png)

Projet réalisé dans le cadre du cursus de l'école 42.

## Présentation

**so_long** est un petit jeu 2D développé en C avec la MiniLibX. Le joueur
doit parcourir une carte, récupérer tous les collectibles, puis atteindre la
sortie sans traverser les murs.

Le projet met en pratique :

- la création d'une fenêtre graphique avec la MiniLibX ;
- la gestion des événements clavier et de la fermeture de la fenêtre ;
- le parsing et la validation de cartes au format `.ber` ;
- la vérification de l'accessibilité de la carte par flood fill ;
- la gestion des collisions, des déplacements et des ressources.

La version bonus ajoute notamment des animations, des fantômes, le compteur de
mouvements et le mode Super Pacman.

## Prérequis communs

- `git` ;
- `make` ;
- un compilateur C (`cc`, `clang` ou `gcc`) ;
- une carte au format `.ber`.

Le dépôt contient la MiniLibX Linux dans [minilibx-linux](minilibx-linux).

## Installation sur macOS

La MiniLibX Linux fonctionne sur macOS avec XQuartz.

### 1. Installer XQuartz

Avec Homebrew :

```bash
brew install --cask xquartz
```

Après l'installation, redémarre la session macOS. Si nécessaire, ouvre
également **XQuartz** depuis `Applications > Utilitaires`.

Tu peux vérifier l'installation avec :

```bash
ls /opt/X11/include/X11/Xlib.h
```

### 2. Compiler

Depuis la racine du projet :

```bash
make
```

Pour compiler la version bonus :

```bash
make bonus
```

Le [Makefile](Makefile) est actuellement configuré pour macOS et utilise
`libmlx_Darwin.a` ainsi que les bibliothèques XQuartz.

## Installation sur Linux

Sur Debian ou Ubuntu, installe les dépendances suivantes :

```bash
sudo apt update
sudo apt install build-essential xorg libxext-dev libbsd-dev libx11-dev libxrandr-dev libxrender-dev
```

Compile ensuite la MiniLibX depuis sa propre commande :

```bash
make -C minilibx-linux
```

Sur Linux, la MiniLibX produit `libmlx_Linux.a`. Avant de compiler le projet,
le [Makefile](Makefile) doit donc utiliser les références Linux suivantes :

```make
MLX_LIB := $(MLX_DIR)/libmlx_Linux.a
LDLIBS  := -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
```

Une fois le Makefile adapté à Linux :

```bash
make
```

Pour compiler la version bonus :

```bash
make bonus
```

## Compilation et nettoyage

Depuis la racine du projet :

```bash
make
```

Version bonus :

```bash
make bonus
```

Supprimer les fichiers objets :

```bash
make clean
```

Supprimer les fichiers objets, les bibliothèques et les exécutables :

```bash
make fclean
```

Recompiler entièrement :

```bash
make re
```

## Lancement

Le programme doit recevoir une carte `.ber` en argument :

```bash
./so_long maps/valid_map/map1.ber
```

Version bonus :

```bash
./so_long_bonus maps/valid_map/map1.ber
```

Des cartes d'exemple sont disponibles dans :

```text
maps/valid_map/
maps/invalid_map/
```

## Contrôles

| Action | Touches |
| --- | --- |
| Déplacer vers le haut | `W` ou flèche haut |
| Déplacer vers le bas | `S` ou flèche bas |
| Déplacer vers la gauche | `A` ou flèche gauche |
| Déplacer vers la droite | `D` ou flèche droite |
| Quitter | `Échap` ou fermer la fenêtre |

## Format d'une carte

Chaque carte doit :

- avoir l'extension `.ber` ;
- être rectangulaire ;
- être entourée de murs ;
- contenir exactement un joueur, une sortie et au moins un collectible ;
- permettre au joueur d'atteindre tous les collectibles et la sortie.

| Symbole | Signification |
| --- | --- |
| `1` | Mur |
| `0` | Sol |
| `P` | Position initiale du joueur |
| `C` | Collectible |
| `E` | Sortie |

Exemple :

```text
111111111
1000C0001
101111101
1P0000E01
111111111
```

## Arborescence

```text
.
├── includes/          # Fichiers d'en-tête
├── maps/              # Cartes de jeu
├── minilibx-linux/    # MiniLibX basée sur X11
├── srcs/              # Version obligatoire
├── srcs_bonus/        # Version bonus
└── textures/          # Textures et sprites
```

## Licence

Projet pédagogique réalisé dans le cadre de l'école 42.
