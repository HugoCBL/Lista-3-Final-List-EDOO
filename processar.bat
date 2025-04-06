@echo off
echo --- PROCESSANDO entrada1.txt ---
copy entrada1.txt entrada.txt
echo Conteúdo de entrada.txt ANTES da execução:
type entrada.txt
covid_genoma.exe
echo Conteúdo de saida.txt:
type saida.txt
ren saida.txt saida1.txt
pause

echo --- PROCESSANDO entrada2.txt ---
copy entrada2.txt entrada.txt
echo Conteúdo de entrada.txt ANTES da execução:
type entrada.txt
covid_genoma.exe
echo Conteúdo de saida.txt:
type saida.txt
ren saida.txt saida2.txt
pause