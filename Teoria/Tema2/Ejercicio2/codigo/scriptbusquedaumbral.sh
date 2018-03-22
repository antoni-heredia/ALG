#!/bin/bash


# Script de bash que genera una imagen con los resultados del algoritmo burbuja
# para arrays de diferentes tamaños.

# Variables:
INICIO=1000
FIN=1000000
INCREMENTO=100000
EJECUTABLE=ejercicio2DyV.out
SALIDA=busquedaumbral.data

i=$INICIO
echo > $SALIDA
while [ $i -le $FIN ]
do
  echo Ejecución umbral = $i
  echo `./$EJECUTABLE 500000000 $i` >> $SALIDA
  i=$((i+$INCREMENTO))
done