import os
import csv

class Materia:
    curso = str
    periodo = str
    vagas = int
    inscritos = int
    inscrito_por_vaga = int
    inscritos_fem = int
    inscritos_masc = int

class Aluno:
    nome = str
    sexo = str
    cpf = str
    curso = str
    periodo = str

bcc = Materia()
bcc.curso = 'CIENCIA DA COMPUTACAO'
bcc.periodo = 'INTEGRAL'
bcc.vagas = 0
bcc.inscritos = 0
bcc.inscrito_por_vaga = 0
bcc.inscritos_fem = 0
bcc.inscritos_masc = 0

ads_not = Materia()
ads_not.curso = 'ANALISE E DESENVOLVIMENTO DE SISTEMAS'
ads_not.periodo = 'NOTURNO'
ads_not.vagas = 0
ads_not.inscritos = 0
ads_not.inscrito_por_vaga = 0
ads_not.inscritos_fem = 0
ads_not.inscritos_masc = 0

ads_ead = Materia()
ads_ead.curso = 'ANALISE E DESENVOLVIMENTO DE SISTEMAS'
ads_ead.periodo = 'EAD'
ads_ead.vagas = 0
ads_ead.inscritos = 0
ads_ead.inscrito_por_vaga = 0
ads_ead.inscritos_fem = 0
ads_ead.inscritos_masc = 0

direito_noturno = Materia()
direito_noturno.curso = 'DIREITO'
direito_noturno.periodo = 'NOTURNO'
direito_noturno.vagas = 0
direito_noturno.inscritos = 0
direito_noturno.inscrito_por_vaga = 0
direito_noturno.inscritos_fem = 0
direito_noturno.inscritos_masc = 0

direito_diurno = Materia()
direito_diurno.curso = 'DIREITO'
direito_diurno.periodo = 'DIURNO'
direito_diurno.vagas = 0
direito_diurno.inscritos = 0
direito_diurno.inscrito_por_vaga = 0
direito_diurno.inscritos_fem = 0
direito_diurno.inscritos_masc = 0

eng = Materia()
eng.curso = 'ENGENHARIA DE SOFTWARE'
eng.periodo = 'EAD'
eng.vagas = 0
eng.inscritos = 0
eng.inscrito_por_vaga = 0
eng.inscritos_fem = 0
eng.inscritos_masc = 0

with open('arquivo.csv') as arquivo:
    dados = csv.DictReader(arquivo)
    dados.fieldnames = ['curso','periodo','vagas']
    for row in dados:
        curso = row['curso'].upper()
        periodo = row['periodo'].upper()
        match curso:
            case 'CIENCIA DA COMPUTACAO':
                bcc.vagas = int(row['vagas'])
            case 'ANALISE E DESENVOLVIMENTO DE SISTEMAS':
                match periodo:
                    case 'EAD':
                        ads_ead.vagas = int(row['vagas'])
                    case 'NOTURNO':
                        ads_not.vagas = int(row['vagas'])
            case 'DIREITO':
                match periodo:
                    case 'NOTURNO':
                        direito_noturno.vagas = int(row['vagas'])
                    case 'DIURNO':
                        direito_diurno.vagas = int(row['vagas'])
            case 'ENGENHARIA DE SOFTWARE':
                eng.vagas = int(row['vagas'])


def write_aluno(novo_aluno):
    with open('alunos.csv', 'a', newline='') as write_alunos:
        fieldnames = ['nome', 'sexo', 'cpf', 'curso', 'periodo']
        cursor = csv.DictWriter(write_alunos, fieldnames=fieldnames)
        cursor.writerow({'nome': novo_aluno.nome, 'sexo': novo_aluno.sexo,
                        'cpf': novo_aluno.cpf, 'curso': novo_aluno.curso, 'periodo': novo_aluno.periodo})


def write_class(materia):
    with open("relatorio.csv", 'a', newline='') as write_classes:
        fieldnames = ['curso', 'periodo', 'vagas', 'inscritos',
                      'inscrito_por_vaga', 'inscritos_fem', 'inscritos_masc']
        cursor = csv.DictWriter(write_classes, fieldnames=fieldnames)
        cursor.writerow({'curso': materia.curso, 'periodo': materia.periodo, 'vagas': materia.vagas, 'inscritos': materia.inscritos,
                        'inscrito_por_vaga': materia.inscrito_por_vaga, 'inscritos_fem': materia.inscritos_fem, 'inscritos_masc': materia.inscritos_masc})


CURSOS = ['CIENCIA DA COMPUTACAO', 'DIREITO',
          'ENGENHARIA DE SOFTWARE', 'ANALISE E DESENVOLVIMENTO DE SISTEMAS']
PERIODOS = ['DIURNO', 'NOTURNO', 'EAD', 'INTEGRAL']


def inscricao():
    novo_aluno = Aluno()
    os.system('cls')
    novo_aluno.nome = str(input('Digite o seu nome:'))

    if novo_aluno.nome != '':
        novo_aluno.sexo = input('Digite o sexo:').upper()

        if novo_aluno.sexo == 'F' or novo_aluno.sexo == 'M':
            novo_aluno.cpf = input("Digite o seu cpf:")

            if len(novo_aluno.cpf) == 11:
                novo_aluno.curso = input('Digite o curso sem acentos:').upper()
                if novo_aluno.curso in CURSOS:
                    novo_aluno.periodo = input('Digite o periodo: ').upper()

                    if novo_aluno.periodo in PERIODOS:
                        match novo_aluno.curso:
                            case 'CIENCIA DA COMPUTACAO':
                                if novo_aluno.periodo == 'INTEGRAL':
                                    bcc.inscritos += 1
                                    match novo_aluno.sexo:
                                        case 'F':
                                            bcc.inscritos_fem += 1
                                        case 'M':
                                            bcc.inscritos_masc += 1
                                    write_aluno(novo_aluno)
                                else:
                                    print('Periodo invalido!')
                                    os.system('pause')

                            case 'DIREITO':
                                match novo_aluno.periodo:
                                    case 'NOTURNO':
                                        direito_noturno.inscritos += 1
                                        match novo_aluno.sexo:
                                            case 'F':
                                                direito_noturno.inscritos_fem += 1
                                            case 'M':
                                                direito_noturno.inscritos_masc += 1
                                        write_aluno(novo_aluno)
                                        os.system('pause')
                                    case 'DIURNO':
                                        direito_diurno.inscritos += 1
                                        match novo_aluno.sexo:
                                            case 'F':
                                                direito_diurno.inscritos_fem += 1
                                            case 'M':
                                                direito_diurno.inscritos_masc += 1
                                        write_aluno(novo_aluno)
                                    case _:
                                        print('Periodo invalido')
                                        os.system('pause')

                            case 'ANALISE E DESENVOLVIMENTO DE SISTEMAS':
                                match novo_aluno.periodo:
                                    case 'EAD':
                                        ads_ead.inscritos += 1
                                        match novo_aluno.sexo:
                                            case 'F':
                                                ads_ead.inscritos_fem += 1
                                            case 'M':
                                                ads_ead.inscritos_masc += 1
                                        write_aluno(novo_aluno)
                                    case 'NOTURNO':
                                        ads_not.inscritos += 1
                                        match novo_aluno.sexo:
                                            case 'F':
                                                ads_not.inscritos_fem += 1
                                            case 'M':
                                                ads_not.inscritos_masc += 1
                                        write_aluno(novo_aluno)
                                    case _:
                                        print('Periodo invalido!')
                                        os.system('pause')

                            case 'ENGENHARIA DE SOFTWARE':
                                if novo_aluno.periodo == 'EAD':
                                    eng.inscritos += 1
                                    match novo_aluno.sexo:
                                        case 'F':
                                            eng.inscritos_fem += 1
                                        case 'M':
                                            eng.inscritos_masc += 1
                                    write_aluno(novo_aluno)
                                else:
                                    print('Periodo invalido')
                                    os.system('pause')
                    else:
                        print('Periodo invalido')
                        os.system('pause')
                else:
                    print('Curso invalido')
                    os.system('pause')
            else:
                print('CPF invalido!')
                os.system('pause')
        else:
            print("sexo invalido!")
            os.system('pause')
    else:
        print('Nome invalido!')
        os.system('pause')

def readalunos():
    with open('alunos.csv', 'r') as alunos:
        dados = csv.DictReader(alunos)
        dados.fieldnames = ['nome', 'sexo', 'cpf', 'curso', 'periodo']
        for row in dados:
            curso = row['curso'].upper()
            periodo = row['periodo'].upper()
            sexo = row['sexo'].upper()

            match curso:
                case 'CIENCIA DA COMPUTACAO':
                    bcc.inscritos += 1
                    match sexo:
                        case 'M':
                            bcc.inscritos_masc += 1
                        case 'F':
                            bcc.inscritos_fem += 1

                case 'ANALISE E DESENVOLVIMENTO DE SISTEMAS':
                    match periodo:
                        case 'EAD':
                            ads_ead.inscritos += 1
                            match sexo:
                                case 'F':
                                    ads_ead.inscritos_fem += 1
                                case 'M':
                                    ads_ead.inscritos_masc += 1
                        case 'NOTURNO':
                            ads_not.inscritos+=1
                            match sexo:
                                case 'F':
                                    ads_not.inscritos_fem += 1
                                case 'M':
                                    ads_not.inscritos_masc += 1

                case 'DIREITO':
                    match periodo:
                        case 'NOTURNO':
                            direito_noturno.inscritos += 1
                            match sexo: 
                                case 'F':
                                    direito_noturno.inscritos_fem += 1
                                case 'M':
                                    direito_noturno.inscirtos_masc += 1
                        case 'DIURNO':
                            direito_diurno.inscritos += 1
                            match sexo:
                                case 'F':
                                    direito_noturno.inscritos_fem += 1
                                case 'M':
                                    direito_noturno.inscritos_masc += 1

                case 'ENGENHARIA DE SOFTWARE':
                    eng.inscritos += 1
                    match sexo:
                        case 'F':
                            eng.inscritos_fem += 1
                        case 'M':
                            eng.inscritos_masc += 1

def infos():
    print('Curso | Periodo | N.Vagas | Total Inscritos | Inscr. p Vaga | Inscr Fem | Inscr Masc')
    for curso in CURSOS:
        match curso:
            case 'CIENCIA DA COMPUTACAO':
                bcc.inscrito_por_vaga = round((bcc.inscritos/bcc.vagas), 4)
                print(bcc.curso, bcc.periodo, bcc.vagas, bcc.inscritos,
                      bcc.inscrito_por_vaga, bcc.inscritos_fem, bcc.inscritos_masc)
                write_class(bcc)

            case 'ANALISE E DESENVOLVIMENTO DE SISTEMAS':
                ads_ead.inscrito_por_vaga = round(
                    (ads_ead.inscritos/ads_ead.vagas), 4)
                print(ads_ead.curso, ads_ead.periodo, ads_ead.vagas, ads_ead.inscritos,
                      ads_ead.inscrito_por_vaga, ads_ead.inscritos_fem, ads_ead.inscritos_masc)
                ads_not.inscrito_por_vaga = round(
                    (ads_not.inscritos/ads_not.vagas), 4)
                print(ads_not.curso, ads_not.periodo, ads_not.vagas, ads_not.inscritos,
                      ads_not.inscrito_por_vaga, ads_not.inscritos_fem, ads_not.inscritos_masc)
                write_class(ads_ead)
                write_class(ads_not)

            case 'DIREITO':
                direito_diurno.inscrito_por_vaga = round(
                    (direito_diurno.inscritos/direito_diurno.vagas), 4)
                print(direito_diurno.curso, direito_diurno.periodo, direito_diurno.vagas,
                      direito_diurno.inscritos, direito_diurno.inscrito_por_vaga, direito_diurno.inscritos_fem, direito_diurno.inscritos_masc)
                direito_noturno.inscrito_por_vaga = round(
                    (direito_noturno.inscritos/direito_noturno.vagas), 4)
                print(direito_noturno.curso, direito_noturno.periodo, direito_noturno.vagas,
                      direito_noturno.inscritos, direito_noturno.inscrito_por_vaga, direito_noturno.inscritos_fem, direito_noturno.inscritos_masc)
                write_class(direito_noturno)
                write_class(direito_diurno)

            case 'ENGENHARIA DE SOFTWARE':
                eng.inscrito_por_vaga = round((eng.inscritos/eng.vagas), 4)
                print(eng.curso, eng.periodo, eng.vagas, eng.inscritos,
                      eng.inscrito_por_vaga, eng.inscritos_fem, eng.inscritos_masc)
                write_class(eng)
    print('\n')
    os.system('pause')

def menu():
    os.system('cls')

    print("Digite uma opção para ser escolhida:")
    print("[A] Inscricao")
    print("[B] Informações de cursos")
    print("[Z] SAIR")

#evento de repeticao principal
try:
    readalunos()
except:
    open('alunos.csv', 'w')
finally:
    op = str
    while op != 'Z':
        menu()
        op = str(input('\n\nOpção:')).upper()

        match op:
            case 'A':
                inscricao()
                os.system('cls')
            case 'B':
                try:
                    os.remove("relatorio.csv")
                except:
                    continue
                finally:
                    infos()

#assegurar que os dados sempre serao gravados ao sair
try: 
    os.remove("relatorio.csv")
finally:
    write_class(bcc)
    write_class(ads_ead)
    write_class(ads_not)
    write_class(direito_noturno)
    write_class(direito_diurno)
    write_class(eng)