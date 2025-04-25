Porte de Poulailler Automatique – 2 Modes (Auto & Manuel)
Un projet simple, fiable et personnalisable pour automatiser l’ouverture/fermeture de votre poulailler, tout en gardant la main quand les poules jouent les rebelles.

Description 

Ce projet propose une porte de poulailler motorisée, contrôlée par un microcontrôleur ATtiny84, avec deux modes de fonctionnement :

Un mode automatique basé sur la luminosité ambiante

Un mode manuel, activé via un interrupteur à 2 positions et un bouton poussoir multifonction

Le système inclut une gestion des erreurs (détection de blocage) et un retour visuel grâce à une LED.

Fonctionnalités
Mode automatique :

La porte s’ouvre le matin (lumière suffisante) et se ferme à la tombée de la nuit (obscurité détectée via LDR).

Mode manuel :

Un bouton permet de commander l’ouverture ou la fermeture manuelle (selon l’état actuel de la porte).

Détection de blocage :

Si la porte n’atteint pas sa position finale après un temps donné, le moteur s’arrête et la LED clignote pour signaler le blocage.

LED d’état :

🔴 Clignotante : porte bloquée

🔴 Allumée fixe : mode manuel actif

🔴 Éteinte : mode automatique, tout va bien

Matériel nécessaire

Composant	Description
ATtiny84	Microcontrôleur principal
LDR + résistance	Détecteur de luminosité
2 x Fins de course	Détection position ouverte/fermée
1 x Bouton poussoir	Déblocage + commande manuelle
1 x Interrupteur 2 pos	Sélection mode auto / manuel
1 x LED + résistance	Indication visuelle
Pont en H (L298N...)	Commande du moteur
Moteur DC	Pour la porte
Alimentation 5-12V	Selon le moteur

