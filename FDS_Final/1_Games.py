def take(student_list,sports_name):
    num=int(input(f"Enter the number of students who play {sports_name}:- "))
    for i in range(num):
        name=input(f"Enter Student No {i+1} who play {sports_name} :- ")
        student_list.append(name)

def show(student_list,sports_name):
    print(f"Students Who play {sports_name} :- ")
    for name in student_list:
        print(name,end=" ")
    print()

def search(student_list,name):
    return 1 if name in student_list else 0
    
def find_intersection(set1,set2,result):
    for student in set1:
        if search(set2,student):
            result.append(student)

def find_diffrent(set1,set2,result):
    for student in set1:
        if not search(set2,student):
            result.append(student)


def find_union(set1,set2,result):
    result.extend(set1)
    for student in set2:
        if not search(set1,student):
            result.append(student)

def main():
    cricket=[]
    badminton=[]
    football=[]

    while True:
        print("\n Menu")
        print("\t1. Append data")
        print("\t2. List of students who play both cricket and badminton")
        print("\t3. List of students who play either cricket or badminton but not both")
        print("\t4. Number of students who play neither cricket nor badminton")
        print("\t5. Number of students who play cricket and football but not badminton")
        print("\t6. Exit")

        ch=int(input("Enter Your Choice :- "))
        result=[]

        if ch==6:
            print("Than You !!")
            break

        elif ch==1:
            take(cricket,"Cricket")
            take(badminton,"Badminton")
            take(football,"Football")

            show(cricket,"Cricket")
            show(badminton,"Badminton")
            show(football,"Football")

        elif ch==2:
            find_intersection(cricket,badminton,result)
            show(result," List of students who play both cricket and badminton")
        elif ch==3:
            union=[]
            inter=[]
            find_union(cricket,badminton,union)
            find_intersection(cricket,badminton,inter)
            find_diffrent(union,inter,result)
            show(result,"List of students who play either cricket or badminton but not both")

        elif ch==4:
            union=[]
            find_union(cricket,badminton,union)
            find_diffrent(football,union,result)
            show(result,"Number of students who play neither cricket nor badminton ")
            print("Number of students who play neither cricket nor badminton",len(result))

        elif ch==5:
            intern=[]
            find_intersection(cricket,football,intern)
            find_diffrent(intern,badminton,result)
            show(result,"Number of students who play cricket and football but not badminton ")
            print("Number of students who play cricket and football but not badminton ",len(result))
        else:
            print("Invalid")

main()




    