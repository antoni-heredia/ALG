#!/bin/bash


# Script de bash que genera una imagen con los resultados del algoritmo burbuja
# para arrays de diferentes tamaños.

# Variables:
INICIO=1
FIN=25
INCREMENTO=1
EJECUTABLE=fuerzabruta.out
SALIDA=fuerzabruta.data

i=$INICIO
echo > $SALIDA
while [ $i -le $FIN ]
do
  echo Ejecución subconjunto de suma = $i
  echo `./$EJECUTABLE $i 25` >> $SALIDA
  i=$((i+$INCREMENTO))
done