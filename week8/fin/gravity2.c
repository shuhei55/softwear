#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* 今回の設定を構造体で記述*/
struct condition {
    int width;
    int height;
    double G;  // gravity constant
};

struct star {
    double m;           // mass
    double x, y, z;     // position_x_y
    double vx, vy, vz;  // velocity_x_y
};

struct star stars[] = {
    {1.0, -1.0, -5.0, 0.0, 0.0, 0.0, 0.0},
    {0.5, 5.0, 5.0, 0.0, 0.1, 0.0, 0.0},
    {0.5, 0.0, 5.0, 0.0, 0.1, 0.1, 0.0}};

double get_r(struct star s1, struct star s2)
{
    return sqrt((s1.x - s2.x) * (s1.x - s2.x) + (s1.y - s2.y) * (s1.y - s2.y) + (s1.z - s2.z) * (s1.z - s2.z));
}


int nstars = sizeof(stars) / sizeof(struct star);

void plot_stars(FILE* fp, const double t, struct condition cond)
{
    int width = cond.width;
    int height = cond.height;
    char space[width][height];

    memset(space, ' ', sizeof(space));
    for (int i = 0; i < nstars; i++) {
        const int x = width / 2 + stars[i].x;
        const int y = height / 2 + stars[i].y;
        if (x < 0 || x >= width)
            continue;
        if (y < 0 || y >= height)
            continue;
        if (stars[i].m == 0.0)
            continue;
        char c = (stars[i].m >= 1.0) ? 'O' : 'o';  // 質量が大きい場合は表示を変える
        space[x][y] = c;
    }

    fprintf(fp, "----------\n");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++)
            fputc(space[x][y], fp);
        fputc('\n', fp);
    }
    fflush(fp);

    printf("%5.1f", t);
    for (int i = 0; i < nstars; i++)
        printf("%d %7.2f %7.2f %7.2f ", i, stars[i].x, stars[i].y, stars[i].z);
    printf("\n");
}

void update_velocities(const double dt, struct condition cond)
{
    int i, j;
    for (i = 0; i < nstars; i++) {
        double ax = 0;
        double ay = 0;
        double az = 0;
        for (j = 0; j < nstars; j++) {
            if (i == j)
                continue;
            ax += stars[j].m * (stars[j].x - stars[i].x) / (get_r(stars[j], stars[i]) * get_r(stars[j], stars[i]) * get_r(stars[j], stars[i]));
            ay += stars[j].m * (stars[j].y - stars[i].y) / (get_r(stars[j], stars[i]) * get_r(stars[j], stars[i]) * get_r(stars[j], stars[i]));
            az += stars[j].m * (stars[j].z - stars[i].z) / (get_r(stars[j], stars[i]) * get_r(stars[j], stars[i]) * get_r(stars[j], stars[i]));
        }
        ax *= cond.G;
        ay *= cond.G;
        az *= cond.G;
        stars[i].vx += ax * dt;
        stars[i].vy += ay * dt;
        stars[i].vz += az * dt;
    }
}

void get_fusion(int i, int j)
{
    stars[i].vx = (stars[i].m * stars[i].vx + stars[j].m * stars[j].vx) / (stars[i].m + stars[j].m);
    stars[i].vy = (stars[i].m * stars[i].vy + stars[j].m * stars[j].vy) / (stars[i].m + stars[j].m);
    stars[i].vz = (stars[i].m * stars[i].vz + stars[j].m * stars[j].vz) / (stars[i].m + stars[j].m);
    stars[i].m = stars[i].m + stars[j].m;
    stars[j].m = 0.0;
    stars[i].x = (stars[i].x + stars[j].x) / 2.0;
    stars[i].y = (stars[i].y + stars[j].y) / 2.0;
    stars[i].z = (stars[i].z + stars[j].z) / 2.0;
}

void update_positions(const double dt)
{
    for (int i = 0; i < nstars; i++) {
        stars[i].x += stars[i].vx * dt;
        stars[i].y += stars[i].vy * dt;
        stars[i].z += stars[i].vz * dt;
    }
    for (int i = 0; i < nstars; i++) {
        if (stars[i].m == 0.0)
            continue;
        for (int j = 0; j < nstars; j++) {
            if (i == j)
                continue;
            if (stars[j].m == 0.0)
                continue;
            if (get_r(stars[i], stars[j]) < 0.5)
                get_fusion(i, j);
        }
    }
}

int main(int argc, char** argv)
{
    const char* filename = "space.txt";
    FILE* fp;
    if ((fp = fopen(filename, "a")) == NULL) {
        fprintf(stderr, "error: cannot open %s.\n", filename);
        return 1;
    }

    if (argc != 2) {
        fprintf(stderr, "usage:./gravity [dt]\n");
        return 1;
    }

    double dt;
    dt = atof(argv[1]);
    const double stop_time = 4000;

    struct condition cond;
    cond.height = 40;
    cond.width = 75;
    cond.G = 1.0;

    double t = 0.;
    for (int i = 0; t <= stop_time; i++) {
        t = i * dt;
        update_velocities(dt, cond);
        update_positions(dt);
        if (i % 10 == 0) {
            plot_stars(fp, t, cond);
            usleep(200 * 1000);
        }
    }

    fclose(fp);

    return 0;
}
