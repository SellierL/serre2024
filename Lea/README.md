# Greenhouse Project: Thermal Camera MLX90621 on ESP32 with Arduino framework

Le capteur de température MLX90621 de Melexis utilise la technologie de mesure de température sans contact pour créer une solution de thermographie très rentable. Couvrant une plage de température de -20 °C à 300 °C, avec une résolution de 16 x 4 pixels, soit 64 pixels pour une image.

## Utilisation de MyApplication:
	
* MyApplication() *//Constructeur*
	- Instancie la classe MyApplication et initialise les différents attributs ainsi qu'un tableau [64] avec des 0.
* initialisation()
	- Méthode public faisant appel aux différentes méthodes d'initialisation de la classe MLX90621. On retrouve l'utilisation de différentes méthode de cette classe comme *setRefreshRate(RATE_8HZ)*, *setResolution(RES_bit)*, *setEmissivity(1.0)* et *initilialize()*
	- Initialisation de la vitesse de transmission serial (ici 115200)
	- Appel de la méthode *ConnexionAPI::connexionWiFi()* pour connecter notre ESP32 au Wi-Fi (plus de précisions sur son fonctionnement dans sa propre description)
* setSeuil()
	- Test de la connexion Wi-Fi et de la connectivité avec l'API grâce aux méthode *ConnexionAPI::connexionXiFi()* et *ConnexionAPI::authenticate()*
	- retourne la valeur du seuil pour la conservé dans l'attribut seuil de la classe *MyApplication*