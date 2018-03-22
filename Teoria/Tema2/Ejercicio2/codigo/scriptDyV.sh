#!/bin/bash


# Script de bash que genera una imagen con los resultados del algoritmo burbuja
# para arrays de diferentes tamaños.

# Variables:
INICIO=10000000
FIN=100000000
INCREMENTO=2500000
EJECUTABLE=ejercicio2DyV.out
SALIDA=busquedamayordyv.data

i=$INICIO
echo > $SALIDA
while [ $i -le $FIN ]
do
  echo Ejecución datos = $i
  echo `./$EJECUTABLE $i 10000` >> $SALIDA
  i=$((i+$INCREMENTO))
done