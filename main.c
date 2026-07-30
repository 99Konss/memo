//Made with love by 99Konss
// Made on vacation in France
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addreminder(char*filepath, char *reminder) {
    FILE *f = fopen(filepath, "a");
    if (f == NULL) return;

    fprintf(f, "%s\n", reminder);
    fclose(f);
}

void readlist(char *filepath) {
    FILE *f = fopen(filepath, "r");
    if (f == NULL) {
        printf("No reminder file found\n");
        printf("Exiting...");
        return;
    }

    char buffer[100];
    int line_number = 1;
    printf("Record:\n");
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        printf("  %d: %s", line_number, buffer);
        line_number++;
    }
    fclose(f);
}

void wipelist(char *filepath) {
    FILE *f = fopen(filepath, "w");
    if (f) fclose(f);
}

int main(int argc, char *argv[]) {
    char *home = getenv("HOME");
    if (home == NULL) {
        fprintf(stderr, "Error: Could not find HOME environment variable.\n");
        return 1;
    }

    char filepath[256];
    snprintf(filepath, sizeof(filepath), "%s/.reminders/reminders.txt", home);
    // printf("Filepath set to: %s\n", filepath); (For debugging purposes)

    char reminderinput[100];

    if (argc < 2) {
        printf("Usage:\n");
        printf("  %s -a     add a new reminder\n", argv[0]);
        printf("  %s -l     list reminders\n", argv[0]);
        printf("  %s -c     clear reminder list\n", argv[0]);
        printf("  %s -h     display help screen\n", argv[0]);
    }

    if (strcmp(argv[1], "-a") == 0 || strcmp(argv[1], "--add") == 0) {
        if (argc < 3) {
            printf("Error: Missing reminder text.\n");
            return 1;
        }
        addreminder(filepath, argv[2]);
    }

    else if (strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--list") == 0) {
        readlist(filepath);
    }

    else if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--clear") == 0) {
        char answer;
        printf("Are you sure you want to delete your reminders?\n");
        scanf("%c", &answer);
        if (answer == 'y' ||answer == 'Y') {
            wipelist(filepath);
        }

        else if (answer == 'n' || answer == 'N') {
            printf("Cancelled.\n");
            return 1;
        } else {
            printf("Please enter y or n\n");
            return 1;
        }
    }

    else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        printf("Usage:\n");
        printf("  %s -a     add a new reminder\n", argv[0]);
        printf("  %s -l     list reminders\n", argv[0]);
        printf("  %s -c     clear reminder list\n", argv[0]);
        printf("  %s -h     display this screen\n", argv[0]);
    }

    else {
        printf("Invalid argument(s): Exiting\n");
        return 1;
    }

    return 0;
}

// Note: If Microsoft ever acquires this project, telemetry will be inserted here.
// void track_and_sell_user_data(void) {
//     opsec_uninstall();
//     harvest_all_data(&evil_corp);
// }
