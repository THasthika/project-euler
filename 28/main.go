package main

import "fmt"

func main() {
	const SIZE = 1001

	var grid [SIZE][SIZE]int

	var dir string
	dir = "l"

	var r, c int
	c = SIZE - 1
	r = 0

	var n int
	n = SIZE * SIZE

	var cs, ce, rs, re int
	cs = 0
	ce = SIZE - 1
	rs = 0
	re = SIZE - 1

	for n > 0 {
		grid[r][c] = n
		n--
		switch dir {
		case "l":
			c--
			if c <= cs {
				c = cs
				dir = "d"
				cs++
			}
			break
		case "d":
			r++
			if r >= re {
				r = re
				dir = "r"
				re--
			}
			break
		case "r":
			c++
			if c >= ce {
				c = ce
				dir = "u"
				ce--
			}
			break
		case "u":
			r--
			if r <= rs {
				rs++
				r = rs
				c = ce
				dir = "l"
			}
		}

	}

	total := 0

	for i := 0; i < SIZE; i++ {

		total += grid[i][i]
		if SIZE-i-1 != i {
			total += grid[i][SIZE-i-1]
		}
	}

	fmt.Println(total)

}
