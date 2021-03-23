import sys
import re

soma = 0
semaforo = True

for linha in sys.stdin:
    if res := re.findall(r'([oO][nN])|([oO][fF]{2})|(=)|(\d+)', linha):
        for (on,off,pr,num) in res:
            if on:
                semaforo = True
                print("Semaforo ligado")
            elif off:
                semaforo = False
                print("Semaforo desligado")
            elif pr:
                print("O valor acumulado é ", soma)
            elif num:
                if semaforo:
                    soma += int(num)
                    print("Somado com sucesso")

