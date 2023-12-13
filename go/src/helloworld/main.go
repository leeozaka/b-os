package main

import (
	"fmt"
	"github.com/myuser/calculator"
)

func soma(nmr1 int, nmr2 int) (resultado int, resultado2 int) {
	resultado = nmr1 + nmr2
	resultado2 = nmr1 * nmr2
	return
}

func main() {
	//var inteiro32 uint = -10
	//i, _ := strconv.Atoi("-42")
	nome := "Leonardo"
	alteranome(&nome)
	//_, soma := soma(10, 20)
	valor := calculator.Sum(10, 20)
	pass := true
	if pass {
		fmt.Println(valor)
		fmt.Println(nome)
	}
	//fmt.Printf("Hello World!")
}

func alteranome(nome *string) {
	*nome = "Tiago"
}
