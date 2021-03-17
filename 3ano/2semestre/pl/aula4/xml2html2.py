import sys
import re

def xml2html2(texto):
    if res := re.search(r'encoding\s*=\s*(\"[^"]*\")',texto) :
       encoding = res.group(1) 
       print(f'''<!DOCTYPE html>\n<html>\n\t<header>\n\t\t<title>Relatório<\/title>\n\t\t<meta charset={encoding}/>\n\t</header>''')

    elif (re.search( r'<relatorio>', texto)):
            print("\t<body>")

    elif (re.search( r'<\/relatorio>', texto)):
            print("\t</body>")

    elif res := re.search( r'<titulo>((.|\n)*)<\/titulo>', texto):
            print("\t\t<h1>", res.group(1), "</h1>")

    elif res := re.search( r'<data>((.|\n)*)<\/data>', texto):
            print("\t\t<h2>", res.group(1), "</h2>")

    elif (re.search( r'<autores>', texto)):
            print("\t\t<h3>Autores</h3>\n\t\t<ul>")

    elif (re.search( r'<\/autores>', texto)):
            print("\t\t</ul>")

    elif (re.search( r'<autor>', texto)):
            print("\t\t\t<li>", end="")

    elif (re.search( r'<\/autor>', texto)):
            print("</li>")

    elif res := re.search( r'<nome>((.|\n)*)</nome>', texto):
            print(res.group(1), end="")

    elif res := re.search( r'<numero>((.|\n)*)</numero>', texto):
            print(" (",res.group(1), ")", end="")

    elif res := re.search( r'<email>((.|\n)*)</email>', texto):
            print(":", res.group(1), end="")

    elif res := re.search( r'<descricao>', texto):
            print("\t\t<h3>Resumo</h3>")

    elif res := re.search( r'<\/descricao>', texto):
            pass           

    else:
         print("\t\t\t<p>",texto,"</p>")   


#-------------- Programa Principal ----------------
for linha in sys.stdin:
    xml2html2(linha)