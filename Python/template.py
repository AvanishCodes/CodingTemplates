# Function for Fast Output 
import io, os, sys, time 
def fast_out(x): 
  sys.stdout.write(str(x)+"\n")         

# Function for Fast Input 
def fast_input(): 
	
	# Reinitialize the Input function 
	# to take input from the Byte Like 
	# objects 
	input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline 
	s = input().decode() 
	print(type(s), s)
	return s

# Driver Code 
if __name__ == "__main__": 

  # For getting input from input.txt file 
  # sys.stdin = open('input.txt', 'r')    
  # Printing the Output to output.txt file 
  # sys.stdout = open('output.txt', 'w') 
  x = fast_input()
  # x = "GfG"
  fast_out(x)
