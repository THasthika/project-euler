package main

import "fmt"

func find3and5(n int64) int64 {

	p := n / 3
	q := n / 5
	r := n / 15

	if n%3 == 0 {
		p--
	}

	if n%5 == 0 {
		q--
	}

	if n%15 == 0 {
		r--
	}

	t3 := 3 * (p * (p + 1) / 2)
	t5 := 5 * (q * (q + 1) / 2)
	t15 := 15 * (r * (r + 1) / 2)

	res := t3 + t5 - t15

	return res
}

func main() {

	res := find3and5(1000)
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

	// 	res := find3and5(n)

	// 	fmt.Println(res)

	// 	t--
	// }

}
