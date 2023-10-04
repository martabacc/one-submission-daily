package com.okta.developer

import kotlin.random.Random

fun race(horses: List<Int>) = horses.sortedDescending()

fun findFastestInGroup(horses: List<Int>) = horses.sortedDescending().first()

fun sevenRaces(groups: List<List<Int>>): List<Int> {
    val insideGroupSorted = groups.map { race(it) }
    val groupSortedByWinner = insideGroupSorted.sortedBy {
        -it[0]
    }
    val fastestOfAll = findFastestInGroup(
        groupSortedByWinner.map { it -> it[0] }
    )
    val topThreeGroups = groupSortedByWinner.chunked(3).first()
    val finalRaceHorse = listOf(
        topThreeGroups.last().first(),
        topThreeGroups[1][0],
        topThreeGroups[1][1],
        topThreeGroups[0][1],
        topThreeGroups[0][2]
    )
    val finalResult = race(finalRaceHorse)

    return listOf(fastestOfAll, finalResult.first(), finalResult[1])
}

fun sixRaces(groups: List<List<Int>>): List<Int> {
    val insideGroupSorted = groups.map { race(it) }
    val groupSortedByWinner = insideGroupSorted.sortedBy {
        -it[0]
    }
    val firstWinnersInGroups = groupSortedByWinner.map { it -> it[0] }
    val finalResult = race(firstWinnersInGroups)

    return finalResult.chunked(3).first()
}

fun generateRandomNumberInRange(min: Int = -99999, max: Int=99999999): Int {
    return Random.nextInt(min, max) // Generates a random integer in the specified range [min, max]
}

fun main() {
    for (i in 1..5) {
        val horseCount = 25
        val horses = IntArray(horseCount){ generateRandomNumberInRange() }.toList()
        val groups = horses.chunked(5)

        val expected = race(horses).chunked(3).first()

//        println(groups)
        println("expected result: ${expected}")
        val sevenRaceResult = sevenRaces(groups)
        val sixRaceResult = sixRaces(groups)
        println("[7 races] correct: ${expected.equals(sevenRaceResult)}")
        println("[6 races] correct: ${expected.equals(sixRaceResult)}")
    }

}

