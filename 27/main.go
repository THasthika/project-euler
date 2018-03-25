package main

import "fmt"

func main() {

	var a, b, n, num int

	LL := -1000
	UL := 1000

	a = LL
	b = LL

	var max int
	max = 0

	for ; a <= UL; a++ {
		for b = LL; b <= UL; b++ {

			n = 0
			num = n*n + a*n + b
			for isPrime(num) {
				n++
				num = n*n + a*n + b
			}

			if n > max {
				max = n + 1
				fmt.Printf("%v %v %v %v\n", max, a*b, a, b)
			}

		}
	}

}

func isPrime(num int) bool {

	if num <= 1 {
		return false
	}

	if num == 2 {
		return true
	}

	if num%2 == 0 {
		return false
	}

	for i := 3; i*i <= num; i += 2 {
		if num%i == 0 {
			return false
		}
	}

	return true
}
