object QuickSort {
  def main(args: Array[String]): Unit = {
    val arr = takeUserInput()

    println("Enter the sorting method (imperative/functional):")
    val method = scala.io.StdIn.readLine()

    val sortedArray = method.toLowerCase match {
      case "imperative" => quickSortImperative(arr)
      case "functional" => quickSortFunctional(arr)
      case _ => {
        println("Invalid sorting method. Exiting the program.")
        sys.exit(1)
      }
    }

    println("Sorted array:")
    sortedArray.foreach(println)
  }

  def takeUserInput(): Array[Int] = {
    println("Enter the number of elements in the array:")
    val n = scala.io.StdIn.readInt()

    println(s"Enter $n elements:")
    val arr = new Array[Int](n)
    for (i <- 0 until n) {
      arr(i) = scala.io.StdIn.readInt()
    }
    arr
  }

  def quickSortImperative(arr: Array[Int]): Array[Int] = {
    val sortedArr = arr.clone()
    quickSortImperativeHelper(sortedArr, 0, sortedArr.length - 1)
    sortedArr
  }

  def quickSortImperativeHelper(arr: Array[Int], low: Int, high: Int): Unit = {
    if (low < high) {
      val pivotIndex = partition(arr, low, high)
      quickSortImperativeHelper(arr, low, pivotIndex - 1)
      quickSortImperativeHelper(arr, pivotIndex + 1, high)
    }
  }

  def partition(arr: Array[Int], low: Int, high: Int): Int = {
    val pivot = arr(low)
    var i = low + 1
    var j = high

    while (i <= j) {
      if (arr(i) <= pivot) {
        i += 1
      } else if (arr(j) > pivot) {
        j -= 1
      } else {
        swap(arr, i, j)
        i += 1
        j -= 1
      }
    }

    swap(arr, low, j)
    j
  }

  def swap(arr: Array[Int], i: Int, j: Int): Unit = {
    val temp = arr(i)
    arr(i) = arr(j)
    arr(j) = temp
  }

  def quickSortFunctional(arr: Array[Int]): Array[Int] = {
    if (arr.length <= 1) arr
    else {
      val pivot = arr(arr.length / 2)
      Array.concat(
        quickSortFunctional(arr.filter(_ < pivot)),
        arr.filter(_ == pivot),
        quickSortFunctional(arr.filter(_ > pivot))
      )
    }
  }
}
