cmake_minimum_required(VERSION 3.19)
project(CP)

set(CMAKE_CXX_STANDARD 14)

add_executable(CP
    Atcoder/189/ASlot.cpp
    Atcoder/189/BAlcoholic.cpp
    Atcoder/189/CMandarinOrange.cpp
    Atcoder/196/A.cpp
    Atcoder/196/B.cpp
    Atcoder/196/C.cpp
    Atcoder/DP/A.cpp
    Atcoder/DP/B.cpp
    Atcoder/practice/ABC200/A.cpp
    Atcoder/practice/ABC200/B.cpp
    Atcoder/practice/ABC200/C.cpp
    Atcoder/practice/ABC200/D.cpp
    Atcoder/practice/ABC200/E.cpp
    Atcoder/practice/ABC202/A.cpp
    Atcoder/practice/ABC202/B.cpp
    Atcoder/practice/ABC202/C.cpp
    Atcoder/practice/digitalGraffiti.cpp
    Atcoder/practice/powerSocket.cpp
    Atcoder/practice/qualificationSimulator.cpp
    Atcoder/practice/rally.cpp
    Atcoder/practice/removeIt.cpp
    Atcoder/practice/vanishingPitch.cpp
    CC/aprLong/boolgame.cpp
    CC/aprLong/chaosemp.cpp
    CC/aprLong/EMP.cpp
    CC/aprLong/kavgmat.cpp
    CC/aprLong/mexstr.cpp
    CC/aprLong/mexstr2.cpp
    CC/aprLong/sdice.cpp
    CC/aprLong/treeperm.cpp
    CC/febLong/atwnt.cpp
    CC/febLong/checks.cpp
    CC/febLong/checks2.cpp
    CC/febLong/f_sumXOR.cpp
    CC/febLong/frogs.cpp
    CC/febLong/hdivisr.cpp
    CC/febLong/maxfun.cpp
    CC/febLong/meet.cpp
    CC/febLong/mulgame.cpp
    CC/febLong/prigame.cpp
    CC/febLong/subsets.cpp
    CC/febLong/sumxor.cpp
    CC/febLong/sumxor2.cpp
    CC/febLong/sushsumxor2.cpp
    CC/febLong/teamname.cpp
    CC/febLong/test1.cpp
    CC/janCookoff/manysums.cpp
    CC/janCookoff/passwd.cpp
    CC/janCookoff/ptuples.cpp
    CC/marLong/wireless-electricity/checker_public.cpp
    CC/marLong/wireless-electricity/generator_public.cpp
    CC/marLong/wireless-electricity/wirelesselectricity.cpp
    CC/marLong/colglf4.cpp
    CC/marLong/consadd.cpp
    CC/marLong/densegrp.cpp
    CC/marLong/irstxor.cpp
    CC/marLong/maxtopo.cpp
    CC/marLong/paparazi.cpp
    CC/marLong/spacearr.cpp
    CC/mayLong/cl2.cpp
    CC/mayLong/iss.cpp
    CC/mayLong/kkling.cpp
    CC/mayLong/modeq.cpp
    CC/mayLong/tctctoe.cpp
    CC/mayLong/thouses.cpp
    CC/mayLong/vpath.cpp
    CC/mayLong/xorequal.cpp
    CC/practice/cnote.cpp
    CC/practice/lecandy.cpp
    CC/practice/salary.cpp
    CC/billrd.cpp
    CC/COINS.cpp
    CC/decodeit.cpp
    CC/divThree.cpp
    CC/evenpsum.cpp
    CC/fairelct.cpp
    CC/lue.cpp
    CC/marbles.cpp
    CC/orand.cpp
    CC/posprefs.cpp
    CC/vaccine1.cpp
    CC/vaccine2.cpp
    CF/696/arrayDestruction.cpp
    CF/696/cleaning.cpp
    CF/696/diffDiv.cpp
    CF/696/puzzleFromTheFuture.cpp
    CF/697/ballInBerland.cpp
    CF/697/cleaningThePhone.cpp
    CF/697/nyn.cpp
    CF/697/oddDivisor.cpp
    CF/698/nezzarColorfulballs.cpp
    CF/704/A.cpp
    CF/704/B.cpp
    CF/710/A.cpp
    CF/710/B.cpp
    CF/710/C.cpp
    CF/710/D.cpp
    CF/710/E.cpp
    CF/717/A.cpp
    CF/717/B.cpp
    CF/DP-practice/hitTheLottery.cpp
    CF/EDU/binarySearch/1A.cpp
    CF/EDU/binarySearch/1B.cpp
    CF/EDU/binarySearch/1C.cpp
    CF/EDU/binarySearch/1D.cpp
    CF/EDU/binarySearch/2A.cpp
    CF/EDU/graph/connectedComponents.cpp
    CF/EDU/graph/representation.cpp
    CF/practice/Div2A/579A.cpp
    CF/practice/Div2A/antiqueItems.cpp
    CF/practice/Div2A/antonLetters.cpp
    CF/practice/Div2A/applemanEasyTask.cpp
    CF/practice/Div2A/AreplacingElements.cpp
    CF/practice/Div2A/arrivalOfGeneral.cpp
    CF/practice/Div2A/bearRaspberry.cpp
    CF/practice/Div2A/beautiful-matrix.cpp
    CF/practice/Div2A/beautifulYear.cpp
    CF/practice/Div2A/berSUBall.cpp
    CF/practice/Div2A/bit.cpp
    CF/practice/Div2A/borze.cpp
    CF/practice/Div2A/bovine-dilemma.cpp
    CF/practice/Div2A/BstringLCM.cpp
    CF/practice/Div2A/cakeminator.cpp
    CF/practice/Div2A/caps-lock.cpp
    CF/practice/Div2A/chat-room.cpp
    CF/practice/Div2A/cheapTravel.cpp
    CF/practice/Div2A/chessCheater.cpp
    CF/practice/Div2A/choosingTeams.cpp
    CF/practice/Div2A/domino.cpp
    CF/practice/Div2A/dragons.cpp
    CF/practice/Div2A/dreamoonStairs.cpp
    CF/practice/Div2A/dscj.cpp
    CF/practice/Div2A/dubstep.cpp
    CF/practice/Div2A/evenArray.cpp
    CF/practice/Div2A/evenOdds.cpp
    CF/practice/Div2A/expression.cpp
    CF/practice/Div2A/favourite-sequence.cpp
    CF/practice/Div2A/fedorGame.cpp
    CF/practice/Div2A/flippingGame.cpp
    CF/practice/Div2A/foxSnake.cpp
    CF/practice/Div2A/games.cpp
    CF/practice/Div2A/gameWithSticks.cpp
    CF/practice/Div2A/helpfulMath.cpp
    CF/practice/Div2A/ilyaBank.cpp
    CF/practice/Div2A/iqTest.cpp
    CF/practice/Div2A/IwannaBeTheGuy.cpp
    CF/practice/Div2A/laptops.cpp
    CF/practice/Div2A/last-minute-enhancement.cpp
    CF/practice/Div2A/longWords.cpp
    CF/practice/Div2A/lucky-division.cpp
    CF/practice/Div2A/lunchRush.cpp
    CF/practice/Div2A/matrixGame.cpp
    CF/practice/Div2A/newyearcandles.cpp
    CF/practice/Div2A/newYearHurry.cpp
    CF/practice/Div2A/newyeartrans.cpp
    CF/practice/Div2A/next-round.cpp
    CF/practice/Div2A/num_seq.cpp
    CF/practice/Div2A/olesya-rodion.cpp
    CF/practice/Div2A/pashmakGarden.cpp
    CF/practice/Div2A/presents.cpp
    CF/practice/Div2A/pstrings.cpp
    CF/practice/Div2A/puzzles.cpp
    CF/practice/Div2A/queueSchool.cpp
    CF/practice/Div2A/randomTeams.cpp
    CF/practice/Div2A/rising-bacteria.cpp
    CF/practice/Div2A/road-to-zero.cpp
    CF/practice/Div2A/segmentsOwnPoints.cpp
    CF/practice/Div2A/shortSubstrings.cpp
    CF/practice/Div2A/sortTheArray.cpp
    CF/practice/Div2A/special_permutation.cpp
    CF/practice/Div2A/string-task.cpp
    CF/practice/Div2A/teamf.cpp
    CF/practice/Div2A/teamOlympiad.cpp
    CF/practice/Div2A/theatre-square.cpp
    CF/practice/Div2A/twins.cpp
    CF/practice/Div2A/unique_bid_auction.cpp
    CF/practice/Div2A/vanyaAndLanterns.cpp
    CF/practice/Div2A/watermelon.cpp
    CF/practice/Div2A/whiteSheet.cpp
    CF/practice/Div2A/worms.cpp
    CF/practice/Div2A/xringroad.cpp
    CF/practice/Div2A/xxxxx.cpp
    CF/practice/Div2A/young-physicist.cpp
    CF/practice/Div2B/currency.cpp
    CF/practice/Div2B/lecture.cpp
    CF/practice/Div2B/pins.cpp
    CF/practice/Div2B/sortShift.cpp
    CF/practice/Div2B/tprimes.cpp
    CF/template.cpp
    CSES/introProb/1-weird-algo.cpp
    CSES/introProb/2-missing-number.cpp
    CSES/introProb/3-repetitions.cpp
    CSES/introProb/4-increasing-array.cpp
    CSES/introProb/5-permutations.cpp
    CSES/introProb/bitStrings.cpp
    CSES/introProb/numberSpiral.cpp
    CSES/introProb/trailingZeros.cpp
    CSES/introProb/twoKnights.cpp
    CSES/introProb/twoSets.cpp
    CSES/diceCombination.cpp
    "DSA/Compression Algorithms/Huffman Coding.cpp"
    "DSA/Data Structures/Binary Indexed Tree.cpp"
    "DSA/Data Structures/Binary Search Tree.cpp"
    "DSA/Data Structures/Binomial Heap.cpp"
    "DSA/Data Structures/Bit Queue.cpp"
    "DSA/Data Structures/Circular Doubly-Linked List.cpp"
    "DSA/Data Structures/Disjoint Set Union.cpp"
    "DSA/Data Structures/Fibonacci Heap.cpp"
    "DSA/Data Structures/Link-cut Tree.cpp"
    "DSA/Data Structures/Pairing Heap.cpp"
    "DSA/Data Structures/Priority Queue.cpp"
    "DSA/Data Structures/Proto-vEB Tree.cpp"
    "DSA/Data Structures/Segment Tree.cpp"
    "DSA/Data Structures/Splay Tree.cpp"
    "DSA/Data Structures/Suffix Array + LCP Array.cpp"
    "DSA/Data Structures/Suffix Automaton.cpp"
    "DSA/Data Structures/Trie.cpp"
    "DSA/Data Structures/van Emde Boas Tree.cpp"
    "DSA/Data Structures/XOR Linked List.c"
    "DSA/Dynamic Programming/0-1 Knapsack.cpp"
    "DSA/Dynamic Programming/Longest Common Subsequence.cpp"
    "DSA/Dynamic Programming/Matrix Chain Multiplication.cpp"
    "DSA/Dynamic Programming/Needleman-Wunsch.cpp"
    "DSA/Dynamic Programming/Nussinov Algorithm.cpp"
    "DSA/Dynamic Programming/Segmented Least Squares.cpp"
    "DSA/Dynamic Programming/Unbounded Knapsack.cpp"
    "DSA/Geometric Algorithms/Graham Scan.cpp"
    "DSA/Geometric Algorithms/Point in Convex Polygon.cpp"
    "DSA/Geometric Algorithms/Segment Intersection.cpp"
    "DSA/Graph Algorithms/Bellman-Ford Algorithm.cpp"
    "DSA/Graph Algorithms/Breadth-First Search.cpp"
    "DSA/Graph Algorithms/Connected Components.cpp"
    "DSA/Graph Algorithms/Cycle Detection.cpp"
    "DSA/Graph Algorithms/Depth-First Search.cpp"
    "DSA/Graph Algorithms/Dijkstra's Algorithm.cpp"
    "DSA/Graph Algorithms/Dinic's Algorithm.cpp"
    "DSA/Graph Algorithms/Edmonds-Karp Algorithm.cpp"
    "DSA/Graph Algorithms/Floyd-Warshall Algorithm.cpp"
    "DSA/Graph Algorithms/Ford-Fulkerson Algorithm.cpp"
    "DSA/Graph Algorithms/Heavy-Light Decomposition.cpp"
    "DSA/Graph Algorithms/Kosaraju's Algorithm.cpp"
    "DSA/Graph Algorithms/Kruskal's Algorithm.cpp"
    "DSA/Graph Algorithms/Prim's Algorithm.cpp"
    "DSA/Graph Algorithms/Tarjan's SCC Algorithm.cpp"
    "DSA/Graph Algorithms/Topological Sorting.cpp"
    "DSA/Greedy Algorithms/First-Fit Bin Packing.cpp"
    "DSA/Greedy Algorithms/Interval Scheduling.cpp"
    "DSA/Mathematical Algorithms/Euclidean Algorithm.cpp"
    "DSA/Mathematical Algorithms/Exponentiation by Squaring.cpp"
    "DSA/Mathematical Algorithms/Extended Euclidean Algorithm.cpp"
    "DSA/Mathematical Algorithms/Matrix Exponentiation.cpp"
    "DSA/Mathematical Algorithms/Matrix Multiplication.cpp"
    "DSA/Mathematical Algorithms/PageRank.cpp"
    "DSA/Mathematical Algorithms/Pascal's Triangle.cpp"
    "DSA/Mathematical Algorithms/Sieve of Eratosthenes.cpp"
    "DSA/Mathematical Algorithms/Simplex Algorithm.cpp"
    "DSA/Mathematical Algorithms/Strassen's Algorithm.cpp"
    "DSA/Miscellaneous/Fast Input (Thanks to Ermin Hodzic).cpp"
    "DSA/Recursion, Backtracking etc./K-Combinations.cpp"
    "DSA/Recursion, Backtracking etc./Permutations.cpp"
    "DSA/Recursion, Backtracking etc./Power Set.cpp"
    "DSA/Searching Algorithms/Binary Search.cpp"
    "DSA/Searching Algorithms/Quickselect.cpp"
    "DSA/Searching Algorithms/Ternary Search.cpp"
    "DSA/Sorting Algorithms/Bitonic Sorter.cpp"
    "DSA/Sorting Algorithms/Bubble Sort.cpp"
    "DSA/Sorting Algorithms/Counting Sort.cpp"
    "DSA/Sorting Algorithms/Heapsort.cpp"
    "DSA/Sorting Algorithms/Insertion Sort.cpp"
    "DSA/Sorting Algorithms/Merge Sort.cpp"
    "DSA/Sorting Algorithms/Quicksort.cpp"
    "DSA/Sorting Algorithms/Selection Sort.cpp"
    "DSA/String Algorithms/Knuth-Morris-Pratt.cpp"
    "DSA/String Algorithms/Z Algorithm.cpp"
    Files/DP-NT-contest/test/chef_award.cpp
    Files/DP-NT-contest/test/cvl.cpp
    Files/DP-NT-contest/test/invrsion.cpp
    Files/DP-NT-contest/DP-NT.cpp
    Files/DP-NT-contest/generator.cpp
    Files/GRUNDY-contest/generatorGRUNDY.cpp
    Files/GRUNDY-contest/GRUNDY_.cpp
    Files/aaAA-revise-check.cpp
    Files/ar-fibo-dp.cpp
    Files/ar-fibo-rec.cpp
    Files/ar-itro-numth.cpp
    Files/ar-matexp-fibo.cpp
    Files/ar-Zeckendorf.cpp
    Files/gen.cpp
    Files/generatorMAKEDIV.cpp
    Files/solMAKEDIV.cpp
    test/cvl/generator.cpp
    test/cvl/sol.cpp
    test/invrsion/generator.cpp
    test/invrsion/sol.cpp
    test/traveljo/generator.cpp
    test/traveljo/sol.cpp
    stl.cpp
    template.cpp)
