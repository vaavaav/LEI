#Deteção de endereços de email

import re

word = "[a-zA-Z0-9_]"

email1 = re.compile(r'(\b(\w+\.)*\w+@(\w+\.)*\w+\b)')
email2 = re.compile(r'(([a-zA-Z0-9_]+\.)*[a-zA-Z0-9_]+@([a-zA-Z0-9_]+\.)*[a-zA-Z0-9_]+)')
email3 = re.compile(rf'(\b({word}+\.)*{word}+@({word}+\.)*{word}+\b)')

lista = []

n = int(input())
for i in range(n):
    linha = input()
    r1 = email1.findall(linha)
    r2 = email2.findall(linha)
    r3 = email3.findall(linha)
    if(r1 or r2 or r3):
        for(email,_,_) in r1:
            lista.append(email)

lista.sort()
print(';'.join(lista))

 
