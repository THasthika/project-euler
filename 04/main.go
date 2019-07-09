package main

import (
	"fmt"
	"strconv"
)

func isPalindrome(n int64) bool {
	s := strconv.FormatInt(n, 10)
	l := len(s)
	for i := 0; i < l/2; i++ {
		if s[i] != s[l-i-1] {
			return false
		}
	}
	return true
}

func factorize(n int64, i int64) int64 {
	if n%i == 0 {
		return n / i
	}
	return 0
}

func isValidNumber(n int64) bool {
	if !isPalindrome(n) {
		return false
	}
	for i := int64(100); i < 1000; i++ {
		v := factorize(n, i)
		if v >= 100 && v <= 999 {
			return true
		}
	}
	return false
}

func findAnswer(n int64) int64 {

	for i := n - 1; i > 0; i-- {
		if isValidNumber(i) {
			return i
		}
	}

	return 0
}

func main() {

	res := findAnswer(1000000)
	fmt.Println(res)

	// var t int
	// _, err := fmt.Scanf("%d", &t)

	// if err != nil {
	// 	panic(err)
	// }

	// for t > 0 {
	// 	var n int64
	// 	_, err = fmt.Scanf("%d", &n)

	// 	if err != nil {
	// 		panic(err)
	// 	}

	// 	res := findAnswer(n)

	// 	fmt.Println(res)

	// 	t--
	// }

}
