from random import randint
import os

while True:
    resp = randint(0,100)
    tentativa = 0
    find = 0
    num_jogador = 0
    os.system('cls')
    while tentativa < 20 and find < 1:
        try:
            num_jogador = int(input("Digite um numero: "))
        except:
            print("Valor Invalido")
        else:
            print ("menor") if num_jogador < resp else print("maior")
        tentativa += 1
        find = 1 if num_jogador == resp else 0
    if find == 1:
        print ("Parabéns você acertou! O número era", resp, " e foi encontrado na", tentativa, "tentativa")
    auxiliar = input("jogar novamente? 'S'") 
    if auxiliar == 's' or auxiliar == 'S':
        continue
    else: break