#pragma once

#include <libsystem/eventloop/Notifier.h>
#include <libsystem/io/Connection.h>

typedef struct Client
{
    Notifier notifier;

    Connection *connection;
} Client;

Client *client_create(Connection *connection);

void client_destroy(Client *client);

void client_send_message(Client *client, Message *message, size_t size);