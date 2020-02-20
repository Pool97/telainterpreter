# telainterpreter
Un interprete per il linguaggio di programmazione imperativo Tela, progettato nel corso di Tecnologie dei Linguaggi Artificiali presso l'Università degli Studi di Brescia.

## Features
Su un file sorgente .tela vengono compiute le seguenti operazioni:
* Analisi lessicale
* Analisi sintattica
* Analisi semantica
* Interpretazione del codice sorgente (di fatto, interpretazione dell'AST)

## Libraries 
* [flex]: the fast lexical analyser generator 
* [bison]: GNU Project parser generator

## Installation
* Clona il repo sulla tua macchina utilizzando https://github.com/fvcproductions/SOMEREPO
* È necessario poi creare l'eseguibile -*telai*- relativo all'interprete. Nella cartella del repo invoca il seguente comando: 
```
$ make
```
