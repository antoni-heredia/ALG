#!/bin/bash
# Variables:
INICIO=1000
FIN=30000
INCREMENTO=1000
EJECUTABLE=burbuja
SALIDA=burbuja.data

i=$INICIO
echo > $SALIDA
while [ $i -le $FIN ]
do
  echo Ejecución tam = $i
  echo `./$EJECUTABLE $i` >> $SALIDA
  i=$((i+$INCREMENTO))
done