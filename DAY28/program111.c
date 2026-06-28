#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TICKETS 100
#define MAX_SEATS 20

typedef struct {
    int ticketId;
    char customerName[50];
    int seatNumber;
    int booked;
} Ticket;

Ticket tickets[MAX_TICKETS];
int ticketCount = 0;
int seats[MAX_SEATS + 1];

void flushInput(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void initializeSeats(void) {
    for (int i = 1; i <= MAX_SEATS; i++) {
        seats[i] = 0;
    }
}

void displaySeatLayout(void) {
    printf("\nSeat Layout (0 = available, 1 = booked):\n");
    for (int i = 1; i <= MAX_SEATS; i++) {
        printf("%2d:%d  ", i, seats[i]);
        if (i % 5 == 0) {
            printf("\n");
        }
    }
}

int findTicketIndex(int ticketId) {
    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].booked && tickets[i].ticketId == ticketId) {
            return i;
        }
    }
    return -1;
}

void bookTicket(void) {
    if (ticketCount >= MAX_TICKETS) {
        printf("Ticket booking capacity reached.\n");
        return;
    }

    displaySeatLayout();
    printf("\nEnter seat number to book (1-%d): ", MAX_SEATS);
    int seat;
    scanf("%d", &seat);
    flushInput();

    if (seat < 1 || seat > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }
    if (seats[seat]) {
        printf("Seat %d is already booked. Choose another seat.\n", seat);
        return;
    }

    printf("Enter customer name: ");
    fgets(tickets[ticketCount].customerName, sizeof(tickets[ticketCount].customerName), stdin);
    tickets[ticketCount].customerName[strcspn(tickets[ticketCount].customerName, "\n")] = '\0';

    tickets[ticketCount].ticketId = ticketCount + 1;
    tickets[ticketCount].seatNumber = seat;
    tickets[ticketCount].booked = 1;
    seats[seat] = 1;
    ticketCount++;

    printf("Ticket booked successfully. Ticket ID: %d, Seat: %d\n",
           tickets[ticketCount - 1].ticketId,
           tickets[ticketCount - 1].seatNumber);
}

void cancelTicket(void) {
    int ticketId;
    printf("\nEnter ticket ID to cancel: ");
    scanf("%d", &ticketId);
    flushInput();

    int index = findTicketIndex(ticketId);
    if (index < 0) {
        printf("Ticket not found.\n");
        return;
    }

    seats[tickets[index].seatNumber] = 0;
    tickets[index].booked = 0;
    printf("Ticket %d cancelled successfully. Seat %d is now available.\n",
           ticketId,
           tickets[index].seatNumber);
}

void displayTickets(void) {
    int found = 0;
    printf("\nBooked Tickets:\n");
    printf("ID\tSeat\tCustomer\n");
    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].booked) {
            printf("%d\t%d\t%s\n",
                   tickets[i].ticketId,
                   tickets[i].seatNumber,
                   tickets[i].customerName);
            found = 1;
        }
    }
    if (!found) {
        printf("No tickets booked yet.\n");
    }
}

void searchTicket(void) {
    int ticketId;
    printf("\nEnter ticket ID to search: ");
    scanf("%d", &ticketId);
    flushInput();

    int index = findTicketIndex(ticketId);
    if (index < 0) {
        printf("Ticket not found.\n");
        return;
    }

    printf("\nTicket Details:\n");
    printf("Ticket ID: %d\n", tickets[index].ticketId);
    printf("Customer: %s\n", tickets[index].customerName);
    printf("Seat Number: %d\n", tickets[index].seatNumber);
}

int main(void) {
    initializeSeats();
    int choice;

    printf("============================\n");
    printf("Ticket Booking System\n");
    printf("============================\n");

    while (1) {
        printf("\n1. Display Seat Layout\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. Display Booked Tickets\n");
        printf("5. Search Ticket\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        flushInput();

        switch (choice) {
            case 1:
                displaySeatLayout();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                displayTickets();
                break;
            case 5:
                searchTicket();
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
