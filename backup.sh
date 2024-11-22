#!/bin/bash

kopiowany_katalog="~/Desktop/lab6"
kopiowany_do="/backup"
LOG="$HOME/backup.log"
DATA=$(date +"%Y-%m-%d")
PLIK="backup_${DATA}.tar.gz"
kopiowany_katalog=$(eval echo "$kopiowany_katalog")

mkdir -p "$kopiowany_do"
mkdir -p "$(dirname "$LOG")"

printf "[%s] Tworzenie kopii: %s\n" "$(date +"%Y-%m-%d %H:%M:%S")" "$kopiowany_katalog " >> "$LOG"

if tar -czf "$kopiowany_do/$PLIK" $kopiowany_katalog >> "$LOG" 2>&1; then
	printf "[%s] Tworzenie kopii: %s\n" "$(date +'%Y-%m-%d %H-%M-%S')" "$kopiowany_katalog" >> "%LOG"
else
	printf "[%s] Niepowodzenie: %s\n" "$(date +'%Y-%m-%d %H-%M-%S')" >> "%LOG"
fi
