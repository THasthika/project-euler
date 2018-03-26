package main

import (
	"fmt"
)

const TARGET = 200

func checkCombinations(target int, coins *[]int, current int, index int) int {
	if current > target {
		return 0
	} else if current == target {
		return 1
	}

	if current < target && index >= len(*coins) {
		return 0
	}

	count := 0
	ctemp := 0

	for target >= ctemp {
		// for t := 0; t < index; t++ {
		// 	fmt.Printf("\t")
		// }
		// fmt.Printf("current: %v | coin: %v | index: %v\n", current, (*coins)[index], index)
		tmp := current + ctemp
		count += checkCombinations(target, coins, tmp, index+1)
		ctemp += (*coins)[index]
	}

	return count

}

func main() {

	coins := []int{200, 100, 50, 20, 10, 5, 2, 1}
	// coins := []int{5, 2, 1}

	f := checkCombinations(TARGET, &coins, 0, 0)

	fmt.Printf("Result: %v\n", f)

}
