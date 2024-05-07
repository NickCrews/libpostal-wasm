#include <stdio.h>
#include <stdlib.h>
#include <emscripten.h>
#include "libpostal/src/libpostal.h"


int main(int argc, char **argv)
{
    // Setup (only called once at the beginning of your program)
    if (!libpostal_setup() || !libpostal_setup_parser())
    {
        exit(EXIT_FAILURE);
    }

    libpostal_address_parser_options_t options = libpostal_get_address_parser_default_options();
    libpostal_address_parser_response_t *parsed = libpostal_parse_address("781 Franklin Ave Crown Heights Brooklyn NYC NY 11216 USA", options);

    for (size_t i = 0; i < parsed->num_components; i++)
    {
        printf("%s: %s\n", parsed->labels[i], parsed->components[i]);
    }

    // Free parse result
    libpostal_address_parser_response_destroy(parsed);

    // Teardown (only called once at the end of your program)
    libpostal_teardown();
    libpostal_teardown_parser();
}

EMSCRIPTEN_KEEPALIVE
int parse_address(char *oneline, char** result)
{
    libpostal_address_parser_options_t options = libpostal_get_address_parser_default_options();
    libpostal_address_parser_response_t *parsed = libpostal_parse_address(oneline, options);

    for (size_t i = 0; i < parsed->num_components; i++)
    {
        printf("%s: %s\n", parsed->labels[i], parsed->components[i]);
        result[i] = parsed->components[i];
    }

    // Free parse result
    libpostal_address_parser_response_destroy(parsed);

    return 0;
}