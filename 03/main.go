package main

import "fmt"

func isPrime(n int64) bool {
	if n == 1 {
		return false
	}
	if n == 2 {
		return true
	}
	if n%2 == 0 {
		return false
	}
	i := int64(3)
	for i*i <= n {
		if n%i == 0 {
			return false
		}
		i += 2
	}
	return true
}

func getFactors(n int64) []int64 {
	l := make([]int64, 0)
	r := make([]int64, 0)
	i := int64(1)
	for i*i <= n {
		if n%i == 0 {
			l = append(l, i)
			b := n / i
			if b != i {
				r = append(r, b)
			}
		}
		i++
	}
	for i := len(r)/2 - 1; i >= 0; i-- {
		opp := len(r) - 1 - i
		r[i], r[opp] = r[opp], r[i]
	}
	ret := append(l, r...)
	return ret
}

func findAnswer(n int64) int64 {

	fac := getFactors(n)

	for i := len(fac) - 1; i >= 0; i-- {
		if isPrime(fac[i]) {
			return fac[i]
		}
	}

	return 0
}

func main() {

	// res := findAnswer(600851475143)
	// fmt.Println(res)

	var t int
	_, err := fmt.Scanf("%d", &t)

	if err != nil {
		panic(err)
	}

	for t > 0 {
		var n int64
		_, err = fmt.Scanf("%d", &n)

		if err != nil {
			panic(err)
		}

		res := findAnswer(n)

		fmt.Println(res)

		t--
	}

}
