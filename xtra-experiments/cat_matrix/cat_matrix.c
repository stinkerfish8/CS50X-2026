#define _DEFAULT_SOURCE
#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define SLEEP(ms) usleep((ms) * 1000)

const char *cat_shape[] = {
    "                                             ",
    "                                             ",
    "                                             ",
    "          #####               #####          ",
    "          #######           #######          ",
    "          #########################          ",
    "          #########################          ",
    "          #########################          ",
    "          #########################          ",
    "          #########################          ",
    "            #####################            ",
    "            #####################            ",
    "                 ###########                 ",
    "                                             ",
    "                                             ",
    "                                             "
};

int main(void) {
    int height = 16;
    int width = 45;
    int drops[45];
    int char_buffer[16][45];
    const char *chars = "0123456789ABCDEF";
    const char *footer = "mc.catcraft.it";
    int footer_len = strlen(footer);
    int footer_start = (width - footer_len) / 2;

    int visible_chars = 0;
    int footer_frame_count = 0;

    srand((unsigned int)time(NULL));
    for (int i = 0; i < width; i++) {
        drops[i] = -(rand() % height);
    }

    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            char_buffer[r][c] = chars[rand() % 16];
        }
    }

    system("clear");

    while (1) {
        printf("\033[H");

        for (int r = 0; r < height; r++) {
            for (int c = 0; c < width; c++) {
                if (r == 15 && c >= footer_start && c < footer_start + footer_len) {
                    if (c == footer_start) {
                        int count = visible_chars;
                        if (count > footer_len) count = footer_len;
                        if (count > 0) {
                            printf("\033[1;92m"); // Grassetto + verde lime
                            for (int i = 0; i < count; i++) {
                                putchar(footer[i]);
                            }
                            printf("\033[0m");
                        }
                        c += footer_len - 1;
                    }
                } else if (cat_shape[r][c] == '#') {
                    if (r >= drops[c] && r < drops[c] + 20) {
                        printf("\033[92m%c\033[0m", char_buffer[r][c]);
                    } else {
                        putchar(' ');
                    }
                } else {
                    putchar(' ');
                }
            }
            putchar('\n');
        }

        for (int c = 0; c < width; c++) {
            drops[c]++;
            for (int r = 0; r < height; r++) {
                if (rand() % 10 == 0) {
                    char_buffer[r][c] = chars[rand() % 16];
                }
            }

            if (drops[c] > height) {
                drops[c] = -2;
            }
        }

        footer_frame_count++;
        if (footer_frame_count % 2 == 0) {
            visible_chars++;
            if (visible_chars > footer_len + 15) {
                visible_chars = 0;
            }
        }

        SLEEP(100);
    }
    return 0;
}
