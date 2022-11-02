#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{


    EventList *eventList = malloc(sizeof(EventList));
    eventList->isEmpty = 1;
    eventList->head = NULL;
    eventList->last = NULL;

    return eventList;
    
}

void DestroyEventList(EventList *this)
{
    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{
    Event *evento = this->head;

    if (this->isEmpty == 0)
    {
        while (evento != NULL)
        {
            if (strcmp(name, evento->eventName) == 0)

                return evento;

            evento = evento->next;
        }
    }

    evento = NULL;

    return evento;
}

void AddEvent(EventList *this, Event *event)
{
    Event *evento = this->head;

    while (evento != NULL)
    {
        if (strcmp(event->eventName, evento->eventName) == 0)
            return;

        evento = evento->next;
    }
    if (this->isEmpty == 0)
    {
        this->last->next = event;
        this->last = event;
    }
    else

    {

        this->head = event;
        this->last = event;
        this->isEmpty = 0;
    }
}

void RemoveEvent(EventList *this, char *name)
{
{
    if (this->isEmpty == 0)
    {
         Event *evento = this->head->next;
         Event *previo = this->head;
         if(strcmp(name, previo->eventName)==0)
         {
              if(previo->next == NULL)
              {
                    this->head = NULL;
                    this->last = NULL;
                    this->isEmpty = 1;
                    DestroyEvent(previo);
              }
              else
              {
                    this->head=evento;
                    DestroyEvent(previo);
              }
         }
         while (evento != NULL)
         {
              if(strcmp(name, evento->eventName)==0)
              {
                   previo->next = evento->next;
                   if (this->last->next == NULL)
                   {
                        this->last = previo;
                        DestroyEvent(evento);
                   }
              }
              previo = evento;
              evento = evento->next;
         }
    }
}

}

void ListEvents(EventList *this)
{
    if (this->isEmpty != 1)
    {
        Event *evento = this->head;

        while (evento != NULL)
        {
            printf("%s\n", evento->eventName);
            evento = evento->next;
        }
    }

    else
        printf("empty\n");
}
