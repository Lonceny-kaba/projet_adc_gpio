#include <stdio.h>      // Permet d'utiliser printf()
#include <stdint.h>     // Permet d'utiliser uint8_t, uint16_t, etc.
#include <windows.h>    // Permet d'utiliser Sleep() sous Windows

#define LED_BIT 0       // On associe la LED au bit 0 du registre GPIO_OUT

// Fonction qui simule la lecture d'un ADC
uint16_t lire_adc(void)
{
    // Pour l'instant, on renvoie une valeur fixe de 2500
    // Sur un vrai microcontrôleur, on lirait ici le périphérique ADC
    return 2500;
}

// Fonction qui convertit une valeur ADC en tension
float adc_vers_tension(uint16_t valeur_adc, float Vref)
{
    // Un ADC 12 bits fournit une valeur comprise entre 0 et 4095
    // On convertit cette valeur en tension grâce à :
    // tension = (valeur_adc / 4095) * Vref
    return ((float)valeur_adc / 4095.0f) * Vref;
}

// Fonction principale du programme
int main(void)
{
    // Seuil de tension utilisé pour décider si la LED doit être allumée
    const float seuil = 2.0f;

    // Tension de référence de l'ADC
    const float Vref = 3.3f;

    // Variable qui simule un registre de sortie GPIO sur 8 bits
    // Au départ tous les bits valent 0, donc la LED est éteinte
    uint8_t GPIO_OUT = 0;

    // Boucle infinie : le programme fonctionne en continu
    while (1)
    {
        // Appel de la fonction lire_adc()
        // La valeur retournée est stockée dans valeur_adc
        uint16_t valeur_adc = lire_adc();

        // Conversion de la valeur ADC en tension
        float tension = adc_vers_tension(valeur_adc, Vref);

        // Si la tension dépasse le seuil
        if (tension > seuil)
        {
            // On met à 1 le bit correspondant à la LED
            // Cela simule l'allumage de la LED
            GPIO_OUT |= (1 << LED_BIT);
        }
        else
        {
            // Sinon on remet ce bit à 0
            // Cela simule l'extinction de la LED
            GPIO_OUT &= ~(1 << LED_BIT);
        }

        // On teste l'état du bit de la LED
        if (GPIO_OUT & (1 << LED_BIT))
        {
            // Si le bit vaut 1, la LED est considérée comme allumée
            printf("LED = ON\n");
        }
        else
        {
            // Sinon, la LED est considérée comme éteinte
            printf("LED = OFF\n");
        }

        // Affichage de la valeur ADC et de la tension calculée
        printf("ADC = %u, Tension = %.2f V\n",
               (unsigned int)valeur_adc,
               tension);

        // Pause de 1000 millisecondes = 1 seconde
        Sleep(1000);
    }

    // Cette ligne indique normalement que le programme s'est terminé correctement
    // Ici, elle ne sera pratiquement jamais atteinte car while(1) est infini
    return 0;
}