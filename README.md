-- --

<div align="center">
    <img src="./resources/badge.png">
</div>

-- --

<div align="center">

![Made with](https://img.shields.io/badge/Made%20with-C++-blue?style=for-the-badge) 
![Compiled with](https://img.shields.io/badge/Compiled%20with-CMake-%236E39BB?style=for-the-badge)
[![Made by](https://img.shields.io/badge/Made%20by-Iwaki-red?style=for-the-badge)](https://github.com/IwakiLeKiwi/)
[![GitHub License](https://img.shields.io/github/license/IwakiLeKiwi/Aria?style=for-the-badge)](https://mit-license.org/)

</div>

Aria est une application console en C++ qui se connecte en SSH et utilise Docker sur votre serveur distant pour facilité l'exécution de certains processus en utilisant des commandes personnalisées.

## Fonctionnalités

- Connexion en SSH à un serveur distant
- Exécution de commandes Docker sur le serveur distant
- Utilisation de commandes personnalisées pour simplifier l'utilisation

## Configuration
Pour configurer et utiliser Aria, suivez ces étapes :

### Parie Code (IDE)

**1.** Clonez le Repo :

- Ouvrez votre IDE préféré.
- Clonez le référentiel Aria en utilisant la commande suivante dans le terminal de votre IDE :
```bash
git clone https://github.com/IwakiLeKiwi/Aria.git
```

**2.** Modifier le Fichier de Configuration :

- Renommez le fichier ``config.h.in.example`` en ``config.h.in``.
- Ouvrez le fichier ``config.h.in`` nouvellement créé et renseignez vos identifiants de connexion pour le serveur SSH.

**3.** Compilation avec CMake :

- Assurez-vous d'avoir ``CMake`` installé sur votre système.
- Compilez le projet avec CMake pour générer l'exécutable. Vous pouvez le faire en utilisant les commandes suivantes dans le terminal de votre IDE :
```bash
cd Aria
mkdir build
cd build
cmake ..
cmake --build .
```
- Cela générera l'exécutable Aria prêt à être utilisé.

### Partie Utilisateur

**1.** Téléchargement de l'Exécutable :

- Si vous ne souhaitez pas compiler le projet vous-même, vous pouvez télécharger la version exécutable depuis la section des [releases](https://github.com/IwakiLeKiwi/Aria/releases) sur GitHub.

**2.** Renseignez vos Identifiants :

- Avant d'utiliser Aria, assurez-vous de renseigner vos identifiants de connexion dans le fichier de configuration.
- Utilisez un éditeur de texte pour ouvrir le fichier ``config.h.in`` et fournissez vos informations de connexion pour le serveur SSH.

**3.** Exécution de l'Application :

- Exécutez l'application Aria dans votre terminal en utilisant la commande appropriée pour votre système d'exploitation.


## Auteur

- [@IwakiLeKiwi](https://www.github.com/IwakiLeKiwi/)


## Licence
Aria est sous la licence [MIT](./LICENSE)