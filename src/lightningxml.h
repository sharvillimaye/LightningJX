/**
 * Copyright (c) 2024 Sharvil Limaye
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See `LICENSE.md` for details.
 */

#ifndef LIGHTNINGXML_H
#define LIGHTNINGXML_H

#define LIGHTNINGXML_VERSION "0.1.0"

#define BUFFER_SIZE 1024

typedef enum {
    STATE_START,
    STATE_OPEN_TAG,
    STATE_CLOSE_TAG,
    STATE_CONTENT,
    STATE_END
} ParserState;

typedef struct {
    ParserState state;
    char buffer[BUFFER_SIZE];
    size_t buffer_index;
} LXML_Parser;

void parse_xml(LXML_Parser *, const char *);

#endif