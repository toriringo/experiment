#include <stdio.h>
#include <string.h>

struct Container{
    int i;
    double d;
};

int main()
{
    FILE *file;

    // ファイルに書く
    struct Container container;
    container.i = 1;
    container.d = 2.0;
    file = fopen("file.txt", "w");
    fwrite(&container, sizeof(struct Container), 1, file);
    fclose(file);

    // ファイルを読む
    struct Container container2;
    file = fopen("file.txt", "r");
    while(fread(&container2, sizeof(struct Container), 1, file)){
        printf ("%d, %lf\n", container2.i, container.d);
    }
    fclose(file);

    return 0;
}
