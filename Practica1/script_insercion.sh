#!/bin/bash
#!/bin/bash


# Script de bash que genera una imagen con los resultados del algoritmo burbuja
# para arrays de diferentes tamaños.

# Variables:
INICIO=1000
FIN=30000
INCREMENTO=1000
EJECUTABLE=insercion
SALIDA=insercion.data

i=$INICIO
echo > $SALIDA
while [ $i -le $FIN ]
do
  echo Ejecución tam = $i
  echo `./$EJECUTABLE $i` >> $SALIDA
  i=$((i+$INCREMENTO))
done