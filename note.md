# Note

## Index
* [Google Code Jam](#google-code-jam)

## [Google Code Jam](https://codingcompetitions.withgoogle.com/codejam)
### [2020](https://codingcompetitions.withgoogle.com/codejam/archive/2020)
#### [Qualification Round](https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27)
**Indicium** </br>
First, we need to deal with the main diagonal. Just use the DFS to go through all the possible combination of **n** elements with the number **1** to **n**. In this step, we can exclude some impossible combinations of **n** and **k**, such as `n = 3, k = 4`. Actually, the impossible situation can be described as **k** can only be expressed as the sum of some number with the amout **n-1** and the other different number with the amount **1**. </br>
</br>
Then, after getting the diagonal, we need to use the bipartite matching to assign the numbers to each cell in the result matrix. We first do the bipartite matching to those numbers has been used in the diagonal. Then we do the bipartite matching to the other numbers. </br>
</br>
For the bipartite matching, we first need to generate a matrix to indicate current available positions for this number. With the matrix, we greedily assign the numbers to the available positions firstly row by row and secondly column by column. In some cases, there will be some conflicts, and then the algorithm will go back to the previous row to find another avaible positions in it. Of course, we need three auxilary arrays, two arrays for the bipartite matching to store indices of rows and columns and one array to indicate whether this column is used or not.