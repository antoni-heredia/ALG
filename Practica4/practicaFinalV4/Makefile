######################################################
# Makefile para Practica Final MP Parte 4	     #
# Metodología de la Programación.		     #
# 1º D Ing. Informática.			     #
# Grupo D1.                                          #
# Universidad de Granada.                            #
# David Luque Callejas.                      	     #
# Miguel Ángel Hinojosa Castro.                      #
######################################################

BIN = bin
OBJ = obj
SRC = src
INCLUDE = include
LIB = lib
CPPFLAGS = -I$(INCLUDE) -std=c++11 -Wall -g 

.PHONY: doc all clean distclean zip valgrind

$(BIN)/tspFinal: $(OBJ)/PracticaFinalMP.o $(OBJ)/Funciones.o $(LIB)/libtsp.a
	g++ -L$(LIB) -o $@ $^ $(CPPFLAGS) -ltsp

# Creamos la librería

$(LIB)/libtsp.a: $(OBJ)/Punto.o $(OBJ)/Problema.o $(OBJ)/Solucion.o
	ar -rvs $(LIB)/libtsp.a $(OBJ)/Punto.o $(OBJ)/Problema.o $(OBJ)/Solucion.o

# Creamos los objetos

$(OBJ)/Punto.o : $(SRC)/Punto.cpp
	g++ -c $(CPPFLAGS) -o $@ $< 

$(OBJ)/Problema.o : $(SRC)/Problema.cpp
	g++ -c $(CPPFLAGS) -o $@ $< 

$(OBJ)/Solucion.o: $(SRC)/Solucion.cpp
	g++ -c $(CPPFLAGS) -o $@ $<

$(OBJ)/PracticaFinalMP.o: $(SRC)/PracticaFinalMP.cpp
	g++ -c $(CPPFLAGS) -o $@ $< 

$(OBJ)/Funciones.o: $(SRC)/funciones.cpp
	g++ -c $(CPPFLAGS) -o $@ $< 

doc: 
	doxygen doc/Doxyfile

# Creamos el dstino clean que elimina objeto, librerias y ejecutables previos
clean:
	@echo Borrando...
	-rm $(OBJ)/*
	@echo Objetos borrados.

distclean: clean
	-rm $(LIB)/*
	@echo Librerias borradas.
	-rm $(BIN)/*
	@echo Ejecutables borrados.
	-rm tspFinal.zip
	@echo Zip borrado
	-rm -r doc/html doc/rtf
	@echo documentacion borrada.
	-rm soluciones/*.sol
	@echo soluciones anteriores borradas.
zip: distclean
	zip -v9r tspFinal.zip *
	
valgrind: $(BIN)/tspFinal
	valgrind --leak-check=full --track-origins=yes $(BIN)/tspFinal soluciones/ficheros.txt
	@echo
	@echo
