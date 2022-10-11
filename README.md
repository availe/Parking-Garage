# Parking Garage
 A solution to the Parking Garage problem utilizing linked lists
 
 Commented out cout lines were used for debugging purposes
 
 Program reads txt files formatted likewise to "cars.txt" or "cars1.txt"
 ____
 
 What the program does:
 
 If car is arriving:
 - Note: Lane1 and lane2 each has capacity of 10 cars
 - If lane1 is not full push car to lane1 (add to stack lane1)
 - If lane1 is full but not lane2, push car to lane2 (add to stack lane2)
 - If lane1 and lane2 is full, then garage is full (car not added to stack)
 
 
 If car is departing:
 - Note: When pushing a car, the car is pushed to the opposite lane, or to the street if the opposite lane is fulll
 - Note: Each time a car is pushed in the depart function, it counts as 1 move
 - If departing car is on top of lane, simply delete it from the stack
 - If departing car is NOT on top of lane, do following steps:
    - Step 1: Push car to other lane/street until it reaches departing car
    - Step 2: Delete departing car from stack/linked list
    - Step 3: Push every car moved in Step 1 back to its original lane
