#include <stdio.h>

int calculateDuration(int entryH, int entryM, int exitH, int exitM) {
    int totalMinutes = (exitH * 60 + exitM) - (entryH * 60 + entryM);
    if (totalMinutes < 0) {
        // Overnight parking adjustmenta
        totalMinutes += 24 * 60;
    }
    int hours = totalMinutes / 60;
    if (totalMinutes % 60 != 0) {
        hours++; // round up partial hour
    }
    return hours;
}

float calculateFee(int hours, int vehicleType) {
    float fee = 0;
    if (hours <= 2) return 0;

    switch (vehicleType) {
        case 1: // Car
            if (hours <= 5)
                fee = (hours - 2) * 2.0;
            else
                fee = 10.0 + (hours - 5) * 1.0;
            break;
        case 2: // Bike
            if (hours <= 5)
                fee = (hours - 2) * 1.0;
            else
                fee = 5.0 + (hours - 5) * 0.5;
            break;
        case 3: // Truck
            if (hours <= 5)
                fee = (hours - 2) * 3.0;
            else
                fee = 15.0 + (hours - 5) * 2.0;
            break;
            
        default:
            printf("Invalid vehicle type.\n");
            return -1;
    }
    return fee;
}

int main() {
    int vehicleType;
    int entryHour, entryMin, exitHour, exitMin;

    // Menu
    printf("Select vehicle type:\n");
    printf("1. Car\n2. Bike\n3. Truck\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &vehicleType);
    
    if (vehicleType < 1 || vehicleType > 3) {
    printf("Invalid vehicle type.\n");
    return 1;
}


    // Input time
    printf("Enter entry time (HH MM): ");
    scanf("%d %d", &entryHour, &entryMin);
    printf("Enter exit time (HH MM): ");
    scanf("%d %d", &exitHour, &exitMin);

    // Validation
    if (entryHour < 0 || entryHour >= 24 || entryMin < 0 || entryMin >= 60 ||
        exitHour < 0 || exitHour >= 24 || exitMin < 0 || exitMin >= 60) {
        printf("Invalid time entered.\n");
        return 1;
    }

    // Duration
    int hoursParked = calculateDuration(entryHour, entryMin, exitHour, exitMin);
    printf("Total hours parked: %d\n", hoursParked);

    // Fee
    float totalFee = calculateFee(hoursParked, vehicleType);
    if (totalFee >= 0)
        printf("Total parking fee: $%.2f\n", totalFee);

    return 0;
}

    