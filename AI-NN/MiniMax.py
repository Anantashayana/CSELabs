# Write a program to implement a Minimax decision-making algorithm, typically used in a turn-based, two player 
# games. The goal of the algorithm is to find the optimal next move. 

import math
import random 

#minimax class
def minimax (currentDepth, nodeIndex, 
             maxTurn, score,  
             tarDepth): 
  
    # base case : tarDepth reached 
    if (currentDepth == tarDepth):  
        return score[nodeIndex] 
      
    if (maxTurn): 
        return max(minimax(currentDepth + 1, nodeIndex * 2,  
                    False, score, tarDepth),  
                   minimax(currentDepth + 1, nodeIndex * 2 + 1,  
                    False, score, tarDepth)) 
      
    else: 
        return min(minimax(currentDepth + 1, nodeIndex * 2,  
                     True, score, tarDepth),  
                   minimax(currentDepth + 1, nodeIndex * 2 + 1,  
                     True, score, tarDepth)) 
      
# Driver code 
score = random.sample(range(1, 50), 4)
print(str(score))  
treeDepth = math.log(len(score), 2) 
print("Tree Depth:"+str(treeDepth))
  
print("The optimal value is : ", end = "") 
print(minimax(0, 0, True, score, treeDepth)) 

