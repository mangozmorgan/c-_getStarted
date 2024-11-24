# Get started Window

## Installer le compilateur
- Télécharger & installer **ming64** (en général C:\msys64\mingw64.exe)
- Utiliser la ligne de commande suivante pour installer le compilateur **g++** 
```bash
pacman -Syu  # Met à jour les paquets existants et l'outil de gestion des paquets
pacman -S mingw-w64-x86_64-gcc

```
- Ajouter **g++** au variables d'environnement Window ( en général C:\msys64\mingw64\bin)
- Ouvrir un **nouveau** terminal et lancer la commande suivante 
```bash
g++ --version
```
  - résultat attendu ou similaire: 
```bash
g++.exe (Rev2, Built by MSYS2 project) 14.2.0
Copyright (C) 2024 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

## Configuration VS Code
- Installer l'extension C/C++ + 
- Installer l'extension C/C++ Extension Pack 
- Installer l'extension C/C++ + Compile Run
- Créer un dossier **.vscode**
- Créer un fichier **tasks.json** dans le dossier **.vscode** avec le contenu suivant :
  - pour fichier simple :  
    ```json
    {
      "version": "2.0.0",
      "tasks": [
        {
          "label": "Build C++",
          "type": "shell",
          "command": "g++",
          "args": [
            "-g",
            "${file}",
            "-o",
            "${fileDirname}/${fileBasenameNoExtension}"
          ],
          "group": {
            "kind": "build",
            "isDefault": true
          },
          "problemMatcher": ["$gcc"],
          "detail": "Build a C++ file using g++"
        }
      ]
    }

    ```
  - pour multi-fichiers :  
    ```json
    {
      "version": "2.0.0",
      "tasks": [
        {
        "label": "Build C++ Program",
        "type": "shell",
        "command": "g++",
        "args": [
          "-g",
          "monPremierFichier.cpp",
          "monSecondFichier.cpp",
          "-o",
          "test"
        ],
        "group": {
          "kind": "build",
          "isDefault": true
        },
        "problemMatcher": ["$gcc"],
        "detail": "Task for building C++ programs using G++"
        }
      ]
    }
    ```  
## Build le programme 

- utiliser **ctrl + shift + b**