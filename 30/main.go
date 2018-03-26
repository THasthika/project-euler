package main

import (
	"fmt"
	"math/big"
)

func numToArray(num int64) []int8 {

	ret := make([]int8, 0)
	var t int8

	for num > 0 {
		t = int8(num % 10)
		num /= 10
		ret = append([]int8{t}, ret...)
	}

	return ret

}

func testNumber(num int64, pow int) bool {

	arr := numToArray(num)

	total := int64(0)

	var j, k *big.Int

	k = big.NewInt(int64(pow))

	for i := range arr {
		j = big.NewInt(int64(arr[i]))
		j.Exp(j, k, nil)
		total += j.Int64()

		if total > num {
			return false
		}
	}

	if total == num {
		return true
	}

	return false

}

func main() {

	const LIMIT = 1000000
	const POW = 5

	total := int64(0)

	for i := int64(10); i < LIMIT; i++ {
		fmt.Printf("\r%d", i)
		if testNumber(i, POW) {
			total += i
		}
	}

	fmt.Printf("\nTotal: %v\n", total)

}
