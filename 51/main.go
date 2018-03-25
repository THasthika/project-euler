package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {

	// i := uint(13)

	// s := []rune(strconv.Itoa(int(i)))

	// fmt.Printf("%s\n", string(s))

	// s := []rune("56**3")

	// a := getNums(s)

	// fmt.Printf("%v\n", a)
	// fmt.Printf("%d\n", getPrimeCount(a))

	// allPatterns(s, 0, 1)

	// strconv.Atoi

	var curMax int
	var curNum int

	curMax = 0
	curNum = 0

	num := 100000
	LIMIT := num * 100

	for ; num < LIMIT; num++ {
		if isPrime(num) {
			allPatterns([]rune(strconv.Itoa(num)), 0, 4, &curMax, &curNum)
		}
	}

	fmt.Printf("\nResult: %v %v\n", curMax, curNum)

}

func getPrimeNums(s []rune) []int {

	ns := make([]rune, len(s))
	copy(ns, s)

	ret := make([]int, 0)

	for n := 0; n < 10; n++ {
		for i := 0; i < len(s); i++ {
			if s[i] == '*' {
				ns[i] = rune('0') + rune(n)
			}
		}
		if ns[0] == '0' {
			continue
		}
		num, err := strconv.Atoi(string(ns))
		if err != nil {
			panic("ERROR!")
		}
		if isPrime(num) {
			ret = append(ret, num)
		}
	}

	return ret
}

func allPatterns(s []rune, j int, limit int, pCurMax *int, pCurNum *int) {

	c := 0
	for i := 0; i < len(s); i++ {
		if s[i] == '*' {
			c++
		}
	}

	if c >= 1 {
		arr := getPrimeNums(s)
		fmt.Printf("\rsearching... %s\t\tcurMax: %v\t\tcurNum: %v", string(s), *pCurMax, *pCurNum)
		if len(arr) > 0 && len(arr) > *pCurMax {
			*pCurMax = len(arr)
			*pCurNum = arr[0]
			if *pCurMax == 8 {
				fmt.Printf("\nResult: %v %v\n", *pCurMax, *pCurNum)
				os.Exit(0)
			}
		}
	}

	if c >= limit {
		return
	}

	for i := j; i < len(s); i++ {
		ns := make([]rune, len(s))
		copy(ns, s)
		if ns[i] == '*' {
			continue
		}
		ns[i] = '*'
		allPatterns(ns, j+1, limit, pCurMax, pCurNum)
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
