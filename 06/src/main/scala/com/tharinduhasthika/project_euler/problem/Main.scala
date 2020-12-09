package com.tharinduhasthika.project_euler.problem

object Main {

//  def removeUnDivisible(num: Int, list: List[Int]): List[Int] = {
//    list.filter(_ % num == 0)
//  }

  def sumOfNums(n: Long): Long = (n * (n + 1)) / 2

  def sumOfSquares(n: Long): Long = (n * (n + 1) * (2 * n + 1)) / 6

  def main(args: Array[String]): Unit = {
    val N = 100

    val s = sumOfNums(N)

    print((s*s) - sumOfSquares(N))


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
