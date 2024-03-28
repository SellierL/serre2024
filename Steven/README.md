
# Documentation du projet serre 2024
## application web et api
L'application est programmée en php. Elle est basée sur le framwork **symfony 7**.
## Création d’une nouvelle application Symfony :
```symfony new --webapp my_project```
Nous avons donc fait cela : ```symfony new --webapp Serre2024```. 

### ajouter un controller :
Créez votre premier Controller avec la commande make:controller :
```symfony console make:controller ConferenceController```

## Base de données & Symfony :

### Installation de Doctrine : 

Pour l'installation de doctrine nous allons avoir besoin de rentée c'est deux commande : 
- ```composer require symfony/orm-pack```
- ```composer require --dev symfony/maker-bundle```

### Création de la base de donnée :
```php bin/console doctrine:database:create``` Cette commande nous permet de crée la base de donnée, pour pouvoir la visualiser de notre coter nous utilison debeaver. Dans notre cas la base de donnée portera le non de **serre2024**

### Creation d'entité : 
```php bin/console make:entity```
une fois que toute les entity on etait gréer nous avons besoin de faire une migration pour les syncronisers avec la base de données
les deux commande sont les suivante : 
- ```php bin/console make:migration``` cela permet de créer le fichier de migration.
- ``` php bin/console doctrine:migrations:migrate``` cela permet d'appliquer la migrations. 



