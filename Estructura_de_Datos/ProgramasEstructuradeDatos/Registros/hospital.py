
#funcion para ingresar datos del paciente
def ingresar_paciente():
    nombre = input("Dame el nombre del paciente: ")
    edad = int(input("Dame la edad del paciente: "))

    sexo = input("¿Cuál es el sexo del paciente (M/F): ") or "No especificado"
    domicilio = {
        "calle": input("Calle: ") or "No especificado",
        "numero": int(input("Numero: ")),
        "ciudad": input("Ciudad: ") or "No especificado"
    }
    telefono = int(input("Teléfono: "))
    seguro = input("¿Esta asegurado? (Y/N): ") or "No especificado"

    paciente = {
        "nombre": nombre,
        "edad": edad,
        "sexo": sexo,
        "domicilio": domicilio,
        "telefono": telefono,
        "seguro": seguro
    }
    return  paciente
#----------------------------------------------------------
#Funcion para calcular el porcentaje de los pacientes según lo que se evalue
def porcentaje_pacientes(pacientes, condicion):
  #condicion es una funcion: porecentaje_pacientes recibira una funcion que le devolvera un valor
    contador_condicion_cumplida = 0

    for elemento in pacientes:
        if condicion(elemento):
            contador_condicion_cumplida += 1

    total_pacientes = len(pacientes)
    porcentaje = (contador_condicion_cumplida/total_pacientes) * 100 if total_pacientes > 0 else 0

    return porcentaje
#----------------------------------------------------------
#funcion para revisar que el paciente sea mujer
#devolvera un valor de verdadero o falso dependiendo si es cierto que es sexo es f de femenino o no
def condicion_mujer(paciente):
    sexo = paciente.get("sexo")
    return sexo.lower() == "f"
#----------------------------------------------------------
#funcion para revisar si el paciente es menor de 13 años de edad
#devolvera un valor de falso o verdadero dependiendo si es cierto que edad es menor a 13 o no
def condicion_edad(paciente):
    edad = paciente.get("edad")
    return edad < 13
#----------------------------------------------------------
def condicion_asegurado(paciente):
    seguro = paciente.get("seguro")
    return seguro.lower() == "y"
#----------------------------------------------------------
def nombre_y_asegurado(pacientes,condicion):
    """
    
    """
    contadorseguro = 0

    for i, elemento in enumerate(pacientes, start=1):
        nombre = elemento.get("nombre")
        print(f"Nombre del paciente {i}: {nombre}")

        if condicion(elemento):
            contadorseguro += 1
    print(f"El número total de los pacientes asegurados es: {contadorseguro}")

#----------------------------------------------------------
def busacar_elemento(pacientes, nombre):

    for paciente in pacientes:

        if paciente.get("nombre", " ").lower() == nombre.lower():
            domicilio = paciente.get("domicilio")
            print(f"El domicilio de {nombre} es: {domicilio.get('calle')}, No.{domicilio.get('numero')}, Ciudad:{domicilio.get('ciudad')} ")
        return
    print(f"No se encontró al paciente con el nombre {nombre}").upper()
#----------------------------------------------------------

def main():
    #Declaro un arreglo
    pacienteslista = []
    #----------------------------------------------------------
    #Pido la longitud del arreglo

    n_pacientes = int(input("El número de pacientes que deseas agregar: "))
    #----------------------------------------------------------
    #Lleno el arrreglo mandando a llamar a la funcion ingresarpaciente, según haya sido el numero de
    #paceintes que quiera ingresar
    for i in range(n_pacientes):
        print(f"\nDatos del paciente {i+1}: ")
        paciente = ingresar_paciente()
        pacienteslista.append(paciente)
    #----------------------------------------------------------
    #Recorro el arreglo pacienteslista, uso enumerate para saltarme el paso de crear el itereador i que recorra cada elemento del arreglo
    #Como use enumerate solo es necesario poner el elemento del arreglo "elemento" y la clave del valor que quiero buscar en el diccionario
    #por que aunque pacienteslista sea un arreglo, es un arreglo de pacientes y paciente es un diccionario, por lo tanto un elemento del arreglo
    #es un diccionario
    porcentaje_mujer = porcentaje_pacientes(pacienteslista, condicion_mujer)
    print(f"\nEl porcentaje de pacientes mujeres es: {porcentaje_mujer}")

    porcentaje_edad = porcentaje_pacientes(pacienteslista, condicion_edad)
    print(f"\nEl porcentaje de pacientes menores de 13 años es: {porcentaje_edad}")

    nombre_y_asegurado(pacienteslista,condicion_asegurado)

    especifico = input("\nDame el nombre del paciente que deseas conocer su domicio: ")

    busacar_elemento(pacienteslista, especifico)

if __name__ == "__main__":
    main()
