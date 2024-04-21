#Mr. Chris'Group B.
#BSc. IT
#Simelane N. Vezokuhle - 202301485
#Shoulder N. Sharoon - 202304483
#Mazibuko Thabiso 202302349
#Fakudze Mazwamahle 202302260
#Khumalo Vuyo 202302214
#Gwebu N. Beyond 202304934


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
    print(" ")

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
    """Prints the multiplication tables up to the specified number. Starting from 3"""
    base = 3
    multiplier = 1

    while base <= n:
        while multiplier <= n:
            print(base, " x ", multiplier, " = ", base * multiplier)
            multiplier += 1

        base += 1
        multiplier = 1
        print(" ")
        

        
def matrix_multiplication(A, B):
    """Multiplies two matrices that respect laws of matrix multiplication"""
    Matrix_A = A
    Matrix_B = B

    rows_A = len(Matrix_A) 
    cols_A = len(Matrix_A[0])
    
    rows_B = len(Matrix_B)
    cols_B = len(Matrix_B[0])
    
    A_Placeholder = []
    i = 0
    while i < rows_A:
        row = [0] * cols_B
        A_Placeholder[i:i] = [row]
        i += 1

    
    if cols_A != rows_B:
        print("The matrices cannot be multiplied because the number of columns in the first matrix does not match the number of rows in the second matrix.")
        return
    
    i = 0
    while i < rows_A:
        j = 0
        while j < cols_B:
            k = 0
            product = 0
            while k < cols_A:
                
                product += Matrix_A[i][k] * Matrix_B[k][j]
                k += 1
            
            A_Placeholder[i][j] = product
            j += 1
        i += 1

    
    print("This is the product matrix of", Matrix_A, " and ", Matrix_B, "is")
    for i in A_Placeholder:
        print(i)

    print(" ")
    print(" ")


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


#Calls 

draw_square()
factorial(10)
fibonacci()
multiplication_table(8)
matrix_multiplication(A,B)


