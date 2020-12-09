package com.tharinduhasthika.project_euler.problem

import scala.collection.mutable.ListBuffer

object Main {

//  def removeUnDivisible(num: Int, list: List[Int]): List[Int] = {
//    list.filter(_ % num == 0)
//  }

  def time[R](block: => R): R = {
    val t0 = System.nanoTime()
    val result = block    // call-by-name
    val t1 = System.nanoTime()
    println("Elapsed time: " + ((t1 - t0) / 1000000.0) + " ms")
    result
  }

  def sieveOfEratosthenes(arr: Array[Boolean], expandTo: Int): Array[Boolean] = {
    val prevLimit = arr.length
    assert(prevLimit <= expandTo)
    val retArr = Array.fill(expandTo)(true)
    arr.copyToArray(retArr)
    val limit = expandTo
    var i = 2
    while (i*i <= limit) {
      if (retArr(i)) {
        var j = i * i
        var k = 1
        while (j < limit) {
          retArr(j) = false
          j = (i*i) + k*i
          k += 1
        }
      }
      i += 1
    }
    retArr
  }

  def sieveArrToList(arr: Array[Boolean]): List[Long] = {
    val lb = new ListBuffer[Long]()
    arr(0) = false
    arr.zipWithIndex.foreach(x => {
      if (x._1) {
        lb += (x._2)
      }
    })
    lb.toList
  }

  def getPrimeOfPosition(index: Int): Long = {
    var arrSize = 1000
    var increment = 1000

    var s = Array.fill(arrSize)(true)
    s(0) = false
    s(1) = false
    s = sieveOfEratosthenes(s, arrSize)
//    println("Calculated Sieve: size = " + arrSize)
    while (s.count(x => x) <= index) {
      arrSize += increment
      s = sieveOfEratosthenes(s, arrSize)
//      println("Calculated Sieve: size = " + arrSize)
      increment += increment
    }

    val l = sieveArrToList(s)
    l(index)
  }


  def main(args: Array[String]): Unit = {
    val index = 10001
    val x = time { getPrimeOfPosition(index - 1) }
    print(x)

//    val indices = Array(100, 1000, 10000, 100000, 1000000, 10000000)
//    indices.foreach(i => {
//      val x = time { getPrimeOfPosition(i - 1) }
//      println(i + ": " + x)
//    })

  }

}
