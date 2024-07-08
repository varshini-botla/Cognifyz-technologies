#include <stdio.h>
#include <stdlib.h>

int main() {
    char sourceFileName[100], destinationFileName[100];
    FILE *sourceFile, *destinationFile;
    char ch;

    // Prompt the user to input the names of the source and destination files
    printf("Enter the source file name: ");
    scanf("%s", sourceFileName);
    printf("Enter the destination file name: ");
    scanf("%s", destinationFileName);

    // Open the source file for reading
    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Error: Could not open source file %s\n", sourceFileName);
        return 1;
    }

    // Open the destination file for writing
    destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Error: Could not open destination file %s\n", destinationFileName);
        fclose(sourceFile);
        return 1;
    }

    // Read contents from the source file and write to the destination file
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    printf("File copied successfully from %s to %s\n", sourceFileName, destinationFileName);

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}

