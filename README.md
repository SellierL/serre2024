# Documentation du projet serre 2024
## application web et api
L'application est programmée en php. Elle est basée sur le framwork **symfony 7**.
## Création d’une nouvelle application Symfony :
```symfony new --webapp my_project```
Nous avons donc fait cela : ```symfony new --webapp Serre2024```. 

### ajouter un controller :
Créez votre premier Controller avec la commande make:controller :
```symfony console make:controller ConferenceController```

### Creation d'entité avec composer : 
```php bin/console make:entity```
une fois que toute les entity on etait gréer nous avons besoin de faire une migration pour les syncronisers avec la base de données
les deux commande sont les suivante : 
- ```php bin/console make:migration``` cela permet de créer le fichier de migration.
- ``` php bin/console doctrine:migrations:migrate``` cela permet d'appliquer la migrations.


## camera thermqie avec - esp32
## capteur humidité de l'air et température ambiante (DHT22) - esp32
## capteur d'humidité du sol, capteur de luminosité, capteur de niveau(srf10) - esp32
