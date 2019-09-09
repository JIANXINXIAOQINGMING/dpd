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
    int re_val;

    const char *const short_options = "hs:od";
    const struct option long_options[] = {
        {"help", 0, NULL, 'h'},
        {"start", 1, NULL, 's'},
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
            dpd_init(atoi(optarg));
            re_val = dpd_mode();
            if (re_val == 1)
            {
                dpd_run();
            }
            break;
        case 'o':
            dpd_close();
            break;
        case 'd':
            COMMANDSTATUS();
            break;
        }
    }
}