# telainterpreter
Un interprete per il linguaggio di programmazione imperativo Tela, progettato nel corso di Tecnologie dei Linguaggi Artificiali presso l'Università degli Studi di Brescia.

## Features
Su un file sorgente .tela vengono compiute le seguenti operazioni:
* Analisi lessicale
* Analisi sintattica
* Analisi semantica
* Interpretazione del codice sorgente (di fatto, interpretazione dell'AST)
* Generazione di errori

## Librerie 
* [flex](https://github.com/westes/flex/): the fast lexical analyser generator 
* [bison](https://www.gnu.org/software/bison/): GNU Project parser generator

## Installazione
Su piattaforma Linux:

* Clona il repo sulla tua macchina utilizzando https://github.com/Pool97/telainterpreter.git
* È necessario poi creare l'eseguibile *telai* relativo all'interprete. Nella cartella del repo invoca il seguente comando: 
```
$ make
```
## Utilizzo
Nel repo sono presenti alcuni programmi di esempio, contenuti nella cartella SamplePrograms. Per eseguire il programma contenuto in *fibonacci.tela* è necessario invocare il seguente comando nella cartella : 
```
$ ./telai ./SamplePrograms/fibonacci.tela
```
In generale, è sufficiente richiamare l'interprete passando come argomenti il path del file sorgente da eseguire e i parametri attuali del modulo principale.

## Feedback
Il software è stato testato su piattaforma Linux. Ciò non pregiudica la portabilità del codice. Dato che nel repo ho reso disponibili solo i file originali codificati in flex e bison, per ottenere i corrispondenti file .c del lexer e del parser su Windows è necessario utilizzare uno dei porting disponibili su tale piattaforma. In questo caso l'installazione dell'interprete è diversa da quella presentata precedentemente.
In caso di eventuali bug riscontrati sentiti libero/a di inviare un feedback mediante la sezione degli issues di GitHub oppure inviando una mail a [roberto.poletti01gmail.com](mailto:roberto.poletti01@gmail.com)". Richieste per eventuali migliorie sono accolte!

## Todo
L'interprete è stato concepito come un prototipo, pertanto è possibile attuare diverse migliorie sia a livello di specifica del linguaggio che a livello di implementazione, tra cui:

* Introduzione dei tipi non atomici (quali strutture, unioni, tuple, ...)
* Aggiunta di un meccanismo esplicito di allocazione dinamica della memoria (richiede l'aggiunta di un heap o di uno stack)
* Aggiunta del passaggio dei parametri per indirizzo

## Per contribuire
Effettua un fork di questo repository e crea una pull request! Eventuali miglioramenti sensati saranno ben accetti!

## Licenza

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
