#Mr. Chris'Group B.
#BSc. IT



from turtle import *
def draw_square():
  """Draws a square of the specified size."""
  
  s = Turtle()
  size = 4
  i = 0
  while i < size:
      s.forward(150)
      s.left(90)
      i+=1    

def factorial(number):
    """Calculates the factorial of the specified number."""
    factorial_result = 1
    counter = 1
    while counter < number + 1:
        factorial_result *= counter
        counter += 1
    print("The factorial of ", number, " is ", factorial_result)
    print(" ") # For spacing between function calls.

    
def fibonacci():
  """Returns the nth Fibonacci number."""
  FiboN = 10
  Fibo1,Fibo2 = 1,1
  i = 0

  while i < FiboN:
      print("Fibonacci number: ", Fibo1)
      Fibo1,Fibo2 = Fibo2, Fibo1+Fibo2
      i += 1

  print(" ")

def multiplication_table(n):
    """Prints the multiplication tables up to the specified number. Starting from 3."""
    base = 3
    multiplier = 1

    while base <= n:
        while multiplier <= n:
            print(base, " x ", multiplier, " = ", base * multiplier)
            multiplier += 1 #while base won't continue looping until while multiplier is done, generating multiple tables.

        base += 1 # Increments ba
        multiplier = 1 # resets the multiplier to create next table
        print(" ")
        

        
def matrix_multiplication(A, B):
    """Multiplies two matrices"""
    # Store the input matrices in variables for easier reference
    Matrix_A = A
    Matrix_B = B

    # Get the dimensions of the first matrix
    rows_A = len(Matrix_A)
    cols_A = len(Matrix_A[0])
    
    # Get the dimensions of the second matrix
    rows_B = len(Matrix_B)
    cols_B = len(Matrix_B[0])
    
    # Initialize an empty list to store the result of the multiplication
    A_Placeholder = []
    # Use a while loop to create a list of lists with the desired dimensions
    i = 0
    while i < rows_A:
        # Create a new row with all elements initialized to 0
        row = [0] * cols_B
        # Add the new row to the result list using indexing
        A_Placeholder[i:i] = [row]
        i += 1

    
    # Check if the matrices can be multiplied
    if cols_A != rows_B:
        print("The matrices cannot be multiplied because the number of columns in the first matrix does not match the number of rows in the second matrix.")
        return
    
    # Use a nested while loop to perform the matrix multiplication.
    i = 0 # Tracks row of Mat A
    while i < rows_A:
        j = 0 #This variable will be used to keep track of the current column of Matrix_B
        while j < cols_B:
            k = 0 #This variable is used to keep track of the current value in the row of Matrix_A and column of Matrix_B.
            product = 0
            while k < cols_A:
                # Calculate the dot product of the current row of Matrix_A and the current column of Matrix_B
                product += Matrix_A[i][k] * Matrix_B[k][j] 
                k += 1
            # Store the result in the corresponding element of A_Placeholder
            A_Placeholder[i][j] = product
            j += 1
        i += 1

    # Print the result matrix row by row
    print("This is the product matrix of", Matrix_A, " and ", Matrix_B, "is")
    for i in A_Placeholder:
        print(i)

    print(" ")
    print(" ")

#Calls 

draw_square()
factorial(10)
fibonacci()


A = [[1, 2, 3, 4, 5], 
     [6, 7, 8, 9, 10], 
     [11, 12, 13, 14, 15], 
     [16, 17, 18, 19, 20], 
     [21, 22, 23, 24, 25]] 
B = [[1],
     [2], 
     [3], 
     [4], 
     [5]]

matrix_multiplication(A,B)



