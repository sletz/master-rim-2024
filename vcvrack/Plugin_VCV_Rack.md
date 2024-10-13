## Procédure pour compiler un plugin générique stéréo

#### Attention: ne pas mettre d'espaces dans le path contenant Rack-SDK !!

- on va suivre (en partie) le tutoriel : https://vcvrack.com/manual/PluginDevelopmentTutorial

- télécharger le SDK : https://vcvrack.com/downloads/. 
    - si on a encore la version Intel de VCV Rack (émulée avec Rosetta), on charge: https://vcvrack.com/downloads/Rack-SDK-2.4.1-mac-x64.zip
    - si on a la version ARM de VCV Rack, on charge: https://vcvrack.com/downloads/Rack-SDK-2.5.2-mac-x64+arm64.zip

- ouvrir un terminal, se placer dans le dossier du SDK (Rack-SDK) avec « **cd /path/to/SDK** » 

- dans le terminal taper : **export RACK_DIR="/path/to/SDK"**

- dans le terminal taper : **export PATH="/opt/homebrew/bin:$PATH"**

- dans le terminal taper pour créer le plugin : **./helper.py createplugin MyPlugin**

- un nouveau dossier MyPlugin est créé, se placer dans ce dossier avec « **cd MyPlugin** » 

- télécharger le fichier `MyModule.svg` depuis cette URL https://github.com/sletz/master-rim-2024/tree/master/vcvrack et le mettre dans le dossier MyPlugin/res 

- créer le fichier C++ à partir de cette interface SVG, avec dans le terminal : 

**../helper.py createmodule MyModule res/MyModule.svg src/MyModule.cpp**

- ouvrir les fichiers `plugin.hpp` et `plugin.cpp` et décommenter les 2 lignes nécessaires 

(To enable the module, add
 `extern Model *modelMyModule; `
to plugin.hpp, and add
 `p->addModel(modelMyModule); `
to the init() function in plugin.cpp.)

- dans le terminal taper : **make**

- bien s'assurer que l'application RACK a été démarrée au moins une fois

- dans le terminal taper : **make install** 

- ouvrir l’application VCV Rack, appuyer sur la touche "return" pour faire apparaitre la liste des plugins, et vérifier que le nouveau plugin apparait (il a 4 entrées de contrôle, 2 entrées audio, 2 sorties audio)
