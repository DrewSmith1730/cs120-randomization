# M2OEP-Randomization-jcmcgowa-asmith16
Jack McGowan and Drew Smith Randomization Project

## Jack McGowan's Randomize Function
Creates a copy of the vector of objects, then generates a random index value, and then compares that value to a vector of previous indexes, and generates a new one if there is a conflict. Then pushes the item from the copy of the original vector to the original vector.

## Drew Smith's Randomize Function
This randomize function selects a random function selects a random position and swaps the object with the next one in the vector.
If the last object in the vector is selected it will swap with first one. This is done 400 times.

## Data Tracked about the Randomize Functions
For a total of 10000 the distribution of one of the items is tracked. The number of times this item ends up in a location is then stored in a vector. After the run is finished the max, min, average and Standard deviation of the distribution is printed.

## Break down of the data
By looking at the standard deviation of the distribution of the randomization methods Jack's algorithm is significantly better. Jack's algorithm tends to have a standard deviation of about 10 while Drew's algorithm tends to have a standard deviation of about 70.
As far as time efficency Jacks algorithm runs in about half the time Drews runs.
