def add():
    n = int(input("Enter the number of elements in Set 1: "))
    s = set()
    for i in range(n):
        e = int(input("Enter number: "))
        s.add(e)
    print("Set 1:", s)

    m = int(input("Enter the number of elements in Set 2: "))
    t = set()
    for i in range(m):
        f = int(input("Enter number: "))
        t.add(f)
    print("Set 2:", t)
    
    return s, t

def remo_from_set(set_name, s):
    q = int(input(f"Enter the element to be removed from {set_name}: "))
    if q in s:
        s.remove(q)
    else:
        print("Element not found in the set.")
    print(f"{set_name} after removal:", s)

def check_element(set_name, s):
    x = int(input(f"Enter the element to check in {set_name}: "))
    if x in s:
        print(f"***Element present in {set_name}***")
    else:
        print(f"***Element not present in {set_name}***")

def size(set_name, s):
    print(f"Size of {set_name} =", len(s))

def union(s, t):
    print("Union =", s | t)

def intersection(s, t):
    print("Intersection =", s & t)

def diff(s, t):
    print("Difference (Set1 - Set2) =", s - t)

def subset1(s, t):
    print("Is Set1 a subset of Set2?", s.issubset(t))

def subset2(s, t):
    print("Is Set2 a subset of Set1?", t.issubset(s))


# Main program
s, t = set(), set()
flag = 1
while flag == 1:
    print("\n--- MENU ---")
    print("1. Add elements")
    print("2. Remove element from Set 1")
    print("3. Remove element from Set 2")
    print("4. Check element in Set 1")
    print("5. Check element in Set 2")
    print("6. Size of Set 1")
    print("7. Size of Set 2")
    print("8. Union")
    print("9. Intersection")
    print("10. Difference")
    print("11. Is Set1 subset of Set2?")
    print("12. Is Set2 subset of Set1?")
    print("13. Exit")

    ch = int(input("**ENTER YOUR CHOICE**: "))

    if ch == 1:
        s, t = add()
    elif ch == 2:
        remo_from_set("Set 1", s)
    elif ch == 3:
        remo_from_set("Set 2", t)
    elif ch == 4:
        check_element("Set 1", s)
    elif ch == 5:
        check_element("Set 2", t)
    elif ch == 6:
        size("Set 1", s)
    elif ch == 7:
        size("Set 2", t)
    elif ch == 8:
        union(s, t)
    elif ch == 9:
        intersection(s, t)
    elif ch == 10:
        diff(s, t)
    elif ch == 11:
        subset1(s, t)
    elif ch == 12:
        subset2(s, t)
    elif ch == 13:
        flag = 0
    else:
        print("Enter a valid choice.")
