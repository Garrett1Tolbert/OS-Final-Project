#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
//TODO: Create objects

//contents of a ticket
typedef struct Ticket {
    int number_of_tickets;
    int customer_id;
    int ticket_id;
    struct Ticket *next;
} Ticket;

typedef struct Stadium {
    int maximum_seats;
    int seats_left;
    int total_seats_handled;
    int seller_count;
    int MAX_SELLER_SEATS;
    Ticket* tickets;
    pthread_mutex_t mutex;
    pthread_cond_t can_add_tickets, can_sell_tickets;
}Stadium;

//Create function protypes and descriptions

/**
 * Opens the Stadium
 *  - allocate space for the Stadium
 *  - initialize all its variables
 *  - initialize its synchronization objects
 */
Stadium* OpenStadium(int MAXIMUM_SEATS, int MAX_SELLER_SEATS);

/**
 * Closes the Stadium
 * -make sure there are no more ticket request in the ticket list 
 * -make sure the maximum_seats have been fullfilled
 * -destroy all synchronization objects
 * -free the space of the Stadium
 */

void CloseStadium(Stadium *techxarena);
/**
 * Picks a random number of tickets and returns it.
 */
 
int randomTicketPicker();

/**
 * Lock Mutex
 * Wait until the stadium is not empty
 * Add tickets 
 * increments total_seats_handled
 */
bool addTicket(Stadium *techxarena);

//requestTicket
/**
 * Adds a ticket object to the Stadium tickets
 * -check to see if there are seats avaliable
 * -add the ticket to the end of stadium ticket list
 * -(optional-  if there are less seats than wanted, keep decreasing tickets)
*/

void requestTicket(Ticket **listofTickets, Ticket *ticket);
 
/**
 * Sells a random number of tickets
 * -Checks to see if total_seats_handled has reached the limit
 * -get a random amount of ticket from the list and free them
 */
void sellTicket(Stadium *techxarena);

/**
 * Gets a random number of tickets from the ticket list.
 * -lock all threads
 * -get from the front list
 * -decrease seats_sold
 */
Ticket *getTicket(Ticket **listofticket);

/**
 * -get a ticket from the TicketList
 * -increment the seats_sold
 */
//assignSeats
//
void print1(Ticket **listoftickets);