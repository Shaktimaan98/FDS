def accept_array(A): 
    n = int(input("Enter the total no. of students: "))
    for i in range(n):
        x = float(input(f"Enter the first year percentage of student {i + 1}: "))
        A.append(x)
    print("Array accepted successfully\n\n")

def display_array(A): 
    n = len(A)
    if n == 0:
        print("\nNo records in the database")
    else:
        print("Array of FE Marks:", end=' ')
        for i in range(n):
            print(f"{A[i]:.2f}", end=' ')
        print("\n")

def Selection_sort(A):
    n = len(A)
    for pos in range(n - 1):
        min_ind = pos
        for i in range(pos + 1, n):
            if A[i] < A[min_ind]:
                min_ind = i
        A[pos], A[min_ind] = A[min_ind], A[pos]  # Swap in one line

def Bubble_sort(A):
    n = len(A)
    for pass_num in range(1, n):
        for i in range(n - pass_num):
            if A[i] < A[i + 1]:  # Sort in descending order
                A[i], A[i + 1] = A[i + 1], A[i]  # Swap in one line

def Main(): 
    A = []
    while True:
        print("\t1 : Accept & Display the FE Marks")
        print("\t2 : Selection Sort Ascending order")
        print("\t3 : Bubble sort Descending order and display top five scores")
        print("\t4 : Exit")
        ch = int(input("Enter your choice: "))
        if ch == 4:
            print("End of Program")
            break
        elif ch == 1:
            accept_array(A)
            display_array(A)
        elif ch == 2:
            print("Marks before sorting:")
            display_array(A)
            Selection_sort(A)
            print("Marks after sorting:")
            display_array(A)
        elif ch == 3:
            print("Marks before sorting:")
            display_array(A)
            Bubble_sort(A)
            print("Marks after sorting:")
            display_array(A)
            print("Top Five Scores:")
            top_scores = A[:5] if len(A) >= 5 else A
            for score in top_scores:
                print(f"\t{score:.2f}")
        else:
            print("Wrong choice entered! Try again.")

Main()
