# Projet ADC GPIO en C

Ce projet simule une chaîne simple d'acquisition et de commande en langage C.

Le programme :
- simule la lecture d'un ADC 12 bits ;
- convertit la valeur ADC en tension ;
- compare la tension à un seuil ;
- commande l'état d'une LED simulée via un registre GPIO ;
- affiche la valeur ADC, la tension calculée et l'état de la LED ;
- répète l'opération toutes les secondes.

## Fonctionnement

La valeur ADC simulée est fixée à 2500.

La tension de référence vaut 3.3 V.

La tension est calculée avec :

```text
Tension = (valeur_ADC / 4095) × Vref
```

Avec une valeur ADC de 2500, on obtient environ :

```text
2.01 V
```

Le seuil est fixé à :

```text
2.0 V
```

Comme 2.01 V > 2.0 V, la LED simulée est allumée.

## Notions utilisées

- langage C ;
- fonctions ;
- types `uint8_t` et `uint16_t` ;
- ADC 12 bits ;
- conversion numérique vers tension ;
- GPIO ;
- opérations bit à bit ;
- conditions ;
- boucle infinie `while(1)` ;
- temporisation avec `Sleep()` sous Windows.

## Exemple de sortie

```text
LED = ON
ADC = 2500, Tension = 2.01 V
```

## Remarque

Ce projet est actuellement une simulation exécutée sous Windows.

L'objectif est de reproduire la logique utilisée dans un système embarqué avant de la transférer sur un véritable microcontrôleur.