# Documentation du projet serre 2024
## application web et api
L'application est programmée en php. Elle est basée sur le framwork **symfony 7**.
## Installation de Symfony sur Windows 11 :
1. Premièrement dans l’invité de commande de windows il faut rentrer la commande suivante :  ```scoop install symfony-cli```
2.  Création d’une nouvelle application Symfony :
```symfony new --webapp my_project```
Nous avons donc fait cela : ```symfony new --webapp Serre2024```.
3. Installation de différents composants tels que PHP, Composer, Doctrine…

### Lancement du service :
``` cd C:\Users\Utilisateur\Downloads\symfony-cli_windows_amd64\serre2024>..\symfony server:start```

#### Accédez à la page de l'API : 
Si on souhaite accéder à la page de notre API il suffit simplement d’aller sur un moteur de recherche et taper cette URL dans le navigateur : http://localhost:8000/mapage/number soit pour nous  http://172.18.10.42:8000/index . Ce qui nous fait arriver sur la page d'accueil. 

### Intégration du CSS & du CSS :
Pour cela dans symfony 7 tout ce passe directement dans les Assets il nous suffit juste de créer dans le dossier Style un fichier CSS (Exemple : PageAcceuil.CSS)
Après il nous suffit à remplir le fichier dans y intégrer la balise ```<Style> - -</Style>```

### Utilisation des Templates (htlm.twig) :


### ajouter un controller :
Créez votre premier Controller avec la commande make:controller :
```symfony console make:controller ConferenceController```


## Utilisation de Doctrine : 

### Installation de doctrine : 
- ```composer require symfony/orm-pack```
- ``` composer require --dev symfony/maker-bundle```
 


### Creation d'entité avec composer : 
```php bin/console make:entity```
une fois que toute les entity on etait gréer nous avons besoin de faire une migration pour les syncronisers avec la base de données
les deux commande sont les suivante : 
- ```php bin/console make:migration``` cela permet de créer le fichier de migration.
- ``` php bin/console doctrine:migrations:migrate``` cela permet d'appliquer la migrations.

lkkmljlkjljk


## camera thermqie avec - esp32
## capteur humidité de l'air et température ambiante (DHT22) - esp32
## capteur d'humidité du sol, capteur de luminosité, capteur de niveau(srf10) - esp32
