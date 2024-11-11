#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hotel {
    char* name;
    char* address;
    char grade;
    unsigned int numberOfRooms;
    unsigned int roomCharges;
} hotel;

void init(hotel* h) {
    h->name = (char*)malloc(50 * sizeof(char));
    h->address = (char*)malloc(100 * sizeof(char));
    h->numberOfRooms = 0;
    h->roomCharges = 0;
}

void printHotelsByGrade(hotel* hotels, int numHotels, char grade) {
    printf("%c:\n", grade);
    for (int i = 0; i < numHotels; i++) {
        if (hotels[i].grade == grade) {
            printf("- %s\n", hotels[i].name);
        }
    }
}

void printHotelsByRoomCharges(hotel* hotels, int numHotels, unsigned int maxRoomCharges) {
    printf("Hotels with room charges less than %u:\n", maxRoomCharges);
    for (int i = 0; i < numHotels; i++) {
        if (hotels[i].roomCharges < maxRoomCharges) {
            printf("- %s\n", hotels[i].name);
        }
    }
}

int main() {
    int numHotels;
    
    printf("Enter the number of hotels: ");
    scanf("%d", &numHotels);

    hotel* hotels = (hotel*)malloc(numHotels * sizeof(hotel));

    for (int i = 0; i < numHotels; i++) {
        init(&hotels[i]);
        printf("\nEnter details for hotel %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]%*c", hotels[i].name);
        printf("Address: ");
        scanf(" %[^\n]%*c", hotels[i].address);
        printf("Grade: ");
        scanf(" %c", &hotels[i].grade);
        printf("Number of rooms: ");
        scanf("%u", &hotels[i].numberOfRooms);
        printf("Room charges: ");
        scanf("%u", &hotels[i].roomCharges);
    }

    char grade;
    printf("\nEnter the grade to search for hotels: ");
    scanf(" %c", &grade);
    printHotelsByGrade(hotels, numHotels, grade);

    unsigned int maxRoomCharges;
    printf("\nEnter the maximum room charges ");
    scanf("%u", &maxRoomCharges);
    printHotelsByRoomCharges(hotels, numHotels, maxRoomCharges);

    for (int i = 0; i < numHotels; i++) {
        free(hotels[i].name);
        free(hotels[i].address);
    }
    free(hotels);

    return 0;
}
