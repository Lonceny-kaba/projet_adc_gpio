# Projet ADC GPIO en C

Simulation en langage C d'une chaîne simple d'acquisition et de commande inspirée d'un système embarqué.

## Objectif

Le programme simule :

- la lecture d'un ADC 12 bits ;
- la conversion de la valeur numérique en tension ;
- la comparaison de cette tension à un seuil ;
- la commande d'une LED simulée via un registre GPIO ;
- l'affichage de la mesure et de l'état de la LED ;
- une nouvelle mesure toutes les secondes.

## Fonctionnement

La lecture ADC est simulée avec une valeur fixe :

```text
ADC = 2500
```

La tension de référence vaut :

```text
Vref = 3.3 V
```

La conversion est réalisée avec :

```text
Tension = (valeur_ADC / 4095) × Vref
```

Pour une valeur ADC de 2500 :

```text
Tension ≈ 2.01 V
```

Le seuil est fixé à :

```text
2.0 V
```

Comme :

```text
2.01 V > 2.0 V
```

la LED simulée est activée.

## Exemple de sortie

```text
LED = ON
ADC = 2500, Tension = 2.01 V
```

## Concepts utilisés

- langage C ;
- fonctions ;
- `uint8_t` et `uint16_t` ;
- ADC 12 bits ;
- conversion numérique / tension ;
- GPIO ;
- opérations bit à bit ;
- conditions `if / else` ;
- boucle `while(1)` ;
- temporisation avec `Sleep()` sous Windows.

## Organisation

```text
projet_adc_gpio/
├── main.c
├── README.md
└── .gitignore
```

## Limites actuelles

Le projet est actuellement une simulation exécutée sous Windows.

La lecture ADC et le registre GPIO sont simulés en logiciel. Une évolution future du projet consistera à transférer cette logique sur un véritable microcontrôleur.

## Auteur

Projet réalisé dans le cadre de mon apprentissage du langage C appliqué aux systèmes embarqués.