
import org.apache.spark.{SparkContext, SparkConf}
import org.apache.spark.rdd._
object tweetmining {
  val conf = new SparkConf().setAppName("User mining") .setMaster("local[*]")
  val sc = new SparkContext(conf)
  var pathToFile = ""
  def main(args: Array[String]) {
    if (args.length != 1) {
      System.exit(1)
    }
    pathToFile = args(0)
    val tweets = sc.textFile(pathToFile).mapPartitions(TweetUtils.parseFromJson(_))
    val tweetsByUser = tweets.map(x => (x.user,x) ).groupByKey()
    val numTweetsByUser = tweetsByUser.map(x=> (x._1, x._2.size))
    val sortedUsersByNumTweets = numTweetsByUser.sortBy(_._2, ascending=false)  
    sortedUsersByNumTweets.take(10).foreach(println)

    val selectedTweets= sortedUsersByNumTweets.take(10)
  }
}
import com.google.gson._
object TweetUtils {
	case class Tweet (
		id : String,
		user : String,
		userName : String,
		text : String,
		place : String,
		country : String,
		lang : String
		)
	def parseFromJson(lines:Iterator[String]):Iterator[Tweet] = {
		val gson = new Gson
		lines.map(line => gson.fromJson(line, classOf[Tweet]))
	}
}


/** 
  Whenever you have heavyweight initialization that should be done once for many RDD elements 
  rather than once per RDD element, use mapPartitions() instead of map(). 
  mapPartitions() provides for the initialization to be done once per worker task/thread/partition 
  instead of once per RDD data element for example.

  Example Scenario : if we have 100K elements in a particular RDD partition then we will fire 
  off the function being used by the mapping transformation 100K times when we use map.

  Conversely, if we use mapPartitions then we will only call the particular function one time, 
  but we will pass in all 100K records and get back all responses in one function call.

  There will be performance gain since map works on a particular function so many times, 
  especially if the function is doing something expensive each time that it wouldn't need 
  to do if we passed in all the elements at once(in case of mappartitions).
  * */

