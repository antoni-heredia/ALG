#!/bin/bash
#!/bin/bash


# Script de bash que genera una imagen con los resultados del algoritmo burbuja
# para arrays de diferentes tamaños.

# Variables:
INICIO=1
FIN=1000
INCREMENTO=40
EJECUTABLE=floyd
SALIDA=floyd.data

i=$INICIO
echo > $SALIDA
while [ $i -le $FIN ]
do
  echo Ejecución tam = $i
  echo `./$EJECUTABLE $i` >> $SALIDA
  i=$((i+$INCREMENTO))
done