//reecrire la fonction ls en c 

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// Définition des codes d'échappement ANSI pour les couleurs
#define RESET   "\x1B[0m"
#define GREEN   "\x1B[32m"
#define BLUE    "\x1B[34m"

void ls(const char* directory) {
    DIR* dir;
    struct dirent* entry;
    size_t max_length = 0; // Longueur maximale du nom de dossier
    char output_buffer[4096] = ""; // Tampon pour stocker la sortie

    // Ouvre le répertoire
    dir = opendir(directory);
    if (dir == NULL) {
        perror("Erreur lors de l'ouverture du répertoire");
        return;
    }

    // Trouve la longueur maximale du nom de dossier dans le répertoire
    while ((entry = readdir(dir)) != NULL) {
        size_t len = strlen(entry->d_name);
        if (len > max_length) {
            max_length = len;
        }
    }

    // Réinitialise la position du flux de répertoire
    rewinddir(dir);

    // Parcourt le répertoire et construit la sortie dans le tampon
    while ((entry = readdir(dir)) != NULL) {
        // Vérifie si l'entrée est un dossier
        if (entry->d_type == DT_DIR) {
            // Calcule l'espace supplémentaire pour l'alignement horizontal
            int extra_space = max_length - strlen(entry->d_name);

            // Construit la sortie pour le dossier avec la couleur bleue et l'alignement horizontal
            char folder_entry[512];
            snprintf(folder_entry, sizeof(folder_entry), "%s%s", entry->d_name, BLUE);
            strncat(output_buffer, folder_entry, sizeof(output_buffer) - strlen(output_buffer) - 1);

            for (int i = 0; i < extra_space + 1; i++) {
                strncat(output_buffer, " ", sizeof(output_buffer) - strlen(output_buffer) - 1);
            }
        }
    }

    // Ferme le répertoire
    closedir(dir);

    // Affiche la sortie sur une ligne
    printf("Contenu du répertoire '%s':\n%s%s\n", directory, output_buffer, RESET);
}

int main() {
    const char* directory = "."; // Répertoire actuel (peut être remplacé par le chemin absolu du répertoire souhaité)

    ls(directory);

    return 0;
}
