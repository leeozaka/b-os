# Jogo do Pedra – Papel – Tesoura, 
#também chamado em algumas regiões do Brasil de jokempô 
#é um jogo de mãos recreativo e simples para duas ou mais pessoas, 
#que não requer equipamentos nem habilidade. A forma de jogar é a seguinte: 
#os jogadores devem simultaneamente esticar a mão, na qual cada um formou um símbolo 
#(que significa pedra, papel ou tesoura). 
#Então, os jogadores comparam os símbolos para decidir quem ganhou, 
#da seguinte forma: Pedra ganha da tesoura (amassando-a ou quebrando-a). 
#Tesoura ganha do papel (cortando-o). 
#Desenvolva um programa em Python em que você jogue com o computador, 
#você escolhe um dos 3 símbolos e o computador sorteia aleatoriamente um dos 3 símbolos para ele, 
#seu programa deverá processar e informar quem foi o ganhador da rodada.

from enum import *
from random import randint
from os import system

class Mao(Enum):
    PEDRA = 1
    PAPEL = 2
    TESOURA = 3

def brain (user):
    if user == 1:
        user = Mao.PEDRA.value
    elif user == 2:
        user = Mao.PAPEL.value
    elif user == 3:
        user = Mao.TESOURA.value
    else:
        return 404

    computador = randint(1, 3)
    print("Sua resposta: ", Mao(user).name, "\nResposta do computador: ", Mao(computador).name)
    if user == computador:
        return 0
    elif computador == Mao.PEDRA.value:
        if user == Mao.PAPEL.value:
            return 1
        if user == Mao.TESOURA.value:
            return -1
    elif computador == Mao.PAPEL.value:
        if user == Mao.TESOURA.value:
            return 1
        if user == Mao.PEDRA.value:
            return -1
    elif computador == Mao.TESOURA.value:
        if user == Mao.PEDRA.value:
            return 1
        if user == Mao.PAPEL.value:
            return -1

while True:
    system('cls')
    print("Escolha uma opção: [1] Pedra [2] Papel [3] Tesoura")
    try:
        resp = brain(int(input("Sua tentativa: ")))
    except:
        system('pause')
    else: 
        if resp == 0:
            print ("Empate")
        elif resp == 404:
            print("Opção inválida")
        elif resp < 0:
            print ("Computador Ganhou!")
        elif resp > 0:
            print ("Voce Ganhou!")
        system('pause')