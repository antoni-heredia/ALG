#!/bin/bash


# Script de bash que genera una imagen con los resultados del algoritmo burbuja
# para arrays de diferentes tamaños.

# Variables:
INICIO=15
FIN=28
INCREMENTO=1
EJECUTABLE=backtraking1.out
SALIDA=backtraking1.data

i=$INICIO
echo > $SALIDA
while [ $i -le $FIN ]
do
  echo Ejecución subconjunto de suma = $i
  echo `./$EJECUTABLE $i 40` >> $SALIDA
  i=$((i+$INCREMENTO))
done