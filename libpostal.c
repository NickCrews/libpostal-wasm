#include <stdio.h>
#include <stdlib.h>
#include <emscripten.h>
#include "libpostal/src/libpostal.h"




// Call once at the beginning of your program
EMSCRIPTEN_KEEPALIVE
bool setup()
{
    return libpostal_setup() && libpostal_setup_parser();
}

// Call once at the end of your program
EMSCRIPTEN_KEEPALIVE
void teardown()
{
    libpostal_teardown();
    libpostal_teardown_parser();
}

EMSCRIPTEN_KEEPALIVE
int parse_address(char *oneline)
{
    libpostal_address_parser_options_t options = libpostal_get_address_parser_default_options();
    libpostal_address_parser_response_t *parsed = libpostal_parse_address(oneline, options);

    for (size_t i = 0; i < parsed->num_components; i++)
    {
        printf("%s: %s\n", parsed->labels[i], parsed->components[i]);
    }

    // Free parse result
    libpostal_address_parser_response_destroy(parsed);

    return 42;
}