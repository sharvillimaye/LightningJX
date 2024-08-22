/**
 * Copyright (c) 2024 Sharvil Limaye
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See `LICENSE.md` for details.
 */

#include <stdio.h>
#include <string.h>

#include "lightningxml.h"

void start_element(LXML_Parser *parser, const char *name) {
    printf("Start element: %s\n", name);
}

void end_element(LXML_Parser *parser, const char *name) {
    printf("End element: %s\n", name);
}

void characters(LXML_Parser *parser, const char *content) {
    printf("Characters: %s\n", content);
}

void process_char(LXML_Parser *parser, char ch) {
    switch (parser->state) {
        case STATE_START:
            if (ch == '<') {
                parser->state = STATE_OPEN_TAG;
                parser->buffer_index = 0;
            }
            break;
        case STATE_OPEN_TAG:
            if (ch == '/') {
                parser->state = STATE_CLOSE_TAG;
            } else if (ch == '>') {
                parser->buffer[parser->buffer_index] = '\0';
                start_element(parser, parser->buffer);
                parser->state = STATE_CONTENT;
            } else {
                parser->buffer[parser->buffer_index++] = ch;
            }
            break;
        case STATE_CLOSE_TAG:
            if (ch == '>') {
                parser->buffer[parser->buffer_index] = '\0';
                end_element(parser, parser->buffer);
                parser->state = STATE_CONTENT;
            } else {
                parser->buffer[parser->buffer_index++] = ch;
            }
            break;
        case STATE_CONTENT:
            if (ch == '<') {
                parser->buffer[parser->buffer_index] = '\0';
                if (parser->buffer_index > 0) {
                    characters(parser, parser->buffer);
                }
                parser->state = STATE_OPEN_TAG;
                parser->buffer_index = 0;
            } else {
                parser->buffer[parser->buffer_index++] = ch;
            }
            break;
        case STATE_END:
            // End of document
            break;
        default:
            break;
    }
}

void parse_xml(LXML_Parser *parser, const char *xml_data) {
    size_t length = strlen(xml_data);
    for (size_t i = 0; i < length; i++) {
        process_char(parser, xml_data[i]);
    }
    // Handle any remaining content in the buffer
    if (parser->state == STATE_CONTENT && parser->buffer_index > 0) {
        parser->buffer[parser->buffer_index] = '\0';
        characters(parser, parser->buffer);
    }
}