#!/bin/bash
#!/bin/bash


# Script de bash que genera una imagen con los resultados del algoritmo burbuja
# para arrays de diferentes tamaños.

# Variables:
INICIO=10
FIN=200
INCREMENTO=5
EJECUTABLE=mergesort
SALIDA=mergesort.data

i=$INICIO
echo > $SALIDA
while [ $i -le $FIN ]
do
  echo Ejecución umbral = $i
  echo `./$EJECUTABLE 50000000 $i` >> $SALIDA
  i=$((i+$INCREMENTO))
done