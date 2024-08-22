/**
 * Copyright (c) 2024 Sharvil Limaye
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See `LICENSE.md` for details.
 */

#include <stdio.h>
#include <stdlib.h>

#include "log.h"
#include "lightningxml.h"

void printLogo();

int main(int argc, char *argv[]) {
    LXML_Parser parser;
    parser.state = STATE_START;
    parser.buffer_index = 0;

    const char *xml_data = "<root><child>Hello World</child></root>";
    parse_xml(&parser, xml_data);

    return EXIT_SUCCESS;
}

void printLogo() {
    const char *yellow = "\033[1;93m";
    const char *reset = "\033[0m"; // Reset color
    printf("%s================================================================================================\n", yellow);
    printf("================================================================================================\n");
    printf(" __                   __      __                                __   __           __        \n");
    printf("/\\ \\       __        /\\ \\    /\\ \\__         __                 /\\ \\ /\\ \\  /'\\_/`\\/\\ \\       \n");
    printf("\\ \\ \\     /\\_\\     __\\ \\ \\___\\ \\ ,_\\   ___ /\\_\\    ___      __ \\ `\\`\\/\\/'/\\      \\ \\ \\      \n");
    printf(" \\ \\ \\  __\\/\\ \\  /'_ `\\ \\  _ `\\ \\ \\/ /' _ `\\/\\ \\ /' _ `\\  /'_ `\\`\\/ > <  \\ \\ \\__\\ \\ \\ \\  __ \n");
    printf("  \\ \\ \\L\\ \\\\ \\ \\/\\ \\L\\ \\ \\ \\ \\ \\ \\ \\_/\\ \\/\\ \\ \\ \\/\\ \\/\\ \\/\\ \\L\\ \\  \\/'/\\`\\\\ \\ \\_/\\ \\ \\ \\L\\ \\\n");
    printf("   \\ \\____/ \\ \\_\\ \\____ \\ \\_\\ \\_\\ \\__\\ \\_\\ \\_\\ \\_\\ \\_\\ \\_\\ \\____ \\ /\\_\\\\ \\_\\ \\_\\\\ \\_\\ \\____/\n");
    printf("    \\/___/   \\/_/\\/___L\\ \\/_/\\/_/\\/__/\\/_/\\/_/\\/_/\\/_/\\/_/\\/___L\\ \\\\/_/ \\/_/\\/_/ \\/_/\\/___/ \n");
    printf("                   /\\____/                                  /\\____/                         \n");
    printf("                   \\_/__/                                   \\_/__/                          \n");
    printf("================================================================================================\n");
    printf("================================================================================================\n");
    printf("%s", reset); // Reset color back to default
    printf("\n");
}