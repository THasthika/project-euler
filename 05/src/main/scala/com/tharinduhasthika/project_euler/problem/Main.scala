package com.tharinduhasthika.project_euler.problem

object Main {

//  def removeUnDivisible(num: Int, list: List[Int]): List[Int] = {
//    list.filter(_ % num == 0)
//  }

  def divisible(num: Long, n: Long): Boolean = {
    if (n == 1) {
      return true
    }
    if (num % n != 0) {
      return false
    }
    return divisible(num, n - 1)
  }

  def main(args: Array[String]): Unit = {

    val N = 20L

    var i = N
    var found = false

    while (!found) {
      found = divisible(i, N)
      if (!found) {
        i += 1
      }
    }

    println(i)

//    var t = BigInt(1)
//
//    for (a <- 1 to 100) {
//      t *= a
//    }
//
//    var tt = BigInt(0)
//    var rem = BigInt(0)
//
//    while (t > 0) {
//      rem = t % 10
//      t = t / 10
//      tt += rem
//    }
//
//    print(tt)

  }

}
