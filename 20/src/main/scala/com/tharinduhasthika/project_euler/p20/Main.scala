package com.tharinduhasthika.project_euler.p20

object Main {



  def main(args: Array[String]): Unit = {

    var t = BigInt(1)

    for (a <- 1 to 100) {
      t *= a
    }

    var tt = BigInt(0)
    var rem = BigInt(0)

    while (t > 0) {
      rem = t % 10
      t = t / 10
      tt += rem
    }

    print(tt)

  }

}
