import cherrypy
import os
from datetime import *
localDir = os.path.dirname(__file__)

class Principal():
    topo = open("html/topo.html",encoding="utf-8").read()
    rodape = open("html/rodape.html",encoding="utf-8").read()
    @cherrypy.expose() # possibilita exibir no navegador
    def index(self):
        html = self.topo
        horario = datetime.now()
        mens = 'Boa noite!!'
        if horario.hour > 0 and horario.hour <= 12:
            mens = 'Bom dia!!'
        elif horario.hour <= 18:
            mens = 'Boa tarde!!'
        html = html + '<h1>' + mens + '</h1>'
        html = html + self.rodape
        return html

# Esta parte serve para criar o servidor local, configurar ele e exibir o que foi implementado (HTML e CSS) e chamado pelo método index
local_config={'/':{'tools.staticdir.on':True,
                   'tools.staticdir.dir':localDir},}
server_config={
 'server.socket_host': '127.0.0.1',
 'server.socket_port': 80
}
cherrypy.config.update(server_config)
# instanciar um objeto da classe
home = Principal()
cherrypy.quickstart(home,config=local_config) # criando um servidor local (localhost) para o navegador conseguir execurar o nosso código