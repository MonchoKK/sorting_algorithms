#ifndef LIST_H
#define LIST_H

/* Define struct listint_s */
typedef struct listint_s
{
    int n;                      /* Integer stored in the node */
    struct listint_s *prev;    /* Pointer to the previous element of the list */
    struct listint_s *next;    /* Pointer to the next element of the list */
} listint_t;

#endif /* LIST_H */
