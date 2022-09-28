#ifndef AUTH_H
#define AUTH_H

#include "proyecto.h"

// [!] User Management structures

enum UserErrors
{
    OK = 0,
    USER_NOT_FOUND = ErrorType::User,
    INCORRECT_PASSWORD,
    USER_DISABLED,
    USER_ALREADY_EXISTS,
    USER_NOT_ALLOWED,
    UNKNOWN_USER_ERROR,
};

// Those structures define the level of users available in the system
// and the level of access to the system that each user has.

// The level of access is defined by the following values.
typedef enum Sate
{
    ENABLED,
    DISABLED
} Sate;

typedef enum Type
{
    NORMAL,
    ADMIN
} Type;

typedef struct User
{
    String name;
    String pass;
    Sate state;
    Type type;
    // if the user is an admin, this field will be null
    LList* queued_routes;
} User;

// [!] User Management functions

/*
    If the user has not enough permissions to perform the action,
    every function will return the error USER_NOT_ALLOWED.

    If the user is disabled, every function will return the error USER_DISABLED.
*/

/*
    Attempts to login with the given credentials.
    If the login is successful, the function returns the user.

    If the requested user is not found, the function returns USER_NOT_FOUND.
    If the password is incorrect, the function returns INCORRECT_PASSWORD.
    If the user is disabled, the function returns USER_DISABLED.
*/
Result login(String name, String pass);

/*
    Attempts to create a new user with the given credentials.
    If the user is created successfully, the function returns the user.

    If the user already exists, the function returns USER_ALREADY_EXISTS.
*/
Result add_user(User Requester, String NewUserName, String NewUserPass, Type NewUserType);

/*
    Attempts to modify the user with the given credentials.
    If the user is modified successfully, the function returns the user.

    If the user does not exists, the function returns USER_NOT_FOUND.
*/
Result modify_user(User Requester, String UserName, String NewUserPass, Type NewUserType);

/*
    Attempts to delete the user with the given credentials.
    If the user is deleted successfully, the function returns the deleted user.

    If the user does not exists, the function returns USER_NOT_FOUND.
*/
Result remove_user(User Requester, String UserName);

/*
    Attempts to query the user with the given username.
    If the user is found, the function returns the user.

    If the user does not exists, the function returns USER_NOT_FOUND.
*/
Result query_user(User Requester, String UserName);

#endif