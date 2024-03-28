
# 🌿 Documentation du projet serre 2024 🌿 
## 🌏 application web et api 🌏 
> Symfony est un framework PHP qui facilite le développement d'API Web. Les API Web permettent aux applications de communiquer entre elles de manière efficace et standardisée. Grâce à Symfony, les développeurs peuvent créer rapidement des API robustes et sécurisées en utilisant des composants intégrés pour gérer les requêtes HTTP, les routes, la validation des données et la sécurité. Symfony offre également des bundles spécialisés, comme FOSRestBundle et API Platform, qui simplifient encore plus le processus de création d'API RESTful et GraphQL. En utilisant Symfony, vous pouvez rapidement mettre en place des API Web performantes pour répondre aux besoins de votre application.
## Création d’une nouvelle application Symfony :
```symfony new --webapp my_project```
Nous avons donc fait cela : ```symfony new --webapp Serre2024```. 

#### Lancement du service : 
Pour faire le lancemement du service nous avons besoin de taper dans l'inviter de commande de l'ordintaur les deux commande suivante : 

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
```$ php bin/console make:entity Category```

### Migration des données vers la base 💾:

- ```php bin/console make:migration``` cela permet de créer le fichier de migration.
- ``` php bin/console doctrine:migrations:migrate``` cela permet d'appliquer la migrations. 


### Utiliser des relations entre les Tables : 
Pour cela nous allons utilisé la commande ```ManyToOne```, celle ci nous permet de créer une relation avec une clef primaire entre deux table 🗝 

une fois que nous avons créer l'entité nous devons refaire ```php bin/console make:entity``` mais cette fois si nous allons y faire une Upgrade car elle a deja etait créer. Quelle que ligne plus bas nous allons tomber sur cette ligne ```Field type (enter ? to see all types) [string]: relation``` c'est a partir de la que nous allons commencer la mise en place de la relation. 

Arriver sur cette ligne nous devons aplliquer ce ci : ```Relation type? [ManyToOne, OneToMany, ManyToMany, OneToOne]:
ManyToOne``` Ce ci va permettre de crée la relation entre les deux tables que nous aurrons choisis.


> Une fois que notre configuration terminer nous allons retouver tout cela dans l'onglet **Entity** dans visual studio code. 


