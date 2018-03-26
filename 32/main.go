package main

import "fmt"

func getDigitCount(num int) int {
	c := 0
	for num > 0 {
		c++
		num /= 10
	}
	return c
}

func isPandigital(nums [3]int) bool {

	if getDigitCount(nums[0])+getDigitCount(nums[1])+getDigitCount(nums[2]) != 9 {
		return false
	}

	set := make(map[int]bool)

	var n, t int

	for i := 0; i < 3; i++ {
		n = nums[i]
		for n > 0 {
			t = n % 10
			n /= 10
			if set[t] == true {
				return false
			}
			set[t] = true
		}
	}

	for i := 1; i <= 9; i++ {
		if set[i] == false {
			return false
		}
	}

	return true

}

func main() {

	const LIMIT = 100

	total := 0

	var n, a, b int

	for n = 1; n < LIMIT*LIMIT; n++ {
		for a = 1; a*a <= n; a++ {
			if n%a == 0 {
				b = n / a
				if isPandigital([3]int{a, b, n}) {
					total += n
					break
				}
			}
		}
	}

	fmt.Println(total)

	// for a := 1; a < LIMIT; a++ {
	// 	for b := a + 1; b < LIMIT; b++ {
	// 		tmp = a * b
	// 		if isPandigital(a, b, tmp) && !set[tmp] {
	// 			set[tmp] = true
	// 			total += tmp
	// 		}
	// 	}
	// }

	// fmt.Printf("%v\n", total)

}
