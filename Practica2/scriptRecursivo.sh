#!/bin/bash

# Script de bash que genera una imagen con los resultados del algoritmo burbuja
# para arrays de diferentes tamaños.

# Variables:
INICIO=100
FIN=5000000000
INCREMENTO=200000000
EJECUTABLE=potenciaLogaritmica
SALIDA=potenciaLogaritmica.data

i=$INICIO
echo > $SALIDA
while [ $i -le $FIN ]
do
  echo Ejecución tam = $i
  echo `./$EJECUTABLE $i` >> $SALIDA
  i=$((i+$INCREMENTO))
done
