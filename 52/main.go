package main

import "fmt"

const MAX_MUL = 2

func getDigitCount(num int) int {
	c := 0
	for num > 0 {
		c++
		num /= 10
	}
	return c
}

func isSameDigits(nums []int) bool {
	set := make(map[int]bool)

	if len(nums) == 1 {
		return true
	}

	var n int
	n = nums[0]

	for n > 0 {
		if set[n%10] == true {
			return false
		}
		set[n%10] = true
		n /= 10
	}

	for i := 1; i < len(nums); i++ {
		tmpSet := make(map[int]bool)
		n = nums[i]
		for n > 0 {
			if set[n%10] == false {
				return false
			}
			if set[n%10] == true && tmpSet[n%10] == true {
				return false
			}
			tmpSet[n%10] = true
			n /= 10
		}
	}

	return true

}

func main() {

	i := 2

	for {
		// fmt.Printf("\r%v", i)
		if isSameDigits([]int{
			i,
			2 * i,
			3 * i,
			4 * i,
			5 * i,
			6 * i}) {
			fmt.Printf("\nResult: %v\n", i)
			break
		}
		i++
	}

}
