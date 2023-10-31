strings = []
high = []
highnote = []

def main():
    with open("datfile.dat", "r") as _data: 
        for line in _data: 
            line = line.strip() 
            strings.append(line)
            lst_aux = line.split()
            name = lst_aux[0]
            lst_aux = [ x for x in lst_aux if x.isdigit()] 

            lst_aux = [int(x) for x in lst_aux]

            high.append([name, max(lst_aux)])

            if len(lst_aux) > 5:
                highnote.append(name)

            med = sum(lst_aux)/len(lst_aux)
            print("al: ", name, " med: ", med)

        print("high_notes: ", highnote)
        print("highest notes foreach : ", high)

main()