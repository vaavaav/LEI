import re

def busca():
  fraseFonte = input(">> ")
  while fraseFonte != "":
    y = re.search(r'^(1?\d{1,2}|2([0-4]\d|5[0-5])\.){3}(1?\d{1,2}|2([0-4]\d|5[0-5]))$', fraseFonte)
    if(y): 
      print("ipv4")   
    else:
        y = re.search(r'', fraseFonte)
        if(y):
            print("ipv6")
        else:
            print("Não encontrado")
    fraseFonte = input(">> ")

busca()