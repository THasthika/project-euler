package main

import "fmt"

func findAnswer(n int64) int64 {
	j := int64(0)
	var k int64

	total := int64(0)

	for i := int64(1); i < n; {
		if i%2 == 0 {
			total += i
		}
		k = i
		i = k + j
		j = k
	}

	return total

}

func main() {

	// res := findAnswer(4000000)
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
