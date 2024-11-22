#!/bin/bash

kopiowany_katalog="/home/debian/Desktop/lab6/"
kopiowany_do="/backup"
LOG="/backup/backup.log"
DATA=$(date +"%Y-%m-%d")
PLIK="$kopiowany_do/backup_${DATA}.tar.gz"
kopiowany_katalog=$(eval echo "$kopiowany_katalog")

echo "$(date): Rozpoczecie tworzenia kopii zapasowej" >> "$LOG"

if  [ -d "$kopiowany_katalog" ]; then
	tar -czf "$PLIK" -C "$kopiowany_katalog" . && \
	echo "$(date): Udana kopia: $PLIK" >> "$LOG"
else
	echo "$(date): Kopia nieudana" >> "$LOG"
	exit 1
fi 

echo "$(date): Zakonczono tworzenie kopii zapasowej" >> "$LOG"

