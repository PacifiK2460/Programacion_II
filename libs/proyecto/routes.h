#ifndef ROUTES_H
#define ROUTES_H

#include "proyecto.h"
#include "../sstring/sstring.h"
#include "../llist/llist.h"

// [!] Routes Management structures

// enum RouteErrors
// {
//     // OK = 0,
//     // = ErrorType::Route,
// };

typedef enum Weekday
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} Weekday;

typedef struct Time
{
    Weekday day;
    int hour;
} Time;

typedef struct Route
{
    String name;
    String destination;
    LList* scheduled_times;
} Route;

#endif