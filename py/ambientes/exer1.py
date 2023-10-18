palavra = input("Palavra a verificar: ").replace(" ", "")
print("palindromo") if palavra == palavra[::-1] else print("nao é palindromo")