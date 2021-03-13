# Conversão de um relatório XML para uma página web

import re 

def xml2html(docXML):
    declXML = re.search(r'<\?[^<]+\?>', docXML).group()
    encoding = re.search(r'encoding\s*=\s*(\"[^"]*\")',declXML).group(1)
    
    docHTML = re.sub(
        r'<\?[^<]+\?>',
rf'''<!DOCTYPE html>
<html>
  <header>
    <title>Relatório<\/title>
    <meta charset={encoding}/>
  </header>''',
        docXML
    )

    docHTML = re.sub(
        r'<relatorio>((.|\n)*)<\/relatorio>',
        r'<body>\1</body>\n</html>',
        docHTML
    )

    docHTML = re.sub(
        r'<titulo>((.|\n)*)<\/titulo>',
        r'<h1>\n\1\n</h1>',
        docHTML
    )

    docHTML = re.sub(
        r'<data>((.|\n)*)<\/data>',
        r'<h2>\n\1\n</h2>',
        docHTML
    )

    docHTML = re.sub(
        r'<autores>((.|\n)*)<\/autores>',
        r'<h3>Autores</h3>\n<ul>\1</ul>',
        docHTML
    )

    docHTML = re.sub(
        r'<autores>((.|\n)*)<\/autores>',
        r'<h3>Autores</h3>\n<ul>\1</ul>',
        docHTML
    )

    print(docHTML)


with open("relatorio.xml") as f:
    conteudo = f.read()
    xml2html(conteudo)