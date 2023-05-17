/*
 This code estimates the mass of the universe based on simplified assumptions. 
 It calculates the volume of the observable universe using a given radius, 
 assumes a critical density, and calculates the mass based on the volume and density. 
 Additionally, it considers the contributions of dark matter and dark energy by calculating 
 their respective masses. Finally, it sums up the masses of the universe, dark matter, 
 and dark energy to provide an estimate of the total mass of the universe.
*/

#include <stdio.h>
#include <math.h>

double calculateVolume(double radius) {
    return (4 * M_PI * pow(radius, 3)) / 3;
}

double calculateMass(double density, double volume) {
    return density * volume;
}

double calculateDarkMatterMass(double massOfUniverse) {
    double darkMatterFraction = 0.27;
    return darkMatterFraction * massOfUniverse;
}

double calculateDarkEnergyMass(double massOfUniverse, double criticalDensity) {
    double darkEnergyFraction = 0.68;
    double darkEnergyDensity = darkEnergyFraction * criticalDensity;
    double darkEnergyVolume = calculateVolume(pow(10, -26));  // Example radius for dark energy component
    return calculateMass(darkEnergyDensity, darkEnergyVolume);
}

double calculateMassOfUniverse() {
    const double GRAVITATIONAL_CONSTANT = 6.67430e-11;
    const double CRITICAL_DENSITY = 2.52e-27;  // kg/m^3
    
    // Estimate the radius of the observable universe
    const double SPEED_OF_LIGHT = 2.998e8;
    double hubbleTime = 4.4e17;  // seconds
    double radiusOfUniverse = SPEED_OF_LIGHT * hubbleTime;

    double volume = calculateVolume(radiusOfUniverse);
    double density = CRITICAL_DENSITY;  // Assume critical density for simplicity
    double massOfUniverse = calculateMass(density, volume);
    double darkMatterMass = calculateDarkMatterMass(massOfUniverse);
    double darkEnergyMass = calculateDarkEnergyMass(massOfUniverse, CRITICAL_DENSITY);

    return massOfUniverse + darkMatterMass + darkEnergyMass;
}

int main() {
    double massOfUniverse = calculateMassOfUniverse();
    printf("The estimated mass of the universe is: %e kg\n", massOfUniverse);
    return 0;
}
