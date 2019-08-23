#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <getopt.h>
#include "decide.h"
#include "address.h"
#include "init.h"
#include "mode.h"
#include "dpd_err.h"

void print_usage(FILE *stream, int exit_code)
{
    fprintf(stream,
            "\t-h  --help     Display this usage information.\n"
            "\t-s  --start    DPD on.\n"
            "\t-o  --stop     DPD off.\n"
            "\t-i  --init     DPD init.\n"
            "\t-m  --mode     DPD mode set.\n"
            "\t-a  --status   DPD status.\n"
            "\t-r  --reset    DPD reset.\n");
    exit(exit_code);
}

int main(int argc, char *argv[])
{
    char *tty_node;
    int next_option = 1;
    int re_val = 0;

    const char *const short_options = "hsiom:ar";
    const struct option long_options[] = {
        {"help", 0, NULL, 'h'},
        {"start", 0, NULL, 's'},
        {"init", 0, NULL, 'i'},
        {"stop", 0, NULL, 'o'},
        {"mode", 1, NULL, 'm'},
        {"status", 0, NULL, 'a'},
        {"reset", 0, NULL, 'r'},
        {NULL, 0, NULL, 0}};

    while (next_option != -1)
    {
        next_option = getopt_long(argc, argv, short_options, long_options, NULL);
        switch (next_option)
        {
        case 'h':
            print_usage(stdout, 0);
        case 'i':
            dpd_init();
            break;
        case 's':
            // dpd_on();
            break;
        case 'o':
            // dpd_off();
            break;
        case 'm':
            dpd_mode_set(optarg);
            break;
        case 'a':
            break;
        case 'r':
            dpd_init();
            break;
        }
    }
}