class Equipo(object):

  def __init__(self, team, f, a):
    self.team = team
    self.f = f
    self.a = a

  def getTeam(self):
    return self.team

  def getF(self):
    return self.f

  def getA(self):
    return self.a

  def setTeam(self, team):
    self.team = team

  def setF(self, f):
    self.f = f

  def setA(self, a):
    self.a = a

  def imprimir(self):
    print self.getTeam(), self.getF(), "\t", self.getA()


class ArregloEquipos(object):

  def __init__(self):
    self.arreglo = []

  def leerArchivo(self):
    archivo = open("football.dat")
    archivo.seek(67,0)

    for x in range(21):
      if x == 17:
        archivo.seek(59, 1)
      else:
        equipo = Equipo("", 0, 0)
        equipo.setTeam(archivo.read(16))
        archivo.seek(20, 1)
        equipo.setF(int(archivo.read(2)))
        archivo.seek(5, 1)
        equipo.setA(int(archivo.read(2)))
        self.agregar(equipo)
        archivo.seek(14, 1)
    archivo.close()

  def agregar(self, equipo):
    self.arreglo.append(equipo)

  def imprimir(self):
    print "Team\t\t", "F\t", "A"
    print("--------------------------")
    for x in range(len(self.arreglo)):
      self.arreglo[x].imprimir()

  def menorDiferencia(self):
    idx = 0; diferencia = 100

    for x in range(len(self.arreglo)):
      resta = (self.arreglo[x].getF() - self.arreglo[x].getA())
      if resta < 0:
        resta = resta - (resta*2)
      if resta < diferencia:
        diferencia = resta
        idx = x
    
    print(" Equipo con menor diferencia de goles")
    print "Equipo: ", self.arreglo[idx].getTeam(), "Diferencia: ", diferencia

def main():
  
  arregloEquipos = ArregloEquipos()
  
  arregloEquipos.leerArchivo()
  arregloEquipos.imprimir()
  arregloEquipos.menorDiferencia()

if __name__ == '__main__':
	main()