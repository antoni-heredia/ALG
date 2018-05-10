#!/bin/bash


# Script de bash que genera una imagen con los resultados del algoritmo burbuja
# para arrays de diferentes tamaños.

# Variables:
INICIO=20
FIN=100
INCREMENTO=1
EJECUTABLE=backtraking3.out
SALIDA=backtraking3.data

i=$INICIO
echo > $SALIDA
while [ $i -le $FIN ]
do
  echo Ejecución subconjunto de suma = $i
  echo `./$EJECUTABLE $i 50` >> $SALIDA
  i=$((i+$INCREMENTO))
done