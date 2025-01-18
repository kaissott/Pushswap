# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra

# Trouver tous les fichiers .c récursivement
SOURCES = $(shell find . -name "*.c")
# Générer les noms des exécutables (même nom que le .c sans extension)
EXECUTABLES = $(SOURCES:.c=)

# Règle par défaut
all: $(EXECUTABLES)

# Règle pour créer les exécutables
%: %.c
	$(CC) $< -o $@ $(CFLAGS)

# Nettoyer les fichiers générés
clean:
	find . -type f -executable -delete

.PHONY: all clean
SOURCES
