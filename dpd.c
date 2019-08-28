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
            "\t-d  --debug    DPD debug.\n");
    exit(exit_code);
}

int main(int argc, char *argv[])
{
    int next_option = 1;

    const char *const short_options = "hsod";
    const struct option long_options[] = {
        {"help", 0, NULL, 'h'},
        {"start", 0, NULL, 's'},
        {"stop", 0, NULL, 'o'},
        {"debug", 0, NULL, 'd'},
        {NULL, 0, NULL, 0}};

    while (next_option != -1)
    {
        next_option = getopt_long(argc, argv, short_options, long_options, NULL);
        switch (next_option)
        {
        case 'h':
            print_usage(stdout, 0);
        case 's':
            dpd_init();
            // dpd_mode_set();
            break;
        case 'o':
            break;
        case 'd':
            COMMANDSTATUS(114);
            break;
        }
    }
}