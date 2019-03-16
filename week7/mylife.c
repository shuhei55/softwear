//#include "gol.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_init_cells_byfile(FILE* fp, const int h, const int w, int cell[h][w])
{
    int m_h, m_w;
    while ((fscanf(fp, "%d %d", &m_h, &m_w)) != EOF) {
        if (0 <= m_h && m_h < h && 0 <= m_w && m_w < w) {
            cell[m_h][m_w] = 1;
        } else {
            fprintf(stderr, "file has irregular number!");
            exit(EXIT_FAILURE);
        }
    }
}

void my_init_cells(const int h, const int w, int cell[h][w])
{
    int m_h, m_w;
    FILE* defile;
    if ((defile = fopen("default.dat", "r")) == NULL) {
        perror("デフォルトファイルが読み込めません");
        exit(EXIT_FAILURE);
    }
    while ((fscanf(defile, "%d %d", &m_h, &m_w)) != EOF) {
        if (0 <= m_h && m_h < h && 0 <= m_w && m_w < w) {
            cell[m_h][m_w] = 1;
        } else {
            fprintf(stderr, "file has irregular number!");
            exit(EXIT_FAILURE);
        }
    }
}

void my_print_cells(FILE* fp, int gen, const int h, const int w, int cell[h][w])
{
    fprintf(fp, "generation = %d\n", gen);
    for (int i = 0; i < h + 2; i++) {
        for (int j = 0; j < w + 2; j++) {
            if (i == 0 || i == h + 1) {
                if (j == 0 || j == w + 1) {
                    fprintf(fp, "+");
                } else {
                    fprintf(fp, "-");
                }
            } else if (j == 0 || j == w + 1) {
                fprintf(fp, "|");
            } else {
                fprintf(fp, "\x1b[31m");
                if (cell[i - 1][j - 1] == 1) {
                    fprintf(fp, "#");
                } else {
                    fprintf(fp, " ");
                }
                fprintf(fp, "\x1b[39m");
            }
            if (j == w + 1) {
                fprintf(fp, "\n");
            }
        }
    }
    sleep(1);
}

void my_update_cells(const int h, const int w, int cell[h][w])
{
    int tmp_cell[h][w] = {0};
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int cnt = 0;
            if (i == 0 && j == 0) {
                if (cell[i + 1][j] == 1)
                    cnt++;
                if (cell[i][j + 1] == 1)
                    cnt++;
                if (cell[i + 1][j + 1] == 1)
                    cnt++;
                if (cell[i][j] == 0) {
                    if (cnt == 3)
                        tmp_cell[i][j] = 1;
                } else {
                    if (cnt == 2 || cnt == 3)
                        tmp_cell[i][j] = 1;
                }
            } else if (i == 0 && j == w - 1) {
                if (cell[i + 1][j] == 1)
                    cnt++;
                if (cell[i][j - 1] == 1)
                    cnt++;
                if (cell[i + 1][j - 1] == 1)
                    cnt++;
                if (cell[i][j] == 0) {
                    if (cnt == 3)
                        tmp_cell[i][j] = 1;
                } else {
                    if (cnt == 2 || cnt == 3)
                        tmp_cell[i][j] = 1;
                }
            } else if (i == h - 1 && j == 0) {
                if (cell[i - 1][j] == 1)
                    cnt++;
                if (cell[i][j + 1] == 1)
                    cnt++;
                if (cell[i - 1][j + 1] == 1)
                    cnt++;
                if (cell[i][j] == 0) {
                    if (cnt == 3)
                        tmp_cell[i][j] = 1;
                } else {
                    if (cnt == 2 || cnt == 3)
                        tmp_cell[i][j] = 1;
                }
            } else if (i == h - 1 && j = w - 1) {
                if (cell[i - 1][j] == 1)
                    cnt++;
                if (cell[i][j - 1] == 1)
                    cnt++;
                if (cell[i - 1][j - 1] == 1)
                    cnt++;
                if (cell[i][j] == 0) {
                    if (cnt == 3)
                        tmp_cell[i][j] = 1;
                } else {
                    if (cnt == 2 || cnt == 3)
                        tmp_cell[i][j] = 1;
                }
            } else if (i == 0) {
                if (cell[i + 1][j] == 1)
                    cnt++;
                if (cell[i][j - 1] == 1)
                    cnt++;
                if (cell[i + 1][j - 1] == 1)
                    cnt++;
                if (cell[i][j + 1] == 1)
                    cnt++;
                if (cell[i + 1][j + 1] == 1)
                    cnt++;
                if (cell[i][j] == 0) {
                    if (cnt == 3)
                        tmp_cell[i][j] = 1;
                } else {
                    if (cnt == 2 || cnt == 3)
                        tmp_cell[i][j] = 1;
                }
            } else if (i == h - 1) {
                if (cell[i - 1][j] == 1)
                    cnt++;
                if (cell[i][j + 1] == 1)
                    cnt++;
                if (cell[i - 1][j - 1] == 1)
                    cnt++;
                if (cell[i][j - 1] == 1)
                    cnt++;
                if (cell[i - 1][j + 1] == 1)
                    cnt++;
                if (cell[i][j] == 0) {
                    if (cnt == 3)
                        tmp_cell[i][j] = 1;
                } else {
                    if (cnt == 2 || cnt == 3)
                        tmp_cell[i][j] = 1;
                }
            } else if (j == 0) {
                if (cell[i + 1][j] == 1)
                    cnt++;
                if (cell[i - 1][j] == 1)
                    cnt++;
                if (cell[i + 1][j + 1] == 1)
                    cnt++;
                if (cell[i - 1][j + 1] == 1)
                    cnt++;
                if (cell[i][j + 1] == 1)
                    cnt++;
                if (cell[i][j] == 0) {
                    if (cnt == 3)
                        tmp_cell[i][j] = 1;
                } else {
                    if (cnt == 2 || cnt == 3)
                        tmp_cell[i][j] = 1;
                }
            } else if (j == w - 1) {
                if (cell[i + 1][j - 1] == 1)
                    cnt++;
                if (cell[i][j - 1] == 1)
                    cnt++;
                if (cell[i - 1][j - 1] == 1)
                    cnt++;
                if (cell[i - 1][j] == 1)
                    cnt++;
                if (cell[i + 1][j] == 1)
                    cnt++;
                if (cell[i][j] == 0) {
                    if (cnt == 3)
                        tmp_cell[i][j] = 1;
                } else {
                    if (cnt == 2 || cnt == 3)
                        tmp_cell[i][j] = 1;
                }
            } else {
            }
            cell = tmp_cell;
        }
    }
    system("clear");
}


int main(int argc, char** argv)
{
    int gen;
    FILE* fp = stdout;
    const int height = 40;
    const int width = 70;
    int cell[40][70] = {0};

    /* ファイルを引数にとるか、ない場合はデフォルトの初期値を使う */
    if (argc > 2) {
        fprintf(stderr, "usage: %s [filename for init]\n", argv[0]);
        exit(EXIT_FAILURE);
    } else if (argc == 2) {
        FILE* lgfile;
        if ((lgfile = fopen(argv[1], "r")) != NULL) {
            my_init_cells_byfile(lgfile, height, width, cell);  // ファイルによる初期化
        } else {
            fprintf(stderr, "cannot open file %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        fclose(lgfile);
    } else {
        my_init_cells(height, width, cell);  // デフォルトの初期値を使う
    }

    my_print_cells(fp, 0, height, width, cell);  // 表示し、1秒休止する

    /* 世代を進める*/
    for (gen = 1;; gen++) {
        my_update_cells(height, width, cell);          // セルを更新
        my_print_cells(fp, gen, height, width, cell);  // 表示し、1秒休止する
    }

    return 0;
}
