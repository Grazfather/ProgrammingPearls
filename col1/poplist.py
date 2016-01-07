with open("nums.txt", "w") as f:
    for i in range(10000000, 0, -1):
        f.write(str(i))
        f.write("\n")
