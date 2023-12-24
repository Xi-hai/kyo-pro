grid = [list(map(int, input().split())) for _ in range(9)]
ans = True

# rows
for i in range(9):
    checklist = [False] * 10
    for j in range(9):
        if checklist[grid[i][j]] == True:
            ans = False
            break
        else:
            checklist[grid[i][j]] = True
    else:
        continue
    break

# columns
for j in range(9):
    checklist = [False] * 10
    for i in range(9):
        if checklist[grid[i][j]] == True:
            ans = False
            break
        else:
            checklist[grid[i][j]] = True
    else:
        continue
    break

# blocks
for di in range(3):
    for dj in range(3):
        checklist = [False] * 10
        for i in range(3):
            for j in range(3):
                if checklist[grid[ i+3*di ][ j+3*dj ]] == True:
                    ans = False
                    break
                else:
                    checklist[grid[ i+3*di ][ j+3*dj ]] = True
            else:
                continue
            break
        else:
            continue
        break
    else:
        continue
    break

print("Yes" if ans else "No")